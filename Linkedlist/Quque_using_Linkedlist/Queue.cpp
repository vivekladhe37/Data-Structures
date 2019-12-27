#include"Linkedlist.cpp"
template<class T>
class Queue
{  
	Linkedlist <int>l;
  public:
	  void Add(int x)
	     {
	        l.Addatend(x);
	     }
  	  T Delete()
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

 Queue<int> q;
 q.Add(10);
 q.Add(11);
 q.Add(12);
 q.Add(13);
 q.Add(14);
 int x=q.Delete();
 cout<<x;
 q.Display();

}
