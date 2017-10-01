//1.1.3 ʵ��Ӧ���ڷ���
/*��1-1 ��C++ʵ��һ������ʹ��ɴ洢10���������ݣ�����ʵ�ֲ��롢�޸�Ԫ�ء�
ɾ��Ԫ�غ��������˳���Ĺ��ܡ�*/
#include<iostream>
using namespace std;
/*************���Ա����ݽṹ****************/
template <typename DataType> class SeqList
{
	public:
		//���캯��
		SeqList(int size=defaultSize)
		{
			if(size>0)
			{
				maxSize = size;
				length = 0;
				elements = new DataType[maxSize];
				for(int i=0;i<maxSize;i++)
					elements[i]=NULL;
			}
		}
		//��������
		~SeqList()
		{
			delete[] elements;
		}
		bool insertElement(DataType data);        //���β������Ԫ��
		bool deleteElement(int location);         //ɾ��ָ��λ�õ�Ԫ��
		DataType getElement(int location);        //����ָ��λ��Ԫ��
		bool changeElement(int location,DataType newData); //�޸�ָ��λ�õ�Ԫ��ֵ 
		//��ȡ˳�����
		int getLength()
		{
			return length;
		} 
	private:
		static const int defaultSize=10;
		DataType *elements;
		int maxSize;            //˳�������С 
		int length;             //˳������Ч���� 
}; 
/**********˳���������************/
template <typename DataType> bool SeqList<DataType>::insertElement(DataType data)
{
	int currentIndex=length;
	if(length>=maxSize)
	{
		return false;
	}
	else
	{
		elements[currentIndex]=data;
		length++;
		return true;
	}
}
/***********��ȡָ��λ�õ�Ԫ��**************/
template <typename DataType> DataType SeqList<DataType>::getElement(int location)
{
	if(location<0 || location>length)
	{
		std::cout<<"������Ч"<<std::endl;
		return 0;
	}
	else
	{
		return elements[location];
	}
}
/********ɾ��ָ��λ�õ�Ԫ��*************/
template <typename DataType> bool SeqList<DataType>::deleteElement(int location)
{
	if(location >= length || length < 0)
	{
		return false;
	}
	else
	{
		for(int i=location;i<length;i++)
		{
			elements[i]=elements[i+1];
		}
		length--;
		return true;
	}
}
/*************�޸�ָ��λ�õ�Ԫ��ֵ**********/
template <typename DataType> bool SeqList<DataType>::changeElement(int location,DataType newData)
{
	if(location<0 || location>=length)
	{
		return false;
	}
	else
	{
		elements[location]=newData;
		return true;
	}
}
int main()
{
	SeqList<int> list(10);
	for(int i=0;i<10;i++)
	{
		list.insertElement(i*10);  //��������ʵ�ֳ�ʼ�� 
	}
	//�����ʼ�����˳���
	for(int i=0;i<list.getLength();i++)
		cout<<list.getElement(i)<<" ";
	cout<<endl; 
	//ɾ������Ϊ3��Ԫ��
	list.deleteElement(3);
	//���ɾ��Ԫ�غ��˳���
	for(int i=0;i<list.getLength();i++)
		cout<<list.getElement(i)<<" ";
	cout<<endl;
	//��˳�������Ϊ5��Ԫ��ֵ�޸�Ϊ44
	list.changeElement(5,44);
	//����޸ĺ��˳���
	for(int i=0;i<list.getLength();i++)
		cout<<list.getElement(i)<<" ";
	cout<<endl;
	return 0; 
} 
/*
������
0 10 20 30 40 50 60 70 80 90
0 10 20 40 50 60 70 80 90
0 10 20 40 50 44 70 80 90
*/ 

