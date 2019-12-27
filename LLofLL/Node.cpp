#include<iostream>
template <class T>
class Node
{
	private:
	T Data;
	Node* next;
	public:

	Node* Getnext()
	{
		return next;
	}

	void Setnext(Node* temp)
	{
		next=temp;	
	}
        T Getdata()
	{
		return Data;
	}
	void Setdata(T ele)
        {
                Data=ele;
        }

		
};

