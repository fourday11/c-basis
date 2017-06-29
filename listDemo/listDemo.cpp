/*
�Ӻ������ܣ�˳��ṹ�ĳ�ʼ������ѯ�Ƿ�����Ա������Ա���գ���ȡ���Ա��ȣ�
��ѯ���Ա��Ԫ�أ������Ա��в���Ԫ�أ�ɾ�����Ա�Ԫ�أ������Ա��в����Ƿ�����Ҫ����Ԫ����ȵ�Ԫ�ء�
���������ܣ������������Ա�a,b,����b����a�С�
author����С��
data:17/6/26

*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
const int MAXSIZE=50;//���Ա�����洢����
const int ERROR=0;
const int TRUE=1;
typedef int ElemType;//�������Ա�����������
typedef struct linearList
{
	ElemType *data;
	int length;
}list;
//��ʼ�����Ա�
void initList(list *l)
{
	l->data=(ElemType*)malloc(MAXSIZE*sizeof(int));
	if(!l->data)
	{
		printf("��ʼ��ʧ�ܣ�");
		exit(0);
	}else{
		l->length=0;
		
	}
	
}
void creatList(list *l,int n)
{
	int i;
	printf("������Ԫ��:");
	for (i=0;i<n;i++)
	{
		scanf_s("%d",&l->data[i]);
		l->length=n;

	}
}
void printList(list *l,int n)
{
	int i;
	printf("�����Ա������Ϊ:\n");
	for(i=0;i<n;i++)
	{
		printf("%d",(l->data)[i]);//ע�⣬����ʹ��*(l->data++),��Ϊ�ᵼ��ָ���λ�÷����ı�
	
}
	printf("\n");
}
//��ȡ���Ա�l��i�����ݣ������丳ֵ��e
void getElem(list *l,int i, ElemType *e)
{
	*e=(l->data)[i];
}


//������e���뵽���Ա�l��i��λ��
void ListInsert(list *l,int i, ElemType *e)
{
	int k;
	if(i>MAXSIZE)
		{
			printf("������λ�ó�����Χ");
	}
	else if(i==MAXSIZE)
	{
		printf("���Դ洢������");

	} else {
		for (k=l->length-1;k>i-1;k--)
		{
			(l->data)[k+1]=(l->data)[k];
		}
	}
	(l->data)[i-1]=*e;
	l->length++;

}
/*
ɾ���������������1����ɾ��λ�ó�������ķ�Χ
���2����ɾ��λ���������ĩβ
*/
void listDelete(list *l,int i)
{
	int j;
	//��һ�����
	if ((i<1)||(i>l->length))
		{
			printf("������ɾ���ķ�Χ");
			exit(1);
	}
	//�ڶ������
	if(i==l->length)
	{
		
		l->length--;
	}
	if(i<l->length)
	{
		for(j=i;j<l->length;j++)
			l->data[j-1]=l->data[j];//����iλ�õ�����ɾ��
		l->length--;
	}
}
void main()
{
	list a,b;//�������Դ洢��
	int i,n1,n2,e; //iΪ�������֣�nΪ�������λ��
	a.length=0;
	b.length=0;
	printf("���������Ա�a����󳤶�:");
	scanf("%d",&n1);
	printf("���������Ա�b����󳤶�:");
	scanf("%d",&n2);
	initList(&a);//��ʼ������
	initList(&b);
	creatList(&a,n1);//��������
	creatList(&b,n2);
	printList(&a,n1);
	printList(&b,n2);
	for(i=0;i<n2;i++)
	{
		getElem(&b,i,&e);
		ListInsert(&a,++n1,&e);
	}
	printList(&a,a.length);
	listDelete(&a,10);
	//printf("%d",a.length);
	printList(&a,a.length);


	
}
