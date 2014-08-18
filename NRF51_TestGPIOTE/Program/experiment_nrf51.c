/*====================================================================================================*/
/*====================================================================================================*/
#include "nrf51_system.h"
#include "nrf51_gpiote.h"
#include "experiment_nrf51.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define LED_PORT  (*((vu8*)(&(NRF_GPIO->OUT))))   // Use Port0 ( Pin 0-7 )
/*====================================================================================================*/
/*====================================================================================================*/
int main( void )
{
  u8 i = 0;

  GPIO_Config();
  GPIOTE_Config();

  #define DELAY_TIME 8
  while(1) {

    // Port 0 ( Pin 0-7 ) Blink
    for(i = 0; i<8; i++) {
      LED_PORT = ~(0x01<<i);
      Delay_10ms(DELAY_TIME);
    }
    for(i = 6; i>0; i--) {
      LED_PORT = ~(0x01<<i);
      Delay_10ms(DELAY_TIME);
    }

    // Pin 19 Toggle
    nrf_gpio_pin_toggle(LED_1);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void GPIO_Config( void )
{
  nrf_gpio_range_cfg_output( 0,  7);              // Pin 00-07 - output
  nrf_gpio_range_cfg_output(LED_0, LED_1);        // Pin 18-19 - output
}
/*====================================================================================================*/
/*====================================================================================================*/
void GPIOTE_Config( void )
{
  GPIOTE_InitTypeDef GPIOTE_InitStruct;

  GPIOTE_InitStruct.GPIOTE_Pin = KEY;                                 // pin 20
  GPIOTE_InitStruct.GPIOTE_Mode = GPIOTE_CONFIG_MODE_Event;           // output
  GPIOTE_InitStruct.GPIOTE_Polarity = GPIOTE_CONFIG_POLARITY_HiToLo;  // high to low
  GPIOTE_Init(&GPIOTE_InitStruct, KEY_EL);                            // Line 0

  NVIC_EnableIRQ(GPIOTE_IRQn);
}
/*====================================================================================================*/
/*====================================================================================================*/
