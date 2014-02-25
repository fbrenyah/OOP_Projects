//-------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-367
//		Project		no. 11
//		Date		May 15th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: To perform multiple types of algebraic operations
//			 with two point coordinates the user enters.
//
//		Enter the coordinate for point A(numbers ONLY): 3 5
//		Enter the coordinate for point B(numbers ONLY): -2 4
//		(3, 5) + (-2, 4) = (1, 9)
//		(3, 5) - (-2, 4) = (5, 1)
//		(3, 5) + 1 = (4, 6)
//		(-2, 4) + 1 = (-1, 5)
//------------------------------------------------------------------------
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class POINTS
{
	private: int x, y;
	public: void ReadPoint1()
			{
				cout<<"Enter the coordinate for point A(numbers ONLY): ";
				cin>>x>>y;
			}

			void ReadPoint2()
			{
				cout<<"Enter the coordinate for point B(numbers ONLY): ";
				cin>>x>>y;
			}

			void showpoint()
			{
				cout<<"("<<x<<", "<<y<<")";
			}

			friend POINTS operator+(POINTS A, POINTS B)
			{
				POINTS Z;

				Z.x = A.x+B.x;
				Z.y = A.y+B.y;

				return Z;
			}

			friend POINTS operator-(POINTS A, POINTS B)
			{
				POINTS W;

				W.x = A.x-B.x;
				W.y = A.y-B.y;

				return W;
			}

			friend void operator++(POINTS& K)
			{
				K.x = K.x+1;
				K.y = K.y+1;
			}

			friend float distance(POINTS A, POINTS B)
			{
				return sqrt(float((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y)) );
			}
};

int main()
{
	POINTS P;//point A
	POINTS Q;//point B
	POINTS Sum;
	POINTS Difference;
	
	P.ReadPoint1();//read data for point A
	Q.ReadPoint2();//read data for point B

    Sum = P+Q;//Get sum of point A and B

	//display sum of point A and B
	P.showpoint(); cout<<" + "; Q.showpoint(); cout<<" = "; Sum.showpoint();
	cout<<endl;
	
	Difference = P-Q;//Get difference of point A and B

	//display difference of point A and B
	P.showpoint(); cout<<" - "; Q.showpoint(); cout<<" = "; Difference.showpoint();
	cout<<endl;

	P.showpoint(); cout<<" + 1 = ";
	P++;//Get the increment of point A
	P.showpoint();//display increment of point A
	cout<<endl;

	Q.showpoint(); cout<<" + 1 = ";
	Q++;//Get the increment of point B
	Q.showpoint();//display uncrement of point B
	cout<<endl;

	//Get the distance between the two points	
	//Distance = P*Q;//get [(point A)x(point B)]^(1/2)
	//cout<<"AB = "<<distance(P, Q)<<endl;

	system("pause");
	return 0;
}
/*----------------------------------------------------------------------
Enter the coordinate for point A(numbers ONLY): 3 5
Enter the coordinate for point B(numbers ONLY): -2 4
(3, 5) + (-2, 4) = (1, 9)
(3, 5) - (-2, 4) = (5, 1)
(3, 5) + 1 = (4, 6)
(-2, 4) + 1 = (-1, 5)
Press any key to continue . . .
------------------------------------------------------------------------*/