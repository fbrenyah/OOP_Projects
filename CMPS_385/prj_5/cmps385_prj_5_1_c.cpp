//------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.5 part 1(C)
//		Date		Oct. 15th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: The connect two list together and and show how may nodes
//			 are in the newly connected list.
//
//		 The joined list is:
//		        7->5->8->9->3->3->9->8->1->NULL
//		There are (9) nodes in the joined list.
//------------------------------------------------------------------------
#include <iostream>
using namespace std;

struct NODE //STACK-like list
{
	int info;
	NODE *link;
};
int main()
{
	//initialize data source
	int a[5]={3, 9, 8, 5, 7};
	int b[4]={3, 9, 8, 1};

	NODE *stackheader, *newBOX;
	NODE *Qheader, *Qrear;
	NODE *temp;

	//stack linked list
	stackheader=NULL;
	for(int i=0; i<5; i++)
	{
		newBOX = new NODE;
		newBOX->info = a[i];
		newBOX->link = stackheader;
		stackheader = newBOX;
	}

	//queue linked list
	Qheader = NULL; Qrear = NULL;
	for(int i=0; i<4; i++)
	{
		newBOX = new NODE;
		newBOX->info = b[i];
		newBOX->link = NULL;
		if( Qheader==NULL )
		{
			Qheader = newBOX;
			Qrear = newBOX;
		}
		else
		{
			Qrear->link = newBOX;
			Qrear = newBOX;
		}
	}

	temp = stackheader; //a pointer to navigate the list

	//connect the linked lists
	while( temp->link != NULL )
	{
		temp = temp->link;
	}
	temp->link = Qheader;

	//display the connect linked list
	cout<<" The joined list is:\n"; cout<<'\t';
	temp = stackheader;
	while( temp != NULL )
	{
		cout<< temp->info <<"->";
		temp = temp->link;
	}cout<<"NULL \n";

	//count and display the number of nodes in the list
	temp = stackheader;
	int ListSIZE=0;
	while( temp != NULL )
	{
		temp = temp->link;
		ListSIZE++;
	}
	cout<<" There are ("<<ListSIZE<<") nodes in the joined list.\n";

	//end program
	system("PAUSE");
	return 0;
}