/*
�����ꡢ�¡��գ���������Ǹ���ĵڼ��졣
*/

#include<stdio.h>

int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int sum(int month,int day)
{
	int i;
	for(i=1;i<month;i++)
		day=day+a[i];
	return day;
}


void main()
{
	int year,month,day;
	printf("�������꣺");
	scanf("%d",&year);
	printf("�������£�");
	scanf(" %d",&month);
	if(month<1||month>12)
		printf("input error!!!");
	else
		printf("�������գ�");
		scanf("%d",&day);
	    day=sum(month,day);
        printf("���Ǹ���ĵ�%d��",year%4==0&&month>2?day+1:day);
}


