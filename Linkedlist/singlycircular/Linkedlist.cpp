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
		else{	
			Node<T>* temp=head;
			
				cout<<"\n The Linkedlist contains\n";
				while(temp!=tail)
				{
					cout<<temp->Getdata()<<".....>";
					temp=temp->Getnext();
				}
				cout<<tail->Getdata()<<".....>";
		//	cout<<tail->Getnext()->Getdata();
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
			tail->Setnext(head);
			count=count+1;
		}
		else
		{
			tail->Setnext(temp);
			temp->Setnext(head);
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
			tail->Setnext(head);
			count=count+1;
		}
		else
		{
			temp->Setnext(head);
			tail->Setnext(temp);
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
		  Node<T>* temp=head;
                  T ele=head->Getdata();

	   	if(Isempty())
	   	{
	    	     cout<<"empty list";
	   	}
	        else
	        {
	           
		    if(head==tail)
		    {
		         cout<<"hello";
		         head=tail=nullptr;
		         delete temp;
		    }
		    else
		    {
	   	         while(temp->Getnext()!=tail)
	    	        {
	    	            temp=temp->Getnext();
	      	        }
	      	          T ele= tail->Getdata(); 
                          delete tail;
	                  tail=temp;
			  tail->Setnext(head);
	                 
	                 
		    }

	     }
	       return ele;
	  }

	 T Deleteatbeg()
	 {
	   if(Isempty())
	   {
	     cout<<"empty list";
	   }
	   else 
	   {
		   if(head->Getnext()==head)
		   {

			 T ele=head->Getdata();
		cout<<"/n";	
			 delete head;

		   }
		   else{
	      Node<T>* temp=head;
	      head=head->Getnext();
	      int ele= temp->Getdata(); 
	      temp->Setnext(nullptr);
		tail->Setnext(head);
		temp=nullptr;
		
	   

	       cout<<"\n";
	       delete temp;}

	   

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
			if(x<count)
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
			 else if(x==count)
			{
				while(c<(x-2))
				{
					p=p->Getnext();
					q=q->Getnext();
					c++;
				 
				}

				p->Setnext(temp);
				temp->Setnext(q);
				q->Setnext(head);


			}
		}

	}	
};
int main()
{
	Linkedlist<int> l1;
	l1.Addatbeg(10);
	l1.Addatbeg(20);
	l1.Addatbeg(30);
	l1.Addatbeg(40);
	l1.Addatbeg(50);
	l1.Addatbeg(60);
	l1.Addatbeg(70);
	l1.Addatbeg(80);
	l1.Addatbeg(90);
//	l1.Addatbeg(10);
//l1.Deleteatbeg();

//l1.Deleteatbeg();
//l1.Deleteatbeg();
//l1.Deleteatbeg();
//l1.Deleteatbeg();
//l1.Deleteatbeg();
//l1.Deleteatbeg();
      l1.Display();
	l1.Reverse();
	l1.Display();
	return 0; 

}
