
//#include"stack.cpp"
#include"Stack.h"

int main()
{
int  n,ch,a;
 float y,x,z;
cout<<"Enter size of array";
cin>>n;
Stack<float>st(n);
/* int i=0;
 while(n!=0)
 { 
  int rem=n%16;
 // p =rem*pow(8,i);
if (rem>9)
{   rem-=10;
rem+=65;
  st.push(rem);
  count++;
}
else
{
st.push(rem+48);
  count++;
  //n=n/10;
 // i++;
 }
n=n/16;
}
 cout<<"Binary conversion is:";
 while(count--)
 {
 y =st.pop();
cout<<y;
 }
 //cout<<y;

 /*try{
 st.push(11);
int x= st.pop();
cout<<"poped element is"<<x<<endl;

 st.push(21);
 st.push(31);
 st.push(41);
 st.push(51);
st.pop();
st.push(61);
st.push(71);
int y=st.peep();
cout<<y;
//st.push(81);
 }

 catch( runtime_error e)
 {
   cout<<e.what();
 
 }
 st.display();*/
 do
 {
 cout<<"1.Push\t2.Pop\t3.Peep";
 cout<<"Enter the choice";
 cin>>ch;
cin.get();
 switch(ch)
 {
	case 1: cout<<"Enter the element to push";
		cin>>x;
		st.push(x);
		break;
	case 2:  y=st.pop();
 		cout<<"poped element is"<<y;
		 break;
	case 3: z=st.peep();
		cout<<"Element on top is:"<<z;
		break;
	default:cout<<"Invalid choice"; 	

 
 }
   cout<<"Do u want to continue: press 1";
   cin>>a;
 }while(a==1);

return 0;

}
