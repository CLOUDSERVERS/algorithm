/*
��һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b
ע��ע��Ч�ʣ�ʱ�临�ӶȺͿռ临�ӶȾ����ܵ�

*/

#include<stdio.h>
#define M 256

int main()
{
	int i,m,h;
	int a[M]={0};
	char str[M];
	printf("�������ַ�����");
	for(i=0;i<M;i++)
	{
		scanf("%c",&str[i]);
		if(str[i]=='$')
			break;
	}
	m=i;
	for(i=0;i<m;i++)
	{
		h=str[i];
		a[h]++;
	}
	for(i=0;i<m;i++)
	{
		h=str[i];
		if(a[h]==1)
		{
			printf("���ַ����е�һ��ֻ����һ�ε��ַ���%c\n",str[i]);
		    return 0;
		}
	}
	printf("���ַ�����û��ֻ����һ�ε��ַ���\n");
	return 0;
}
		



