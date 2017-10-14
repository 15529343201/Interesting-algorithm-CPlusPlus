/*例1-7 定义栈的数据结构,要求添加一个min()函数，能够得到栈的最小元素。要求
函数min(),push()即pop()函数的时间复杂度是O(1)。*/
/*分析:该题的目的是要考察对栈数据结构的深入理解。要实现题目的要求，需要对
栈数据结构进行改进。我们可以设置一个变量min来存储栈中数据最小的值。因为栈
中所有的元素都是大于或等于该元素作为栈顶时的最小元素值min,所以可以在栈中不
存储原始的元素值,而存储元素值与最小值min之间的差值。在入栈时,如果原始的元素
值比当前最小值min大,则将n-min入栈,此时栈中为正值。如果发现此时入栈的元素比当
前最小值min小,则将它们的差值入栈,此时为负值,同时用当前入栈值更新min。整理一下
这种思路可以得到下面的步骤。
*/
/*
	(1)对push()函数修改：首先在入栈时,如果当前入栈的值n<当前最小值min,更新min的值
为n的值,将n-min的值入栈;否则直接将n-min的值入栈。
	(2)相应的对pop()函数进行修改：如果栈顶元素top<=0,则说明此时的原始栈顶元素
为当前最小元素min,则出栈时,直接弹出当前的最小值min,同时更新min值为min-top;
如果栈顶元素top>0,则pop()函数返回top+min为原始元素值。
	(3)对于min()函数来说,只需要返回min就可以了。整体来看,这3个函数都满足了时间
复杂度为O(1)的要求。
*/
#include<iostream>
#include<vector>
#include<CASSERT>
using namespace std;
/**********定义栈的数据结构,要求添加一个min()函数,
能够得到栈的最小元素。要求函数min(),push()及pop()
的时间复杂度都是O(1)***********/
/***********定义栈结构*************/
template<typename T> class Stack{
	public:
		vector<int> value;     //定义栈结构,用vector存储元素
		T m_min;               //存储最小值的变量
	public:
		const T& min();        //声明min()函数
		void pop();
		void push(const T &n);
		void printValue();     //获取栈顶元素值
		bool isEmpty();        //判断栈是否为空 
};

/********获取最小值的函数**********/
template<typename T> const T& Stack<T>::min()
{
	assert(!value.empty());    //如果栈空,则推出
	return m_min; 
} 

/********定义push()函数***************/
template<typename T> void Stack<T>::push(const T &n)
{
	if(value.empty())          //如果栈空,则更新最小值
		m_min=n;
	T diff=n-m_min;            //计算入栈元素与最小值的差值
	value.push_back(diff);     //差值入栈
	if(diff<0)
		m_min=n;               //如果差值小于0,则更新最小值 
}

/*********定义pop()函数**********/
template<typename T> void Stack<T>::pop()
{
	assert(!value.empty());               //如果栈为空,则推出
	T top=value.back();                   //获取栈顶值
	if(top<0)                             //如果栈顶值为负,则更新最小值
		m_min-=top;
	value.pop_back();                     //弹出元素 
 } 

/*********输出栈顶值*************/
template<typename T> void Stack<T>::printValue()
{
	assert(!value.empty());
	T originValue;
	T top=value.back();
	if(top<0)
		originValue=m_min;
	else
		originValue=top+m_min;
	cout<<originValue;
} 
 
/***********定义函数isEmpty()判断栈是否为空************/
template<typename T> bool Stack<T>::isEmpty()
{
	if(value.empty())
	{
		return true;
	}else{
		return false;
	}
} 
 

int main()
{
	Stack<int> stack;
	int b[]={6,8,15,2,3,1,2};   //设定元素
	for(int i=0;i<7;i++)
	{
		cout<<"入栈值:"<<b[i]<<" ";
		stack.push(b[i]);  //入栈	
		cout<<"当前最小值min:"<<stack.min()<<endl;
	} 
	cout<<"出栈情况:"<<endl;
	while(!stack.isEmpty())
	{
		cout<<"出栈值:"<<" ";
		stack.printValue();
		cout<<"当前最小值min:"<<stack.min()<<endl;
		stack.pop();
	}
	return 0;
}
/*输出结果
入栈值:6 当前最小值min:6
入栈值:8 当前最小值min:6
入栈值:15 当前最小值min:6
入栈值:2 当前最小值min:2
入栈值:3 当前最小值min:2
入栈值:1 当前最小值min:1
入栈值:2 当前最小值min:1
出栈情况:
出栈值: 2当前最小值min:1
出栈值: 1当前最小值min:1
出栈值: 3当前最小值min:2
出栈值: 2当前最小值min:2
出栈值: 15当前最小值min:6
出栈值: 8当前最小值min:6
出栈值: 6当前最小值min:6
*/ 
