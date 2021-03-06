/*====================================================================================================*/
/*====================================================================================================*/
#include "nrf51_system.h"
#include "experiment_nrf51.h"
#include "ble_beaconAdv.h"
/*====================================================================================================*/
/*====================================================================================================*/
int main( void )
{
  GPIO_Config();

  nrf_gpio_pin_set(LED_R);
  nrf_gpio_pin_set(LED_G);
  nrf_gpio_pin_set(LED_B);

  nrf_gpio_pin_clear(LED_BLINK);

  ble_init();

  while(1) {
    ble_power_manage();
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
void GPIO_Config( void )
{
  nrf_gpio_range_cfg_output(LED_R, LED_B);
}
/*====================================================================================================*/
/*====================================================================================================*/
