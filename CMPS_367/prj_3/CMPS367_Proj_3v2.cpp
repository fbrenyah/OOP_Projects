//-------------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-367
//		Project		no. 3 part 2
//		Date		Feb. 26nd, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Get and display the first two char's of a one word state.
//			 Get and display the first char's of each word in a two word state.
//
//		Enter a state name: New Hampshire
//
//				New Hampshire or NH
//				CONTINUE(y/n)? y
//
//		Enter a state name: California
//				California or CA
//				CONTINUE(y/n)? n
//-------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
	
	//declare identifiers
	string  state;
	char	YesNo;

	do {
		// get state name
		cout<<"Enter a state name: ";
		getline(cin, state);
		
		int space=state.find(' ');

		// determine if word is one word or two words
		if(space==-1) {
			// space was not found so must be one word state
			cout<<"\t"<<state<<" or "<<char(toupper(state[0]))<<char(toupper(state[1]))<<endl;
		} else  {
			// space was found so must be two word state
			cout<<"\t"<<state<<" or "<<char(toupper(state[0]))<<char(toupper(state[space+1]))<<endl;
		}	
		cout<<"\tCONTINUE(y/n)? ";
		cin>>YesNo;
		cout<<endl;
		YesNo=toupper(YesNo);

	} while(YesNo=='Y');
	
	//terminate program
	return 0;
}
/*------------output----------------------------------------------------------------------------------
Enter a state name: New Hampshire

        New Hampshire or NH
        CONTINUE(y/n)? y

Enter a state name: California
        California or CA
        CONTINUE(y/n)? n
Press any key to continue
------------------------------------------------------------------------------------------------------*/
