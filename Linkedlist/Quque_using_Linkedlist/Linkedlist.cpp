#include"Node.cpp"
#include<iostream>
using namespace std;

template<class T>
class Linkedlist
{
	private:
	int count;
	Node<T> *head;
	Node<T> *tail;

	public:
	
	Linkedlist()
	{
		head=nullptr;
		tail=nullptr;
		count=0;
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

	
	void Addatend(int x)
	{
		Node<T>* temp=new Node<T>;
		temp->Setdata(x);
		temp->Getnext();
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
	
	
	void Addatbeg(int x)
	{
		Node<T>* temp=new Node<T>;
		temp->Setdata(x);
		if (Isempty())
		{
			head=tail=temp;
			count=count+1;
		}
		else
		{
			temp->Setnext(head);
			head=temp;
			count=count+1;
		}
	}

	void Reverse()
	{
		if(Isempty())
		{
			cout<<"NULL";
		}
		else
		{
			Node<T>* nhead=tail;
			Node<T>* temp=head;
			Node<T>* temp1=nhead;
			while(tail!=head)
			{
				temp = head;
				while(temp->Getnext()!=tail)
				{
					temp=temp->Getnext();
				}
				temp->Setnext(nullptr);
				tail=temp;
				temp1->Setnext(tail);
				temp1=temp1->Getnext();

			}
			head=nhead;
			temp1->Setnext(nullptr);
			tail=temp1;
		}
		
	}
	
/*	void Reverse1()	
	{
		if(Isempty())
		{
			cout<<"Nothing to reverse";
		}
		else
		{
		Node<T>* temp= head;
		Node<T>* ntail;
		Node<T>* temp1;
			head=head->Getnext();
		while (head!=tail)
		{
			temp1=temp;

			ntail=temp;
			temp=temp->Getnext();
			temp1=temp1->Setnext(nullptr);

			

		}
		




		}
	}
*/
	 T Deleteatend()
	 {
	   if(Isempty())
	   {
	     cout<<"empty list";
	   }
	   else
	   {Node<T>* temp=head;
	     while(temp->Getnext()!=tail)
	     {
	     
	      temp=temp->Getnext();
	     }
	      // delete tail;
	      int ele= tail->Getdata(); 
	      temp->Setnext(nullptr);

	       delete tail;
	       tail=temp;
	       cout<<"\n";
	       return ele;

	      
	      
	   
	   }
	 
	 
	 }
	 T Deleteatbeg()
	 {
	   if(Isempty())
	   {
	     cout<<"empty list";
	   }
	   else
	   {
		Node<T>* temp=head;
	    head=head->Getnext();
	      int ele= temp->Getdata(); 
	      temp->Setnext(nullptr);

	       delete temp;
	       cout<<"\n";
	       return ele;
	   }
	 }
	void Addatposition(int ele, int x)
	{
		Node<T>* temp= new Node<T>;
		Node<T>* p=head;
		int c=0;
			
		Node<T>* q=head;
		q=q->Getnext();
		temp->Setdata(ele);
		if(Isempty())
		{
			head=tail=temp;
		}
		else
		{
			if(x<=count)
			{
				while(c<(x-2))
				{
					p=p->Getnext();
					q=q->Getnext();
					c++;
				 
				}

				p->Setnext(temp);
				temp->Setnext(q);


			}
		}

	}
};
/*
int main()
{
	Linkedlist<int> l1;
	l1.Addatend(10);
	l1.Addatend(20);
	l1.Addatend(30);
	l1.Addatend(40);
//	l1.Addatend(50);
//	l1.Addatend(60);
//	l1.Addatend(70);
//	l1.Addatposition(80,3);
	l1.Display();
	int y=l1.Deleteatend();cout<<y;
	int x=l1.Deleteatend();cout<<x;
	int a=l1.Deleteatbeg();cout<<a;
	int b=l1.Deleteatbeg();cout<<b;

	l1.Display();
	l1.Reverse();
	l1.Display();
	return 0; 

}*/
