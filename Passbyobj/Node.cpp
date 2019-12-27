#include<iostream>
using namespace std;
template<class T>
class Node
{
	private:

		T ele;
		Node<T>* next;

	public:

		T Getdata()
		{
			return ele;
		}

		void Setdata(T e)
		{
			ele=e;
		}

		Node<T>* Getnext()
		{
			return next;
		}

		void Setnext(Node* temp)
		{
			next=temp;
		}


		
};

