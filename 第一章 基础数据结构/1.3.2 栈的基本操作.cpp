//1.3.2 ջ�Ļ�������
//1.��ջ����
/*****************��ջ����*****************/
template<typename DataType> bool Stack<DataType>::push(DataType data)
{
	if(top==maxSize)           //�ж��Ƿ�ջ��
		return false;
	elements[++top]=data;      //��ջ��ѹ��Ԫ��
	return true; 
}
//2.��ջ����
/**************��ջ����***************/
template<typename DataType> DataType Stack<DataType>::pop()
{
	if(top==-1)                //�ж��Ƿ�ջ��
	{
		exit(1);
	}
	return elements[top--];    //����ջ��Ԫ�� 
} 
