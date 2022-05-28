#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

struct time1 
{
	unsigned short year;
	unsigned char  month;
	unsigned char  day;
	unsigned char  hour;
	unsigned char  minute;
	unsigned char  second;
};

struct time1 t1;

void time2cnt(struct time1 t, unsigned int *cnt)
{
	*cnt = t.second;
}

void cnt2time(unsigned int cnt, struct time1 *t)
{
	t->second = cnt;
}

int main(void)
{
	unsigned int cnt = 0;

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
	
	time2cnt(t1, &cnt); 
	//localtime(t1, &cnt); 
	
	printf("cnt=%d",cnt);
	
	while (1)
	{
		cnt2time(cnt, &t1);

		
		printf("%d %d %d %d:%d:%d\n", t1.year, t1.month, t1.day, t1.hour, t1.minute, t1.second);
		
		cnt++;

		//usleep(1000000);
		Sleep(1000);
	}
}