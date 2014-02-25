//-------------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-367
//		Project		no. 7 part 2
//		Date		Apr. 4th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Sort and display a given array
//-------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//--------functions-----------------------
template <class T>
void SORT(T x[], int n)
{
	T temp;
	for(int i=0; i < n; ++i)
	{
		for(int j=0; j < n-1-i;)
		{
			if(x[j] > x[j+1])
			{
				temp=x[j]; 
				x[j]=x[j+1];
				x[j+1]=temp;
			}
		}
	}
	cout<<endl;
}
//------------------------------------------
template <class T>
void DisplayArray(T x[], int n)
{
	for(int i=0; i < n; ++i)
		cout<<x[i]<<"  ";
	cout<<endl;
}
//-----------------------------------------
int main()
{
	int		a[5]={11, 55, 22, 88, 33};

	string	month[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
					   "Aug", "Sep", "Oct", "Nov", "Dec"};

	char	Letters[4]={'E', 'X', 'A', 'M'};

	//display original array "a"
		cout<<"Original array a: ";	DisplayArray(a, 5);

	//display predefined sorted array
		sort(a, a+5);
		cout<<"  Array a sorted by predefined sort function: "; DisplayArray(a, 5);

	//display user-defined sorted rray
		SORT(a, 5);
		cout<<"  Array a sorted by user-defined sort function: "; DisplayArray(a, 5);

	//display original string array "month"
		cout<<"Original array month: "; DisplayArray(month, 12);

	//display predefined sorted array
		sort(month, month+12);
		cout<<"  Array month sorted by predefined sort function: "; DisplayArray(month, 12);

	//display user-defined sorted array
		SORT(month, 12);
		cout<<"  Array month sorted by predefined sort function: "; DisplayArray(month, 12);

	//display original array "Letters"
		cout<<"Original array Letters: "; DisplayArray(Letters, 4);

	//display predefined sorted array
		sort(Letters, Letters+4);
		cout<<"  Array Letters sorted by predefined sort function: "; DisplayArray(Letters, 4);

	//display user-defined sorted array
		SORT(Letters, 4);
		cout<<"  Array Letters sorted by predefined sort function: "; DisplayArray(Letters, 4);

	//terminate program
	system("pause");
	return 0;
}