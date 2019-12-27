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
	void Setdata(T s1)
	{
		Data=s1;
	}
		
};

