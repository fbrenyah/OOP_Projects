//----------------------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.3 part 4
//		Date		Sep. 23rd, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Read a sentence and display only the letters of it, backwards.
//
//		Please, type a sentence: My name is "FRANK", and this code works $$$.
//		skrowedocsihtdnaKNARFsiemanyM
//----------------------------------------------------------------------------------------
#include <iostream>
#include "STACK.h"
using namespace std;
//
int main() 
{
	//declare objects of stack
	STACK<char, 100> P;
	char SENT;
	P.MakeStack();

	//collect the sentence
	cout << "Please, type a sentence: "; cin.get(SENT); //read first character

	//collect the sentence a character at a time
	while( SENT!='\n' )
	{	
		if( isalpha(SENT) )
			P.PushStack(SENT);
		
		cin.get(SENT); //get next character
	}

	//display sentence in reverse (*reverse is normal in stack*)
	while( !P.EmptyStack()!='\0' )
		cout<<P.PopStack();
	cout<<endl;

	//end program
	system("PAUSE");
	return 0;
}