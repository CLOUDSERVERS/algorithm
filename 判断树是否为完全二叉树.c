/*
�ж����Ƿ���ȫ���������㷨
*/

#include<stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1
#define M 50

typedef char DataType;

typedef struct Node
{
	DataType data;
	struct Node *Lchild;
	struct Node *Rchild;
}Bitree;

Bitree *Create()
{
	char ch;
	Bitree *root;	
    scanf("%c",&ch);
	if(ch=='#')
		root=NULL;
	else
	{
		root=(Bitree *)malloc(sizeof(struct Node));
		root->data=ch;
		root->Lchild=Create();
		root->Rchild=Create();
	}
	return root;
}

/*�ж��Ƿ���ȫ������*/
int is_sheer(Bitree *root)
{
       Bitree *queue[M],*p;            /*�������*/
       int rear=0,front=0;
       if(root!=NULL)
       {
           queue[rear]=root;
           rear=(rear+1)%M;
       }       
       while(rear!=front)                   /*��while���������ڸ��ڵ��ڶ��ڵĳ�ʼ����¿�ʼ*/
	   {                                    /*����α���������ֻ���������������еĽڵ� while����ʱ pָ���һ������ڵ�*/       
          p=queue[front];
          front=(front+1)%M;
          if((rear+1)%M!=front&&p->Lchild!=NULL&&p->Rchild!=NULL)              /*���Ӳ�����*/
          {
            queue[rear]=p->Lchild;
            rear=(rear+1)%M;
            queue[rear]=p->Rchild;
            rear=(rear+1)%M;
           }
           else break;
	   }                                                                    /*��ǰ���while��p�϶�ָ���һ��û��˫�ӵĽڵ㣬��ʱ�ַ��������*/
        if(p->Lchild==NULL&&p->Rchild!=NULL)                                 /*��һ��:�������� �϶�������ȫ������*/
			return FALSE;                                              
        else if(p->Lchild!=NULL&&(p->Lchild->Lchild!=NULL||p->Lchild->Rchild!=NULL))      /*�ڶ���:�������ҵ��������������� �ų�*/
        return FALSE;                      
        else                                                         /*������:�������� ��Ҳ����*/
        {
              while(rear!=front)                                     /*���ڼ�������α��������У����ֺ�����ĳ���ڵ�������,�ų�*/
              {
                 p=queue[front];
                 front=(front+1)%20;
                 if(p->Lchild!=NULL||p->Rchild!=NULL) 
					 return FALSE;
              }
         }
         return TRUE;
}                                                           

void main()
{
      
	  Bitree *root;
	  printf("�봴����������");
      root=Create();
	  if(is_sheer(root)==1)
      printf("���������ȫ��������");
	  else
	  printf("�����������ȫ��������");
      printf("\n");
}

