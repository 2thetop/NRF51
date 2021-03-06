/*====================================================================================================*/
/*====================================================================================================*/
#include "nrf51_system.h"
#include "experiment_nrf51.h"
#include "module_rs232.h"
/*====================================================================================================*/
/*====================================================================================================*/
int main( void )
{
  uint8_t RecvData = 0;

  GPIO_Config();
  RS232_Config();

  Delay_1ms(1);

  RS232_SendStr((uint8_t*)"\r\nHello World!\r\n\r\n");

  while(1) {
    nrf_gpio_pin_toggle(LED_1);
    nrf_gpio_pin_toggle(LED_2);
    nrf_gpio_pin_toggle(LED_3);
    nrf_gpio_pin_toggle(LED_4);

    if(RS232_RecvByteWTO(&RecvData, 1000) != SUCCESS) {
      if(RecvData == 0x0D)  // if press enter
        RS232_SendStr((uint8_t*)"\r\n");
      else
        RS232_SendByte(RecvData);
    }
    else {
      RS232_SendStr((uint8_t*)"Timeout ... \r\n");
    }
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void GPIO_Config( void )
{
  nrf_gpio_range_cfg_output(LED_1, LED_4);
}
/*====================================================================================================*/
/*====================================================================================================*/
