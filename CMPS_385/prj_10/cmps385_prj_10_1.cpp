//----------------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.10
//		Date		Nov. 26th, 2012
//		Professor	Ray	Ahmadnia
//
//	Purpose: Build a Hash organized by the number of months in a month, display
//			 it, and allow for searching the Hash.
//---------------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
//
struct NODE
{
	string Name;
	int Days;
	NODE* link;
};
//
void Intialize_HASH( NODE* H[] )
{//set HASH table to NULL.
	for(int i=0; i<4; i++)
		H[i] = NULL;
}
//
int HASH_funct( int a )
{//get last digit of number.
	return ( a % 10 );
}
//
void Insert( NODE* H[], string x, int y )
{//insert Month and Days into HASH.
	int i = HASH_funct( y );

	NODE *P; P = new( NODE );
	P->Name = x; P->Days = y; 
	P->link = H[i];
	H[i] = P;
}
//
void Display( NODE* H[] )
{//Display HASH table a row at a time.
	NODE* P;
	for(int i=0; i<4; i++)
	{
		P = H[i];
		while( P != NULL )
			cout<< P->Name <<"|"<< P->Days <<"-> "; P = P->link;
		cout<<"NULL\n";
	}
}
//
void Search_HASH( NODE* H[], string a )
{//Search for a.
	NODE* Q;
	for(int k=0; k<4; k++)
	{
		Q = H[k];
		while( Q->Name != a )
			Q = Q->link;
	}
	int x; Q->Days = x;

	int i = HASH_funct( x );
	NODE* P = H[i];

	while( P != NULL && P->Days != x )
		P = P->link;

	if( P == NULL )
		cout<<"Sorry, "<< a <<" does not exist!\n";
	else
		cout<< a <<" has <<.\n";
}
int main()
{
	//intialize key components
	NODE* M[4];
	Intialize_HASH(M);
	string month[13]={"JAN", "FEB", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
	int days[13]={31, 29, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
	string choice;

	//build the Hash table
	for(int i=0; i<13; i++)
		Insert( M, month[i], days[i]);

	//display Hash table.
	Display(M);

	//find the number of days in a month
	cout<<"\tPlease, enter the first three letters of the month your looking for: ";
	cin>>choice;

	Search_HASH( M, choice );

	system("PAUSE");
	return 0;
}