//--------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-367
//		Project		no. 9 part 5
//		Date		Apr. 16th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Read information into arrays in a class and display it.
//
//		Enter 4 characters: B A B Y
//
//		Enter 5 integers: 13 24 38 54 09
//
//		  This is array x of object P: B A B Y
//		  This is array x of object Q: 13 24 38 54 9
//--------------------------------------------------------------------
#include <iostream>
using namespace std;

template <class T, int n>
class FIVE
{	
	private:
		T x[n];
	public: 
		
		void READ()
		{	for(int i=0; i < n; ++i) cin>>x[i];	}

		
		void Display()
		{	for(int i=0; i < n; ++i) cout<<x[i]<<" ";	}
};

int main()
{
	//declare arrays
	//declare objects of class FIVE
	FIVE<char, 4> p;
	FIVE<int,5> q;

	//collect information for template type array
	cout<<"Enter 4 characters: "; p.READ(); cout<<endl;
	cout<<"Enter 5 integers: "; q.READ(); cout<<endl;

	//display content in both arrays
	cout<<"  This is array x of object P: "; p.Display(); cout<<endl;
	cout<<"  This is array x of object Q: "; q.Display(); cout<<endl;

	//terminate program
	system("pause");
	return 0;
}
/*--------------output-------------------------------------------------
Enter 4 characters: B A B Y

Enter 5 integers: 13 24 38 54 09

  This is array x of object P: B A B Y
  This is array x of object Q: 13 24 38 54 9
Press any key to continue . . .
-----------------------------------------------------------------------*/