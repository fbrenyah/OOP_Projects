//-------------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.7 part 1
//		Date		Oct. 27th, 2012
//		Professor	Ray Ahmadnia
//	
//	Purpose: Generate ten random numbers under fifty and use it to build a
//			 linked list. Secondly, we want to display the odd and even 
//			 numbers, the maximum and minimum numbers, and display and 
//			 compute the average of all the numbers in the linked list.
//------------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//
struct NODE
{
	int info;
	NODE* next;
};
//functions prototype
void insert(NODE*&LIST, int ran);
void DisplayODD(NODE*&LIST);
void DisplayEVEN(NODE*&LIST);
void DisplayMaxMin(NODE*&LIST);
float ComputeAve(NODE*&LIST);
void Display(float& average);
//
int main()
{
	NODE* list; list=NULL; float Ave;
	
	//insert 10 random numbers <50 in an ordered linked list
	cout<<"Generating numbers...\n"; 
	int x=0;
	srand( time(0) );
	for(int i=0; i<10; i++)
	{
		x = rand()%50;
		insert( list, x );
	}
	cout<<"\tDONE.\n";
	//display all EVEN numbers followed by all ODD numbers
	cout<<"\tThe odd number list is: "; DisplayODD(list); 
	cout<<"\tThe even number list is: "; DisplayEVEN(list);

	//display the largest and smallest number
	DisplayMaxMin(list);

	//compute and display the average of a ll numbers
	Ave = ComputeAve(list);
	Display(Ave);

	//end program
	system("PAUSE");
	return 0;
}
//functions
void insert(NODE*&LIST, int ran)
{
	NODE *P, *Q, *T;

	T = new(NODE);
	T->info = ran;
	if(LIST==NULL)
	{
		T->next = NULL; LIST = T;
	}
	else
	{
		P=Q = LIST;
		while( P!=NULL && P->info < T->info )
		{
			Q = P; P = P->next;
		}
		if(P==NULL)
		{
			P->next = T; LIST = T;
		}
		else
		{
			Q->next = T; T->next = P;
		}
	}
}
void DisplayODD(NODE*&LIST)
{
	NODE *P;
	P = LIST;
	while( P!=NULL )
	{
		if( (P->info % 2) == 1)
			cout<<P<<"->"; 
		P = P->next;
	}
	cout<<"NULL\n";
}
void DisplayEVEN(NODE*&LIST)
{
	NODE *P;
	P = LIST;
	while( P!=NULL )
	{
		if( (P->info % 2) == 0 )
			cout<<P<<"->"; 
		P = P->next;
	}
	cout<<"NULL\n";
}
void DisplayMaxMin(NODE*&LIST)
{
	NODE *P, *Q;
	P = LIST;
	int max, min;
	max=min=P->info; Q=LIST->next;
	while( Q!=NULL )
	{
		if( Q->info > max )
			max = Q->info;
		else if( Q->info < min )
			min = Q->info;
		Q = Q->next;
	}
	cout<<"\tThe maximum is: "<<max<<endl;
	cout<<"\tThe minimum is: "<<min<<endl;
}
float ComputeAve(NODE*&LIST)
{
	NODE *P;
	P = LIST;
	int total=0; int counter=0;
	while( P!=NULL )
		total += P->info; counter++; P = P->next;
	float ave = total/counter;
	return ave;
}
void Display(float& average)
{
	cout<<"\tThe average is: "<<average<<endl;
}
//end functions