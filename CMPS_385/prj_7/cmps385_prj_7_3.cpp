#include <iostream>
#include <fstream>
using namespace std;
//
struct NODE
{
	string name;
	int age;
	NODE *link;
};
int main()
{
	NODE* List;
	//get data from file
	fstream A;
	A.open("seven_two_data.txt", ios::in);
	for(int i=0; i<5; i++)
	{
		A >> List->name >> List->age;
		List = List->link;
	}

	//end  program
	system("PAUSE");
	return 0;
}