/*
��������������10���ȳ����ַ�����������һ���������ǽ������򣨲����ַ���������򣩡�
Ȼ���������������10���Ѿ��ź�����ַ��������������strcmp������
*/
#include<stdio.h>
#include<string.h>
#define M 100

void fun(char a[10][M],int n)
{
	char str[10][M];
	int i,j,k,h;
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<10;j++)
		{
			k=0;
			while(k<n)
			{
				if(a[i][k]<a[j][k])
					break;
				else if(a[i][k]>a[j][k])
				{
					for(h=0;h<n;h++)
					{
						str[i][h]=a[i][h];
						a[i][h]=a[j][h];
						a[j][h]=str[i][h];
					}
					break;
				}
				else k++;
			}	
		}
	}

}

void main()
{
	char a[10][M],ch;
	int i,j,n;
	printf("�������ַ����ĳ���:");
	scanf("%d",&n);	
	for(i=0;i<10;i++)
	{
		ch=getchar();
		for(j=0;j<n;j++)
		{
			scanf("%c",&a[i][j]);
		}
	}
	fun(a,n);
	printf("����֮��\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%c",a[i][j]);
		    
		}
		printf("\n");
	}
}