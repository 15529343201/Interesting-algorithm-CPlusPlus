//���еĻ�������
//1.��Ӳ���
/*************��Ӳ���***************/
template<typename DataType> bool Queue<DataType>::insert(DataType data)
{
	if(count==maxSize)              //�ж϶����Ƿ�����
		return false;
	elements[rear]=data;            //�����ݲ����β
	rear=(rear+1)%maxSize;          //�����βָ��,Ϊ��ʡ�ռ�,��ȡȡģ��ʽ�����βλ��
	count++;                        //Ԫ�ؼ�1
	return true; 
}

//2.���Ӳ���
/************���Ӳ���***************/
template<typename DataType> DataType Queue<DataType>::delElement()
{
	if(count==0)                 //�ж��Ƿ�ӿ�
		exit(0);
	DataType temp=elements[front];//ȥ������Ԫ��
	front=(front+1)%maxSize;      //�����µĶ���Ԫ��,Ϊ��ʡ�ռ�,��ȡģ��
	count--;
	return temp; 
} 
