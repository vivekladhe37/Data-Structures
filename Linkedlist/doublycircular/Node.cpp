
template <class T>
class Node
{
	private:
	T Data;
	Node* next;
	Node* previous;
	public:

	Node* Getnext()
	{
		return next;
	}

	Node* Getprevious()
	{
		return previous;
	}


	void Setnext(Node* temp)
	{
		next=temp;	
	}

	void Setprevious(Node* temp)
	{
		previous=temp;	
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

