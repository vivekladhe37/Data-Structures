#include<iostream>
#include"NodeLink.cpp"
//#include"Node.cpp"
template <class T>
class LLofLL
{	
       NodeLink<T>* headL;
       NodeLink<T>* tailL;
	public:
         void Addatend1(Node<T>* t)
        {
                NodeLink<T>* temp=new NodeLink<T>;
                temp->SetheadL(t);
                temp->SetnextL(nullptr);
                if(headL==nullptr && tailL==nullptr)
                {
                        headL=tailL=temp;
                       
                }
                else
                {       
                
                        //tailL->Sethead(t);
                        //tail->Setnext(nullptr);
                        tailL->SetnextL(temp);
                        tailL=temp;
                }
        }



//friend istream& operator>>(istream& input, Linkedlist& l);
	
//friend ostream& operator<<(ostream& output,const Linkedlist& l);

};
int main()
{
        Linkedlist<int> l1;
        l1.Addatend(10);
        l1.Addatend(20);
        l1.Addatend(30);
        Linkedlist<int> l2;
        l2.Addatend(10);
        l2.Addatend(20);
        l2.Addatend(30);
        Linkedlist<int> l3;
        l3.Addatend(10);
        l3.Addatend(20);
        l3.Addatend(30);
        l1.Display();
        //Linkedlist<>ll;
        ll.Addatend1(l1);

        //Linkedlist<NodeLink> l;
        //l.Addatend1(l1.Gethead());
        //l.Display();
//      l.Addatend1(l2);
//      l.Addatend1(l3);
        return 0;

}



/*ostream& operator<<(ostream& output,const Linkedlist& l)
{
  output<<l.;
}

 istream& operator>>(istream& input, Linkedlist& l)
{
   
   input>>l.
}*/
