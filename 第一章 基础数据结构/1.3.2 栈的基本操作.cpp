//1.3.2 栈的基本操作
//1.入栈操作
/*****************入栈操作*****************/
template<typename DataType> bool Stack<DataType>::push(DataType data)
{
	if(top==maxSize)           //判断是否栈满
		return false;
	elements[++top]=data;      //从栈顶压入元素
	return true; 
}
//2.出栈操作
/**************出栈操作***************/
template<typename DataType> DataType Stack<DataType>::pop()
{
	if(top==-1)                //判断是否栈空
	{
		exit(1);
	}
	return elements[top--];    //返回栈顶元素 
} 
