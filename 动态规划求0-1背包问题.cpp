/*6	���ö�̬�滮�ķ��������0-1��������: ��һ��������װ������������ΪC, 
��n�����壬����Ϊw1,w2,..,wn, ��ֵ�ֱ�Ϊv1,v2,��vn������һ��װ�ط�����
ʹ�ñ���װ�ص������ܼ�ֵ������У�C, w����������*/
#include<stdio.h>
#define N 50

int max(int a,int b)
{
	return a>b?a:b;
}

void KnapSack(int n,int C,int w[],int m[])
{
	int i,j,V[N][N],x[N];
	for(i=0;i<=n;i++)
		V[i][0]=0;
	for(j=0;j<=C;j++)
		V[0][j]=0;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=C;j++)
		{
			if(j<w[i])
				V[i][j]=V[i-1][j];
			else
				V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+m[i]);
		}
	}
	j=C;
	for(i=n;i>0;i--)
	{
		if(V[i][j]>V[i-1][j])
		{
			x[i]=1;
			j=j-w[i];
		}
		else
			x[i]=0;			
	}

	printf("��������ֵ����Ʒ��:");
	for(i=1;i<=n;i++)
	{
		if(x[i]!=0)
			printf("%d ",i);
	}
	printf("\n����ֵΪ:%d\n",V[n][C]);
}

void main()
{
	int w[N],m[N];
	int C,i,n;
	printf("�����뱳����������");
	scanf("%d",&C);
	printf("��������Ʒ�ĸ�����");
	scanf("%d",&n);
	printf("������ÿ����Ʒ�������ͼ�ֵ���ԷֺŸ���\n");
	w[0]=m[0]=0;
	for(i=1;i<=n;i++)
	{
		printf("��%d����Ʒ�������ͼ�ֵ�ֱ�Ϊ:",i);
		scanf("%d%d",&w[i],&m[i]);
	}
	KnapSack(n,C,w,m);
}