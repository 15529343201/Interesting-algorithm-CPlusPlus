//设计程序实现利用栈构造队列
/*
(1)入队时,检测s1是否为满栈，如果是则不进行入栈操作，如果不是则入栈。
(2)出队时,判断s2是否为空,如不为空，则直接弹出顶元素；如为空，则将
s1的n-1元素逐个"倒入"s2,将留在栈s1中的最后一个元素直接弹出，完成
"出队操作"。
*/
#include<iostream>
using namespace std;
/**************定义stack结构***************/
template<typename DataType> class Stack
{
	public:
		Stack(int size)
		{
			maxSize=size;                              //设置最大容量
			top=-1;                                    //初始化为空栈 
			elements=new DataType[size];               //分配空间 
		}
		~Stack()
		{
			delete[] elements;
		}
		//入栈操作
		bool push(DataType data);
		//出栈操作
		DataType pop();
		//判空
		bool isEmpty();
		//获取元素数
		int eleNumber();
	private:
		DataType *elements;                           //数据域指针
		int top;                                      //栈顶
		int maxSize;                                  //栈的最大容量 
};

/*****************入栈操作*****************/
template<typename DataType> bool Stack<DataType>::push(DataType data)
{
	if(top==maxSize)           //判断是否栈满
		return false;
	elements[++top]=data;      //从栈顶压入元素
	return true; 
}

/**************出栈操作***************/
template<typename DataType> DataType Stack<DataType>::pop()
{
	if(top==-1)                //判断是否栈空
	{
		exit(1);
	}
	return elements[top--];    //返回栈顶元素 
} 

/**************栈判空******************/
template<typename DataType> bool Stack<DataType>::isEmpty()
{
	if(top==-1)
		return true;
	else
		return false;
}

/**************获取当前元素数***************/
template<typename DataType> int Stack<DataType>::eleNumber()
{
	if(top>=0)
		return top+1;
	else
		return 0;
} 

 
