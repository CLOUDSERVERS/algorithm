/*
�������100000��int��������������kֵ��100<=k<=500����
Ҫ�������С��k��������
�����ַ���ʵ�֡�

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define M 100000

int main()
{
	int i,j=0,m,n,k,h=0;
	int a[M];
	double x;
	printf("��������Ҫ���������������1~");
	scanf("%d",&m);
	printf("��������Ҫ����������ĸ���n��");
	scanf("%d",&n);
	printf("��������Ҫȡ������С���ĸ���100~500��");
	scanf("%d",&k);
	srand((int)time(0));
	while(j<n)
	{
		x=((double)rand()/((double)(RAND_MAX)+(double)(1)));
		i=(int)(x*m);
		a[j]=i;
		j++;
	}
	printf("��100000�����������С��%d����Ϊ��",k);
	j=0;   
	for(i=1;i<M;i++)
	{
		for(h=0;h<M;h++)
		{
			if(a[h]==i)
			{
				printf("%d ",a[h]);
				j++;
			}
			if(j==k)
			goto loop;
		}
	}
loop:return 0;
}



