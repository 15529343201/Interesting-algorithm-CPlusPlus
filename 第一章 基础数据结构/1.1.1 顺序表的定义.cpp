//1.1.1 ˳���Ķ���
/**********���Ա����ݽṹ**************/
const int defaultSize = 10;             //����Ĭ��˳����С
template <typename DataType> class SeqList
{
	public:
		//���캯��
		SeqList(int size=defaultSize){
			if(size > 0)   //��鸳���˳����С������Ϸ��������Ӧ��С���ڴ�
			{
				maxSize = size;
				elements = new DataType(maxSize);  //�����ڴ��С 
			} 
		}
		//��������
		~SeqList()
		{
			delete[] elements;        //�����ڴ�ռ� 
		} 
	private:
		DataType *elements;
		int maxSize;                  //˳�������С 
};


 
