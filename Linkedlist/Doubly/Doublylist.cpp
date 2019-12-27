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

		if(Isempty())
		{
			head=tail=temp;
			head->Setnext(nullptr);
			head->Setprevious(nullptr);
			count=count+1;
		}
		else
		{
			tail->Setnext(temp);
			temp->Setprevious(tail);
			temp->Setnext(nullptr);
			head->Setprevious(nullptr);
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
			head->Setnext(nullptr);
			head->Setprevious(nullptr);
			count=count+1;	
		}
		else
		{

			temp->Setnext(head);
			temp->Setprevious(nullptr);
			head->Setprevious(temp);
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
			Node<T>* temp;
		
				temp=tail;		
				cout<<"\n The Linkedlist contains\n";
				while(temp!=nullptr)
				{
					cout<<temp->Getdata()<<".....>";
					temp=temp->Getprevious();
				}	
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
	    head->Setprevious(nullptr);

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
				temp->Setprevious(p);
				
				temp->Setnext(q);
				q->Setprevious(temp);


			}
		}

	}
};
int main()
{
	Linkedlist<int> l1;
	l1.Addatbeg(10);
	l1.Deleteatbeg();cout<<b;

//	l1.Display();
//	l1.Reverse();
	l1.Display();
	return 0; 

}
