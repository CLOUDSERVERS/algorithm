/*
����һ��10������������Ȼ�����������Ӧ��2���ƣ�8���ƣ�16��������
*/
#include<stdio.h>
#define M 100

char b[6]={'A','B','C','D','E','F'};

void fun1(int p,int q)
{
	int i=0,j=0,h,x,a[M];
	while(p!=0)
	{
		h=p%q;
		p=p/q;
		a[i]=h;
		i++;
	}
	x=i;
	for(i=x-1;i>=0;i--)
	printf("%d",a[i]);
}

void fun2(int p,int q)
{
	int i=0,j=0,h,x;
	char a[M];
	while(p!=0)
	{
		h=p%q;
		p=p/q;
		if(h>=10)
		    a[i]=b[h-10];
		else
			a[i]=h;
		i++;
	}
    x=i;
	for(i=x-1;i>=0;i--)
		if(a[i]<10)
			printf("%d",a[i]);
		else
	        printf("%c",a[i]);
}

void main()
{
	int p;
	printf("������Ҫת��������:");
	scanf("%d",&p);
	printf("�����ת��Ϊ������Ϊ");
	fun1(p,2);
	printf("\n");
	printf("�����ת��Ϊ�˽���Ϊ");
	fun1(p,8);
	printf("\n");
	printf("�����ת��Ϊʮ������Ϊ");	
	fun2(p,16);
	printf("\n");
}
		



