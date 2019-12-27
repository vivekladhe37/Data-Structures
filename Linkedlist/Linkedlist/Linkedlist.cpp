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

		bool Isempty()
		{
			return(head==NULL && tail==NULL);
		}

		bool Isfull()
		{
			return false;
		}

		bool Addatend(int x)
		{
			bool bsuccess = false;

			Node<T>* temp=new Node<T>;
			temp->Setdata(x);

			if(Isempty())
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

		bool Addatbeg(int x)
		{
			bool bsuccess = false;

			Node<T>* temp=new Node<T>;
			temp->Setdata(x);

			if(Isempty())
			{		
				head=tail=temp;
				bsuccess = true;
			}

			else
			{
			temp->Setnext(head);
			head=temp;
			bsuccess = true;
			}
			count = count + 1;
			return bsuccess;
		}

		void Display()
		{
			bool bsuccess = false;
			Node<T>*temp=NULL;
			temp=head;

			cout<<"\n \nThe linked list is shown as"<<endl;
			while(temp!=tail)
			{
				ele=temp->Getdata();
				cout<<"==>"<<ele;
				temp=temp->Getnext();
			}
				ele=temp->Getdata();
				cout<<"==>"<<ele;
			cout<<"==>NULL";
			bsuccess = true;
		}

		bool Addatposition(int x, int pos)
		{
			bool bsuccess;
			int c = 0;

			if (pos == 1)
			{
				bsuccess=Addatbeg(x);
				return true;
			}

			if (pos==(count+1))
			{
				bsuccess=Addatend(x);
				return true;
			}
			

			else if(pos<=0 || pos>(count+1))
			{
				cout<<"\nInvalid Position ";
				return false;
			}

			else
			{
			Node<T>* temp = new Node<T>;
			temp->Setdata(x);
			Node<T>* p = head;
			Node<T>* q = head;
			q=q->Getnext();
			cout<<q->Getdata()<<endl;
				while(c<(pos-2))
				{
				p=p->Getnext();
				q=q->Getnext();
				c++;
				}
				p->Setnext(temp);
				temp->Setnext(q);
				bsuccess=true;
			}
			count = count +1;
			return bsuccess;
		}

		bool Deleteatend()
		{
			bool bsuccess;

			if(Isempty())
			{
				return false;
			
			}

			else
			{
			Node<T>* temp;
			Node<T>* temp1=tail;
			temp=head;
			ele=tail->Getdata();
			while(temp!=tail)
			{
				temp=temp->Getnext();
			}
			tail=temp;
			temp->Setnext(NULL);
			delete temp1;
			count=(count-1);
			}

		}

};

int main()
{
	char ch;
	int position;
	Linkedlist<int> l1;
	int choice;
	int element;
	do
	{
	cout<<"\n**********MENU LIST**********\n \n";
	cout<<"\n1. Addatend\n2. Addatbeg\n3. Deleteatend\n4. Deleteatbeg\n5. Insertatposition\n6. Reversethelist\n7. Display"<<endl;
	cout<<"\n Enter the choice"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:{
				cout<<"\nEnter the element to be added from end  "<<endl;
				cin>>element;
				l1.Addatend(element);
				break;
			}

		case 2:{
			        cout<<"\n Enter the element to be added from beg "<<endl;
			        cin>>element;
			        l1.Addatbeg(element);
				break;

		       }

		case 3:{
			       l1.Deletefromend();
			       break;
		       }

		case 5:{
			       cout<<"\nEnter the data of the element to be added at given position "<<endl;
			       cin>>element;
			       cout<<"\nEnter the position where the element is to be added "<<endl;
			       cin>>position;
			       l1.Addatposition(element,position);
			       break;
		       }

		case 7:{
				l1.Display();
				break;
			}

		default: cout<<"\n You have entered a wrong choice "<<endl;


		



	}
cout<<"\n \nDo you want to continue if yes press y"<<endl;
cin>>ch;
	
	}while(ch=='y');
	
	
}
