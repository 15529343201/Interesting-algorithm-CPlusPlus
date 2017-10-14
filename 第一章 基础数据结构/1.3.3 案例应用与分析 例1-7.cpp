/*��1-7 ����ջ�����ݽṹ,Ҫ�����һ��min()�������ܹ��õ�ջ����СԪ�ء�Ҫ��
����min(),push()��pop()������ʱ�临�Ӷ���O(1)��*/
/*����:�����Ŀ����Ҫ�����ջ���ݽṹ��������⡣Ҫʵ����Ŀ��Ҫ����Ҫ��
ջ���ݽṹ���иĽ������ǿ�������һ������min���洢ջ��������С��ֵ����Ϊջ
�����е�Ԫ�ض��Ǵ��ڻ���ڸ�Ԫ����Ϊջ��ʱ����СԪ��ֵmin,���Կ�����ջ�в�
�洢ԭʼ��Ԫ��ֵ,���洢Ԫ��ֵ����Сֵmin֮��Ĳ�ֵ������ջʱ,���ԭʼ��Ԫ��
ֵ�ȵ�ǰ��Сֵmin��,��n-min��ջ,��ʱջ��Ϊ��ֵ��������ִ�ʱ��ջ��Ԫ�رȵ�
ǰ��СֵminС,�����ǵĲ�ֵ��ջ,��ʱΪ��ֵ,ͬʱ�õ�ǰ��ջֵ����min������һ��
����˼·���Եõ�����Ĳ��衣
*/
/*
	(1)��push()�����޸ģ���������ջʱ,�����ǰ��ջ��ֵn<��ǰ��Сֵmin,����min��ֵ
Ϊn��ֵ,��n-min��ֵ��ջ;����ֱ�ӽ�n-min��ֵ��ջ��
	(2)��Ӧ�Ķ�pop()���������޸ģ����ջ��Ԫ��top<=0,��˵����ʱ��ԭʼջ��Ԫ��
Ϊ��ǰ��СԪ��min,���ջʱ,ֱ�ӵ�����ǰ����Сֵmin,ͬʱ����minֵΪmin-top;
���ջ��Ԫ��top>0,��pop()��������top+minΪԭʼԪ��ֵ��
	(3)����min()������˵,ֻ��Ҫ����min�Ϳ����ˡ���������,��3��������������ʱ��
���Ӷ�ΪO(1)��Ҫ��
*/
#include<iostream>
#include<vector>
#include<CASSERT>
using namespace std;
/**********����ջ�����ݽṹ,Ҫ�����һ��min()����,
�ܹ��õ�ջ����СԪ�ء�Ҫ����min(),push()��pop()
��ʱ�临�Ӷȶ���O(1)***********/
/***********����ջ�ṹ*************/
template<typename T> class Stack{
	public:
		vector<int> value;     //����ջ�ṹ,��vector�洢Ԫ��
		T m_min;               //�洢��Сֵ�ı���
	public:
		const T& min();        //����min()����
		void pop();
		void push(const T &n);
		void printValue();     //��ȡջ��Ԫ��ֵ
		bool isEmpty();        //�ж�ջ�Ƿ�Ϊ�� 
};

/********��ȡ��Сֵ�ĺ���**********/
template<typename T> const T& Stack<T>::min()
{
	assert(!value.empty());    //���ջ��,���Ƴ�
	return m_min; 
} 

/********����push()����***************/
template<typename T> void Stack<T>::push(const T &n)
{
	if(value.empty())          //���ջ��,�������Сֵ
		m_min=n;
	T diff=n-m_min;            //������ջԪ������Сֵ�Ĳ�ֵ
	value.push_back(diff);     //��ֵ��ջ
	if(diff<0)
		m_min=n;               //�����ֵС��0,�������Сֵ 
}

/*********����pop()����**********/
template<typename T> void Stack<T>::pop()
{
	assert(!value.empty());               //���ջΪ��,���Ƴ�
	T top=value.back();                   //��ȡջ��ֵ
	if(top<0)                             //���ջ��ֵΪ��,�������Сֵ
		m_min-=top;
	value.pop_back();                     //����Ԫ�� 
 } 

/*********���ջ��ֵ*************/
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
 
/***********���庯��isEmpty()�ж�ջ�Ƿ�Ϊ��************/
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
	int b[]={6,8,15,2,3,1,2};   //�趨Ԫ��
	for(int i=0;i<7;i++)
	{
		cout<<"��ջֵ:"<<b[i]<<" ";
		stack.push(b[i]);  //��ջ	
		cout<<"��ǰ��Сֵmin:"<<stack.min()<<endl;
	} 
	cout<<"��ջ���:"<<endl;
	while(!stack.isEmpty())
	{
		cout<<"��ջֵ:"<<" ";
		stack.printValue();
		cout<<"��ǰ��Сֵmin:"<<stack.min()<<endl;
		stack.pop();
	}
	return 0;
}
/*������
��ջֵ:6 ��ǰ��Сֵmin:6
��ջֵ:8 ��ǰ��Сֵmin:6
��ջֵ:15 ��ǰ��Сֵmin:6
��ջֵ:2 ��ǰ��Сֵmin:2
��ջֵ:3 ��ǰ��Сֵmin:2
��ջֵ:1 ��ǰ��Сֵmin:1
��ջֵ:2 ��ǰ��Сֵmin:1
��ջ���:
��ջֵ: 2��ǰ��Сֵmin:1
��ջֵ: 1��ǰ��Сֵmin:1
��ջֵ: 3��ǰ��Сֵmin:2
��ջֵ: 2��ǰ��Сֵmin:2
��ջֵ: 15��ǰ��Сֵmin:6
��ջֵ: 8��ǰ��Сֵmin:6
��ջֵ: 6��ǰ��Сֵmin:6
*/ 
