//1.2.2 链表的基本操作
//1.插入结点
/*单链表的插入需要分两步实现:
(1)创建一个待插入的结点p，为其分配内存空间，并将其指针域设为NULL。
(2)找到单链表的第i个结点，获取它的地址q，将结点p插入在结点q与其后继结点之间。*/
/*************在链表的第i个结点后插入新结点***************/
template <typename DataType> bool LinkList<DataType>::insertNode(int i,DataType newData)
{
	ListNode<DataType> *p=head;   //设置游标指针，初始化为头结点地址
	int j;
	for(j=1;j<=i-1;j++)   //查找第i个结点，指针需要移动i-1次
	{
		p=p->next;
		if(p==NULL)  //如果指针为空，则不存在该结点，或已到表尾 
		{
			break;
		}
	}
	if(p==NULL && j<(i-1))  //指针为空且没有到第i个位置，说明不存在第i个结点
	{
		std::cout<<"插入位置无效!"<<endl;
		return false;
	}
	ListNode<DataType> *node=new ListNode<DataType>(newData); //建立新结点node
	node->next=p->next; //将node的next指针赋值为p的后继结点地址
	p->next=node;   //p的后继指针指向node
	return true; 
} 
/****************在单链表表尾添加新结点**************/
template<typename DataType> bool LinkList<DataType>::insertNode(DataType newData)
{
	ListNode<DataType> *p=head;  //设置游标指针
	ListNode<DataType> *node=new ListNode<DataType>(newData);  //创建新结点
	if(node==NULL)    //如果新结点内存分配失败，返回false
	{
		return false;
	}
	while(p->next!=NULL) //遍历单链表，找到尾结点
	{
		p=p->next;
	}
	p->next=node; //将尾结点next指针指向新结点
	return true; 
} 
//2.删除结点
/***************删除指定结点******************/
template<typename DataType> bool LinkList<DataType>::removeNode(ListNode<DataType> *q)
{
	if(q==NULL) //判断待删除结点是否存在
	{
		std::cout<<"待删除结点不存在!"<<std::endl;
		return false;
	}
	ListNode<DataType> *tempPointer=head;  //设置游标指针，初始化为头结点
	while(tempPointer->next!=q)  //遍历单链表，找到q所指向结点的前驱结点
	{
		tempPointer=tempPointer->next;
	}
	tempPointer->next=q->next;  //将q结点的后继指针地址赋值给其前驱结点的next指针
	delete q;      //回收结点q的空间
	return true; 
}
//3.查找特定值的结点
/*************查找指定值的结点**************/
template<typename DataType> ListNode<DataType>* LinkList<DataType>::findNode(DataType value)
{
	ListNode<DataType> *currentPointer=head;  //设置游标指针
	//判定游标指针所指结点的值是否与value相等
	while(currentPointer!=NULL && currentPointer->data!=value)
	{
		currentPointer=currentPointer->next;
	}
	if(currentPointer==NULL)
	{
		std::cout<<"没有找到该结点!程序异常退出!"<<endl;
		exit(1);
	}
	else
	{
		return currentPointer;    //返回所找到的结点的指针 
	} 
} 
//4.清空链表
/****************清空链表**************/
template<typename DataType> void LinkList<DataType>::cleanLink()
{
	ListNode<DataType> *current=head;  //设置游标指针
	while(head->next!=NULL) //判断head的后继结点是否为NULL
	{
		current=head->next;
		head->next=current->next;
		delete current;
	} 
} 
