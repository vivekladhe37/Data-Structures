#include"Node.cpp"
#include"Student.cpp"
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
				//	output<<temp->Getdata()<<"===>">;
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

	
	void Addatend(Student s1)
	{
		Node<T>* temp=new Node<T>;
		temp->Setdata(s1);
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
	
	
}
;

int main()
{
	Student s1;
	cin>>s1;
	//cout<<s1;
	/*
	//Linkedlist<int> l1;
	Linkedlist<int> a[5];
	a[0].Addatend(10);
	a[0].Addatend(20);
	a[0].Addatend(30);
	a[0].Addatend(40);
	a[0].Addatend(50);
	a[0].Display();


	a[1].Addatend(11);
	a[1].Addatend(12);
	a[1].Addatend(13);
	a[1].Addatend(14);
	a[1].Display();*/




	/*l1.Addatend(10);
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
	l1.Display();*/
	/*
	Student s1;
	cin>>s1;*/
	Linkedlist<Student> l1;
	l1.Addatend(s1);
	l1.Display();




	
	return 0; 

}
