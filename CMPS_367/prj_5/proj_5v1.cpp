//-------------------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-367
//		Project		no. 5 part 1
//		Date		Mar. 7th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: This program assigns ten random integers to an array of memory "a".
//			 It then displays those assigned numbers, finds and displays the
//			 max and min of those assigned numbers, and lastly, finds the average 
//			 of the assigned numbers and display assigned integer with a value above
//			 that average.
//
//		I have assigned ten random integers to array a
//		Here are the random integers assigned to array a
//		63      84      54      3       26      44      85      22      48      36
//
//		The minimum of array a is 3
//		The maximum of array a is 85
//		Above average integers are
//		63      84      54      85      48
//------------------------------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//functions prototypes
void Assign(int x[]);
void Display(int x[]);
void FindMaxMin(int x[], int& high, int& low);
void Display(int high, int low);
float FindAve(int x[]);
void Display(int x[], float ave);

int main()
{
	 int a[10];
	//Assign 10 random integers between 1 and 100 to array a
	 Assign(a);

	//Display array a
	 Display(a);

	//Find the maximum and minimum numbers in arry a
	 int max, min;
	 FindMaxMin(a, max, min);

	//Show the max and min values. Overload the Display function
	 Display(max, min);

	//Find the average of numbers in array a
	 float Average=FindAve(a);

	//display the numbers in array a whose value is above average. Overload
	//this display function again
	 Display(a, Average);

	//terminate program
	 system("pause");
	 return 0;
}
//-------------------------------------
//Name: Assign
//Purpose: Assign ten random numbers
//to array a
//---------------------------------------------------------------
void Assign(int x[])
{
	cout<<"I have assigned ten random integers to array a\n";
	srand( time(0) );
	for(int i=0; i < 10; ++i)
	{
		int y=rand()%100+1;
		x[i]=y;
	}
}
//---------------------------------------------------------------
//Name: Display (Overloaded)
//Purpose: Show what is in array a
//---------------------------------------------------------------
void Display(int x[])
{
	cout<<"Here are the random integers assigned to array a\n";
	for(int i=0; i < 10; ++i)
	{
		cout<<x[i]<<'\t';
	}
	cout<<endl;
}
//--------------------------------------------------------------
//Name: FindMaxMin
//Purpose: Find max and min of the
//data in array a
//----------------------------------------------
void FindMaxMin(int x[], int& high, int& low)
{
	high=x[0];
	low=x[0];
	for(int i=1; i<10; ++i)
	{
		if(x[i] > high)
		{ 
			high = x[i];
		}
		else if(x[i] < low)
		{
			low = x[i];
		}
	}
}
//-------------------------------------------------
//Name: Display (Overloaded)
//Purpose: Display max and min of the
//data in array a
//-------------------------------------------------
void Display(int high, int low)
{
	cout<<"The minimum of array a is "<<low<<endl;
	cout<<"The maximum of array a is "<<high<<endl;
}
//-------------------------------------------------
//Name: FindAve
//Purpose: Find the average of the intergers
//------------------------------------------------
float FindAve(int x[])
{
	int total=0;
	for(int i=0; i<10; ++i)
	{
		total+=x[i];
	}
	return total/10.;
}
//------------------------------------------
//Name: Display (Overloaded)
//Purpose: Show numbers i array a
//whose value is above average
//------------------------------------------
void Display(int x[], float ave)
{
	int total=0;
	for(int i=0; i<10; ++i)
	{
		total+=x[i];
	}
	ave = total/10.;

	cout<<"Above average integers are\n";
	for(int i=0; i<10; ++i)
	{
		if(x[i] > ave)
		{
			cout<<x[i]<<'\t';
		}
	}
	cout<<endl;
}
/*----------output-------------------------------------------------------------
I have assigned ten random integers to array a
Here are the random integers assigned to array a
63      84      54      3       26      44      85      22      48      36

The minimum of array a is 3
The maximum of array a is 85
Above average integers are
63      84      54      85      48
Press any key to continue . . .
------------------------------------------------------------------------------*/