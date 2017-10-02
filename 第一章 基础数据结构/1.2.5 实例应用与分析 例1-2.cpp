/*例1-2 设计一个算法求出单链表的倒数第m个结点，要求不得求出链表长度，不得对链表
进行逆转，如果找到这样的结点就返回它的地址，如果没有就返回NULL。*/
/*分析:获取单链表顺数的第i个结点的方式是：设置指针p=head,从头指针开始循环执行
p=p->next,一步一步往后移，直到第i个结点停止。这里我们可以把这种方法稍加改动，
即再设置一个指针q，使指针q也沿着链表向后移动并且比指针p落后m-1步，当p到达链表尾部时，
q刚好指向倒数第m个结点。*/
#include<iostream>
#include"LinkList.h"
using namespace std;
ListNode<int>* searchNodeM(LinkList<int> *link,int m)
{
	ListNode<int> *p=link->getNode(1);   //p初始化为链表第一个结点
	if(p!=NULL && m>0)
	{
		for(int i=1;i<m;i++)  //移动p到第m个结点
		{
			p=p->getNext();
			if(p==NULL)  
			{
				cout<<"该链表没有倒数第m个结点"<endl;
				return NULL;
			}
		} 
	}
	ListNode<int> *q=link->getNode(1);   //设置指针q，让它落后于p
	while(p->getNext()!=NULL)    //同时移动两个指针直到p到达表尾
	{
		p=p->getNext();
		q=q->getNext();
	}
	return q; 
} 
