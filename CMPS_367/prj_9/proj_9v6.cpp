//-----------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-367
//		Project		no. 9 part 6
//		Date		Apr. 18st, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: To read data into an array of any type
//			 and find the max, min, and average. Display it all.
//----------------------------------------------------------------
#include <iostream>
using namespace std;

class SIX
{
	private: 
		int x[7];
	public:
		void READ()
		{ 
			for(int i=0; i < 7; ++i)
				cin>>x[i];
		}
		void Display()
		{
			for(int i=0; i < 7; ++i)
				cout<<x[i]<<" ";
			cout<<endl;
		}
		void FindMaxMin(int& mx, int& mn)
		{
			mx = mn = x[0];
			for(int i=1; 1 < 7; ++i)
			{
				if(x[i] < mn)
					mn = x[i];
				if(x[i] > mx)
					mx = x[i];
			}
		}
		int FindTotal()
		{
			int sum=0;
			for(int i=0; i < 7; ++i)
				sum+=x[i];
			return sum;
		}
};

int main()
{
	//declare object to hold info
	SIX me;
	int max, min;

	//read numbers into array
	cout<<"Enter 7 integer data: "; me.READ();

	//display all numbers in array
	cout<<"All data: "; me.Display();

	//display max and min of numbers in array
	me.FindMaxMin(max, min);
	cout<<"Maximum = "<<max<<"\t"<<"Minimum = "<<min<<endl;

	//display the total of numbers in array
	cout<<"Total = "<<me.FindTotal()<<endl;

	//terminate program
	system("pause");
	return 0;
}
//------------------output--------------------------------
//	We had linking problems we could not figure out, 
//	causing no output. You requested I print this 
//	without the output.
//--------------------------------------------------------