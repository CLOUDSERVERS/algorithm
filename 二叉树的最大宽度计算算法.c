/*
�������������ȵ��㷨��
���������������ָ�����������в��нڵ���������ֵ��
*/

#include<stdio.h>
#include<stdlib.h>
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

void main()
{
	Bitree *root,*p;
	Bitree *q[M];
	int front,rear,i=1,j=0,h,max;
	int a[M]={0};
	front=rear=-1; 
	rear++;
	p=(Bitree *)malloc(sizeof(struct Node));
	root=NULL;
	printf("�������������");
	root=Create();
	if(root==NULL)	
		return;
	else 
	{
		a[i]++;
		i++;
	}
    q[rear]=root;
    while(front!=rear)
    {
		if(j<a[i-1])
		{
             front=(front+1)%M;
             p=q[front];
			 j++;
             if(p->Lchild!=NULL)
			 {
			      a[i]++;
                  rear=(rear+1)%M;
                  q[rear]=p->Lchild;
			 }   
             if(p->Rchild!=NULL)
			 {
			      a[i]++;
                  rear=(rear+1)%M;
                  q[rear]=p->Rchild;
			 } 
		}
		else 
		{
			j=0;
			i++;
		}
    } 
	h=i;
	max=a[0];
	for(i=1;i<h;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	printf("�������Ŀ��Ϊ%d",max);
	printf("\n");
}



