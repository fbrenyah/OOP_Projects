//--------------------------------------------------------------------------------------
//		Name		Frank	Brenyah
//		Course		CMPS-367
//		Project		no. 3 part 3
//		Date		Feb. 26th, 2012
//		Professor	Ray Ahmadnia
//
//	Purpose: Get a phone number and ifit has char's, convert
//			 them to numeric form.
//
//		Enter a phone number: 1-800-helpyou
//
//		In numeric form: 1-800-435-7968
//		CONTINUE(y/n)? y
//
//		Enter a phone number: 1-800-freefun
//
//		In numeric form: 1-800-373-3386
//		CONTINUE(y/n)? n
//-------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	//declare identifiers
	string  phone;
	char	YesNo;

	do{
		cout<<"Enter a phone number: ";
		getline(cin, phone);
	
		//using <string> library
		int n=phone.length();
		for(int i=0;i<n;i++)
		{
			if(isalpha(phone[i]))
			{ 
				phone[i]=char(toupper(phone[i]));
				{
					switch(phone[i])
					{
					case 'A': case 'B': case 'C': phone[i]=50; break;
					case 'D': case 'E': case 'F': phone[i]=51; break;
					case 'G': case 'H': case 'I': phone[i]=52; break;
					case 'J': case 'K': case 'L': phone[i]=53; break;
					case 'M': case 'N': case 'O': phone[i]=54; break;
					case 'T': case 'U': case 'V': phone[i]=56; break;
					case 'P': case 'Q': case 'R': case 'S': phone[i]=55; break;
					case 'W': case 'X': case 'Y': case 'Z': phone[i]=57; break;
					default : break;
					}
				}
			}
		}
		phone=phone.insert(9,"-");
		cout<<"In numeric form: "<<phone<<endl;
	
		cout<<"CONTINUE(y/n)? "; cin>>YesNo;
		YesNo=toupper(YesNo);
		cout<<endl;
	}while(YesNo=='Y');

	//terminate program
	return 0;
}
/*-----------output-----------------------------------------------------------------
Enter a phone number: 1-800-helpyou

In numeric form: 1-800-435-7968
CONTINUE(y/n)? y

Enter a phone number: 1-800-freefun

In numeric form: 1-800-373-3386
CONTINUE(y/n)? n

Press any key to continue
-------------------------------------------------------------------------------------*/