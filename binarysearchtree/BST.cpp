#include"Treenode.cpp"
#include<stack>
#include<list>
template<class T>

class BST
{
	private:
		Treenode<T>* root;
	public:
		BST()
		{
			root = NULL;
		}

		void insert(T ele)
		{
			Treenode<T>* node= new Treenode<T>;
			node->Setleft(NULL);
			node->Setright(NULL);
			node->Setdata(ele);
			if(root== NULL)
			{
				root= node;
			}
			else
			{       Treenode<T> *temp = root;
				while(temp!=nullptr)
				{
				     if(ele < temp->Getdata())
				    {
					if(temp->Getleft() == NULL)
					{
						temp->Setleft(node);
						return;
					}
					else
					{
						temp=temp->Getleft();

					}				
				     }
				     else
				     {
					if(temp->Getright() == NULL)
					{
						temp->Setright(node);
						return;
					}
					else
					{
						temp=temp->Getright();

					}				
				     }
				}	     
			}
		}		

		void inorder(Treenode<T>* temp)
		{
			if(temp!=nullptr)
			{
			
			inorder(temp->Getleft());
			cout<<temp->Getdata()<<" ";
			inorder(temp->Getright());
			}
	
		}
			
		void preorder(Treenode<T>* temp)
		{
			if(temp!=nullptr)
			{	
			cout<<temp->Getdata()<<" ";
			preorder(temp->Getleft());
			preorder(temp->Getright());
			}
	
		}
		
		void postorder(Treenode<T>* temp)
		{
			if(temp!=nullptr)
			{
			
			postorder(temp->Getleft());
			postorder(temp->Getright());
			cout<<temp->Getdata()<<" ";
			} 
	
		}

		Treenode<T>* Getroot()
		{
			return root;
		
		}

           void search(T ele)
	   {
	    Treenode<T>* temp=root;
	    while(temp!=nullptr)
	   {
	      if(ele==temp->Getdata())
	      {
	      
	      cout<<"ele found"<<ele;
	      return;
	      }
	      else if(ele<temp->Getdata())
	      {
	         temp=temp->Getleft();
	      }
	      else
	      {
	       temp=temp->Getright();
	      }
	   
	   }
	    cout<<"not found";
       }  

	T Findmin()
	{ 	
		Treenode <T>* temp=root;
		while(temp->Getleft()!=nullptr)
		{
		temp=temp->Getleft();
		}
		cout<<"min is:"<<temp->Getdata();
	
	   
      }
	T Findmax()
	{ 	
		Treenode <T>* temp=root;
		while(temp->Getright()!=nullptr)
		{
		temp=temp->Getright();
		}
		cout<<"max is:"<<temp->Getdata();
	
	   
      }
	void Height()
	{
		
		Treenode<T>* temp=root;
		Treenode<T>* temp1;
		int temp2;
		stack<Treenode<T> *> stk1;
		stack<int> stk2;
		list<int> l1;
		int count=0;
		if(temp == nullptr)
			cout<<"Height 0\n";
		while(1)
		{
		if(temp->Getleft()!=NULL)
		{
				count=count+1;
				if(temp->Getright()!=NULL)
				{
					stk1.push(temp->Getright());
					stk2.push(count);
				}
			temp=temp->Getleft();
			continue;
		}
		if(temp->Getright()!=NULL)

		{
			temp=temp->Getright();
			count=count+1;
			continue;

		}

		l1.push_back(count);
		if(!stk1.empty()) {
		temp = stk1.top();
		stk1.pop();
		count = stk2.top();
		stk2.pop();
		} else {
			break;
		}


		}

		l1.sort();


		cout<<"The Height of BST is "<<l1.back();
	}

	void Delete(T ele)
	{
		Treenode<T>* temp=root;
	    while(temp!=nullptr)
	   {
	      if(ele==temp->Getdata())
	      {
	      cout<<"\n before deleting temp"<<temp->Getdata();
	      
	      temp=NULL;
	      delete temp;
	    //  delete temp->Getright();
	     // delete temp->Getleft();
	     // temp=NULL;
	    //  temp->Setleft(NULL);
	     // temp->Setright(NULL);
	      cout<<"\n After deleting"<<temp->Getdata();
	      return;
	      }
	      else if(ele<temp->Getdata())
	      {
	         temp=temp->Getleft();
	      }
	      else
	      {
	       temp=temp->Getright();
	      }
	   
	   }
	    cout<<" Data is wrong ";

	}
    		
};


int main()
{
	BST<int> b1;

	b1.insert(500);
	b1.insert(501);
	b1.insert(502);
	b1.insert(503);
	b1.insert(504);
	b1.insert(505);
	b1.insert(506);
	b1.insert(507);

	b1.insert(8);
	b1.insert(5);
	b1.insert(3);
	b1.insert(10);
	b1.insert(15);
	b1.insert(16);
	b1.insert(17);
	b1.insert(4);
	b1.insert(9);

	b1.inorder(b1.Getroot());
	cout<<endl;
	b1.preorder(b1.Getroot());
	cout<<endl;
	b1.postorder(b1.Getroot());
	b1.search(44);
	b1.Findmin();
	b1.Findmax();
	b1.Height();
	b1.Delete(504);
	b1.inorder(b1.Getroot());
	cout<<endl;

}


