/*
1��1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20��20���������ѡ��5������,��5���������ظ���
�����Խ�һ�����Ǵ�n�����漴ѡ��m�����ظ�������
*/

#include<stdio.h>
#include<stdlib.h>
#define M 10000

void main()
{
	int a[M];
	int i=1,j=0,n,m,seed=10000;
	double x;
	printf("���������������1~");
	scanf("%d",&n);	
	printf("������������ĸ���:");
	scanf("%d",&m);
	printf("���������ӣ�");
	scanf("%d",&seed);
	srand(seed);
	printf("��%d��������ֱ�Ϊ��",m);
	for(i=1;i<=n;i++)
		a[i]=0;
	while(j<m)
	{
		x=((double)rand()/((double)(RAND_MAX)+(double)(1)));
	    i=(int)(x*n);
		if(a[i]==0)
		{
			a[i]=1;
			j++;
			printf("%d ",i);
		}
	}
	printf("\n");
}

