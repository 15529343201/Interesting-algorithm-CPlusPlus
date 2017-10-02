//1.2.4 循环链表
/*************循环链表结点定义*************/
template<typename DataTyep> class CircularListNode
{
	private:
		CircularListNode *m_next;   //指向下一个节点的指针
		DataType m_data;            //数据域
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
/****************循环链表定义****************/
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
		//清空循环链表
		void cleanUp();
		//获取循环链表的长度
		int getLength();
		//查询具有value值得第i个元素，并返回其指针
		CircularListNode<DataType>* findNode(int i,DataType value);
		//在链表尾部插入元素
		bool insertNode(DataType data);
		//删除具有value值的所有元素
		bool deleteNode(DataType value);
		//获取指定元素的值
		DataType getValue(CircularListNode<DataType> *node); 
}
/************清空链表**************/
template<typename DataType> void CircularList<DataType>::cleanUp()
{
	CircularListNode *p;        //设置指示删除结点的指针
	while(head->m_next!=head)
	{
		p=head->m_next;
		head->m_next=p->m_next;
		delete p;
	} 
}
/************获取链表长度**************/
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
/***************查询具有value值的第i个指针*************/
template<typename DataType> CircularListNode<DataType>* CircularList<DataType>::findNode(int i,DataType value)
{
	int count=0;
	CircularListNode<DataType> *p=head;
	while(count!=i)
	{
		//遍历链表，寻找值与value相等的结点
		p=p->m_next;
		if(p->m_data==value)
		{
			count++;   //记录这是第几个符合条件的结点 
		}
		if(p==head)
			return NULL; 
	}
	return p;
}
/***************在链表尾部插入结点**************/
template<typename DataType> bool CircularList<DataType>::insertNode(DataType data)
{
	CircularListNode<DataType> *p=head;
	//建立新结点
	CircularListNode<DataType> *node=new CircularListNode<DataType>(data,NULL);
	if(node==NULL)
	{
		return false;
	}
	//寻找尾结点
	while(p->m_next!=head)
	{
		p=p->m_next;
	}
	node->m_next=p->m_next; //插入新结点
	p->m_next=node;
	return true; 
}
/***********删除具有value值的所有元素**********/
template<typename DataType> bool CircularList<DataType>::deleteNode(DataType value)
{
	int count=0;
	CircularListNode<DataType> *p=head->m_next,*l=head;
	//遍历链表
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
/**************获取指定元素的值************/
template<typename DataType> DataType CircularList<DataType>::getValue(CircularListNode<DataType> *node)
{
	return node->m_data;
} 
