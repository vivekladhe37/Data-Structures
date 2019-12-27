#include"Node.cpp"
template<class T>
class Linkedlist
{
	private:
		int count;
		int ele;
		Node<T>* head;
		Node<T>* tail;

	public:
		Linkedlist()
		{
			head=NULL;
			tail=NULL;
			count=0;
		}
		void Accept()
		{
			cout<<"\n Enter the element ";
			cin>>ele;
		}
		T Getele()
		{
			return ele;
		}
		bool Addatend(Linkedlist l2)

		{
			bool bsuccess = false;

			Node<T>* temp=new Node<T>;
			temp->Setdata(l2.Getele());

		//	if(Isempty())
		if(head==NULL && tail==NULL)
			{		
				head=tail=temp;
				bsuccess = true;
			}

			else
			{
			tail->Setnext(temp);
			tail=temp;
			bsuccess = true;
			}
			count = count + 1;
			return bsuccess;

		}


		void Display()
		{
			bool bsuccess = false;
			Node<T>*temp=head;

			cout<<"\n \nThe linked list is shown as"<<endl;
			while(temp!=nullptr)
			{
				cout<<temp->Getdata()<<"-->";
				temp=temp->Getnext();
			}
			cout<<"NULL";
		}
		

		
};
int main()
{
	Linkedlist<int> l1;
//	Linkedlist<int> l2;
	
	Linkedlist<int> l2[5];
//	Linkedlist<int> l4;
	//l2.Accept();
//	l3.Accept();
//	l4.Accept();
         for(int i=0;i<5;i++)
	 {
	  l2[i].Accept();
	  l1.Addatend(l2[i]);
	 
	 }

	/*l1.Addatend(l2);
	l1.Addatend(l3);
	l1.Addatend(l4);*/
	l1.Display();


return 0;

}

