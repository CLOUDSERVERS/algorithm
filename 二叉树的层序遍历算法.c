/*
Ӧ�ø������ݽṹ���б�д�������Ĳ�������㷨
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
	int front,rear;
	front=rear=-1; 
	rear++;
	p=(Bitree *)malloc(sizeof(struct Node));
	root=NULL;
	printf("�������������");
	root=Create();
	if(root==NULL)
		return;       
    q[rear]=root;
	printf("��������α���Ϊ��");
    while(front!=rear)
    {
        front=(front+1)%M;
        p=q[front];
        printf("%c ",p->data);
        if(p->Lchild!=NULL)
        {
            rear=(rear+1)%M;
            q[rear]=p->Lchild;
        }   
        if(p->Rchild!=NULL)
        {
            rear=(rear+1)%M;
            q[rear]=p->Rchild;
        }     
    }  
	printf("\n");
}



