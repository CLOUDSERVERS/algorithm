/*
������n����Χ����һ��Բ���ϣ��ִ�ĳһ���˿�ʼ������������m���˳��У�
�����ȥֱ�����е��˶����У�������ǵĳ���˳�򣨿��Խ���ת��Ϊ��Ӧ�����֣�
*/

#include<stdio.h>
#define M 100

int main()
{
	int a[M],b[M]={0};
	int i,s,n,m,x;
	printf("�����������");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    printf("�������%d��Ԫ��",i+1);
	    scanf("%d",&a[i]);
	}
	printf("������ӵڼ���Ԫ�ؿ�ʼ��");
	scanf("%d",&x);
	printf("������ÿ������Ԫ�س��У�");
	scanf("%d",&m);
	i=0;
	printf("���е�˳��Ϊ��");
	while(i<n)
	{
		i++;
		s=m*i+x-2;
		while(s>=n)
			s=s-n;
		while(b[s]==1)
			s++;
        if(s>=n)
			s=s-n;
        printf("%d ",a[s]);
		b[s]=1;
	}
	printf("\n");
	return 0;
}



  
