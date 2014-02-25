//-------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.5 part 1(A)
//		Date		Oct. 9th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Collect data into nodes and store it like a STACK would.
//			 Then display it, compute its contents total, and determine
//			 how many nodes are in the linked list.
//
//		Contents in stack-like list:
//		        7->5->8->9->3->NULL
//------------------------------------------------------------------------
#include <iostream>
using namespace std;
//declare struct for point-implementation of STACK
struct NODE
{
	int info;
	NODE *link;
};
int main()
{
	//declare and initialize source of data
	int a[5]={3, 9, 8, 5, 7};
	
	//declare and intialize nodes
	NODE *firstBOX, *newBOX;
	firstBOX=NULL;
	
	for(int i=0; i<5; i++)
	{
		newBOX = new NODE;
		newBOX->info = a[i];
		newBOX->link = firstBOX;
		firstBOX = newBOX;
	}

	//print the list
	cout<<'\n';
	cout<<"Contents in stack-like list:\n";
	cout<<'\t';
	while( newBOX != NULL )
	{
		cout<< newBOX->info <<"->";
		newBOX = newBOX->link;
	}cout<<"NULL"<<endl;

	//end program
	system("PAUSE");
	return 0;
}