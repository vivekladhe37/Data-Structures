#include<iostream>
#include<stdexcept>
#include<math.h>
using namespace std;
template<class t>
class Stack
{
	int top,s;
        //int *a=new int[s];
	t  *a=NULL;
	public:
	Stack(int x);
	void push(t x);
	t peep();
	t pop();
	
	bool Isfull();
	bool Isempty();
	void display();



};

template class Stack<char>;

template class Stack<float>;
