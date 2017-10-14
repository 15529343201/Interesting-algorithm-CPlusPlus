//��1-9 ���һ�����нṹ,ʵ�ֻ�������
#include<iostream>
using namespace std;
/***********���нṹ����***********/
template<typename DataType> class Queue
{
	public:
		Queue(int size)
		{
			maxSize=size;                          //��ʼ���������
			//��ʼ�����ס���β��Ԫ����λ0
			front=0;
			rear=0;
			count=0;
			elements=new DataType[size];           //����ռ�
			//�ж�����ռ����ʧ��,���˳�
			if(elements==NULL)
				exit(1); 
		}
		~Queue()
		{
			delete[] elements;
		}
		/**********��Ӳ���**********/
		bool insert(DataType data);
		/**********���Ӳ���**********/
		DataType delElement();
	private:
		int count;                         //Ԫ�صĸ���
		int maxSize;                       //���е��������
		int front;                         //����
		int rear;                          //��β
		DataType *elements;                //����ָ�� 
};

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

int main()
{
	Queue<int> queue=Queue<int>(6);                //�������нṹ
	for(int i=0;i<6;i++)
		queue.insert(i*3); 
	for(int i=0;i<6;i++)
	{
		int temp=queue.delElement();
		cout<<temp<<" ";
	}
	cout<<endl;
	return 0;
}
/*��������
0 3 6 9 12 15
*/ 
