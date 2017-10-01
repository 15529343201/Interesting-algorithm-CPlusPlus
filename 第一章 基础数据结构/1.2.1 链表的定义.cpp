//1.2.1 ����Ķ���
/**************����ṹ************/
template <typename DataType> class LinkList
{
	private:
		ListNode *head;  //ͷ���
	public:
		//�޲ι��캯��
		LinkList()
		{
			head=new ListNode();
		}
		//�вι��캯��
		LinkList(ListNode *node)
		{
			head=node;
		}
		//��������
		~LinkList()
		{
			delete head;
		}
		bool insertNode(ListNode *q,DataType newData);     //������
		bool removeNode(ListNode *q);     //ɾ�����
		ListNode* findNode(DataType value);   //����ָ��ֵ�Ľ�㲢���ص�ַ
		bool cleanLink();   //�������
		DataType getNodeData(ListNode *p);   //��ȡ������� 
};
/*************����������************/
template <typename DataType> class ListNode
{
	private:
		friend typename LinkList<DataType>; //��LinkList��Ϊ��Ԫ�࣬�������node�ĳ�Ա���ݺͷ����ķ���
		DataType *next;   //ָ����һ������ָ��
		DataType data;    //����е����� 
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
		//��ȡ����ڵ�����
		DataType getData()
		{
			return data;
		}
		//��ȡָ����
		ListNode* getNext()
		{
			return next;
		} 
}
 
