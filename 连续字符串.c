/*ababc�ķ���ab*/
#include<stdlib.h>
#include<stdio.h>

void main()
{
	int count=0,k=0,x=1,i;//��¼�������ֵ��ַ����ǳ���
	char *a, *s,*star,*snew,*r,*p=0;
	a=(char*)malloc(sizeof(char)*80);
	s=(char*)malloc(sizeof(char)*80);
	while(x)
   {
	
	puts("�������ַ���!\n");
	gets(s);
	star=snew=s;
	while(*s)
	{
		
		while(*snew!='\0')
		{
			
			if(*star==*(++snew))
			{
				
				r=snew;//����snew��λ��
				while(((*star)==(*snew))&&(star!=r))
				{
					star++;
					snew++;
					count++;}
	            
				if((count>k)&&(star==r))
				{
					k=count;//�����ַ����ĳ���
					p=r;//�����ַ����ķ��ص�ַ
					
				}
				
				count=0;
				star=s;
			    snew=r;
			}
		}
		s++;
		star=snew=s;
	}
	
	if(p)
	{
		for(i=0;i<k;i++)
			a[i]=*p++;
	}
	a[i]='\0';
	printf("�ַ�����%s,������%d\n",a,k);
	printf("countine press 1\n");
	printf("exit press 0\n");
	scanf("%d",&x);
	getchar();
	}
}