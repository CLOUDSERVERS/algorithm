/*
����ĩ����ϣ���ʿ�ǣ�m�ˣ���Ůʿ�ǣ�n��, n<m����������ʱ�������ų�һ�ӡ�
���迪ʼʱ�����δ��жӺ�Ů�ӵĶ�ͷ�ϸ���һ�������顣
�����ӳ�ʼ��������ͬ����ϳ�����һ����δ����ߵȴ���һ��������
��Ҫ��дһ�㷨ģ���������������⡣
��1���ڵ�t������ʱ����x��Ů���͵ڼ�������������裿
��2����ʲô�����£�������Ŀ�е�x����1<=x<=m���������п��ܺ������ǵĵ�y����1<=x<=n��Ů�����裬
�ڵڼ�������ʱ��
*/

#include<stdio.h>
#include<stdlib.h>
#define M 100

int fun1(int m,int n,int x,int t)//�ڵ�t������ʱ����x��Ů���͵ڼ��������������
{
	int i,j=0,h=1,s,a[M],b[M];
	for(i=0;i<m;i++)
		a[i]=i;
	while(h<t)
	{
		for(i=0;i<m;i++)
			b[i]=a[i];
		for(j=0;j<m;j++)
		{
			if(j<=n-1)
				a[m-n+j]=b[j];
			else a[j-n]=b[j];
		}
		h++;
	}
	s=a[x-1];
	return s+1;
}

int fun2(int m,int n,int A,int B)//�жϵ�x��������y��Ů���Ƿ�������
{
	int i,j=0,h=1,a[M],b[M],c[M];
	for(i=0;i<m;i++)
	{
		a[i]=i;
	    c[i]=i;
	}
	while(a[B-1]!=A-1)
	{
		h++;
        for(i=0;i<m;i++)
			b[i]=a[i];
		for(j=0;j<m;j++)
		{
			if(j<=n-1)
				a[m-n+j]=b[j];
			else a[j-n]=b[j];
		}
		j=0;
		for(i=0;i<m;i++)
		{
			if(a[i]==c[j])
				j++;
			else
				break;
			if(j==m-1)
			{
				printf("������û�л���һ�����裡\n");
				exit(1);
			}
		}						
	}
	return h;
}

void main()
{
	int m,n,t,x,h,A,B,C;
	printf("��ֱ�����������Ů��������m��n(m>n)\n");
	printf("����������������m:");
	scanf("%d",&m);
	printf("������Ů��������n:");
	scanf("%d",&n);
	/*printf("�������ǵڼ���Ů��:");
	scanf("%d",&x);
	printf("�������ǵڼ�������:");
	scanf("%d",&t);	
	h=fun1(m,n,x,t);
	printf("�����Ů����Ե��ǵ�%d������\n",h);*/
	printf("\n");
	printf("�������ǵڼ��������������ǵ��ǵڼ���Ů��\n");
	printf("�������ǵڼ���������");
	scanf("%d",&A);
	printf("�������ǵڼ���Ů����");
	scanf("%d",&B);
	C=fun2(m,n,A,B);
	printf("�������ڵ�%d�׸�����ʱ��Ϳ���һ������\n",C);
}
