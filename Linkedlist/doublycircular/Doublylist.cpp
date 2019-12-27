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
			Node<T>* temp=head;
			
				cout<<"\n The Linkedlist contains\n";
				while(temp!=tail)
				{
					cout<<temp->Getdata()<<".....>";
					temp=temp->Getnext();
				}
				cout<<tail->Getdata();
				
			
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
			head->Setnext(tail);
			head->Setprevious(tail);
			count=count+1;
		}
		else
		{
			tail->Setnext(temp);
			temp->Setprevious(tail);
			temp->Setnext(head);
			head->Setprevious(temp);
			tail=temp;
			count=count+1;
		}
		cout<<"\n The count is "<<count;
	}
	
	
	void Addatbeg(int x)
	{
		Node<T>* temp=new Node<T>;
		temp->Setdata(x);
		if (Isempty())
		{
			head=tail=temp;
			head->Setnext(tail);
			head->Setprevious(tail);
			count=count+1;	
		}
		else
		{

			temp->Setnext(head);
			temp->Setprevious(tail);
			head->Setprevious(temp);
			tail->Setnext(temp);
			head=temp;
			count=count+1;
		}
	}

		
	
/*	void Reverse()
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
	}*/
	
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
	   {
		   Node<T>* temp=head;
	     while(temp->Getnext()!=tail)
	     {
	     
	      temp=temp->Getnext();
	     }
	      int ele= tail->Getdata(); 
	      temp->Setnext(head);
		tail=nullptr;	
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
	    head->Setprevious(tail);
	    tail->Setnext(head);
	      temp->Setnext(nullptr);
	    temp=nullptr;

	       delete temp;
	       cout<<"\n";
	       return ele;
	   }
	 }
	void Addatposition(int ele, int x)
	{
		Node<T>* temp= new Node<T>;
		if(Isempty())
		{
			head=tail=temp;
			head->Setnext(tail);
		//	tail->Setnext(head);

			
		}




		Node<T>* p=head;
		int c=0;
			
		Node<T>* q=head;
		q=q->Getnext();
		temp->Setdata(ele);
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

				if(q==tail)
				{
					q->Setnext(head);
					head->Setprevious(q);
				}


			}
			else if(count==(x-1))
				 {
					 int c1=0;
					 cout<<"you are smart";
				//	cout<<"\n \n  tell me the value of c "<<c;
				        while(c1<(x-2))
					{
					p=p->Getnext();
					q=q->Getnext();
					c1++;
					}

					p->Setnext(temp);
					temp->Setprevious(p);
					temp->Setnext(head);
					q=temp;
					tail=q;
			//		count= count+1;
				
					//temp->Setnext(q);
					//q->Setprevious(temp);

		
				}
			/*	else
				{
					cout<<"\n \n Check your position ";
					return (-1)
				}
*/


				
		}
		count=count+1;
	}
};
int main()
{
	Linkedlist<int> l1;
///	l1.Addatbeg(20);
/////	l1.Addatbeg(10);
//	l1.Addatend(30);
//	l1.Addatend(40);
///
//	l1.Display();
//	l1.Deleteatend();
////	l1.Deleteatend();
///	l1.Deleteatend();
/////	l1.Deleteatend();
//	l1.Deleteatbeg();
///	l1.Display();
//	l1.Reverse();

	l1.Display();


	l1.Addatposition(10,1);
	l1.Display();

	l1.Addatend(20);
	l1.Addatposition(30,3);
//	l1.Addatend(30);
	l1.Addatend(40);
	l1.Addatend(60);
	l1.Addatposition(50,5);

	l1.Display();


	l1.Addatposition(70,7);
	l1.Display();


	l1.Addatposition(100,10);


//	l1.Display();


	return 0; 

}
