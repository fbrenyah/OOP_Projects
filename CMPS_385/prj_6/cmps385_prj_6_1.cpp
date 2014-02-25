//-----------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.6 part 1
//		Date		Oct. 22nd, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Check to see if a word, phrase, or sentence is a palindrome
//
//		Enter a sentence/phrase: backpack
//		sorry, that's not a palindrome.
//		        CONTINUE (Y/N)? n
//
//		Enter a sentence/phrase: do geese see god
//		Hey! That's a PALINDROME.
//		        CONTINUE (Y/N)? n
//-----------------------------------------------------------------------
#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;
//
struct NODE
{
	char info;
	NODE* link;
};
int main()
{
	NODE *stackheader, *Qheader, *Qrear;
	NODE *newBOX;

	stackheader = NULL; 
	Qheader = Qrear = NULL;

	char checkLIST_one, checkLIST_two;
	char letter;
	char YESno;
	
	do{
		cout<<"Enter a sentence/phrase: "; 
		while( cin.get(letter), letter != '\n' )
		{
			//intialize node
			if( isalpha(letter) )
			{
				letter = toupper( letter );
				newBOX = new( NODE );
				newBOX->info = letter;
				newBOX->link = NULL;
				//build queue list
				if(Qheader == NULL)
				{
					Qheader = newBOX;
					Qrear = newBOX;
				}
				else
				{
					Qrear->link = newBOX;
					Qrear = newBOX;
				}
			}//end if
		}//end while
	
		//build stack list
		 NODE* P = Qheader;
		 while( P!=NULL )
		 {
			newBOX = new( NODE );
			newBOX->info = P->info;
			newBOX->link = stackheader;
			stackheader = newBOX;
			P = P->link;
		}
	
		//check for palindrome (part 1)
		NODE *K;
		P = stackheader; K = Qheader;
		while( P != NULL) //move to pointer to stack end
		{
			checkLIST_one = P->info;
			checkLIST_two = K->info;
	
			if( checkLIST_one == checkLIST_two ) break;
			//
			else
			{
				P = P->link; K = K->link;
			}
		}//end while

		//check for palindrome (part 2)
		if( checkLIST_one == checkLIST_two )
		{
			cout<<" Hey! That's a PALINDROME. \n";
		}
		else
		{
			cout<<"sorry, that's not a palindrome. \n";
		}
		cout<<"\tCONTINUE (Y/N)? ";
		cin>>YESno; YESno = toupper( YESno ); cout<<endl;
    }while(YESno == 'Y' );

	//end program
	system("PAUSE");
	return 0;
}