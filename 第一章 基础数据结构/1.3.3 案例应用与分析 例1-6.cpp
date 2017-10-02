/*例1-6 有一个整数集合{23,56,11,4,87,98},将它们依次存入某数据结构，然后输出
要求输出的顺序为:11,4,56,98,87,23。*/
#include<iostream>
using namespace std;
/****************栈的定义************/
template<typename DataType> class Stack
{
	private:
		DataType *elements;                       //数据域指针
		int top;                                  //栈顶
		int maxSize;                              //栈的最大容量 
	public:
		Stack(int size)
		{
			maxSize=size;                //设置最大容量
			top=-1;                      //初始化为空栈
			elements=new DataType[size]; //分配空间 
		}
		~Stack()
		{
			delete[] elements;
		}
		//入栈操作
		bool push(DataType data);
		//出栈操作
		DataType pop(); 
};  
/*****************入栈操作*****************/
template<typename DataType> bool Stack<DataType>::push(DataType data)
{
	if(top==maxSize)           //判断是否栈满
		return false;
	elements[++top]=data;      //从栈顶压入元素
	return true; 
}
//2.出栈操作
/**************出栈操作***************/
template<typename DataType> DataType Stack<DataType>::pop()
{
	if(top==-1)                //判断是否栈空
	{
		exit(1);
	}
	return elements[top--];    //返回栈顶元素 
} 
int main()
{
	Stack<int> s=Stack<int>(6);
	int temp=0;
	s.push(23);
	s.push(56);
	s.push(11);
	temp=s.pop();
	cout<<temp<<" ";
	s.push(4);
	temp=s.pop();
	cout<<temp<<" ";
	temp=s.pop();
	cout<<temp<<" ";
	//入栈
	s.push(87);
	s.push(98);
	//按要求出栈
	temp=s.pop();
	cout<<temp<<" ";
	temp=s.pop();
	cout<<temp<<" ";
	temp=s.pop();
	cout<<temp<<" ";
	return 0; 
}
/*输出结果:
11 4 56 98 87 23*/ 
