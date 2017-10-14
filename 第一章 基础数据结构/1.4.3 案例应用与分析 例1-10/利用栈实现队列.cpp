#include<iostream>
#include "Stack.h"
using namespace std;
/*************����ջʵ�ֶ��й���**************/
template<class T> class QueueFromStack
{
	public:
		QueueFromStack(int size=10)
		{
			s1=new Stack<T>(size);     
			s2=new Stack<T>(size);
		}
		~QueueFromStack()
		{
			s1->~Stack();
			s2->~Stack();
		}
		bool push(T data);
		T pop();
	private:
		Stack<T> *s1;
		Stack<T> *s2;
		int size;
};

/*************ʵ����Ӳ���*****************/
template<class T> bool QueueFromStack<T>::push(T data)
{
	if(s2->isEmpty())
	{
		return s1->push(data);                   //���s2Ϊ�գ�ֱ����� 
	}else if(s1->eleNumber()<(size-s2->eleNumber())){
		return s1->push(data);                   //���s2��Ϊ�գ�s1ֻ�����size-s2->eleNumber��Ԫ�� 
	}else{
		cout<<"������"<<endl;
		return false;                            //�������ʧ�� 
	}
}

/****************ʵ�ֳ��Ӳ���****************/
template<class T> T QueueFromStack<T>::pop(){
	T temp;
	if(!s2->isEmpty())                          //���s2��Ϊ�գ�ֱ��s2����
	{
		return s2->pop();
	}else{//s2Ϊ�գ���s1�е�Ԫ�ص���s2 
		while(!s1->isEmpty() && s1->eleNumber()>1){
			temp=s1->pop();                    //����eleNumber-1��Ԫ��
			s2->push(temp);                    //ѹ��s2 
		}
		return s1->pop();                      //ֱ�ӽ�s1��ʣ�µ�һ��Ԫ�ص��� 
	} 
}

/**********����������****************/
int main()
{
	QueueFromStack<int> qs(12);
	cout<<"���Ԫ��:"<<endl;
	for(int i=1;i<=12;i++){
		cout<<i*i<<" ";
		qs.push(i*i);
	}
	cout<<endl;
	cout<<"����Ԫ��:"<<endl;
	for(int i=1;i<=12;i++)
	{
		cout<<qs.pop()<<" ";
	}
	cout<<endl;
	return 0;
}
/*������:
���Ԫ��:
1 4 9 16 25 36 49 64 81 100 121 144
����Ԫ��:
1 4 9 16 25 36 49 64 81 100 121 144
*/ 
