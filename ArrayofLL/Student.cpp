#include<iostream>

using namespace std;
class Student
{
  int  roll;
  string name;
	public:
  Student(){roll = 0;
	  name="abc";
  }

/*  int getroll()
  {
  return roll;
  }
  void setroll( int r)
  {
  	roll=r ;
  }*/
 friend ostream& operator<<(ostream& output,const Student& s1);

friend istream& operator>>(istream& input, Student& s1);




};
ostream& operator<<(ostream& output,const Student& s1)
{
	cout << s1.roll;
	cout << s1.name;
	return output;
}
istream& operator>>(istream& input ,Student& s1)
{
	cout << "roll number is: ";
	input>>s1.roll;
	cout << "name is: ";
	input>>s1.name;
	return input;
}
