/*
��дһ�����򣬽���˫��ѭ��������ʵ�����Ĳ��������ɾ������
*/
#include<stdio.h>
#include<stdlib.h>

typedef char DataType;

typedef struct Node
{
	DataType data;
	struct Node *prior,*next;
}Dnode;

Dnode *Create()
{
	Dnode *head,*p=NULL,*t;
	char ch;
	int flag=1;
	head=(Dnode *)malloc(sizeof(struct Node));
	if(head)
	{
	    head->next=head;
		head->prior=head;	    
	}
	t=head;
	while(flag)
	{
	    ch=getchar();	
	    if(ch!='\n')
		{
			p=(Dnode *)malloc(sizeof(struct Node));
	        p->data=ch;
			p->next=head->next;
			p->prior=head;
			head->next->prior=p;
			head->next=p;	
		}
		else flag=0;
	}
	printf("������˫��ѭ������Ϊ:");
	while(head->next!=t)
	{	
		head=head->next;	
		printf("%c",head->data);		
	}
	printf("\n");
	return head;
}
	
void DlinkIns(Dnode *head)
{
	int j=0,i;
	char ch;
	Dnode *s,*q=NULL,*t;
	head=head->next;
	t=head;
	q=(Dnode *)malloc(sizeof(struct Node));
	q=head;	   
	printf("������Ҫ�����λ�ã�");
	scanf("%d",&i);
	getchar();
	printf("������Ҫ�����Ԫ�أ�");
	scanf("%c",&ch);
	while(j<i&&q->next!=NULL)
	{
		q=q->next;
		j++;
	}
	s=(Dnode *)malloc(sizeof(struct Node));
	if(s)
	{	   
			s->data=ch;
			s->prior=q->prior;
			q->prior->next=s;
			s->next=q;
			q->prior=s;			
	}	
	printf("����������Ϊ:");
	while(head->next!=t)
	{	
		head=head->next;	
		printf("%c",head->data);				
	}
	printf("\n");
}

int DlinkDel(Dnode *head)
{
	int j=0,i;	
    Dnode *q=NULL,*t;
    head=head->next;
	q=(Dnode *)malloc(sizeof (struct Node));
	q=head;
	t=head;
	printf("������Ҫɾ����λ�ã�");
	scanf("%d",&i);	
	getchar();
	while(j<i&&q->next!=t)
	{
		q=q->next;
		j++;
	}
	printf("ɾ����Ԫ����%c\n",q->data);
    if(q->next!=NULL)
	{
		q->next->prior=q->prior;
		q->prior->next=q->next;	
		free(q);
		printf("ɾ���ɹ���\n");	
	}
	else 
	{
		printf("�������");
	    return 0;
	}
     printf("ɾ���������Ϊ��");
     while(head->next!=t)
	 {	 		 
		 head=head->next;
		 printf("%c",head->data);				 
	 }
	 printf("\n");
	 return 0;
}
void screen()
{
	int a;	
	Dnode *head;
	printf("˫��ѭ��������ʾ���򣡣�\n");
	while(1)
	{
	printf("1.����");
    printf("2.����");
	printf("3.ɾ��");
	printf("4.�˳�\n");
	printf("��ѡ��:");
	scanf("%d",&a);
    getchar();
	switch(a)
	{
	    case 1:printf("please input:");
			   head=Create();break;
		case 2:DlinkIns(head);break;
		case 3:DlinkDel(head);break;
        case 4:exit(0);break;
		default:printf("������󣡣�");
	}
	}
}


void main()
{	
    Dnode *head;
	head=NULL;
	screen();
}

