/*
��׺���ʽת��Ϊ��׺���ʽ
�������£�
��ʼɨ����׺���ʽ��
���Ϊ����ʱ�������׺���ʽ��
���Ϊ�������
a. ��Ϊ '('����ջ��
b. ��Ϊ ')'�������ΰ�ջ�еĵ�����������׺���ʽ�У�ֱ������'('����ջ��ɾ��'(' ��
c. ��Ϊ �������������������� �������ȼ�����ջ�������ʱ��ֱ����ջ�������ջ����ʼ��
���ε����ȵ�ǰ�������������ȼ��ߺ����ȼ���ȵ��������ֱ��һ���������ȼ��͵Ļ���������һ��������Ϊֹ��
��ɨ�����׺���ʽ����ʱ��ջ�еĵ������������ջ��
*/

#include<stdio.h>
#include<string.h> 
#define Stack_Size 50
#define M 50

typedef struct Node
{
	char elem[Stack_Size];
	int top;
}SeqStack;

void InitStack(SeqStack *S)
{
	S->top=-1;
}

int Push(SeqStack *S,char x)
{
	if(S->top==Stack_Size-1)
		return 0;
	S->top++;
	S->elem[S->top]=x;
	return 1;
}

char *Pop(SeqStack *S)
{
	char *x;
	x=(SeqStack *)malloc(sizeof (struct Node));
	if(S->top==-1)
		return 0;
	else
	{
		*x=S->elem[S->top];
		S->top--;
		return *x;
	}
	return 0;
}

char *GetTop(SeqStack *S)
{
	char *x;
	x=(SeqStack *)malloc(sizeof (struct Node));
	if(S->top==-1)
		return -1;
	else 
	{
		*x=S->elem[S->top];
		return *x;
	}
}

int priority(char op)
{
    if(op=='+'||op=='-')
        return 1;
    else if(op=='/'||op=='%')
        return 2;
	else if(op=='*')
		return 3;
    else if(op=='^')
        return 4;
    else
        return 0;
}

int compare(char ch1,char ch2)
{
	if(priority(ch1)>priority(ch2)||priority(ch1)==priority(ch2))
		return 2;
	else return 1;
}

void main()
{
	int i=0,j=0,k=0,m=0;
	char str[M],hou[M],ch='@';
	SeqStack *OPTR;
	InitStack(&OPTR);
	printf("������Ҫת������׺���ʽ(��#����)��");
	for(i=0;i<M;i++)
	{
	     scanf("%c",&str[i]);
		 if(str[i]=='#')
			 break;
	}
	while(str[k]!='#')
	{
		if(str[k]>='0'&&str[k]<='9')  //��������ֻ���ĸʱ����׺���ʽhou[M]
		{
			hou[m]=str[k];
			m++;
		}
		else if(str[k]>='a'&&str[k]<='z')
		{
			hou[m]=str[k];
			m++;
		}
		else if(str[k]>='A'&&str[k]<='Z')
		{
			hou[m]=str[k];
			m++;
		}
		else if(str[k]=='(')                      //�����������ֱ�ӽ�������ջOPTR
			Push(&OPTR,str[k]);
		else if(str[k]==')')                      //����������ţ������һ��������֮��Ĳ�����ȫ��ѹ���׺���ʽ�У��������ų�ջ
		{
			while(1)
			{
				ch=Pop(&OPTR);
				if(ch=='(')
					break;
				hou[m]=ch;
				m++;
			}
		}
		else if(GetTop(&OPTR)==-1)                //����������,����ջ��Ԫ��Ϊ��ʱ		
			Push(&OPTR,str[k]);
		else if(GetTop(&OPTR)=='(')				  //����������������ջ��Ԫ��Ϊ'('ʱ
			Push(&OPTR,str[k]);
		else
			    switch(compare(str[k],GetTop(&OPTR)))
		{
			    case 2:Push(&OPTR,str[k]);        //������ȼ���ջ����������ȼ���  ֱ����ջ
				       break;				     
			    case 1:while(compare(GetTop(&OPTR),str[k])!=1&&GetTop(&OPTR)!='(')
					   {
									hou[m]=Pop(&OPTR);             // ��Ϊ������߼�����������򽫴�ջ������һ�����ȼ������������������ '('֮��������������ջ�У������������ջ�� 									
									m++;
					   }
					   if(GetTop(&OPTR)=='(')
						   Pop(&OPTR);
					   Push(&OPTR,str[k]);
					   break;
		}
		k++;
	}
	while(GetTop(&OPTR)!=-1)
	{
		hou[m]=Pop(&OPTR);
		m++;
	}
	printf("������׺���ʽת��Ϊ��׺���ʽΪ��");
	for(i=0;i<m;i++)                                              //����ú�׺���ʽ
		printf("%c ",hou[i]);
	printf("\n");
}


