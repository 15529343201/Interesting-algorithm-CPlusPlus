/*��1-2 ���һ���㷨���������ĵ�����m����㣬Ҫ�󲻵���������ȣ����ö�����
������ת������ҵ������Ľ��ͷ������ĵ�ַ�����û�оͷ���NULL��*/
/*����:��ȡ������˳���ĵ�i�����ķ�ʽ�ǣ�����ָ��p=head,��ͷָ�뿪ʼѭ��ִ��
p=p->next,һ��һ�������ƣ�ֱ����i�����ֹͣ���������ǿ��԰����ַ����ԼӸĶ���
��������һ��ָ��q��ʹָ��qҲ������������ƶ����ұ�ָ��p���m-1������p��������β��ʱ��
q�պ�ָ������m����㡣*/
#include<iostream>
#include"LinkList.h"
using namespace std;
ListNode<int>* searchNodeM(LinkList<int> *link,int m)
{
	ListNode<int> *p=link->getNode(1);   //p��ʼ��Ϊ�����һ�����
	if(p!=NULL && m>0)
	{
		for(int i=1;i<m;i++)  //�ƶ�p����m�����
		{
			p=p->getNext();
			if(p==NULL)  
			{
				cout<<"������û�е�����m�����"<endl;
				return NULL;
			}
		} 
	}
	ListNode<int> *q=link->getNode(1);   //����ָ��q�����������p
	while(p->getNext()!=NULL)    //ͬʱ�ƶ�����ָ��ֱ��p�����β
	{
		p=p->getNext();
		q=q->getNext();
	}
	return q; 
} 
