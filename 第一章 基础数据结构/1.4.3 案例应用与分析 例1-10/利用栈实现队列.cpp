#include<iostream>
#include "Stack.h"
using namespace std;
/*************利用栈实现队列功能**************/
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

/*************实现入队操作*****************/
template<class T> bool QueueFromStack<T>::push(T data)
{
	if(s2->isEmpty())
	{
		return s1->push(data);                   //如果s2为空，直接入队 
	}else if(s1->eleNumber()<(size-s2->eleNumber())){
		return s1->push(data);                   //如果s2不为空，s1只能入队size-s2->eleNumber个元素 
	}else{
		cout<<"队列满"<<endl;
		return false;                            //否则入队失败 
	}
}

/****************实现出队操作****************/
template<class T> T QueueFromStack<T>::pop(){
	T temp;
	if(!s2->isEmpty())                          //如果s2不为空，直接s2出队
	{
		return s2->pop();
	}else{//s2为空，则将s1中的元素倒入s2 
		while(!s1->isEmpty() && s1->eleNumber()>1){
			temp=s1->pop();                    //倒入eleNumber-1个元素
			s2->push(temp);                    //压入s2 
		}
		return s1->pop();                      //直接将s1中剩下的一个元素弹出 
	} 
}

/**********测试主函数****************/
int main()
{
	QueueFromStack<int> qs(12);
	cout<<"入队元素:"<<endl;
	for(int i=1;i<=12;i++){
		cout<<i*i<<" ";
		qs.push(i*i);
	}
	cout<<endl;
	cout<<"出队元素:"<<endl;
	for(int i=1;i<=12;i++)
	{
		cout<<qs.pop()<<" ";
	}
	cout<<endl;
	return 0;
}
/*输出结果:
入队元素:
1 4 9 16 25 36 49 64 81 100 121 144
出队元素:
1 4 9 16 25 36 49 64 81 100 121 144
*/ 
