/*
�������100000��int��������������kֵ��100<=k<=500����
Ҫ�������С��k��������
�����ַ���ʵ�֡�

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define M 10000

void main()
{
	int i,j=0,m,n,k;
	int str[M],a[M];
	double x;
	printf("��������Ҫ���������������1~");
	scanf("%d",&m);
	printf("��������Ҫ����������ĸ���n��");
	scanf("%d",&n);
	printf("��������Ҫȡ������С���ĸ���100~500��");
	scanf("%d",&k);
	srand((int)time(0));
	for(i=0;i<m;i++)
		str[i]=0;
	for(i=0;i<m;i++)
		a[i]=1;
	while(j<n)
	{
		
		x=((double)rand()/((double)(RAND_MAX)+(double)(1)));
		i=(int)(x*m);
		if(str[i]==0)
			str[i]=i;
		else	a[i]++;		 
		j++;
	}
	j=0;
	i=1;
	while(j<k)
	{
		if(str[i]!=0)
		{
			while(a[i]!=0)
			{
			    printf("%d ",str[i]);
				j++;
				a[i]--; 		
			}
			i++;        
		}
		else i++;
	}
}




