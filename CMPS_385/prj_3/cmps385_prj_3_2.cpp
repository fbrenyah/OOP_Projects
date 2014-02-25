//---------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.3 part 2
//		Date		Sep. 22nd, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Read 10 integers and organize them into EVEN or ODD.
//
//		Please, enter 10 numbers: 1 2 3 4 5 6 7 8 9 10
//		  The EVEN numbers: 2  4  6  8  10
//		  The ODD numbers: 1  3  5  7  9
//---------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include "STACK.h" //user defined stack
using namespace std;
//
int main() 
{
	//declare object(s) and make stack(s).
	STACK<int, 10> EVEN, ODD; 
	EVEN.MakeStack(); 
	ODD.MakeStack();
	
	int IntNum=0;

	//collect the integer numbers.
	cout<<"Please, enter 10 numbers: ";
	for(int j=1; j<=10; ++j)
	{
		cin>>IntNum; //read FIRST number
		if( (IntNum % 2) == 0 )
			EVEN.PushStack(IntNum);
		else 
			ODD.PushStack(IntNum);
		IntNum=IntNum/2;
	}
	//push into another stack to reverse
	STACK<int, 10> TEMP; //to reverse EVEN and ODD to be in order
	TEMP.MakeStack();

	//display EVEN numbers
	int display=0;
	while( !EVEN.EmptyStack() )
	{
		display=EVEN.PopStack();
		TEMP.PushStack(display);
	}
	cout<<"  The EVEN numbers: ";
	while( !TEMP.EmptyStack() )
		cout<<TEMP.PopStack()<<"  ";
	cout<<endl;
	
	//display ODD numbers
	display=0;
	while( !ODD.EmptyStack() )
	{
		display=ODD.PopStack();
		TEMP.PushStack(display);
	}

	cout<<"  The ODD numbers: ";
	while( !TEMP.EmptyStack() )
		cout<<TEMP.PopStack()<<"  "; 
	cout<<endl;

	//end program
	system("PAUSE");
	return 0;
}