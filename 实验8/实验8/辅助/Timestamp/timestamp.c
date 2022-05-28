#include "Timestamp.h"

static uint32_t DAYS = 24*3600;
static uint32_t FOURYEARS = 365*3+366;
static int norMoth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int leapMoth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
*********************************************************************************************************
*	�� �� ��: getMothAndDay
*	����˵��: ��ȡ����
*	��	  ��: bLeapYear:�Ƿ�����	nDays:������	nMoth:����·�	nDay:�������
*	�� �� ֵ: ��
*********************************************************************************************************
*/
static void getMothAndDay(char bLeapYear, uint32_t nDays, uint32_t *nMoth, uint32_t *nDay)
{
    int i = 0;
    int nTmp = 0;
    int *pMoth = bLeapYear ? leapMoth : norMoth;

    for (i = 0; i < 12; i++)
    {
        nTmp = nDays - pMoth[i];
        if (nTmp <= 0)
        {
            *nMoth = i + 1;
            if (nTmp == 0)
            {
                *nDay = pMoth[i];
            }
            else
            {
                *nDay = nDays;
            }
            break;
        }
        nDays = nTmp;
    }
}

/*
*********************************************************************************************************
*	�� �� ��: Timestamp_change_Time
*	����˵��: ʱ���ת��Ϊ����
*	��	  ��: nTime:ʱ���
*	�� �� ֵ: RTC_DataTime:ת���������
*********************************************************************************************************
*/
RTC_DataTime Timestamp_change_Time(uint32_t nTime)
{
	RTC_DataTime DataTime;
	uint32_t nDays = nTime / DAYS + ((nTime % DAYS) ? 1 : 0);
    uint32_t nYear4 = nDays / FOURYEARS;
    uint32_t nRemain = nDays % FOURYEARS;
    uint32_t nDecyear = 1970 + nYear4 * 4;
    uint32_t nDecmoth = 0;
    uint32_t nDecday = 0;
    char bLeapyear = 0;
    uint32_t nHour;
    uint32_t nMin;
    uint32_t nSec;
	
    if (nRemain < 365)
    {
        ;
    }
    else if (nRemain < 365*2)
    {
        nDecyear += 1;
        nRemain -= 365;
    }
    else if (nRemain < 365*3)
    {
        nDecyear += 2;
        nRemain -= 365*2;
    }
    else
    {
        nDecyear += 3;
        nRemain -= 365*3;
        bLeapyear = 1;
    }
    getMothAndDay(bLeapyear, nRemain, &nDecmoth, &nDecday);
	
    nHour = (nTime % DAYS) / 3600;
    nMin = ((nTime % DAYS) % 3600) / 60;
    nSec = ((nTime % DAYS) % 3600) % 60;
	
	DataTime.Year = (uint8_t)(nDecyear - 2000);
	DataTime.Month = (uint8_t)nDecmoth;
	DataTime.Day = (uint8_t)nDecday;
	DataTime.Hour = (uint8_t)(nHour + 8);
	DataTime.Minutes = (uint8_t)nMin;
	DataTime.Seconds = (uint8_t)nSec;
	
    return DataTime;
}

/*
*********************************************************************************************************
*	�� �� ��: Time_ChangeTimestamp
*	����˵��: ����ת����ʱ���
*	��	  ��: DataTime:��ת��������
*	�� �� ֵ: ʱ���
*********************************************************************************************************
*/
uint32_t Time_ChangeTimestamp(RTC_DataTime DataTime)
{
	uint32_t mon[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	uint32_t Total_days = 0;
	uint32_t i;
	uint32_t year = DataTime.Year + 2000;
	uint32_t month = DataTime.Month;
	uint32_t day = DataTime.Day;
	uint32_t Timestamp = 0;
	
	for(i = 1; i < year; i++)
	{
		Total_days += ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0))? 366 : 365;
	}
	
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		mon[2]++;
	
	for(i = 1; i < month; i++)
	{
		Total_days += mon[i];
	}
	Total_days += day;
	Total_days = Total_days - 719163;
	
	Timestamp = (Total_days * 24 * 3600) + (DataTime.Hour * 3600) + (DataTime.Minutes * 60) + DataTime.Seconds - (8 * 3600);
	return Timestamp;
}


