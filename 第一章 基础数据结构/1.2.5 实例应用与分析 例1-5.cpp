//��1-5 ��д�����ж����������Ƿ��ཻ
/*��������������ֻҪ�ཻ�����ǵ�β���ض���ͬ�����ǿ�����������������ж����������Ƿ��ཻ��
���ȱ�������a������ָ��ͣ��������a��β��㡣Ȼ����һ���µ�ָ��ָ������b��ͷ��㣬��������b��
�ж�����a��b��β���ָ����ָ�ĵ�ַ�Ƿ���ͬ�������ͬ�������������ཻ�������ͬ�����ཻ��*/
#include<iostream>
using namespace std;
/*****************�ж����������Ƿ��ཻ**************/
bool isCrossLink(Node* headA,Node* headB)
{
	if(headA==NULL || headB==NULL)       //�ж����������Ƿ񶼲�Ϊ��
	{
		return false;
	}
	Node* p,q;                           //�����ƶ�ָ��
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
