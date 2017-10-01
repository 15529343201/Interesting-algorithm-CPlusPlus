//1.1.2 顺序表的基本操作
/**************线性表的数据结构*****************/
const int defaultSize = 10;          //设置默认顺序表大小
template <typename DataType> class SeqList
{
	public:
		//构造函数
		SeqList(int size=defaultSize)
		{
			if(size > 0)
			{
				maxSize = size;
				elements = new DataType[maxSize];   //分配内存大小 
			}
		}
		//析构函数
		~SeqList()
		{
			delete[] elements;            //回收内存空间 
		}
		bool insertElement(DataType data);         //向表尾插入新元素
		bool deleteElement(int location);          //删除指定位置的元素
		DataType getElement(int location);         //返回指定位置的元素
		bool changeElement(int location,DataType newData);  //修改指定位置的元素值
	private:
		DataType *elements;
		int maxSize;              //顺序表最大大小
		int length;               //顺序表的有效长度 
}; 

//1.顺序表的插入操作
/**************顺序表插入操作**************/
template <typename DataType> bool SeqList<DataType>::insertElement(DataType data)
{
	int currentIndex = length;           //记录新元素的插入位置
	if(length >= maxSize)      //判断顺序表是否已满
	{
		return false;         //顺序表已满，返回false,插入不成功 
	}
	else
	{
		elements[currentIndex] = data;    //将新元素插入顺序表表尾
		length++;                         //顺序表有效长度加1
		return true; 
	} 
}

//2.顺序表的删除元素操作
/************删除指定位置的元素*************/
template <typename DataType> bool SeqList<DataType>::deleteElement(int location)
{
	if(location >= length || location < 0)   //验证位置索引参数是否有效 
	{
		return false;
	}
	else
	{
		for(int i = location;i<length;i++)
		{
			elements[i] = elements[i+1]; //将指定位置之后的元素依次往前移动覆盖前一个元素 
		}
		length--;   //顺序表长度减1
		return true; 
	}
} 

//3.获取指定位置的元素
/**************获取指定位置的元素**************/
template <typename DataType> DataType SeqList<DataType>::getElement(int location)
{
	if(location<0 || location >length) //判断位置索引是否合法
	{
		std::cout<<"参数无效"<<std::endl;
		return 0;
	}
	else
	{
		return elements[location];     //返回指定位置的元素 
	} 
}

//4.修改指定位置的元素
/*************修改指定位置的元素值**************/
template<typename DataType> bool SeqList<DataType>::changeElement(int location,DataType newData)
{
	if(location<0 || location >= length)    //验证位置索引参数是否有效
	{
		return false;
	}
	else
	{
		elements[location]=newData;         //将指定位置赋值给新元素
		return true; 
	} 
} 
