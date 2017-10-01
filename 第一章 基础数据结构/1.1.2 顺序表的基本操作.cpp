//1.1.2 ˳���Ļ�������
/**************���Ա�����ݽṹ*****************/
const int defaultSize = 10;          //����Ĭ��˳����С
template <typename DataType> class SeqList
{
	public:
		//���캯��
		SeqList(int size=defaultSize)
		{
			if(size > 0)
			{
				maxSize = size;
				elements = new DataType[maxSize];   //�����ڴ��С 
			}
		}
		//��������
		~SeqList()
		{
			delete[] elements;            //�����ڴ�ռ� 
		}
		bool insertElement(DataType data);         //���β������Ԫ��
		bool deleteElement(int location);          //ɾ��ָ��λ�õ�Ԫ��
		DataType getElement(int location);         //����ָ��λ�õ�Ԫ��
		bool changeElement(int location,DataType newData);  //�޸�ָ��λ�õ�Ԫ��ֵ
	private:
		DataType *elements;
		int maxSize;              //˳�������С
		int length;               //˳������Ч���� 
}; 

//1.˳���Ĳ������
/**************˳���������**************/
template <typename DataType> bool SeqList<DataType>::insertElement(DataType data)
{
	int currentIndex = length;           //��¼��Ԫ�صĲ���λ��
	if(length >= maxSize)      //�ж�˳����Ƿ�����
	{
		return false;         //˳�������������false,���벻�ɹ� 
	}
	else
	{
		elements[currentIndex] = data;    //����Ԫ�ز���˳����β
		length++;                         //˳�����Ч���ȼ�1
		return true; 
	} 
}

//2.˳����ɾ��Ԫ�ز���
/************ɾ��ָ��λ�õ�Ԫ��*************/
template <typename DataType> bool SeqList<DataType>::deleteElement(int location)
{
	if(location >= length || location < 0)   //��֤λ�����������Ƿ���Ч 
	{
		return false;
	}
	else
	{
		for(int i = location;i<length;i++)
		{
			elements[i] = elements[i+1]; //��ָ��λ��֮���Ԫ��������ǰ�ƶ�����ǰһ��Ԫ�� 
		}
		length--;   //˳����ȼ�1
		return true; 
	}
} 

//3.��ȡָ��λ�õ�Ԫ��
/**************��ȡָ��λ�õ�Ԫ��**************/
template <typename DataType> DataType SeqList<DataType>::getElement(int location)
{
	if(location<0 || location >length) //�ж�λ�������Ƿ�Ϸ�
	{
		std::cout<<"������Ч"<<std::endl;
		return 0;
	}
	else
	{
		return elements[location];     //����ָ��λ�õ�Ԫ�� 
	} 
}

//4.�޸�ָ��λ�õ�Ԫ��
/*************�޸�ָ��λ�õ�Ԫ��ֵ**************/
template<typename DataType> bool SeqList<DataType>::changeElement(int location,DataType newData)
{
	if(location<0 || location >= length)    //��֤λ�����������Ƿ���Ч
	{
		return false;
	}
	else
	{
		elements[location]=newData;         //��ָ��λ�ø�ֵ����Ԫ��
		return true; 
	} 
} 
