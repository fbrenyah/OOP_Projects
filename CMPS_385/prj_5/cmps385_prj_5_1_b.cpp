//------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.5 part 1(B)
//		Date		Oct. 10th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Build a list in queue form.
//
//		 Contents in queue-like list:
//		        3->9->8->1->
//------------------------------------------------------
#include <iostream>
using namespace std;
//declare struct for pointer-implementation of queue
struct NODE
{
	int info;
	NODE *link;
};
int main()
{
	//declare and initialize data source
	int b[4]={3, 9, 8, 1};

	//declare and initialize nodes
	NODE *firstBOX, *lastBOX, *newBOX;
	firstBOX=NULL; lastBOX=NULL;
	//build list and display list simultaneously
	cout<<'\n';
	cout<<" Contents in queue-like list:\n";
	cout<<'\t';
	for(int i=0; i<4; i++)
	{
		newBOX = new NODE;
		newBOX->info = b[i];
		newBOX->link = NULL;
		if(firstBOX==NULL)
		{
			firstBOX=newBOX;
			lastBOX=newBOX;
		}
		else
		{
			lastBOX->link = newBOX;
			lastBOX = newBOX;
		}
		cout<< newBOX->info <<"->";
	}cout<<endl;

	//end program
	system("PAUSE");
	return 0;
}