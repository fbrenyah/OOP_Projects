//-----------------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.4 part 2
//		Date		Sep. 27th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Read a sentence and determin if it is a palindrome.
//
//		Enter your sentence: candy
//		 ...sorry, that's not a palindrome.
//		         CONTINUE(Y/N)? :n
//
//		Enter your sentence: RaceCar
//		 WHOAH! It's a PALINDROME!
//		         CONTINUE(Y/N)? :n
//-----------------------------------------------------------------------------------
#include <iostream>
#include "STACK.h"
#include <cctype>
#include <iomanip>
using namespace std;
int main()
{
	STACK<char, 100> LeRi, RiLe, TEMP;
	LeRi.MakeStack(); RiLe.MakeStack(); TEMP.MakeStack();

	bool x; //value to cmp with.
	char check1, check2; //value to cmp with
	char SENT, YESno;

	do{
		cout<<"Enter your sentence: "; //collect sentence
			while( cin.get(SENT), SENT != '\n')
			{
				if( isalpha(SENT) )
				{	SENT=toupper(SENT); LeRi.PushStack(SENT); TEMP.PushStack(SENT);	}
			}		
			while( !TEMP.EmptyStack() )
			{
				SENT = TEMP.PopStack();
				RiLe.PushStack(SENT); //passing TEMP<> to RiLe<>.
			}
			while( !LeRi.EmptyStack() )
			{
				check1=LeRi.PopStack();
				check2=RiLe.PopStack();
				
				if(check1!=check2)
					x=false;
				else
					x=true;
			}			
			if(x==true)
				cout<<" WHOAH! It's a PALINDROME!\n";
			else
				cout<<" ...sorry, that's not a palindrome.\n";
					
			cout<<"\t CONTINUE(Y/N)? :"; cin>>YESno; YESno = toupper(YESno);

	}while(YESno=='Y');

			//end program
			system("PAUSE");
			return 0;
}