/*
���������Ϊ������Ȼ��֮�ͣ�Ҫ��������в�ַ�ʽ��
���磺
       36=1+2+3+4+5+6+7+8=11+12+13
Input:
36
Output:
1 2 3 4 5 6 7 8
 
11 12 13

*/

#include<stdio.h>

int fun(int m,int x)
{
	int i=x,k,s=0;
	while(i<=(m+1)/2)
	{
		s+=i;		
		if(s>=m)
		{
			k=i;
		    break;
		}
		i++;
	}
		return k;	
}

void main()
{
	int i,h,j,m,flag=0,s=0;
	printf("������Ҫ��ֵ�������");
	scanf("%d",&m);
	for(i=1;i<=(m+1)/2;i++)
	{
		h=fun(m,i);	
		for(j=i;j<=h;j++)
			s+=j;
		if(s==m)
		{
			flag=1;
			for(j=i;j<=h;j++)				
				printf("%d ",j);
			    printf("\n");
		}		
		s=0;
	} 
	if(flag==0)
		printf("�������ܲ�֣�����\n");
}       