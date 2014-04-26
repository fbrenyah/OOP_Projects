//------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS 455
//		Project		HW 6
//		Date		04/23/14
//		Professor	Ray Ahmadnia
//
//		Purpose: Check a given syntax for compliance.
//
//------------------------------------------------------------------------
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

bool checkIfTerminal(char A){
	switch(A){
		case 'i' : return true;
		case '+' : return true;
		case '-' : return true;
		case '*' : return true;
		case '/' : return true;
		case 'L' : return true;
		case '$' : return true;
		case '(' : return true;
		case ')' : return true;
	default:return false;
	}
}
string assignCharsToTable(int tableCoord){
	string tableValue;
	switch(tableCoord){
		case 1: tableValue = "TQ"; return tableValue;
		case 2: tableValue = "-TQ"; return tableValue;
		case 3: tableValue = "+TQ"; return tableValue;
		case 4: tableValue = "FR"; return tableValue;
		case 5: tableValue = "*FR"; return tableValue;
		case 6: tableValue = "/FR"; return tableValue;
		case 7: tableValue = "(E)"; return tableValue;
		case 8: tableValue = "L"; return tableValue;
		case 9: tableValue = "i"; return tableValue;
		
	default:tableValue = " ";
	return tableValue;
	}
}
int assignIntToChar_1(char B){
	switch(B){
		case 'E': return 0;
		case 'Q': return 1;
		case 'T': return 2;
		case 'R': return 3;
		case 'F': return 4;
	default: return 0;
	}
}
int assignIntToChar_2(char B){
	switch(B){
		case 'i' : return 0;
		case '+' : return 1;
		case '-' : return 2;
		case '*' : return 3;
		case '/' : return 4;
		case 'L' : return 5;
		case '$' : return 6;
		case '(' : return 7;
		case ')' : return 8;
	default:return 0;
	}
}
int main(){

	//initialize stack
	//stack<char> initStk;//normal initial stack
	//stack<int> revStk;//container for coordMap string values in revserse (QT+)
	stack<char> workStk;//the working stack

	//initialize variables
	string eqSyn;
	int coordMap[5][9]={
		1,99,99,99,99,99,99,1,99,
		99,3,2,99,99,99,99,99,8,
		4,99,99,99,99,99,99,4,99,
		99,8,99,5,6,99,8,99,8,
		9,99,99,99,99,99,99,7,99
	};
	char yesNo='n';

	do{		
		//get expression
		cout<<"Please, enter your syntax\n";
		cout<<"\t(end with $, L for lamda): ";
		cin>>eqSyn;
		
		workStk.push('$'); 
		workStk.push('E');		
		int i=0;
		while(!workStk.empty()){
			//begin
			cout<<"\t1\n";
			char a = workStk.top();
			char b = eqSyn[i];
			if( checkIfTerminal(eqSyn[i]) ){
				if(a==b){
					workStk.pop();	
					++i;
					cout<<"\t2\n";
				}else{
					cout<<"\tExpression is illegal!\n";
					cout<<"\t3\n";
				}
			}else{
				cout<<"\t4\n";
				int c = assignIntToChar_1(a);
				int d = assignIntToChar_2(b);
				if(coordMap[c][d]!=99){
					workStk.pop();
					for(int k=assignCharsToTable(coordMap[c][d]).length()-1; k>-1; --k){
						workStk.push(assignCharsToTable(coordMap[c][d])[k]);
						cout<<"\t5\n";
					}
					cout<<"\t6\n";
					++i;
				}else{
					cout<<"\tExpression is illegal!\n";
					cout<<"\t7\n";
				}
			}
			++i;
		}
		cout<<"Would you like to continue? (y/n): ";
		cin>>yesNo; yesNo=toupper(yesNo);
	}while(yesNo=='Y');

	system("PAUSE");
	return 0;
}