/*====================================================================================================*/
/*====================================================================================================*/
#include "nrf51_system.h"
#include "module_sf595.h"
/*====================================================================================================*/
/*====================================================================================================*/
#define SF595_DI_PIN  1
#define SF595_DI_SET  nrf_gpio_pin_set(SF595_DI_PIN)
#define SF595_DI_CLR  nrf_gpio_pin_clear(SF595_DI_PIN)

#define SF595_OE_PIN  2
#define SF595_OE_SET  nrf_gpio_pin_set(SF595_OE_PIN)
#define SF595_OE_CLR  nrf_gpio_pin_clear(SF595_OE_PIN)

#define SF595_ST_PIN  3
#define SF595_ST_SET  nrf_gpio_pin_set(SF595_ST_PIN)
#define SF595_ST_CLR  nrf_gpio_pin_clear(SF595_ST_PIN)

#define SF595_SH_PIN  4
#define SF595_SH_SET  nrf_gpio_pin_set(SF595_SH_PIN)
#define SF595_SH_CLR  nrf_gpio_pin_clear(SF595_SH_PIN)

#define SF595_MR_PIN  5
#define SF595_MR_SET  nrf_gpio_pin_set(SF595_MR_PIN)
#define SF595_MR_CLR  nrf_gpio_pin_clear(SF595_MR_PIN)
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF595_Config
**功能 : 74HC595 Config
**輸入 : None
**輸出 : None
**使用 : SF595_Config();
**====================================================================================================*/
/*====================================================================================================*/
void SF595_Config( void )
{
  nrf_gpio_cfg_output(SF595_DI_PIN);
  nrf_gpio_cfg_output(SF595_OE_PIN);
  nrf_gpio_cfg_output(SF595_ST_PIN);
  nrf_gpio_cfg_output(SF595_SH_PIN);
  nrf_gpio_cfg_output(SF595_MR_PIN);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF595_Init
**功能 : 74HC595 Init
**輸入 : None
**輸出 : None
**使用 : SF595_Init();
**====================================================================================================*/
/*====================================================================================================*/
void SF595_Init( void )
{
  SF595_DI_CLR;
  SF595_OE_CLR;
  SF595_ST_CLR;
  SF595_SH_CLR;
  SF595_MR_SET;

  SF595_Reset();
  SF595_OutputEnable(ENABLE);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF595_Reset
**功能 : Reset 74HC595
**輸入 : None
**輸出 : None
**使用 : SF595_Reset();
**====================================================================================================*/
/*====================================================================================================*/
void SF595_Reset( void )
{
  SF595_MR_CLR;
  Delay_1ms(1);
  SF595_MR_SET;
  Delay_1ms(1);
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF595_OutputEnable
**功能 : 74HC595 Output Enable
**輸入 : None
**輸出 : None
**使用 : SF595_OutputEnable(ENABLE);
**====================================================================================================*/
/*====================================================================================================*/
void SF595_OutputEnable( uint8_t OutputState )
{
  if(OutputState == ENABLE)
    SF595_OE_CLR;
  else
    SF595_OE_SET;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF595_Shift
**功能 : Shift bit
**輸入 : SendData
**輸出 : None
**使用 : SF595_Shift(1);
**====================================================================================================*/
/*====================================================================================================*/
void SF595_Shift( uint8_t SendData )
{
  SF595_SH_CLR;
  SF595_ST_CLR;
  if(SendData & 0x01)
    SF595_DI_SET;
  else
    SF595_DI_CLR;
  SF595_SH_SET;
  SF595_ST_SET;
}
/*====================================================================================================*/
/*====================================================================================================*
**函數 : SF595_SendByte
**功能 : Shift 8 bits
**輸入 : SendData
**輸出 : None
**使用 : SF595_SendByte(SendData);
**====================================================================================================*/
/*====================================================================================================*/
void SF595_SendByte( uint8_t SendData )
{
  uint8_t i = 0;

  for(i=0; i<8; i++) {
    SF595_SH_CLR;
    SF595_ST_CLR;
    if(SendData & (0x80>>i))
      SF595_DI_SET;
    else
      SF595_DI_CLR;
    SF595_SH_SET;
    SF595_ST_SET;
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
