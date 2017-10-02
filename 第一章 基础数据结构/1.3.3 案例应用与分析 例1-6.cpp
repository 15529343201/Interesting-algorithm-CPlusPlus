/*��1-6 ��һ����������{23,56,11,4,87,98},���������δ���ĳ���ݽṹ��Ȼ�����
Ҫ�������˳��Ϊ:11,4,56,98,87,23��*/
#include<iostream>
using namespace std;
/****************ջ�Ķ���************/
template<typename DataType> class Stack
{
	private:
		DataType *elements;                       //������ָ��
		int top;                                  //ջ��
		int maxSize;                              //ջ��������� 
	public:
		Stack(int size)
		{
			maxSize=size;                //�����������
			top=-1;                      //��ʼ��Ϊ��ջ
			elements=new DataType[size]; //����ռ� 
		}
		~Stack()
		{
			delete[] elements;
		}
		//��ջ����
		bool push(DataType data);
		//��ջ����
		DataType pop(); 
};  
/*****************��ջ����*****************/
template<typename DataType> bool Stack<DataType>::push(DataType data)
{
	if(top==maxSize)           //�ж��Ƿ�ջ��
		return false;
	elements[++top]=data;      //��ջ��ѹ��Ԫ��
	return true; 
}
//2.��ջ����
/**************��ջ����***************/
template<typename DataType> DataType Stack<DataType>::pop()
{
	if(top==-1)                //�ж��Ƿ�ջ��
	{
		exit(1);
	}
	return elements[top--];    //����ջ��Ԫ�� 
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
	//��ջ
	s.push(87);
	s.push(98);
	//��Ҫ���ջ
	temp=s.pop();
	cout<<temp<<" ";
	temp=s.pop();
	cout<<temp<<" ";
	temp=s.pop();
	cout<<temp<<" ";
	return 0; 
}
/*������:
11 4 56 98 87 23*/ 
