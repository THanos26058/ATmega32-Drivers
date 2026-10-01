/**
 * @file LM35_Config.h
 * @author Mahmoud Abdallah (nt123456789123456789@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-10-01
 */
#ifndef _HAL_LM35_LM35_CONFIG_H_
#define _HAL_LM35_LM35_CONFIG_H_

/* Reference Voltage in millivolts (e.g. 5000 for AVCC, 2560 for Internal 2.56V) */
#define LM35_VREF_MV               5000UL

/* ADC Resolution */
#define LM35_ADC_RESOLUTION        1024UL

/* Scale Factor: 10 mV / C */
#define LM35_SENSITIVITY_MV        10UL

#endif // _HAL_LM35_LM35_CONFIG_H_
