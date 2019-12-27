#include"Stack.h"
#include<stdexcept>
#include<math.h>
template<class t>
	Stack<t>::Stack(int x)
	{
	  top=-1;
	  s=x;
	  a=new t[s];
	  cout<<"Size of a"<<sizeof(a[1]);

	}
template<class t>


	void Stack<t>::push (t x)
	{  if(Isfull())
	 {
	    throw runtime_error("stack overflow");
	 }
	 else
	 {
	  top++;
	  a[top]=x;
	}

       }

	
template<class t>

	t Stack<t>::peep()
	{
	return   a[top];
	
	}

template<class t>
	t Stack<t>:: pop()
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

	}

template<class t>
	bool Stack<t>::Isfull()
	{
	return (top==s-1);
	}

template<class t>
	bool Stack<t>::Isempty()
	{
	return(top==-1);
	
	}

template<class t>
	void Stack<t>::display()
	{
	 for(int i=0;i<=top;i++)
		cout<<"\n"<<a[i];
	}



