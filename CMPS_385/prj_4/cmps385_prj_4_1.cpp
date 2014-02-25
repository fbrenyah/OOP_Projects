//-----------------------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.4 part 1
//		Date		Sep. 26th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Read a postFIX expression and perform the arithmatic.
//
//         A=3     B=11    C=5     D=8
//		Please, enter your expression (ending with a $): ab*c+d-$
//		         Value: 30
//		         CONTINUE: (Y/N)?y
//		Please, enter your expression (ending with a $): aa+c*b-d+$
//		         Value: 27
//		         CONTINUE: (Y/N)?n
//		 Thank you for using this service. Have a great day.
//-----------------------------------------------------------------------------------------
#include <iostream>
#include <cctype>
#include "STACK.h"
using namespace std;
int main()
{
	STACK<int, 50> Q; Q.MakeStack();

	char EXP, YESno;
	int x, y, R;

	//collect the postFIX expression
	cout<<"\t A=3\t B=11\t C=5\t D=8"<<endl;
	
	do{	//collect the postFIX expression.
		cout<<"Please, enter your expression (ending with a $): "; cin.get(EXP);
		while(EXP != '$')
		{
			switch(EXP)
			{ //check values and perform arithmatic
				case 'a': case 'A': Q.PushStack(3);	break;
				case 'b': case 'B': Q.PushStack(11);break;
				case 'c': case 'C': Q.PushStack(5);	break;
				case 'd': case 'D': Q.PushStack(8);	break;
				case '*': x=Q.PopStack(); y=Q.PopStack(); R=y*x; Q.PushStack(R); break;
				case '/': x=Q.PopStack(); y=Q.PopStack(); R=y/x; Q.PushStack(R); break;
				case '+': x=Q.PopStack(); y=Q.PopStack(); R=y+x; Q.PushStack(R); break;
				case '-': x=Q.PopStack(); y=Q.PopStack(); R=y-x; Q.PushStack(R); break;
			default:	break;
			}
			cin.get(EXP);
		}
		cout<<"\t Value: "<<Q.PopStack()<<endl; //display answer

		//ask user to continue
			cout<<"\t CONTINUE: (Y/N)?"; cin>>YESno; YESno = toupper(YESno);
	}while(YESno=='Y');

	cout<<" Thank you for using this service. Have a great day.\n"; //goodbye if YESno = N

	//end program
	system("PAUSE");
	return 0;
}