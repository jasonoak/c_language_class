#ifndef __TIMESTAMP_H__
#define __TIMESTAMP_H__

#include <stdio.h>
#include "string.h"

typedef unsigned char 			uint8_t;
typedef unsigned short 			uint16_t;
typedef unsigned int 			uint32_t;

typedef struct
{
	uint8_t Year; 		// 0~99
	uint8_t Month; 		// 1~12
	uint8_t Day;  		// 1~31
	uint8_t Hour; 		// 0~23
	uint8_t Minutes; 	// 0~59
	uint8_t Seconds;	// 0~59
}RTC_DataTime;	//日期时间

RTC_DataTime Timestamp_change_Time(uint32_t nTime);
uint32_t Time_ChangeTimestamp(RTC_DataTime DataTime);

#endif

