//��Ƴ���ʵ������ջ�������
/*
(1)���ʱ,���s1�Ƿ�Ϊ��ջ��������򲻽�����ջ�����������������ջ��
(2)����ʱ,�ж�s2�Ƿ�Ϊ��,�粻Ϊ�գ���ֱ�ӵ�����Ԫ�أ���Ϊ�գ���
s1��n-1Ԫ�����"����"s2,������ջs1�е����һ��Ԫ��ֱ�ӵ��������
"���Ӳ���"��
*/
#include<iostream>
using namespace std;
/**************����stack�ṹ***************/
template<typename DataType> class Stack
{
	public:
		Stack(int size)
		{
			maxSize=size;                              //�����������
			top=-1;                                    //��ʼ��Ϊ��ջ 
			elements=new DataType[size];               //����ռ� 
		}
		~Stack()
		{
			delete[] elements;
		}
		//��ջ����
		bool push(DataType data);
		//��ջ����
		DataType pop();
		//�п�
		bool isEmpty();
		//��ȡԪ����
		int eleNumber();
	private:
		DataType *elements;                           //������ָ��
		int top;                                      //ջ��
		int maxSize;                                  //ջ��������� 
};

/*****************��ջ����*****************/
template<typename DataType> bool Stack<DataType>::push(DataType data)
{
	if(top==maxSize)           //�ж��Ƿ�ջ��
		return false;
	elements[++top]=data;      //��ջ��ѹ��Ԫ��
	return true; 
}

/**************��ջ����***************/
template<typename DataType> DataType Stack<DataType>::pop()
{
	if(top==-1)                //�ж��Ƿ�ջ��
	{
		exit(1);
	}
	return elements[top--];    //����ջ��Ԫ�� 
} 

/**************ջ�п�******************/
template<typename DataType> bool Stack<DataType>::isEmpty()
{
	if(top==-1)
		return true;
	else
		return false;
}

/**************��ȡ��ǰԪ����***************/
template<typename DataType> int Stack<DataType>::eleNumber()
{
	if(top>=0)
		return top+1;
	else
		return 0;
} 

 
