//例1-9 设计一个队列结构,实现基本操作
#include<iostream>
using namespace std;
/***********队列结构定义***********/
template<typename DataType> class Queue
{
	public:
		Queue(int size)
		{
			maxSize=size;                          //初始化最大容量
			//初始化队首、队尾和元素数位0
			front=0;
			rear=0;
			count=0;
			elements=new DataType[size];           //分配空间
			//判断如果空间分配失败,则退出
			if(elements==NULL)
				exit(1); 
		}
		~Queue()
		{
			delete[] elements;
		}
		/**********入队操作**********/
		bool insert(DataType data);
		/**********出队操作**********/
		DataType delElement();
	private:
		int count;                         //元素的个数
		int maxSize;                       //对列的最大容量
		int front;                         //队首
		int rear;                          //队尾
		DataType *elements;                //数据指针 
};

/*************入队操作***************/
template<typename DataType> bool Queue<DataType>::insert(DataType data)
{
	if(count==maxSize)              //判断对列是否已满
		return false;
	elements[rear]=data;            //将数据插入队尾
	rear=(rear+1)%maxSize;          //变更队尾指针,为节省空间,采取取模方式计算队尾位置
	count++;                        //元素加1
	return true; 
}

/************出队操作***************/
template<typename DataType> DataType Queue<DataType>::delElement()
{
	if(count==0)                 //判断是否队空
		exit(0);
	DataType temp=elements[front];//去除队首元素
	front=(front+1)%maxSize;      //设置新的队首元素,为节省空间,用取模法
	count--;
	return temp; 
} 

int main()
{
	Queue<int> queue=Queue<int>(6);                //创建队列结构
	for(int i=0;i<6;i++)
		queue.insert(i*3); 
	for(int i=0;i<6;i++)
	{
		int temp=queue.delElement();
		cout<<temp<<" ";
	}
	cout<<endl;
	return 0;
}
/*输出结果：
0 3 6 9 12 15
*/ 
