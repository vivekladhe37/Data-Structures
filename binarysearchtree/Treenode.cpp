#include<iostream>
using namespace std;
template<class T>

class Treenode
{
	private:
		T data; 
		Treenode* left;
		Treenode* right;
	public:
		void Setdata(T ele)
		{
			data=ele;
		}

		void Setleft(Treenode* temp)
		{
			left= temp;
		}

		void Setright(Treenode* temp)
		{
			right= temp;
		}

		 Treenode<T>* Getleft()
		{
			return left;
		}

		 Treenode<T>* Getright()
		{
			return right;
		}
 	
		T Getdata()
		{
			return data;
		}			
};








