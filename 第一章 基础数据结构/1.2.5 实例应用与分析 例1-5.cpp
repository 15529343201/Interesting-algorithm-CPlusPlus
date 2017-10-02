//例1-5 编写程序判断两个链表是否相交
/*分析：两个链表只要相交则它们的尾结点必定相同。我们可以利用这个性质来判断两个链表是否相交。
首先遍历链表a，并将指针停留在链表a的尾结点。然后用一个新的指针指向链表b的头结点，遍历链表b，
判断链表a和b的尾结点指针所指的地址是否相同，如果相同则这两个链表相交，如果不同，则不相交。*/
#include<iostream>
using namespace std;
/*****************判断两个链表是否相交**************/
bool isCrossLink(Node* headA,Node* headB)
{
	if(headA==NULL || headB==NULL)       //判断两个链表是否都不为空
	{
		return false;
	}
	Node* p,q;                           //声明移动指针
	p=headA;
	q=headB;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	while(q->next!=NULL)
	{
		q=q->next;
	}
	if(p==q)
	{
		return true;
	}
	else
	{
		return false;
	} 
}
