//---------------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS-367
//		Project		no. 7 part 3
//		Date		Apr. 4th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: (1)Display all names. (2) Display all names in lower case.
//			 (3)Display all names in upper case. (4)Display names in lower
//			 case with first letter in upper case. (5)Replace Rosalyn with
//			 Keola is Rosalyn is third name.
//---------------------------------------------------------------------------------
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
	char	names[5][10]={"roula", "nicholas", "rosalyn", "elaine", "ricardo"};

	//display names in array
		for(int i=0; i < 5; ++i)
			cout<<names[i];

	//display all names in upper case
		for(int i=0; i < 5; ++i)
		{
			strupr(names[i]);
			cout<<names[i]<<"\t";
		}
		cout<<endl;

	//display all names in lower case
		for(int i=0; i < 5; ++i)
		{
			strlwr(names[i]);
			cout<<names[i]<<"\t";
		}
		cout<<endl;

	//display all names in lower case with first letter, follwed by lenght
		for(int i=0; i < 5; ++i)
		{
			names[i]=toupper(names[i][0]);
			cout<<names[i]<<"\t"<<strlen(names[i]);
		}
		cout<<endl;

	//if ROSALYN is third, replace ROSALYN with KEOLA
		for(int i=0; i < 5; ++i)
		{	strupr(names[i]);	}
				
		if(strcmp(names[2], "ROSALYN") > 0)
		{	strcpy(names[2], "KEOLA");	}

	//terminate program
		system("pause");
		return 0;
}
/*--------ERRORs----------------------------------------------------------
1>proj_7v3.cpp
1>c:\users\frank brenyah\documents\visual studio 2008\projects\cmps367_project_7\cmps367_project_7\proj_7v3.cpp(17) : warning C4996: 'strupr': The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: _strupr. See online help for details.
1>        c:\program files (x86)\microsoft visual studio 9.0\vc\include\string.h(221) : see declaration of 'strupr'
1>c:\users\frank brenyah\documents\visual studio 2008\projects\cmps367_project_7\cmps367_project_7\proj_7v3.cpp(25) : warning C4996: 'strlwr': The POSIX name for this item is deprecated. Instead, use the ISO C++ conformant name: _strlwr. See online help for details.
1>        c:\program files (x86)\microsoft visual studio 9.0\vc\include\string.h(216) : see declaration of 'strlwr'
1>c:\users\frank brenyah\documents\visual studio 2008\projects\cmps367_project_7\cmps367_project_7\proj_7v3.cpp(33) : error C2440: '=' : cannot convert from 'int' to 'char [10]'
1>        There are no conversions to array types, although there are conversions to references or pointers to arrays
--------------------------------------------------------------------------*/