//ȡ�����������1970.1.1 0�㿪ʼ��������ɵ�ǰ�ṹ��ʱ��
void get_rtc_time(unsigned int cnt, struct time1 *t)
{
    struct tm *now_time;
    
    //time_t timer = cnt;			//��������ʱ��
    time_t timer = cnt - 28800; 	//����ʱ��
    //timer = time(NULL); 

    now_time = localtime(&timer);
    
    t->year   = now_time->tm_year + 1900;
    t->month  = now_time->tm_mon + 1;
    t->day    = now_time->tm_mday;
    t->hour   = now_time->tm_hour;
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
    tptr->tm_mon  = t.month - 1;
    tptr->tm_mday = t.day;
    tptr->tm_hour = t.hour;
    tptr->tm_min  = t.minute;
    tptr->tm_sec  = t.second;
    
    //*cnt  = mktime(tptr);	//��������ʱ��
    *cnt  = mktime(tptr) + 28800;	//����ʱ��
    
    free(tptr);
}