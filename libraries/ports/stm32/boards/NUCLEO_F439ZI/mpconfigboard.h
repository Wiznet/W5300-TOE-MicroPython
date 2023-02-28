#define MICROPY_HW_BOARD_NAME       "NUCLEO-F439ZI"
#define MICROPY_HW_MCU_NAME         "STM32F439ZIT6"

#define MICROPY_HW_HAS_SWITCH       (1)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE (1)
#define MICROPY_HW_ENABLE_INTERNAL_FLASH_STORAGE_SEGMENT2 (1)
#define MICROPY_HW_ENABLE_RNG       (1)
#define MICROPY_HW_ENABLE_RTC       (1)
#define MICROPY_HW_ENABLE_USB       (1)
#define MICROPY_HW_ENABLE_SERVO     (1)

// HSE is 8MHz from ST-LINK, in bypass mode, run SYSCLK at 168MHz
#define MICROPY_HW_CLK_USE_BYPASS   (1)
#define MICROPY_HW_CLK_PLLM         (8)
#define MICROPY_HW_CLK_PLLN         (336)
#define MICROPY_HW_CLK_PLLP         (RCC_PLLP_DIV2)
#define MICROPY_HW_CLK_PLLQ         (7)
#define MICROPY_HW_FLASH_LATENCY    FLASH_LATENCY_5

// The board has a 32768Hz crystal for LSE
#define MICROPY_HW_RTC_USE_LSE      (1)
#define MICROPY_HW_RTC_USE_US       (1)

// UART config
#if (MICROPY_PY_NETWORK_WIZNET5K == 5300)
#define MICROPY_HW_UART2_CTS        (pin_A0)
#define MICROPY_HW_UART2_RTS        (pin_A1)
#define MICROPY_HW_UART2_TX         (pin_A2)
#define MICROPY_HW_UART2_RX         (pin_A3)
#define MICROPY_HW_UART3_TX         (pin_C10)
#define MICROPY_HW_UART3_RX         (pin_C11)
#else
#define MICROPY_HW_UART2_CTS        (pin_D3)
#define MICROPY_HW_UART2_RTS        (pin_D4)
#define MICROPY_HW_UART2_TX         (pin_D5)
#define MICROPY_HW_UART2_RX         (pin_D6)
#define MICROPY_HW_UART3_TX         (pin_C10)
#define MICROPY_HW_UART3_RX         (pin_C11)

#endif

#define MICROPY_HW_UART6_TX         (pin_G14)
#define MICROPY_HW_UART6_RX         (pin_G9)
#define MICROPY_HW_UART_REPL        PYB_UART_3
#define MICROPY_HW_UART_REPL_BAUD   115200

// I2C buses
#define MICROPY_HW_I2C1_SCL         (pin_B8)
#define MICROPY_HW_I2C1_SDA         (pin_B9)
#define MICROPY_HW_I2C2_SCL         (pin_F1)
#define MICROPY_HW_I2C2_SDA         (pin_F0)

// SPI buses
#if (MICROPY_PY_NETWORK_WIZNET5K == 5300)
#define MICROPY_HW_SPI1_NSS         (pin_A15)
#else
#define MICROPY_HW_SPI1_NSS         (pin_D14)
#endif

#define MICROPY_HW_SPI1_SCK         (pin_A5)
#define MICROPY_HW_SPI1_MISO        (pin_A6)
#define MICROPY_HW_SPI1_MOSI        (pin_A7)
#define MICROPY_HW_SPI3_NSS         (pin_A4)
#define MICROPY_HW_SPI3_SCK         (pin_B3)
#define MICROPY_HW_SPI3_MISO        (pin_B4)
#define MICROPY_HW_SPI3_MOSI        (pin_B5)

// CAN buses
#if (MICROPY_PY_NETWORK_WIZNET5K == 5300)
#define MICROPY_HW_CAN1_TX          (pin_A12)
#define MICROPY_HW_CAN1_RX          (pin_A11)

#else
#define MICROPY_HW_CAN1_TX          (pin_D1)
#define MICROPY_HW_CAN1_RX          (pin_D0)
#endif

// USRSW is pulled low; pressing the button makes the input go high.
#define MICROPY_HW_USRSW_PIN        (pin_C13)
#define MICROPY_HW_USRSW_PULL       (GPIO_NOPULL)
#define MICROPY_HW_USRSW_EXTI_MODE  (GPIO_MODE_IT_RISING)
#define MICROPY_HW_USRSW_PRESSED    (1)

// LEDs
#define MICROPY_HW_LED1             (pin_B0) // green
#define MICROPY_HW_LED2             (pin_B7) // blue
#define MICROPY_HW_LED3             (pin_B14) // red
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_low(pin))

// USB config (CN13 - USB OTG FS)
#define MICROPY_HW_USB_FS              (1)
#define MICROPY_HW_USB_VBUS_DETECT_PIN (pin_A9)
#define MICROPY_HW_USB_OTG_ID_PIN      (pin_A10)


#if (MICROPY_PY_NETWORK_WIZNET5K == 5300)
// FMC configure for W5300
#define MICROPY_HW_FMC_A0   (pin_F0)
#define MICROPY_HW_FMC_A1   (pin_F1)
#define MICROPY_HW_FMC_A2 	(pin_F2)
#define MICROPY_HW_FMC_A3 	(pin_F3)
#define MICROPY_HW_FMC_A4   (pin_F4)
#define MICROPY_HW_FMC_A5   (pin_F5)
#define MICROPY_HW_FMC_A6	(pin_F12)
#define MICROPY_HW_FMC_A7	(pin_F13)
#define MICROPY_HW_FMC_A8	(pin_F14)
#define MICROPY_HW_FMC_A9	(pin_F15)

#define MICROPY_HW_FMC_D0	(pin_D14)
#define MICROPY_HW_FMC_D1	(pin_D15)
#define MICROPY_HW_FMC_D2	(pin_D0)
#define MICROPY_HW_FMC_D3	(pin_D1)
#define MICROPY_HW_FMC_D4	(pin_E7)
#define MICROPY_HW_FMC_D5	(pin_E8)
#define MICROPY_HW_FMC_D6	(pin_E9)
#define MICROPY_HW_FMC_D7	(pin_E10)
#define MICROPY_HW_FMC_D8	(pin_E11)
#define MICROPY_HW_FMC_D9	(pin_E12)
#define MICROPY_HW_FMC_D10	(pin_E13)
#define MICROPY_HW_FMC_D11	(pin_E14)
#define MICROPY_HW_FMC_D12	(pin_E15)
#define MICROPY_HW_FMC_D13	(pin_D8)
#define MICROPY_HW_FMC_D14	(pin_D9)
#define MICROPY_HW_FMC_D15	(pin_D10)

#define MICROPY_HW_FMC_NO	(pin_D4)
#define MICROPY_HW_FMC_NW	(pin_D5)
#define MICROPY_HW_FMC_NE1	(pin_D7)

#define MICROPY_HW_WIZCHIP_RST	(pin_C8)
#define MICROPY_HW_WIZCHIP_INT 	(pin_C9)


#else
// Ethernet via RMII
#define MICROPY_HW_ETH_MDC          (pin_C1)
#define MICROPY_HW_ETH_MDIO         (pin_A2)
#define MICROPY_HW_ETH_RMII_REF_CLK (pin_A1)
#define MICROPY_HW_ETH_RMII_CRS_DV  (pin_A7)
#define MICROPY_HW_ETH_RMII_RXD0    (pin_C4)
#define MICROPY_HW_ETH_RMII_RXD1    (pin_C5)
#define MICROPY_HW_ETH_RMII_TX_EN   (pin_G11)
#define MICROPY_HW_ETH_RMII_TXD0    (pin_G13)
#define MICROPY_HW_ETH_RMII_TXD1    (pin_B13)
#endif
