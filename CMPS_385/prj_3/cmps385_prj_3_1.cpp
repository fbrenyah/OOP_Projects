//-----------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.3 part 1
//		Professor	Ray Ahmadnia
//		Date		Sep. 20th, 2012
//
//	Purpose: Read a positive integer and convert it to base 2, 8, and 16.
//
//		Please, enter a positive integer number (limit: 239)...163
//				163 at base 2 is 10100011
//				163 at base 8 is 243
//				163 at base 16 is A3
//-----------------------------------------------------------------------
#include <iostream>
#include "STACK.h" //user defined stack
using namespace std;
//
int main() 
{
	//declare object(s) of the stack.
	STACK<int, 20> P; 
	int OrgNum=0;
	P.MakeStack();
	
	//collect the integer (orginal)number.
	cout<<"Please, enter a positive integer number (limit: 239)..."; cin>>OrgNum;
	
	//copy of orignal number to base 2
	cout<<'\t'<<OrgNum<<" at base 2 is ";

	int base2TEMP=0; //a temporary variable to hold (num1 % 2).
	int num2 = OrgNum; //FIRST COPY of OrgNum.
	while( num2 !=0  ) //while there is a number to divide, push.
	{	
		base2TEMP = num2 % 2;
	    	P.PushStack(base2TEMP);
	    	num2=num2/2;
	}
	while( !P.EmptyStack() ) //while the stack is not empty, pop stack.
		cout<<P.PopStack();
	cout<<endl;

	//new stack
	STACK<int, 20> Q;
	Q.MakeStack();

	//copy of orignal number at base 8
	cout<<'\t'<<OrgNum<<" at base 8 is ";
	
	int base8TEMP=0; 
	int num3 = OrgNum; //SECOND COPY of OrgNum.
	while( num3 != 0 )
	{	
		base8TEMP = num3 % 8;
		Q.PushStack(base8TEMP);
		num3=num3/8;
	}
	while( !Q.EmptyStack() )
		cout<<Q.PopStack();
	cout<<endl;

	//new stack
	STACK<int, 20> F;
	F.MakeStack();
	//copy of original number at base 16
	cout<<'\t'<<OrgNum<<" at base 16 is ";

	int base16TEMP=0;
	int num4=OrgNum; //THIRD COPY of OrgNum.
	while( num4!=0 )
	{	
		base16TEMP = num4 % 16;
		F.PushStack(base16TEMP);
		num4=num4/16;
	}
	while( !F.EmptyStack() )
	{
		num4=F.PopStack();
		switch(num4) //check to convert to alpha.
		{
			case 10: cout<<'A'; break;
			case 11: cout<<'B'; break;
			case 12: cout<<'C'; break;
			case 13: cout<<'D'; break;
			case 14: cout<<'E'; break;
			case 15: cout<<'F'; break;
			default: cout<<num4;
		}
	}
	cout<<endl;

	//end program
	system("PAUSE");
	return 0;
}