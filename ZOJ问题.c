/*
ZOJ������һ���ַ������ַ����а���ZOJ�����ַ���������һ����ȣ�
��ZOJ��˳���������ĳ���ַ�����ʱ��ʣ�µ���Ȼ��װZOJ��˳���������������ַ���ΪEʱ��������
Input��
ZZOOOJJJ
ZZZZOOOOOJJJ
E
Output:
ZOJZOJOJ
ZOJZOJZOJZOO

*/
#include<stdio.h>
#define M 100

int main()
{
	int countZ[M]={0};
	int countO[M]={0};
	int countJ[M]={0};
	int i=0,j,h,k,totalcount;
	int b[M];
	char a[M][M];
	printf("�������ַ�����\n");
	while(i<M)
	{
		for(j=0;j<M;j++)
		{
			scanf("%c",&a[i][j]);
			if(a[i][j]=='\n')
			{
				b[i]=j;
				break;
			}
			else if(a[i][j]=='E')
				goto loop;
		    else if(a[i][j]=='Z')
			    countZ[i]++;
			else if(a[i][j]=='O')
			    countO[i]++;
			else 
				countJ[i]++;
		}
		i++;
	}
    loop:h=i;
	printf("�źõ���������Ϊ��\n");
	for(i=0;i<h;i++)
	{		
	         totalcount=countZ[i]+countO[i]+countJ[i];
	         for(k=0;k<totalcount;k++)
			 {
		          if(countZ[i]>0)
				  {
			           printf("Z");
		               countZ[i]--;
				  }
		          if(countO[i]>0)
				  {
			           printf("O");
		               countO[i]--;
				  }
		          if(countJ[i]>0)
				  {	
					   printf("J");
		               countJ[i]--;
				  }   
			 }
			 printf("\n");		
	}
	return 0;
}