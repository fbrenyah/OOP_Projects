//-----------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.7 part 2
//		Date		Oct. 27th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Use numbers entered by the user to develope and compute a
//			 multiple degree linear function.
//
//		//*_  error C2668: 'pow' : ambiguous call to overloaded function _*//
//-----------------------------------------------------------------------------
#include <iostream>
#include <cmath>
using namespace std;
//
struct NODE
{
	int coeff;
	int expo;
	NODE* link;
};
//function prototypes
void GetDATA( NODE*&List );
void DisplayFORMULA( NODE*&List );
float computeVALUE( NODE*&List, int& x );
void DisplayVALUE( float& total );
//
int main()
{
	NODE *LST; LST=NULL;
	int P=0;
	float value;

	//get coefficients and exponents
	GetDATA(LST);

	//display formula for the given coeff's and expo's
	DisplayFORMULA(LST);

	//communte the value of the function
	cout<<"To compute f(x), enter a value for x: "; cin>>P;
	value = computeVALUE(LST, P);

	//display the answer of the function
	cout<<"f("<<P<<") = ";
	DisplayVALUE(value);

	//end program
	system("PAUSE");
	return 0;
}
//functions
void GetDATA( NODE*&List )
{
	do{
		List = new( NODE );
		cout<<"\tPlease, enter the coefficient and degree of one term ("" 0 0"" to stop):";
		cin>> List->coeff >> List->expo;
	}while( List->coeff && List->expo != 0 );
	List->link = NULL;
}
void DisplayFORMULA( NODE*&List )
{
	NODE *K;
	K = List;
	int y=0;

	while( K != NULL )
	{
		cout<<"This is your function f(x)\n";
		cout<<"  f(x) = "<<K->coeff<<"X^"<<K->expo;

			if(K->coeff < 0)
			{
				y = (-2 * K->coeff) + K->coeff; //ex. p = (-2 * -3) + (-3)
				cout<<" + "<< y <<"X^"<< K->expo;
			}
			else
				cout<<" + "<< K->coeff <<"X^"<< K->expo;
			
			K = K->link;
	}
}
float computeVALUE( NODE*&List, int& x )
{
	NODE* K;
	K = List;
	float total=0; //total = f(x)
	while( K != NULL )
	{
		total += (K->coeff * (pow( x, K->expo )));
		K = K->link;
	}
	return total;
}
void DisplayVALUE( float& total )
{
	cout<<'\t'<<total<<endl;
}
//end functions