//-------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-385
//		Project		No.11 part 1
//		Date		Dec. 3rd, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Allow for performing addition, subtraction, multiplication,
//			 and division of two points on a coordinate plane. Also to 
//			 increment and decrement one of those points.
//
//		 Please, enter the point: 3 4

//		 Please, enter the point: 5 6

//		        Point A is (3, 4)
//		        Point B is (5, 6)

//		        (3, 4) + (5, 6) = (8, 10)
//		        (3, 4) - (5, 6) = (-2, -2)
//		        (3, 4) x (5, 6) = (15, 24)
//		        (3, 4) / (5, 6) = (0, 0)
//		        (3, 4)++ = (4, 5)
//		        (5, 6)++ = (6, 7)
//		        (4, 5)-- = (3, 4)
//		        (6, 7)-- = (5, 6)
//------------------------------------------------------------------------			 
#include <iostream>
using namespace std;
class POINT
{
private: int x, y;
public: 
	void ReadData()
	{	
		cout<<" Please, enter the point: ";
		cin>>x>>y; cout<<endl;
	}
	friend POINT operator+(POINT P, POINT Q)
	{
		POINT r;
		r.x = P.x + Q.x;
		r.y = P.y + Q.y;
		return r;
	}
	friend POINT operator-(POINT P, POINT Q)
	{
		POINT r;
		r.x = P.x - Q.x;
		r.y = P.y - Q.y;
		return r;
	}
	friend POINT operator*(POINT P, POINT Q)
	{
		POINT r;
		r.x = P.x * Q.x;
		r.y = P.y * Q.y;
		return r;
	}
	friend POINT operator/(POINT P, POINT Q)
	{
		POINT r;
		r.x = P.x / Q.y;
		r.y = P.y / Q.x;
		return r;
	}
	friend void operator++(POINT& P)
	{
		P.x++; P.y++;
	}
	friend void operator--(POINT& P)
	{
		P.x--; P.y--;
	}
	void Show()
	{
		cout<<"("<< x <<", "<< y <<")";
	}
};
int main()
{
	POINT plotONE, plotTWO, ANS; //declare point objects

	plotONE.ReadData(); //Receive
	plotTWO.ReadData(); //numbers

	cout<<"\tPoint A is ";plotONE.Show(); cout<<endl; //Display
	cout<<"\tPoint B is ";plotTWO.Show(); cout<<endl; //points
	cout<<endl;

	//Add points ONE & TWO
	cout<<'\t'; plotONE.Show(); cout<<" + "; plotTWO.Show();
	ANS = plotONE + plotTWO; cout<<" = "; ANS.Show(); cout<<endl;

	//Subtract points ONE & TWO
	cout<<'\t'; plotONE.Show(); cout<<" - "; plotTWO.Show();
	ANS = plotONE - plotTWO; cout<<" = "; ANS.Show(); cout<<endl;

	//Multiply points ONE & TWO
	cout<<'\t'; plotONE.Show(); cout<<" x "; plotTWO.Show();
	ANS = plotONE * plotTWO; cout<<" = "; ANS.Show(); cout<<endl;

	//Divide points ONE & TWO
	cout<<'\t'; plotONE.Show(); cout<<" / "; plotTWO.Show();
	ANS = plotONE / plotTWO; cout<<" = "; ANS.Show(); cout<<endl;

	//Increment both points
	cout<<'\t'; plotONE.Show(); cout<<"++ = "; plotONE++; plotONE.Show(); cout<<endl;
	cout<<'\t'; plotTWO.Show(); cout<<"++ = "; plotTWO++; plotTWO.Show(); cout<<endl;

	//Decrement both points
	cout<<'\t'; plotONE.Show(); cout<<"-- = "; plotONE--; plotONE.Show(); cout<<endl;
	cout<<'\t'; plotTWO.Show(); cout<<"-- = "; plotTWO--; plotTWO.Show(); cout<<endl;

	//end program
	system("PAUSE");
	return 0;
}