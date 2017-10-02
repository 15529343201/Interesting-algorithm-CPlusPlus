//1.3.1 ջ�Ķ���
/****************ջ�Ķ���************/
template<typename DataType> class Stack
{
	private:
		DataType *elements;                       //������ָ��
		int top;                                  //ջ��
		int maxSize;                              //ջ��������� 
	public:
		Stack(int size)
		{
			maxSize=size;                //�����������
			top=-1;                      //��ʼ��Ϊ��ջ
			elements=new DataType[size]; //����ռ� 
		}
		~Stack()
		{
			delete[] elements;
		}
		//��ջ����
		bool push(DataType data);
		//��ջ����
		DataType pop(); 
}; 
