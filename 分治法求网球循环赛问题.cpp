/*5	����n���˶�Ա��������ѭ���������һ����������Ҫ��ı����ճ̱�
��1��ÿ��ѡ�ֱ���������n-1��ѡ�ֱ���һ�Σ�
��2��ÿ��ѡ��һ��ֻ����1��
��3����n��ż��ʱ��ѭ������n-1�죬��n������ʱ��ѭ��������n��
*/
#include<stdio.h>
#define N 1000

void fun(int n);
void copy(int n);
void copy1(int n);
void copy2(int n);

int a[N][N],b[N];

void copy(int n)
{
	if(n/2>1&&n/2%2!=0)
		copy1(n);
	else
		copy2(n);

}

void copy1(int n)
{
	int m,i,j;
	m=n/2;
	for(i=0;i<m;i++)
	{
		b[i]=m+i;
		b[m+i]=b[i];
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<m+1;j++)//�����Ͻ�С���ֵ�����Ӧ�����½�С���ֵ
		{
			if(a[i][j]>=m)
			{
				a[i][j]=b[i];
				a[m+i][j]=(b[i]+m)%n;
			}
			else
				a[m+i][j]=a[i][j]+m;
		}
		for(j=1;j<m;j++)//�����Ͻ�С���ֵ�����Ӧ�����ϽǺ����½�С���ֵ
		{
			a[i][m+j]=b[i+j];
			a[b[i+j]][m+j]=i;
		}

	}

}

void copy2(int n)
{
	int i,m,j;
    m=n/2;
    for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			a[i][j+m]=a[i][j]+m;//�����Ͻ�С���ֵ�����Ӧ�����Ͻ�С���ֵ
			a[i+m][j]=a[i][j+m];//�����Ͻ�С���ֵ�����Ӧ�����½�С���ֵ
			a[i+m][j+m]=a[i][j];//�����Ͻ�С���ֵ�����Ӧ�����½�С���ֵ

		}
	}
}

void fun(int n)
{
	if(n==1)
	{
		a[0][0]=0;
		return;
	}
	if(n%2==1)
	{
		fun(n+1);
		return;
	}
	fun(n/2);
	copy(n);
}


void main()
{
	int i,num,j;
	printf("������������");
	scanf("%d",&num);
	fun(num);
	if(num%2!=0)
		num++;
	for(i=1;i<num;i++)
	{
		for(j=0;j<num;j++)
		{
			printf("%d ",a[i][j]+1);
		}
		printf("\n");
	}
	printf("ע����nΪ����ʱ����Ϊn+1����ӣ������ֿգ�\n");
}
