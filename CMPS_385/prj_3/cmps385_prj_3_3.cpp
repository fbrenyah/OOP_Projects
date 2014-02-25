//---------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.3 part 3
//		Date		Sep. 24th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Read a sentence and make from it, a list of uppercase letters,
//			 lowercase letters, and vowel letters.
//
//		Please, enter a sentence: Today is Mon Sep 24 YES!
//		 Uppercase letters: S E Y S M T
//		 Lowercase letters: p e n o s i y a d o
//		 Vowel letters: E e o i a o
//----------------------------------------------------------------------
#include <iostream>
#include "STACK.h"
using namespace std;
//
int main() 
{
	//declare object(s) and creat stack(s).
	STACK<char, 100> UPcase, LWcase, VOW;
	UPcase.MakeStack();
	LWcase.MakeStack();
	VOW.MakeStack();
	char SENT;

	cout<<"Please, enter a sentence: "; cin.get(SENT); //read first character
do{  //check if uppercase, lowercase, or vowel.
		if( isupper(SENT) )
			UPcase.PushStack(SENT);
		if( islower(SENT) )
			LWcase.PushStack(SENT);
		
		switch(SENT) 
		{
			case 'A': case 'a': VOW.PushStack(SENT); break;
			case 'E': case 'e': VOW.PushStack(SENT); break;
			case 'I': case 'i': VOW.PushStack(SENT); break;
			case 'O': case 'o': VOW.PushStack(SENT); break;
			case 'U': case 'u': VOW.PushStack(SENT); break;
		default:	break;
		}
		cin.get(SENT); //get next character.
	}while( SENT!='\n' );

	//display while content in stack doesnt stop.
	cout<<"  Uppercase letters: ";
	while( !UPcase.EmptyStack()!='\0' )
		cout<<UPcase.PopStack()<<" ";
	cout<<endl;

	cout<<"  Lowercase letters: ";
	while( !LWcase.EmptyStack()!='\0' )
		cout<<LWcase.PopStack()<<" ";
	cout<<endl;

	cout<<"  Vowel letters: ";
	while( !VOW.EmptyStack()!='\0' )
		cout<<VOW.PopStack()<<" ";
	cout<<endl;
	
	//end program
	system("PAUSE");
	return 0;
}