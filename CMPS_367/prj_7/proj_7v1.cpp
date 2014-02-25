//-------------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-367
//		Project		no. 7 part 1
//		Date		Apr. 4th, 2012
//		Professor	Ray Amadnia
//
//	Purpose: (1)Display who the teenagers are. (2) Display the average age
//			 of all students. (3) Display the average GPA of all students.
//			 (4) Display students whom have a GPA higher than the average GPA.
//
//		Here are the teenagers
//		        Avila   17      2.8
//		        Joseph  16      3.2
//		        Samuel  19      2.9
//		The average age of all students is 19.8333
//		The	avergae GPA of all students is 3.03333
//		Those above average are
//		Bryan   21
//		James   22
//		Joseph  16
//		Will    24
//-----------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int n = 6;

struct PERSON
{
	string	Name;
	int		Age;
	float	GPA;
};
//---functions-----------------------------------
void GetData(char datafile[], PERSON x[], int n)
{
	ifstream data;
	data.open(datafile);

	for(int i=0; i < n; ++i)
		data>>x[i].Name>>x[i].Age>>x[i].GPA;
	data.close();
}
//------------------------------------------------
void DisplayTeen(PERSON x[])
{
	cout<<"Here are the teenagers\n";
	for(int i=0; i < n; ++i)
	{
		if(x[i].Age > 12 && x[i].Age < 20)
			cout<<"\t"<<x[i].Name<<"\t"<<x[i].Age<<"\t"<<x[i].GPA<<endl;
	}
}
//------------------------------------------------
void ComputeAverage(PERSON x[], float& age_ave, float& gpa_ave)
{
	float Total=0;

	for(int i=0; i < n; ++i)
	{
		Total += x[i].Age;
	}
	age_ave = Total/n;

	Total=0;

	for(int i=0; i < n; ++i)
	{
		Total += x[i].GPA;
	}
	gpa_ave = Total/n;
}
//--------------------------------------------------
void DisplayHighGpa(PERSON x[], float gpa_ave)
{
	cout<<"Those above average are\n";

	for(int i=0; i < n; ++i)
	{
		if(x[i].GPA > gpa_ave)
			cout<<x[i].Name<<"\t"<<x[i].Age<<endl;
	}
	cout<<endl;
}
//-------------------------------------------------
int main()
{
	PERSON a[n];
	float AgeAve, GpaAve;

	//Copy data from file
		GetData("data.txt", a, n);

	//Display name, age, and GPA
		DisplayTeen(a);

	//Compute and display the average of all teens in the data file.
		ComputeAverage(a, AgeAve, GpaAve);
		cout<<"The average age of all students is "<<AgeAve<<endl;
		cout<<"The avergae GPA of all students is "<<GpaAve<<endl;

	//Display the name and age of a teen with a GPA higher than the average GPA.
		DisplayHighGpa(a, GpaAve);

	//terminate program
	system("pause");
	return 0;
}
/*------------------output-------------------------------------------------------------
Here are the teenagers
        Avila   17      2.8
        Joseph  16      3.2
        Samuel  19      2.9
The average age of all students is 19.8333
The avergae GPA of all students is 3.03333
Those above average are
Bryan   21
James   22
Joseph  16
Will    24

Press any key to continue . . .
---------------------------------------------------------------------------------------*/