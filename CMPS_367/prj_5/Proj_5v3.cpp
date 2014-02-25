//-------------------------------------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-367
//		Project		no. 5 part 3
//		Date		Mar. 8th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Help the user determine what to do next of five options:
//			 Study, Go see a movie, Stay Home, Call a friend, or Go to Las Vegas.
//
//			    Go to Las Vegas
//			            CONTINUE(y/n)? y
//			    Study
//						CONTINUE(y/n)? y
//				Stay Home
//		                CONTINUE(y/n)? n
//------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

int main()
{
	string Future[5]={"Study", "Go see a movie", "Stay Home", "Call your friend", "Go to Las Vegas"};
	int x;
	char YesNo;
	do{

		for(int i=1; i<=4; ++i)
		{
			srand( time(0) );
			{
				x=rand()%5;
			}
		}

		if(x==0)
		  cout<<'\t'<<Future[0]<<endl; 
		else if(x==1)
		  cout<<'\t'<<Future[1]<<endl; 
		else if(x==2)
		  cout<<'\t'<<Future[2]<<endl; 
		else if(x==3)
		  cout<<'\t'<<Future[3]<<endl; 
		else if(x==4)
		  cout<<'\t'<<Future[4]<<endl; 

		cout<<"\t\tCONTINUE(y/n)? "; cin>>YesNo;
		YesNo=toupper(YesNo);
	}while(YesNo=='Y');

	//terminate program
	system("pause");
	return 0;
}
/*---------output-------------------------------------------------------------------------------
        Go to Las Vegas
                CONTINUE(y/n)? y
        Study
                CONTINUE(y/n)? y
        Stay Home
                CONTINUE(y/n)? n
Press any key to continue . . .
------------------------------------------------------------------------------------------------*/