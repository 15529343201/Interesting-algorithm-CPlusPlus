//1.2.4 ѭ������
/*************ѭ�������㶨��*************/
template<typename DataTyep> class CircularListNode
{
	private:
		CircularListNode *m_next;   //ָ����һ���ڵ��ָ��
		DataType m_data;            //������
	public:
		friend class CircularList<DataType>;
		CircularListNode()
		{
			m_next=NULL;
		}
		CircularListNode(DataType data,CircularListNode *nextOne=NULL)
		{
			m_data=data;
			m_next=nextOne;
		}
		~CircularListNode()
		{
			m_next=NULL;
		} 
}
/****************ѭ��������****************/
template<typename DataType> class CircularList
{
	private:
		CircularListNode<DataType> *head;
	public:
		CircularList()
		{
			head=new CircularListNode<DataType>();
			head->m_next=head;
		}
		~CircularList()
		{
			clearUp();
			delete head;
		}
		//���ѭ������
		void cleanUp();
		//��ȡѭ������ĳ���
		int getLength();
		//��ѯ����valueֵ�õ�i��Ԫ�أ���������ָ��
		CircularListNode<DataType>* findNode(int i,DataType value);
		//������β������Ԫ��
		bool insertNode(DataType data);
		//ɾ������valueֵ������Ԫ��
		bool deleteNode(DataType value);
		//��ȡָ��Ԫ�ص�ֵ
		DataType getValue(CircularListNode<DataType> *node); 
}
/************�������**************/
template<typename DataType> void CircularList<DataType>::cleanUp()
{
	CircularListNode *p;        //����ָʾɾ������ָ��
	while(head->m_next!=head)
	{
		p=head->m_next;
		head->m_next=p->m_next;
		delete p;
	} 
}
/************��ȡ������**************/
template<typename DataType> int CircularList<DataType>::getLength()
{
	int length=0;
	CircularListNode<DataType> *p=head;
	while(p->m_next!=head)
	{
		p=p->m_next;
		length++;
	}
	return length;
}
/***************��ѯ����valueֵ�ĵ�i��ָ��*************/
template<typename DataType> CircularListNode<DataType>* CircularList<DataType>::findNode(int i,DataType value)
{
	int count=0;
	CircularListNode<DataType> *p=head;
	while(count!=i)
	{
		//��������Ѱ��ֵ��value��ȵĽ��
		p=p->m_next;
		if(p->m_data==value)
		{
			count++;   //��¼���ǵڼ������������Ľ�� 
		}
		if(p==head)
			return NULL; 
	}
	return p;
}
/***************������β��������**************/
template<typename DataType> bool CircularList<DataType>::insertNode(DataType data)
{
	CircularListNode<DataType> *p=head;
	//�����½��
	CircularListNode<DataType> *node=new CircularListNode<DataType>(data,NULL);
	if(node==NULL)
	{
		return false;
	}
	//Ѱ��β���
	while(p->m_next!=head)
	{
		p=p->m_next;
	}
	node->m_next=p->m_next; //�����½��
	p->m_next=node;
	return true; 
}
/***********ɾ������valueֵ������Ԫ��**********/
template<typename DataType> bool CircularList<DataType>::deleteNode(DataType value)
{
	int count=0;
	CircularListNode<DataType> *p=head->m_next,*l=head;
	//��������
	while(p!=head)
	{
		if(p->m_data==value)
		{
			l->m_next=p->m_next;
			delete p;
			count++;
			p=l->m_next;
		}
		else
		{
			l=p;
			p=p->m_next;
		}
	}
	if(count==0)
		return false;
	else
		return true; 
}
/**************��ȡָ��Ԫ�ص�ֵ************/
template<typename DataType> DataType CircularList<DataType>::getValue(CircularListNode<DataType> *node)
{
	return node->m_data;
} 
