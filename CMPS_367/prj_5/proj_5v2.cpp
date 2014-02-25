//-----------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-367
//		Project		no. 5 part 2
//		Date		Mar. 21st, 2012
//		Professor	Ray Ahmadnia
//
// Purpose: To display a given set of arrays
//
//		2 5 9 8 7
//		a y h p q r
//		Mon Tue Wed Thr Fri
//----------------------------------------------------------
#include <iostream>
#include <string>
 using namespace std;

//functions prototypes
 template <class T>
 void Show(T[], int x);

 int main()
 {
	 int	a[5]={2, 5, 9, 8, 7};
	 char	c[6]={'a', 'y', 'h', 'p', 'q', 'r'};
	 string s[5]={"Mon", "Tue", "Wed", "Thr", "Fri"};

	 //display arrays with template functions
	 Show(a, 5); Show(c, 6); Show(s, 5);

	 //terminate program
	 system("pause");
	 return 0;
 }
 //----------------------------------
 template <class T>
 void Show(T x[], int y)
 {
	 for(int i=0; i < y; i++)
	 {
		 cout<<x[i]<<" ";
	 }
	 cout<<endl;
 }
 //----------------------------------
/*-----------------output--------------------------------------
2 5 9 8 7
a y h p q r
Mon Tue Wed Thr Fri
Press any key to continue . . .
-------------------------------------------------------------*/