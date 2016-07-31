/**
  ******************************************************************************
  * @file    Project/main.c 
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   Main program body
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */ 


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s_gpio.h"
#include "stm8s_adc1.h"

/* Private defines -----------------------------------------------------------*/
 unsigned int wValue = 0;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void main(void)
{
  
  
  GPIO_DeInit(GPIOA);
  GPIO_DeInit(GPIOD);
  GPIO_DeInit(GPIOC);
  
  GPIO_Init(GPIOA, GPIO_PIN_3, GPIO_MODE_OUT_PP_HIGH_FAST);
  
  GPIO_WriteHigh(GPIOA, GPIO_PIN_3);
  GPIO_WriteLow(GPIOA, GPIO_PIN_3);
  
  GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_IN_FL_NO_IT); // ref AIN3
  GPIO_Init(GPIOC, GPIO_PIN_4, GPIO_MODE_IN_FL_NO_IT); // vol AIN2

  /*
   TIM1_DeInit();
   TIM1_TimeBaseInit(32 - 1, TIM1_COUNTERMODE_UP, 1250 - 1, 0);
   TIM1_SelectOutputTrigger(TIM1_TRGOSOURCE_UPDATE);
  */
  
   /* De-Init ADC1 peripheral */
  ADC1_DeInit();   

    ADC1_ScanModeCmd(ENABLE);
    
    ADC1_ConversionConfig(ADC1_CONVERSIONMODE_CONTINUOUS, ADC1_CHANNEL_3, ADC1_ALIGN_RIGHT);
    ADC1_PrescalerConfig(ADC1_PRESSEL_FCPU_D10);
    ADC1_ExternalTriggerConfig(ADC1_EXTTRIG_TIM, DISABLE);
    ADC1_SchmittTriggerConfig(ADC1_SCHMITTTRIG_ALL, DISABLE);
    ADC1_ITConfig(ADC1_IT_EOCIE, ENABLE);
  //  ADC1_Cmd(ENABLE);   

    
    enableInterrupts();

    ADC1_StartConversion(); 
    
    
      // TIM1_Cmd(ENABLE);

  volatile int counter = 0; 
  
  /* Infinite loop */
  while (1)
  {
      counter++;
      
     
   }
  
  
  
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
