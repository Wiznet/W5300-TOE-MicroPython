 
 /*
  * This file is part of the Wiznet5K W5300 project.
  * Copyright (c) 2023 wiznet <wiznet@wiznet.io>
  * This work is licensed under the MIT license, see the file LICENSE for details.
  *
  * W5300 FMC Driver.
  */

#include <fmc.h>



void mp_hal_fmc_clock_enable() {
	__IO uint32_t tmpreg = 0;
	SET_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN);
	tmpreg = READ_BIT(RCC->AHB3ENR, RCC_AHB3ENR_FMCEN);

	(void)(tmpreg);
}


static void HAL_FMC_Msp_Init(void){

    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_A0, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_A0);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_A1, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_A1);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_A2, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_A2);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_A3, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_A3);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_A4, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_A4);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_A5, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_A5);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_A6, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_A6);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_A7, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_A7);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_A8, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_A8);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_A9, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_A9);

    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D0, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D0);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D1, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D1);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D2, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D2);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D3, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D3);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D4, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D4);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D5, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D5);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D6, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D6);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D7, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D7);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D8, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D8);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D9, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D9);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D10, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D10);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D11, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D11);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D12, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D12);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D13, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D13);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D14, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D14);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_D15, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_D15);
	
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_NO, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_NOE);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_NW, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_NWE);
    mp_hal_pin_config_alt_static_speed(MICROPY_HW_FMC_NE1, MP_HAL_PIN_MODE_ALT, MP_HAL_PIN_PULL_NONE, MP_HAL_PIN_SPEED_VERY_HIGH, STATIC_AF_FMC_NE1);


}

static bool HAL_FMC_Init(void) {

	SRAM_HandleTypeDef hsram1;
	FMC_NORSRAM_TimingTypeDef Timing = {0};
	
#if defined(STM32F4) 
 
    hsram1.Instance = FMC_NORSRAM_DEVICE;
	hsram1.Extended = FMC_NORSRAM_EXTENDED_DEVICE;

    hsram1.Init.NSBank = FMC_NORSRAM_BANK1;
	hsram1.Init.DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
  	hsram1.Init.MemoryType = FMC_MEMORY_TYPE_SRAM;
  	hsram1.Init.MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_16;
  	hsram1.Init.BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
  	hsram1.Init.WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_LOW;
  	hsram1.Init.WrapMode = FMC_WRAP_MODE_DISABLE;
  	hsram1.Init.WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
  	hsram1.Init.WriteOperation = FMC_WRITE_OPERATION_ENABLE;
  	hsram1.Init.WaitSignal = FMC_WAIT_SIGNAL_DISABLE;
  	hsram1.Init.ExtendedMode = FMC_EXTENDED_MODE_DISABLE;
  	hsram1.Init.AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_DISABLE;
  	hsram1.Init.WriteBurst = FMC_WRITE_BURST_DISABLE;
  	hsram1.Init.ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
  	hsram1.Init.PageSize = FMC_PAGE_SIZE_NONE;


	Timing.AddressSetupTime = 1;
	Timing.AddressHoldTime = 15;
	Timing.DataSetupTime = 6;
	Timing.BusTurnAroundDuration = 0;
	Timing.CLKDivision = 16;
	Timing.DataLatency = 17;
	Timing.AccessMode = FMC_ACCESS_MODE_A;

#elif defined(STM32F7) 

	hsram1.Instance = FMC_NORSRAM_DEVICE;
	
	hsram1.Extended = FMC_NORSRAM_EXTENDED_DEVICE;
	/* hsram1.Init */
	hsram1.Init.NSBank = FMC_NORSRAM_BANK1;
	hsram1.Init.DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
	hsram1.Init.MemoryType = FMC_MEMORY_TYPE_SRAM;
	hsram1.Init.MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_16;
	hsram1.Init.BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
	hsram1.Init.WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_LOW;
	hsram1.Init.WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
	hsram1.Init.WriteOperation = FMC_WRITE_OPERATION_ENABLE;
	hsram1.Init.WaitSignal = FMC_WAIT_SIGNAL_DISABLE;
	hsram1.Init.ExtendedMode = FMC_EXTENDED_MODE_DISABLE;
	hsram1.Init.AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_DISABLE;
	hsram1.Init.WriteBurst = FMC_WRITE_BURST_DISABLE;
	hsram1.Init.ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ONLY;
	hsram1.Init.WriteFifo = FMC_WRITE_FIFO_ENABLE;
	hsram1.Init.PageSize = FMC_PAGE_SIZE_NONE;
	/* Timing */
	Timing.AddressSetupTime = 1;
	Timing.AddressHoldTime = 1;
	Timing.DataSetupTime = 7;
	Timing.BusTurnAroundDuration = 0;
	Timing.CLKDivision = 2;
	Timing.DataLatency = 2;
	Timing.AccessMode = FMC_ACCESS_MODE_A;
	/* ExtTiming */

#endif

	if (HAL_SRAM_Init(&hsram1, &Timing, NULL) != HAL_OK)
	{
	//Error_Handler( );
		return false;
	}
	return true;

}

void fmc_w5300_init(void){

	mp_hal_fmc_clock_enable();
	
	HAL_FMC_Msp_Init();
	if (!HAL_FMC_Init()){
		mp_printf(&mp_plat_print, "\r\n!! FMC init failed\n");
	}
}

