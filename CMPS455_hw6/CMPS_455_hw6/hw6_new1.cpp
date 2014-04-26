/*------------------------------------------------------------------------
//		Name		Frank Brenyah
//		Course		CMPS 455
//		Project		HW 6
//		Date		04/23/14
//		Professor	Ray Ahmadnia
//
//		Purpose: Check a given syntax for compliance.

//1
Enter your expression (end with $): (i+i)*i
        1
        3
        4
        1
        3
        4
        1
        3
        4
        1
        2
        ...
        1
        2
        4
        1
        3
        4
        1
        3
        ...
        4
        1
        3
        ...
        3
        4
        1
        3
        4
        1
        2
        4
                * Great! This string legal.
                        You may now pass!

Press any key to continue . . .

//2
Enter your expression (end with $): i*(i+i)$
                * Great! This string legal.
                    You may now pass!

Continue (y/n)? : y
Enter your expression (end with $): i*i/i$
                * Great! This string legal.
                    You may now pass!

Continue (y/n)? : n
Press any key to continue . . .

//3 infinite-loop when string is illegal [ (i+i)i$ ]
		...
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your string is illegal!
        Your stri
//------------------------------------------------------------------------*/
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

bool isThisTerminal(char A){
	switch(A){
		case 'E': return false; break;
		case 'Q': return false; break;
		case 'T': return false; break;
		case 'R': return false; break;
		case 'F': return false; break;

		case 'i': return true; break;
		case '+': return true; break;
		case '-': return true; break;
		case '*': return true; break;
		case '/': return true; break;
		case '(': return true; break;
		case ')': return true; break;
		case '$': return true; break;

		default: 
			break;
	}
}

int giveTokenInt(char B){
	switch(B){
		case 'i': case 'E': return 0; break;
		case '+': case 'Q': return 1; break;
		case '-': case 'T': return 2; break;
		case '*': case 'R' :return 3; break;
		case '/': case 'F': return 4; break;

		case '(': return 5; break;
		case ')': return 6; break;
		case '$': return 7; break;

		default: 
			break;
	}
}

string getMyTokenString(int X){
	switch(X){
		case 1: 
			return "TQ";
			break;
		case 2: 
			return "+TQ"; 
			break;
		case 3: 
			return "-TQ"; 
			break;
		case 4: 
			return "FR"; 
			break;
		case 5: 
			return "*FR"; 
			break;
		case 6: 
			return "/FR"; 
			break;
		case 7: 
			return "i"; 
			break;
		case 8: 
			return "(E)"; 
			break;
		case 9:
			return "L"; 
			break;

		default: 
			break;
	}
}
int main(){
	//init grammar table
	int grammarTable[5][8]={
		1,0,0,0,0,1,0,0,
		0,2,3,0,0,0,9,9,
		4,0,0,0,0,4,0,0,
		0,9,9,5,6,0,9,9,
		7,0,0,0,0,8,0,0,
	};
	//init Stack
	stack<char> workStk;
	//workers
	char topOfStack;
	char currentChar;
	string expSyn;
	char yesNo;

	do{
		//get expression
		cout<<"Enter your expression (end with $): ";
		cin>>expSyn;
		//init stack and set worker
		workStk.push('$');
		workStk.push('E');
		int i=0;//expSyn indexer

		//begin
		while( !workStk.empty() ){
			//set workers
			//cout<<"\t1\n"; //begin
			topOfStack = workStk.top();
			currentChar = expSyn[i];

			if( isThisTerminal(topOfStack)==true ){
				//cout<<"\t2\n"; //'topOfStack' is terminal
				if( topOfStack == currentChar ){
					//'topOfStack' is terminal AND equal to 'expSyn[i]'
					workStk.pop();
					i++;
				}else{
					//'topOfStack' is terminal but NOT equal to 'expSyn[i]'
					cout<<"\tYour string is illegal!\n";
				}
			}
			else{
				//cout<<"\t3\n"; //'topOfStack' is NOT terminal
				//give tokens int value to read 'grammarTable'
				int a = giveTokenInt(topOfStack);
				int b = giveTokenInt(currentChar);
				if( grammarTable[a][b] != 0 ){
					//'grammarTable' is NOT blank!
					workStk.pop();
					//get equation to push onto 'workStk'
					string toPush = getMyTokenString(grammarTable[a][b]);
					//push onto 'workStk' in reverse
					for( int k=toPush.length()-1; k > -1; --k ){
						workStk.push(toPush[k]);
					}
				}else{
					//'grammarTable' is blank!
					cout<<"\tYour string is illegal!\n";
				}

			}
			//cout<<"\t4\n"; //loop back up or end
		}
		cout<<"\n\t\t* Great! This string legal.\n";
		cout<<"\t\t    You may now pass!\n\n";
		//done
		cout<<"Continue (y/n)? : ";
		cin>>yesNo; yesNo=toupper(yesNo);
	}while(yesNo=='Y');

system("PAUSE");
return 0;
}