//1.1.3 实例应用于分析
/*例1-1 用C++实现一个链表，使其可存储10个整形数据，并可实现插入、修改元素、
删除元素和输出整个顺序表的功能。*/
#include<iostream>
using namespace std;
/*************线性表数据结构****************/
template <typename DataType> class SeqList
{
	public:
		//构造函数
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
		//析构函数
		~SeqList()
		{
			delete[] elements;
		}
		bool insertElement(DataType data);        //向表尾插入新元素
		bool deleteElement(int location);         //删除指定位置的元素
		DataType getElement(int location);        //返回指定位置元素
		bool changeElement(int location,DataType newData); //修改指定位置的元素值 
		//获取顺序表长度
		int getLength()
		{
			return length;
		} 
	private:
		static const int defaultSize=10;
		DataType *elements;
		int maxSize;            //顺序表最大大小 
		int length;             //顺序表的有效长度 
}; 
/**********顺序表插入操作************/
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
/***********获取指定位置的元素**************/
template <typename DataType> DataType SeqList<DataType>::getElement(int location)
{
	if(location<0 || location>length)
	{
		std::cout<<"参数无效"<<std::endl;
		return 0;
	}
	else
	{
		return elements[location];
	}
}
/********删除指定位置的元素*************/
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
/*************修改指定位置的元素值**********/
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
		list.insertElement(i*10);  //插入数据实现初始化 
	}
	//输出初始化后的顺序表
	for(int i=0;i<list.getLength();i++)
		cout<<list.getElement(i)<<" ";
	cout<<endl; 
	//删除索引为3的元素
	list.deleteElement(3);
	//输出删除元素后的顺序表
	for(int i=0;i<list.getLength();i++)
		cout<<list.getElement(i)<<" ";
	cout<<endl;
	//将顺序表索引为5的元素值修改为44
	list.changeElement(5,44);
	//输出修改后的顺序表
	for(int i=0;i<list.getLength();i++)
		cout<<list.getElement(i)<<" ";
	cout<<endl;
	return 0; 
} 
/*
结果输出
0 10 20 30 40 50 60 70 80 90
0 10 20 40 50 60 70 80 90
0 10 20 40 50 44 70 80 90
*/ 

