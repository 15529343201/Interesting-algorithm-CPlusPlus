//对列的定义
/************队列结构定义*************/
template<typename DataType> class Queue
{
	public:
		Queue(int size)
		{
			maxSize=size;          //初始化最大容量
			//初始化队首、队尾和元素数位0
			front=0;
			rear=0;
			count=0;
			elements=new DataType[size];    //分配空间
			//判断如果空间分配失败,则退出
			if(elements==NULL)
				exit(1); 
		}
		~Queue()
		{
			delete[] elements;
		}
		/**********入队操作***********/
		bool insert(DataType data);
		/**********出队操作***********/
		DataType delElement(); 
	private:
		int count;                 //元素的个数
		int maxSize;               //对列的最大容量
		int front;                 //队首
		int rear;                  //队尾
		DataType *elements;        //数据指针 
}; 
