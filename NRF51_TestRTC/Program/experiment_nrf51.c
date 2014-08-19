/*====================================================================================================*/
/*====================================================================================================*/
#include "nrf51_system.h"
#include "nrf51_rtc.h"
#include "experiment_nrf51.h"
/*====================================================================================================*/
/*====================================================================================================*/
int main( void )
{
  u8 i = 0;

  GPIO_Config();
  RTC_Config();

  while(1) {

//    nrf_gpio_pin_toggle(LED_0);
//    nrf_gpio_pin_toggle(LED_1);
    for(i = 0; i<7; i++) {
//      nrf_gpio_word_byte_write(&(NRF_GPIO->OUT), NRF_GPIO_PORT_SELECT_PORT0, ~(0x01<<i));
      LED_PORT = ~(0x01<<i);
      Delay_10ms(DELAY_TIME);
    }
//    nrf_gpio_pin_toggle(LED_0);
//    nrf_gpio_pin_toggle(LED_1);
    for(i = 7; i>0; i--) {
//      nrf_gpio_word_byte_write(&(NRF_GPIO->OUT), NRF_GPIO_PORT_SELECT_PORT0, ~(0x01<<i));
      LED_PORT = ~(0x01<<i);
      Delay_10ms(DELAY_TIME);
    }

  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void GPIO_Config( void )
{
  nrf_gpio_range_cfg_output(0, 7);              // Pin 00-07 - output
  nrf_gpio_range_cfg_output(LED_0, LED_1);      // Pin 18-19 - output
  nrf_gpio_cfg_input(KEY, NRF_GPIO_PIN_PULLUP); // Pin 20    - input
}
/*====================================================================================================*/
/*====================================================================================================*/