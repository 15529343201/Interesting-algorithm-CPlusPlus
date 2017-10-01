//1.1.1 顺序表的定义
/**********线性表数据结构**************/
const int defaultSize = 10;             //设置默认顺序表大小
template <typename DataType> class SeqList
{
	public:
		//构造函数
		SeqList(int size=defaultSize){
			if(size > 0)   //检查赋予的顺序表大小，如果合法则分配相应大小的内存
			{
				maxSize = size;
				elements = new DataType(maxSize);  //分配内存大小 
			} 
		}
		//析构函数
		~SeqList()
		{
			delete[] elements;        //回收内存空间 
		} 
	private:
		DataType *elements;
		int maxSize;                  //顺序表最大大小 
};


 
