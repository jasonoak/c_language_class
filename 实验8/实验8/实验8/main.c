#include <stdio.h>
#include <string.h>
#include <windows.h>
struct time1 
{
	unsigned int year;
	unsigned int  month;
	unsigned int  day;
	unsigned int  hour;
	unsigned int  minute;
	unsigned int  second;
};

struct time1 t1;
unsigned int cnt = 0;
unsigned int yearNum = 0;
unsigned int mouthNum = 0;
unsigned int unnormal_year_temp = 0;
unsigned int year_jiange = 0;
unsigned int cnt_yue ,cnt_ri ,cnt_shi;
unsigned int cnt_temp = 0;//专门给倒退用的
void maktime_sun(struct time1 t);
int unnormal_year(struct time1 t);
void localtime_sun(unsigned int cnt, struct time1 *t);
int unnormal_year_one(struct time1 t);
void getMothAndDay(char bLeapYear, unsigned int nDays, unsigned int *nMoth, unsigned int *nDay);

unsigned int normal[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
unsigned int unnormal[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
//========================================================
//int unnormal_year(struct time1 t);
//void set_rtc_time(struct time1 t, unsigned int *cnt);
//=========================================================

int main(void)
{
	t1.year = 2022;
	t1.month = 5;
	t1.day = 28;
	t1.hour = 0;
	t1.minute = 0;
	t1.second = 0;
	
	printf("enter current time:\n");
	printf("year:");
	scanf("%d", &t1.year);
	printf("month:");
	scanf("%d", &t1.month);
	printf("day:");
	scanf("%d", &t1.day);
	printf("hour:");
	scanf("%d", &t1.hour);
	printf("minute:");
	scanf("%d", &t1.minute);
	printf("second:");
	scanf("%d", &t1.second);
	
	printf("aaa%d\n", unnormal_year(t1));
	maktime_sun(t1);
	printf("cnt1=%d\n", cnt);

	//set_rtc_time(t1, &cnt);
	//printf("cnt2=%d\n",cnt);


	while (1)
	{
		localtime_sun(cnt, &t1);
		printf("%d-%d-%d-%d:%d:%d\n", t1.year, t1.month, t1.day, t1.hour, t1.minute, t1.second);		
		//t1.second++;//plus 1 sec
		cnt++;
		Sleep(1);
	}
}
void maktime_sun(struct time1 t)
{ 
	unsigned int normal  [12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	unsigned int unnormal[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	yearNum = (t.year) - 1970;//现在到1970经历了 过了几年
	cnt = (yearNum * 365) + unnormal_year(t1);//假设全部是normal  +unnormal
	if (t.month == 1 ) { cnt += 0; }
	if (t.month == 2 ) { cnt += 31; }
	if (t.month == 3 ) { cnt += 31+28; }
	if (t.month == 4 ) { cnt += 31+28+31; }
	if (t.month == 5 ) { cnt += 31 + 28 + 31+30; }
	if (t.month == 6 ) { cnt += 31 + 28 + 31 + 30+31; }
	if (t.month == 7 ) { cnt += 31 + 28 + 31 + 30 + 31+30; }
	if (t.month == 8 ) { cnt += 31 + 28 + 31 + 30 + 31+30+31; }
	if (t.month == 9 ) { cnt += 31 + 28 + 31 + 30 + 31 + 30 + 31+31; }
	if (t.month == 10) { cnt += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31+30; }
	if (t.month == 11) { cnt += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30+31; }
	if (t.month == 12) { cnt += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31+30; }
	cnt += (t.day-1);
	cnt = (cnt * 86400) + (t.hour * 3600) + (t.minute * 60) + (t.second);
}
//==========================================================================================
int unnormal_year(struct time1 t)
{
	int unnormal = 0, int_unnormal = 0;
	unnormal = (t.year) / 4 - t.year / 100 + t.year / 400;
	int_unnormal = 1970 / 4 - 1970 / 100 + 1970 / 400;
	unnormal_year_temp = (unnormal - int_unnormal);
	return (unnormal - int_unnormal);
}

void localtime_sun(unsigned int cnt,struct time1 *t)
{
	
	unsigned int nDays = cnt / (24*3600) + ((cnt % (24 * 3600)) ? 1 : 0);
	unsigned int nYear4 = nDays / (365 * 3 + 366);
	unsigned int nRemain = nDays % (365 * 3 + 366);
	unsigned int nDecyear = 1970 + nYear4 * 4;
	unsigned int nDecmoth = 0;
	unsigned int nDecday = 0;
	char bLeapyear = 0;
	unsigned int nHour;
	unsigned int nMin;
	unsigned int nSec;

	if (nRemain < 365){;}
	else if (nRemain < 365 * 2)
	{
		nDecyear += 1;
		nRemain -= 365;
	}
	else if (nRemain < 365 * 3)
	{
		nDecyear += 2;
		nRemain -= 365 * 2;
	}
	else
	{
		nDecyear += 3;
		nRemain -= 365 * 3;
		bLeapyear = 1;
	}
	getMothAndDay(bLeapyear, nRemain, &nDecmoth, &nDecday);

	nHour = (cnt % (24 * 3600)) / 3600;
	nMin = ((cnt % (24 * 3600)) % 3600) / 60;
	nSec = ((cnt % (24 * 3600)) % 3600) % 60;

	t->year = (nDecyear);
	t->month = nDecmoth;
	t->day = nDecday;
	t->hour = (nHour);
	t->minute = nMin;
	t->second = nSec;
}
void getMothAndDay(char bLeapYear, unsigned int nDays, unsigned int *nMoth, unsigned int *nDay)
{
	int i = 0;
	int nTmp = 0;
	int *pMoth = bLeapYear ? unnormal : normal;

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
int unnormal_year_one(struct time1 t)
{
	if ((t.year % 4 == 0) && ((t.year % 100) != 0) || t.year % 400 == 0) {  return 1;}
	else {    return 0;}
}
/*
void get_rtc_time(unsigned int cnt, struct time1 *t)
{
	struct tm *now_time;

	//time_t timer = cnt;			//格林威治时间
	time_t timer = cnt - 28800; 	//北京时间
	//timer = time(NULL); 

	now_time = localtime(&timer);

	t->year = now_time->tm_year + 1900;
	t->month = now_time->tm_mon + 1;
	t->day = now_time->tm_mday;
	t->hour = now_time->tm_hour;
	t->minute = now_time->tm_min;
	t->second = now_time->tm_sec;
}

//把收到的时间结构体换算成秒计数器（1970.1.1 0点开始）
//注意是格林威治时间，我们的北京时间应在其基础上+8小时(28800s)
void set_rtc_time(struct time1 t, unsigned int *cnt)
{
	struct tm *tptr;

	tptr = malloc(sizeof(struct tm));

	tptr->tm_year = t.year - 1900;
	tptr->tm_mon = t.month - 1;
	tptr->tm_mday = t.day;
	tptr->tm_hour = t.hour;
	tptr->tm_min = t.minute;
	tptr->tm_sec = t.second;

	//*cnt  = mktime(tptr);	//格林威治时间
	*cnt = mktime(tptr) + 28800;	//北京时间
	free(tptr);
}*/