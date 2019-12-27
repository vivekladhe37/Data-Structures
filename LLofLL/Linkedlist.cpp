
#include"NodeLink.cpp"
#include<iostream>
using namespace std;
template<class T>
class Linkedlist
{
	private:
	int count;
	Node<T> *head;
	Node<T> *tail;
	NodeLink<T>*headL;
	NodeLink<T>*tailL;
	

	public:
//friend istream& operator>>(istream& input, Linkedlist& l);
	
//friend ostream& operator<<(ostream& output,const Linkedlist& l);
	Linkedlist()
	{
		head=nullptr;
		tail=nullptr;
		count=0;
	}
	 Node<T>* Gethead()
	 {
	   return head;
	 }

	
	void Display()
	{
		if(Isempty())
		{
			cout<<"There is no node";
			return;
		}
			Node<T>* temp=nullptr;
			temp=head;
			if(temp!=nullptr)
			{
				cout<<"\n The Linkedlist contains\n";
				while(temp!=nullptr)
				{
					cout<<temp->Getdata()<<".....>";
					temp=temp->Getnext();
				}
				
			}
	}
		
	bool Isempty()
	{
		return(head==nullptr && tail==nullptr);
	}

	
	bool Isfull()
	{
		return false;
	}

	
	void Addatend1(Node<T>* t)
	{
		NodeLink<T>* temp=new NodeLink<T>;
		temp->SetheadL(t);
		temp->SetnextL(nullptr);
		if(Isempty())
		{
			headL=tailL=temp;
			count=count+1;
		}
		else
		{       
		
			//tailL->Sethead(t);
			//tail->Setnext(nullptr);
			tailL->SetnextL(temp);
			tailL=temp;
			count=count+1;
		}
	}
	
	void Addatend(int x)
	{
		Node<T>* temp=new Node<T>;
		temp->Setdata(x);
		if(Isempty())
		{
			head=tail=temp;
			count=count+1;
		}
		else
		{
			tail->Setnext(temp);
			tail=temp;
			count=count+1;
		}
	}
	
};



/*ostream& operator<<(ostream& output,const Linkedlist& l)
{
  output<<l.Getdata();
}

 istream& operator>>(istream& input, Linkedlist& l)
{
   cout<<"Enter element:";
   input>>l.Setdata();
}*/
/*int main()
{
	Linkedlist<int> l1;
	l1.Addatend(10);
	l1.Addatend(20);
	l1.Addatend(30);
	Linkedlist<int> l2;
	l2.Addatend(10);
	l2.Addatend(20);
	l2.Addatend(30);
	Linkedlist<int> l3;
	l3.Addatend(10);
	l3.Addatend(20);
	l3.Addatend(30);
	l1.Display();
	//Linkedlist<>ll;
	ll.Addatend1(l1);

	//Linkedlist<NodeLink> l;
	//l.Addatend1(l1.Gethead());
	//l.Display();
//	l.Addatend1(l2);
//	l.Addatend1(l3);
	return 0; 

}*/
