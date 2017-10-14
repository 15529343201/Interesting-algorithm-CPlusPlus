//对列的基本操作
//1.入队操作
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

//2.出队操作
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
