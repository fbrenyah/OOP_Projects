//-----------------------------------------------------------------------
//		Name		Frank	Brenyah
//		Course		CMPS-367
//		Project		no. 4 part 1
//		Date		Feb. 29th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: To get two friends info and determine things like if they
//			 are a teenager and who's age is above the  average age.
//
//		Enter two friend's age: 27 19
//
//		Enter two friend's name: Bill John
//
//		           Name Age
//				-----------------
//		           Bill 27
//		           John 19
//		Lets see if Bill is a teenager
//				Bill, you are not a teenager
//		Lets see if John is a teenager
//				John, you are a teenager
//		My friends age average is 23
//		Bill your age is above average
//-----------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
//
//declaring functions to compiler
/*---------------------------------------------------------------*/
template<class TYPE1, class TYPE2>
void ReadData(TYPE1& num1, TYPE2& num2);
/*---------------------------------------------------------------*/
template<class TYPE1, class TYPE2, class TYPE3, class TYPE4>
void Display(TYPE1 a, TYPE2 b, TYPE3 num1, TYPE4 num2);
/*---------------------------------------------------------------*/
template<class TYPE1, class TYPE2>
void AreYouTeen(TYPE1 a, TYPE2 num1);
/*---------------------------------------------------------------*/
template<class TYPE1, class TYPE2>
float FindAgeAve(TYPE1 num1, TYPE2 num2);
/*---------------------------------------------------------------*/
template<class TYPE1, class TYPE2, class TYPE3, class TYPE4>
void Display(TYPE1 num1, TYPE2 num2, TYPE3 a, TYPE4 b, float Ave);
/*---------------------------------------------------------------*/
//
int main()
{
	//read the age of two  friends. ReadData is a template function
		int Age1, Age2;
		cout<<"Enter two friend's age: "; ReadData(Age1, Age2);

	//read their names
		string name1, name2;
		cout<<"Enter two friend's name: "; ReadData(name1, name2);

	//Display all data, Display is an overloaded function
		Display(name1, name2, Age1, Age2);

	//determine if your friends are teenagers or not.
		cout<<"Lets see if "<<name1<<" is a teenager\n";
		AreYouTeen(name1, Age1);
		cout<<"Lets see if "<<name2<<" is a teenager\n";
		AreYouTeen(name2, Age2);

	//compute your friends age average
		float AgeAve=FindAgeAve(Age1, Age2);

	//Display the name of a friend whose age is above average
		Display(Age1, Age2, name1, name2, AgeAve);

	//terminate program
		return 0;
}
/*-------------------------------------------*/
template<class TYPE1, class TYPE2>
void ReadData(TYPE1& num1, TYPE2& num2)
{
	cin>>num1>>num2;
	cout<<endl;
}
/*-------------------------------------------*/
template<class TYPE1, class TYPE2, class TYPE3, class TYPE4>
void Display(TYPE1 a, TYPE2 b, TYPE3 num1, TYPE4 num2)
{
	cout<<"\t   Name\tAge   \n";
	cout<<"\t-----------------\n";
	cout<<"\t   "<<a<<"\t"<<num1<<endl;
	cout<<"\t   "<<b<<"\t"<<num2<<endl;
}
/*------------------------------------------------*/
template<class TYPE1, class TYPE2>
void AreYouTeen(TYPE1 a, TYPE2 num1)
{
	if(num1 > 19)
	{ cout<<"\t"<<a<<", you are not a teenager\n"; }
	else
	{ cout<<"\t"<<a<<", you are a teenager\n"; }
}
/*----------------------------------------*/
template<class TYPE1, class TYPE2>
float FindAgeAve(TYPE1 num1, TYPE2 num2)
{
	return (num1 + num2)/2.;
}
/*--------------------------------------------------------*/
template<class TYPE1, class TYPE2, class TYPE3, class TYPE4>
void Display(TYPE1 num1, TYPE2 num2, TYPE3 a, TYPE4 b, float Ave)
{
	if(num1 > Ave)
	{ cout<<a<<" your age is above average\n"; }
	else if(num2 > Ave)
	{ cout<<b<<" your age is above average\n"; }
	cout<<"My friends age average is "<<Ave<<endl;
}
/*--------------------------------------------------------*/
//
/*------------output---------------------------------------------
Enter two friend's age: 27 19

Enter two friend's name: Bill John

           Name Age
        -----------------
           Bill 27
           John 19
Lets see if Bill is a teenager
        Bill, you are not a teenager
Lets see if John is a teenager
        John, you are a teenager
My friends age average is 23
Bill your age is above average
Press any key to continue
---------------------------------------------------------------*/
