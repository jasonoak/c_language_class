#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
struct time1
{
	unsigned short year;
	unsigned int  month;
	unsigned int  day;
	unsigned int  hour;
	unsigned int  minute;
	unsigned int  second;
};

struct time1 t1;
unsigned int cnt = 0;


//========================================================
int unnormal_year(struct time1 t);
void set_rtc_time(struct time1 t, unsigned int *cnt);
//=========================================================

int main(void)
{
	//init


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

	set_rtc_time(t1, &cnt);
	printf("cnt2=%d\n", cnt);

	while (1)
	{
		printf("%d %d %d %d:%d:%d\n", t1.year, t1.month, t1.day, t1.hour, t1.minute, t1.second);
		t1.second++;//plus 1 sec
		Sleep(1000);
	}
}

//ȡ�����������1970.1.1 0�㿪ʼ��������ɵ�ǰ�ṹ��ʱ��
void get_rtc_time(unsigned int cnt, struct time1 *t)
{
	struct tm *now_time;

	//time_t timer = cnt;			//��������ʱ��
	time_t timer = cnt - 28800; 	//����ʱ��
	//timer = time(NULL); 

	now_time = localtime(&timer);

	t->year = now_time->tm_year + 1900;
	t->month = now_time->tm_mon + 1;
	t->day = now_time->tm_mday;
	t->hour = now_time->tm_hour;
	t->minute = now_time->tm_min;
	t->second = now_time->tm_sec;
}

//���յ���ʱ��ṹ�廻������������1970.1.1 0�㿪ʼ��
//ע���Ǹ�������ʱ�䣬���ǵı���ʱ��Ӧ���������+8Сʱ(28800s)
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

	//*cnt  = mktime(tptr);	//��������ʱ��
	*cnt = mktime(tptr) + 28800;	//����ʱ��

	free(tptr);
}