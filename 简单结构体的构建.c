/*
��10��ѧ����ÿ��ѧ�������ݰ���������ѧ�š�3�ſγ̳ɼ����Ӽ�������10��ѧ�������ݣ�Ҫ�����3�ſγ̵���ƽ���ɼ���
�Լ���߷ֵ�ѧ�����ݣ�����������ѧ�š�3�ſγ�ƽ���ɼ���ƽ��������
*/
#include<stdio.h>
#include<stdlib.h>
#define M 10

struct student
{
	char name[20];
	long num;
	float score[3];
};

int main()
{
	struct student stu[M];
	int i,j,k,m;
	float s=0.0,num=0.0,n=0.0;
	char a[20];
	for(i=0;i<M;i++)
	{
		printf("�������%d��ѧ��������",i+1);
	    gets(stu[i].name);
		printf("�������%d��ѧ����ѧ��",i+1);
		gets(a);
		stu[i].num=atol(a);
		printf("�������%d��ѧ�������ŷ���\n",i+1);
		for(j=0;j<3;j++)
		{
		   gets(a);
		   stu[i].score[j]=atof(a);
		}
	}

	for(j=0;j<3;j++)//����ƽ���ɼ�
	{
		printf("��%d�ŵ���ƽ���ɼ�Ϊ:",j+1);
        for(i=0;i<M;i++)
			s+=stu[i].score[j];
			printf("%.1f\n",s/M);
	}

	printf("                                    ����      ѧ��    ƽ���ɼ�\n");

	for(j=0;j<3;j++)//����߷�ѧ������
	{
	   printf("��%d�ſ�Ŀ��߷�ѧ���������ǣ�",j+1);
	   for(i=0;i<M;i++)
	   {
		   if(stu[i].score[j]>num)
		   {
			   num=stu[i].score[j];
		       k=i;
		   }
	   }
	   for(m=0;m<3;m++)
		   n+=stu[k].score[m];		   
	   printf("%10s%10d%10.1f",stu[k].name,stu[k].num,n/3);
	   n=0;
	   printf("\n");
	}

	return 0;
}

