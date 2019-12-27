#include<iostream>
#include"Node.cpp"
template <class T>
class NodeLink
{
	private:
	NodeLink* next;
	Node<T>*h;
	public:

	NodeLink* Getnext()
	{
		return next;
	}
	void SetnextL(NodeLink* temp)
        {
                next=temp;      
        }
	void SetheadL(Node<T> * temp)
	{
	  h=temp;
	}

        


		
};



