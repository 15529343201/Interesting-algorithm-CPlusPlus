//1.2.2 ����Ļ�������
//1.������
/*������Ĳ�����Ҫ������ʵ��:
(1)����һ��������Ľ��p��Ϊ������ڴ�ռ䣬������ָ������ΪNULL��
(2)�ҵ�������ĵ�i����㣬��ȡ���ĵ�ַq�������p�����ڽ��q�����̽��֮�䡣*/
/*************������ĵ�i����������½��***************/
template <typename DataType> bool LinkList<DataType>::insertNode(int i,DataType newData)
{
	ListNode<DataType> *p=head;   //�����α�ָ�룬��ʼ��Ϊͷ����ַ
	int j;
	for(j=1;j<=i-1;j++)   //���ҵ�i����㣬ָ����Ҫ�ƶ�i-1��
	{
		p=p->next;
		if(p==NULL)  //���ָ��Ϊ�գ��򲻴��ڸý�㣬���ѵ���β 
		{
			break;
		}
	}
	if(p==NULL && j<(i-1))  //ָ��Ϊ����û�е���i��λ�ã�˵�������ڵ�i�����
	{
		std::cout<<"����λ����Ч!"<<endl;
		return false;
	}
	ListNode<DataType> *node=new ListNode<DataType>(newData); //�����½��node
	node->next=p->next; //��node��nextָ�븳ֵΪp�ĺ�̽���ַ
	p->next=node;   //p�ĺ��ָ��ָ��node
	return true; 
} 
/****************�ڵ������β����½��**************/
template<typename DataType> bool LinkList<DataType>::insertNode(DataType newData)
{
	ListNode<DataType> *p=head;  //�����α�ָ��
	ListNode<DataType> *node=new ListNode<DataType>(newData);  //�����½��
	if(node==NULL)    //����½���ڴ����ʧ�ܣ�����false
	{
		return false;
	}
	while(p->next!=NULL) //�����������ҵ�β���
	{
		p=p->next;
	}
	p->next=node; //��β���nextָ��ָ���½��
	return true; 
} 
//2.ɾ�����
/***************ɾ��ָ�����******************/
template<typename DataType> bool LinkList<DataType>::removeNode(ListNode<DataType> *q)
{
	if(q==NULL) //�жϴ�ɾ������Ƿ����
	{
		std::cout<<"��ɾ����㲻����!"<<std::endl;
		return false;
	}
	ListNode<DataType> *tempPointer=head;  //�����α�ָ�룬��ʼ��Ϊͷ���
	while(tempPointer->next!=q)  //�����������ҵ�q��ָ�����ǰ�����
	{
		tempPointer=tempPointer->next;
	}
	tempPointer->next=q->next;  //��q���ĺ��ָ���ַ��ֵ����ǰ������nextָ��
	delete q;      //���ս��q�Ŀռ�
	return true; 
}
//3.�����ض�ֵ�Ľ��
/*************����ָ��ֵ�Ľ��**************/
template<typename DataType> ListNode<DataType>* LinkList<DataType>::findNode(DataType value)
{
	ListNode<DataType> *currentPointer=head;  //�����α�ָ��
	//�ж��α�ָ����ָ����ֵ�Ƿ���value���
	while(currentPointer!=NULL && currentPointer->data!=value)
	{
		currentPointer=currentPointer->next;
	}
	if(currentPointer==NULL)
	{
		std::cout<<"û���ҵ��ý��!�����쳣�˳�!"<<endl;
		exit(1);
	}
	else
	{
		return currentPointer;    //�������ҵ��Ľ���ָ�� 
	} 
} 
//4.�������
/****************�������**************/
template<typename DataType> void LinkList<DataType>::cleanLink()
{
	ListNode<DataType> *current=head;  //�����α�ָ��
	while(head->next!=NULL) //�ж�head�ĺ�̽���Ƿ�ΪNULL
	{
		current=head->next;
		head->next=current->next;
		delete current;
	} 
} 
