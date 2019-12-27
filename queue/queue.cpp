#include<iostream>
#include<stdexcept>

using namespace std;
class queue
{
 int rear,front,a[5];
	public:
 	queue()
	{
	  front=0;
	  rear=0;
	}
 	 void add(int x)
	 {

		 
		if(Isfull())
		{  //cout<<"in full";
			throw runtime_error("Queue is full");
			//rear=(rear+1)%5;

		}
		else
		{

		rear=(rear+1)%5;	
		 a[rear]=x;
		 
		
	   
	         cout<<a[rear];
		}
	 }
	 
	 int del()
	 { cout<<"in del";
		 if(IsEmpty())
		 {
			 throw runtime_error("Queue is empty");
			//cout<<"full";
			//front=(front+1)%5;
		  }
		 else{
		 
         int ele=a[front];
         
		
front=(front+1)%5;
	 return ele;
	 
		 }
	 
	 }


	bool Isfull()
	{
	  return((rear+1)==front);

	}
	bool IsEmpty()
	{
	  return (front==rear);
	}


};
int main()
{
	int y=0;
 queue q;
 try{
 
 q.add(18);
 q.add(12);
 q.add(13);
 q.add(14);
 q.add(15);
/*
y= q.del();
cout<<y<<endl;
int z= q.del();
cout<<z<<endl;
int r=q.del();
cout<<r<<endl;
q.add(21);

q.add(22);
q.add(23);
 //q.del();
 //q.del();
 //q.del();
// q.del();
// q.del();
//q.del(); 
 
//int y= q.del();*/
q.add(24);
 
 }
catch (runtime_error e)
 {
	cout<< e.what();
 }
return 0;
}
