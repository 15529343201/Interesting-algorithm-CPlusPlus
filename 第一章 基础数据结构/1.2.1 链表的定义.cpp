//1.2.1 链表的定义
/**************链表结构************/
template <typename DataType> class LinkList
{
	private:
		ListNode *head;  //头结点
	public:
		//无参构造函数
		LinkList()
		{
			head=new ListNode();
		}
		//有参构造函数
		LinkList(ListNode *node)
		{
			head=node;
		}
		//析构函数
		~LinkList()
		{
			delete head;
		}
		bool insertNode(ListNode *q,DataType newData);     //插入结点
		bool removeNode(ListNode *q);     //删除结点
		ListNode* findNode(DataType value);   //查找指定值的结点并返回地址
		bool cleanLink();   //清空链表
		DataType getNodeData(ListNode *p);   //获取结点数据 
};
/*************定义链表结点************/
template <typename DataType> class ListNode
{
	private:
		friend typename LinkList<DataType>; //将LinkList设为友元类，方便其对node的成员数据和方法的访问
		DataType *next;   //指向下一个结点的指针
		DataType data;    //结点中的数据 
	public:
		ListNode()
		{
			next=NULL;
		}
		ListNode(DataType item,ListNode<DataType> *nextNode=NULL)
		{
			data=item;
			next=nextNode;
		}
		~ListNode()
		{
			next=NULL;
		}
		//获取结点内的数据
		DataType getData()
		{
			return data;
		}
		//获取指针域
		ListNode* getNext()
		{
			return next;
		} 
}
 
