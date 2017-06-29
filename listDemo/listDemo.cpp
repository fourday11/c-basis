/*
子函数功能：顺序结构的初始化、查询是否空线性表，将线性表清空，获取线性表长度，
查询线性表的元素，在线性表中插入元素，删除线性表元素，在线性表中查找是否与所要插入元素相等的元素。
主函数功能：创建两个线性表a,b,并将b插入a中。
author：黄小琴
data:17/6/26

*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
const int MAXSIZE=50;//线性表的最大存储容量
const int ERROR=0;
const int TRUE=1;
typedef int ElemType;//定义线性表中数据类型
typedef struct linearList
{
	ElemType *data;
	int length;
}list;
//初始化线性表
void initList(list *l)
{
	l->data=(ElemType*)malloc(MAXSIZE*sizeof(int));
	if(!l->data)
	{
		printf("初始化失败！");
		exit(0);
	}else{
		l->length=0;
		
	}
	
}
void creatList(list *l,int n)
{
	int i;
	printf("请输入元素:");
	for (i=0;i<n;i++)
	{
		scanf_s("%d",&l->data[i]);
		l->length=n;

	}
}
void printList(list *l,int n)
{
	int i;
	printf("该线性表的数据为:\n");
	for(i=0;i<n;i++)
	{
		printf("%d",(l->data)[i]);//注意，不能使用*(l->data++),因为会导致指针的位置发生改变
	
}
	printf("\n");
}
//获取线性表l的i处数据，并将其赋值给e
void getElem(list *l,int i, ElemType *e)
{
	*e=(l->data)[i];
}


//将数据e插入到线性表l的i处位置
void ListInsert(list *l,int i, ElemType *e)
{
	int k;
	if(i>MAXSIZE)
		{
			printf("所插入位置超出范围");
	}
	else if(i==MAXSIZE)
	{
		printf("线性存储表已满");

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
删除操作：满足情况1：所删除位置超出数组的范围
情况2：所删除位置在数组的末尾
*/
void listDelete(list *l,int i)
{
	int j;
	//第一种情况
	if ((i<1)||(i>l->length))
		{
			printf("超出可删除的范围");
			exit(1);
	}
	//第二种情况
	if(i==l->length)
	{
		
		l->length--;
	}
	if(i<l->length)
	{
		for(j=i;j<l->length;j++)
			l->data[j-1]=l->data[j];//将第i位置的数据删除
		l->length--;
	}
}
void main()
{
	list a,b;//定义线性存储表
	int i,n1,n2,e; //i为插入数字，n为所插入的位置
	a.length=0;
	b.length=0;
	printf("请输入线性表a的最大长度:");
	scanf("%d",&n1);
	printf("请输入线性表b的最大长度:");
	scanf("%d",&n2);
	initList(&a);//初始化链表
	initList(&b);
	creatList(&a,n1);//创建链表
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
