#include"Linkedlist.cpp"
template <class T>
class Stack
{
	Linkedlist<int>l;
	public:
		void push(int x)
		{
		 l.Addatbeg(x);
		}
		T pop()
		{
		 l.Deleteatbeg();
		}
		void Display()
		{
		l.Display();
		}
};

int main()
{
 Stack<int> s;
 s.push(10);
 s.push(20);
 s.push(30);
 s.pop();
 s.push(40);
 s.Display();
}

