/*
 * Copyright (C) 2018 BlueKitchen GmbH
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holders nor the names of
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 4. Any redistribution, use, or modification is done solely for
 *    personal benefit and not for any commercial purpose or for
 *    monetary gain.
 *
 * THIS SOFTWARE IS PROVIDED BY BLUEKITCHEN GMBH AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL BLUEKITCHEN
 * GMBH OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Please inquire about commercial licensing options at 
 * contact@bluekitchen-gmbh.com
 *
 */

#define BTSTACK_FILE__ "att_delayed_response.c"

// *****************************************************************************
/* EXAMPLE_START(att_delayed_response): LE Peripheral - Delayed Response
 *
 * @text If the value for a GATT Chararacteristic isn't availabl for read,
 * the value ATT_READ_RESPONSE_PENDING can be returned. When the value is available, 
 * att_server_response_ready is then called to complete the ATT request.
 * 
 * Similarly, the error code ATT_ERROR_WRITE_RESPONSE_PENING can be returned when
 * it is unclear if a write can be performed or not. When the decision was made,
 * att_server_response_ready is is then called to complete the ATT request.
 */
 // *****************************************************************************

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "btstack.h"

// att_delayed_response.gatt contains the declaration of the provided GATT Services + Characteristics
// att_delayed_response.h    contains the binary representation of att_delayed_response.gatt
// it is generated by the build system by calling: $BTSTACK_ROOT/tool/compile_gatt.py att_delayed_response.gatt att_delayed_response.h
// it needs to be regenerated when the GATT Database declared in att_delayed_response.gatt file is modified
#include "att_delayed_response.h"

#define ATT_VALUE_DELAY_MS   3000
#define ATT_VALUE_INVALID_MS 5000

/* @section Main Application Setup
 *
 * @text Listing MainConfiguration shows main application code.
 * It initializes L2CAP, the Security Manager and configures the ATT Server with the pre-compiled
 * ATT Database generated from $att_delayed_response.gatt$. 
 * Additionally, it enables the Battery Service Server with the current battery level.
 * Finally, it configures the advertisements and boots the Bluetooth stack. 
 * In this example, the Advertisement contains the Flags attribute and the device name.
 * The flag 0x06 indicates: LE General Discoverable Mode and BR/EDR not supported.
 */
 
/* LISTING_START(MainConfiguration): Init L2CAP SM ATT Server */
#ifdef ENABLE_ATT_DELAYED_RESPONSE
static btstack_timer_source_t att_timer;
static hci_con_handle_t con_handle;
static int value_ready;
#endif

static uint16_t att_read_callback(hci_con_handle_t con_handle, uint16_t att_handle, uint16_t offset, uint8_t * buffer, uint16_t buffer_size);
static int att_write_callback(hci_con_handle_t connection_handle, uint16_t att_handle, uint16_t transaction_mode, uint16_t offset, uint8_t *buffer, uint16_t buffer_size);

const uint8_t adv_data[] = {
    // Flags general discoverable, BR/EDR not supported
    0x02, 0x01, 0x06, 
    // Name
    0x08, 0x09, 'D', 'e', 'l', 'a', 'y', 'e', 'd', 
};
const uint8_t adv_data_len = sizeof(adv_data);

const char * test_string = "Delayed response";

static void example_setup(void){

    l2cap_init();

    // setup SM: Display only
    sm_init();

    // setup ATT server
    att_server_init(profile_data, att_read_callback, att_write_callback);

    // setup advertisements
    uint16_t adv_int_min = 0x0030;
    uint16_t adv_int_max = 0x0030;
    uint8_t adv_type = 0;
    bd_addr_t null_addr;
    memset(null_addr, 0, 6);
    gap_advertisements_set_params(adv_int_min, adv_int_max, adv_type, 0, null_addr, 0x07, 0x00);
    gap_advertisements_set_data(adv_data_len, (uint8_t*) adv_data);
    gap_advertisements_enable(1);
}
/* LISTING_END */

/*
 * @section att_invalidate_value Handler
 *
 * @text The att_invalidate_value handler 'invalidates' the value of the single Characteristic provided in this example
 */
#ifdef ENABLE_ATT_DELAYED_RESPONSE
static void att_invalidate_value(struct btstack_timer_source *ts){
    UNUSED(ts);
    printf("Value got stale\n");
    value_ready = 0;
} 
#endif

/*
 * @section att_update_value Handler
 *
 * @text The att_update_value handler 'updates' the value of the single Characteristic provided in this example
 */

 /* LISTING_START(att_read_delay): ATT Read Delay Handler */
#ifdef ENABLE_ATT_DELAYED_RESPONSE
static void att_update_value(struct btstack_timer_source *ts){
    UNUSED(ts);
    value_ready = 1;

    // trigger ATT Server to try request again
    int status = att_server_response_ready(con_handle);

    printf("Value updated -> complete ATT request - status %02x\n", status);

    // simulated value becoming stale again
    att_timer.process = &att_invalidate_value;
    btstack_run_loop_set_timer(&att_timer, ATT_VALUE_DELAY_MS);
    btstack_run_loop_add_timer(&att_timer);
} 
#endif

/* LISTING_END */

/*
 * @section ATT Read
 *
 * @text The ATT Server handles all reads to constant data. For dynamic data like the custom characteristic, the registered
 * att_read_callback is called. To handle long characteristics and long reads, the att_read_callback is first called
 * with buffer == NULL, to request the total value length. Then it will be called again requesting a chunk of the value.
 * See Listing attRead.
 */

/* LISTING_START(attRead): ATT Read */

// ATT Client Read Callback for Dynamic Data
// - if buffer == NULL, don't copy data, just return size of value
// - if buffer != NULL, copy data and return number bytes copied
// @param offset defines start of attribute value
static uint16_t att_read_callback(hci_con_handle_t connection_handle, uint16_t att_handle, uint16_t offset, uint8_t * buffer, uint16_t buffer_size){

#ifdef ENABLE_ATT_DELAYED_RESPONSE
    switch (att_handle){
        case ATT_CHARACTERISTIC_0000FF11_0000_1000_8000_00805F9B34FB_01_VALUE_HANDLE:
            if (value_ready){
                return att_read_callback_handle_blob((const uint8_t *)test_string, strlen(test_string), offset, buffer, buffer_size);
            } else {
                printf("Read callback for handle %02x, but value not ready -> report response pending\n", att_handle);
                con_handle = connection_handle;
                return ATT_READ_RESPONSE_PENDING;
            }
            break;
        case ATT_READ_RESPONSE_PENDING:
            // virtual handle indicating all attributes have been queried
            printf("Read callback for virtual handle %02x - all attributes have been queried (important for read multiple or read by type) -> start updating values\n", att_handle);
            // simulated delayed response for example
            att_timer.process = &att_update_value;
            btstack_run_loop_set_timer(&att_timer, ATT_VALUE_DELAY_MS);
            btstack_run_loop_add_timer(&att_timer);
            return 0;
        default:
            break;
    }
#else
    UNUSED(connection_handle);
    // useless code when ENABLE_ATT_DELAYED_RESPONSE is not defined - but avoids built errors
    if (att_handle == ATT_CHARACTERISTIC_0000FF11_0000_1000_8000_00805F9B34FB_01_VALUE_HANDLE){
        printf("ENABLE_ATT_DELAYED_RESPONSE not defined in btstack_config.h, responding right away");
        return att_read_callback_handle_blob((const uint8_t *)test_string, (uint16_t) strlen(test_string), offset, buffer, buffer_size);
    }
#endif

    return 0;
}

/*
 * @section ATT Write
 * */

/* LISTING_START(attWrite): ATT Write */
static int att_write_callback(hci_con_handle_t connection_handle, uint16_t att_handle, uint16_t transaction_mode, uint16_t offset, uint8_t *buffer, uint16_t buffer_size){
    UNUSED(transaction_mode);
    UNUSED(offset);
    UNUSED(buffer_size);
    UNUSED(connection_handle);
    
    if (att_handle == ATT_CHARACTERISTIC_0000FF11_0000_1000_8000_00805F9B34FB_01_VALUE_HANDLE) {
        printf("Write request, value: ");
        printf_hexdump(buffer, buffer_size);
#ifdef ENABLE_ATT_DELAYED_RESPONSE
        if (value_ready){
            printf("Write callback, value ready\n");
            return 0;                    
        } else {
            printf("Write callback for handle %02x, but not ready -> return response pending\n", att_handle);
        }
        // simulated delayed response for example
        att_timer.process = &att_update_value;
        btstack_run_loop_set_timer(&att_timer, ATT_VALUE_DELAY_MS);
        btstack_run_loop_add_timer(&att_timer);
        return ATT_ERROR_WRITE_RESPONSE_PENDING;
#else
        printf("ENABLE_ATT_DELAYED_RESPONSE not defined in btstack_config.h, responding right away");
        return 0;
#endif
    }
    return 0;
}

/* LISTING_END */

int btstack_main(void);
int btstack_main(void)
{
    example_setup();

    // turn on!
	hci_power_control(HCI_POWER_ON);
	    
    return 0;
}
/* EXAMPLE_END */
