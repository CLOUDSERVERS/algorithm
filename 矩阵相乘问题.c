/*
��ά�������, �����һ������ ������ ������ ���ݣ�����ڶ��������С��С����� ��
��ӡ��������������ܳ����ӡ����������ˡ���
*/
#include<stdio.h>
#define A 100
#define B 100
#define N 100

void xiangchen(int a[A][B],int b[A][B],int x,int y,int z)
{
    int c[A][N];
	int i,j,s,m=0,n=0;
    for(i=0;i<x;i++)
	{   
		for(n=0;n<y;n++)
		{
		    s=0;
		    for(j=0;j<y;j++)   
			s+=a[i][j]*b[j][n];	
			c[i][n]=s;					
		}
	}
	for(i=0;i<x;i++)
	{	
		for(j=0;j<z;j++)
			printf("%d ",c[i][j]);
		printf("\n");
	}
}

int main()
{   
	int a[A][B],b[B][N];
	int i,j,m,n;
    int x1,y1,x2,y2;
    printf("�������һ��������У�");
    scanf("%d",&x1);
    printf("�������һ��������У�");
    scanf("%d",&y1);
    printf("������ڶ���������У�");
    scanf("%d",&x2);
    printf("������ڶ���������У�");
    scanf("%d",&y2);
	if(y1!=x2)
	{
       printf("����һ���ܳ��Ծ����������\n");
	   return 0;
	}
    else 
    printf("����һ���Գ��Ծ����������\n");
	printf("�������һ������\n");
    for(i=0;i<x1;i++)
    for(j=0;j<y1;j++)
	   scanf("%d",&a[i][j]);
	printf("������ڶ�������\n");
    for(m=0;m<x2;m++)
    for(n=0;n<y2;n++)
	   scanf("%d",&b[m][n]);
    printf("�¾���Ϊ��\n");
	xiangchen(a,b,x1,y1,y2);
    return 0;
}

