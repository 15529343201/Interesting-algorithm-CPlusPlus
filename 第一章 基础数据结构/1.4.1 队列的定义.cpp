//���еĶ���
/************���нṹ����*************/
template<typename DataType> class Queue
{
	public:
		Queue(int size)
		{
			maxSize=size;          //��ʼ���������
			//��ʼ�����ס���β��Ԫ����λ0
			front=0;
			rear=0;
			count=0;
			elements=new DataType[size];    //����ռ�
			//�ж�����ռ����ʧ��,���˳�
			if(elements==NULL)
				exit(1); 
		}
		~Queue()
		{
			delete[] elements;
		}
		/**********��Ӳ���***********/
		bool insert(DataType data);
		/**********���Ӳ���***********/
		DataType delElement(); 
	private:
		int count;                 //Ԫ�صĸ���
		int maxSize;               //���е��������
		int front;                 //����
		int rear;                  //��β
		DataType *elements;        //����ָ�� 
}; 
