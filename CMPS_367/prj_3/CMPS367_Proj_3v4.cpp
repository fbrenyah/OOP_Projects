//--------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS 367
//		Project		no.3 part 4
//		Date		Feb. 21st, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Get three integers and display the max, min, 
//			 and average of all three.
//
//		Enter three integer numbers: 5 10 20
//		 For the three numbers: 5, 10, and 20
//		        Average= 11.6667
//		        Maximum= 20
//		        Minimum= 5
//------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
/*------------------------------------------------------------*/
void ReadData(int& a, int& b, int& c)
{
	cout<<"Enter three integer numbers: ";
	cin>>a>>b>>c;
}
/*------------------------------------------------------------*/
int ComputeSum(int a, int b, int c)
{
	return a+b+c;
}
/*------------------------------------------------------------*/
float ComputeAverage(int a, int b, int c, int sum)
{
	return sum/3.;
}
/*----------------------------------------------------------------------*/
void Display(int a, int b, int c, float ave)
{
	cout<<" For the three numbers: "<<a<<", "<<b<<", and "<<c<<endl;
	cout<<"\tAverage= "<<ave<<endl;
}
/*----------------------------------------------------------------------*/
int FindMaxMin(int a, int b, int c, int& high, int& low)
{
	if(a>b&&a>c)
	{ high=a; }
	else if(b>c)
	{ high=b; }
	else//c>a&b
	{ high=c; }

	if(a<b&&a<c)
	{ low=a; }
	else if(b<c)
	{ low=b; }
	else//c<a&b
	{ low=c; }

	return high, low;
}
/*------------------------------------------------------------*/
void Display(int high, int low)
{
	cout<<"\tMaximum= "<<high<<endl;
	cout<<"\tMinimum= "<<low<<endl;
	cout<<endl;
}
/*------------------------------------------------------------*/
int main()
{
	//read data into x, y, and z
	int x, y, z;
	ReadData(x, y, z);

	//compute the total of x, y, and z
	int total;
	total = ComputeSum(x, y, z);

	//compute the average of x, y, and z
	float average;
	average = ComputeAverage(x, y, z, total);

	//display total and average of x, y, and z
	Display(x, y, z, average);

	//find the maximum and minimum of x, y, and z
	int max, min;
	FindMaxMin(x, y, z, max, min);

	//overload Display function to show thw max and min values
	Display(max, min);

	//terminate program
	return 0;
}
/*--------------output--------------------------------------------------
Enter three integer numbers: 5 10 20
 For the three numbers: 5, 10, and 20
        Average= 11.6667
        Maximum= 20
        Minimum= 5

Press any key to continue
-----------------------------------------------------------------------*/