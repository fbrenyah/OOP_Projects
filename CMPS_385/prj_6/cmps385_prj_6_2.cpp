//---------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.6 part 2
//		Date		Oct. 22nd, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Get the union of two integer linked lists.
//--------------------------------------------------------------------
#include <iostream>
using namespace std;
//
struct NODE
{
	int info;
	NODE *link;
};
//---functions--------------------------------------------------------
void insert(NODE*& List, int x)
{
	NODE *P, *Q, *T; //P & Q are pointers, T=new node

	T = new( NODE );
	T->info = x;

	if( List == NULL )
	{
		T->link = NULL; List = T;
	}
	else
	{
		P=Q = List;
		while( P != NULL, P->info < T->info )
		{
			Q = P; P = P->link;
		}
		if( P == List )
		{
			T->link = P; List = T;
		}
		else
		{
			T->link = P; Q->link = T;
		}
	}
}
//
void Display(NODE*& List)
{
	NODE *P;
	P = List;
	while( P != NULL )
	{
		cout<< P->info <<"->";
		P = P->link;
	}cout<<"NULL\n";
}
//--------------------------------------------------------------------
int main()
{
	NODE *A, *B, *AUB;
	A=B=AUB = NULL;

	//initialize data source(s)
	int setA[4]={3, 9, 6, 8};
	int setB[7]={17, 19, 2, 6, 4, 1, 3};

	//build two ordered linked list, A & B
	for(int i=0; i<4; i++)
	{
		insert( A, setA[i] );
	}
	for(int i=0; i<7; i++)
	{
		insert( B, setB[i] );
	}

	//build a union list from lists A & B
	while(  A != NULL, A != NULL )
	{
		if( B->info < A->info )
		{
			insert( AUB, B->info );
			B = B->link;
		}
		else if( B->info == A->info )
		{
			insert( AUB, B->info );
			B = B->link; A = A->link;
		}
		else
		{
			insert( AUB, A->info );
			A = A->link;
		}
	}//end while
	while( A != NULL )
	{
		insert( AUB, A->info );
		A = A->link;
	}
	while( B != NULL )
	{
		insert( AUB, B->info );
		B = B->link;
	}
	
	//display A list
	Display(A);

	//display B list
	Display(B);

	//display AUB list
	Display(AUB);

	//end program
	system("PAUSE");
	return 0;
}