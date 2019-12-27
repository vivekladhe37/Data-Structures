#include<iostream>
#include<stdexcept>
#include<math.h>
using namespace std;
template<class t>
class Stack
{
	int top1,top2,s;
        //int *a=new int[s];
	t  *a=NULL;
	public:
	Stack(int x)
	{
	  top1=0;
	  top2=x-1;
	  s=x;
	  a=new t[s];
	 

	}


	void push (t x,int p)
	{ 
	    if(!Isfull())
	 {
	    throw runtime_error("stack overflow");
	 }
	    
	  if(p==1)
	  {
	  a[top1]=x;
	  top1++;
	  }
	  else
	  {
	  a[top2]=x;
          top2--;
	  }
	    


       }

	

/*	t peep()
	{
	return   a[top];
	
	}

/*t pop()
	{
	  if(Isempty())
	  {
	  throw runtime_error("stack underflow");
	  }
	else
	{
	 t ele=a[top];
         top--;
	 return ele;
	}

	}*/

bool Isfull()
	{
	return (top1<=top2);
	}

bool Isempty()
	{
	return(top1==0 && top2==s );
	
	}

};
int main()
{
int  n,ch,a,b;
 int  y,x,z;
cout<<"Enter size of array";
cin>>n;
Stack<float>st(n);



/* int i=0;
 while(n!=0)
 { 
  int rem=n%16;
 // p =rem*pow(8,i);
if (rem>9)
{   rem-=10;
rem+=65;
  st.push(rem);
  count++;
}
else
{
st.push(rem+48);
  count++;
  //n=n/10;
 // i++;
 }
n=n/16;
}
 cout<<"Binary conversion is:";
 while(count--)
 {
 y =st.pop();
cout<<y;
 }
 //cout<<y;

 /*try{
 st.push(11);
int x= st.pop();
cout<<"poped element is"<<x<<endl;

 st.push(21);
 st.push(31);
 st.push(41);
 st.push(51);
st.pop();
st.push(61);
st.push(71);
int y=st.peep();
cout<<y;
//st.push(81);
 }

 catch( runtime_error e)
 {
   cout<<e.what();
 
 }
 st.display();*/
 do
 {
	 
 cout<<"1.Push\t2.Pop\t3.Peep";
 cout<<"Enter the choice";
 cin>>ch;
 cout<<"In Stack 1 or 2";
 cin>>b;
 cin.get();
 switch(ch)
 {
	case 1: cout<<"Enter the element to push";
		cin>>x;
		st.push(x,b);
		break;
/*	case 2:  y=st.pop();
 		cout<<"poped element is"<<y;
		 break;
	case 3: z=st.peep();
		cout<<"Element on top is:"<<z;
		break;
	default:cout<<"Invalid choice"; */	

 
 }
   cout<<"Do u want to continue: press 1";
   cin>>a;
 }while(a==1);

return 0;

}
