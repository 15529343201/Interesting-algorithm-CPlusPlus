//1.3.1 栈的定义
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
