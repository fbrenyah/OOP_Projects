/*-----------------------------------------------------------------------------------------
		Name		Frank Brenyah
		Course		CMPS-385
		Project		No.9 part 1
		Date		Nov. 19th, 2012
		Professor	Ray Ahmandnia

	Purpose: Provide a system to view and interact with accounts and balances.

------F.O. Brenyah Bank LLC------
 A) Display all records
 B) Display name and balance
 C) Deposit
 D) Withdraw
  Please, enter choice(A, B, C, or  D): a
10      Will    $96.99
20      Frank   $200
30      Ana     $1000
40      Kriss   $150
50      Elaine  $330.3
60      Jozeph  $666.66

 CONTINUE?(Y/N) y

  Please, enter choice(A, B, C, or  D): b
 Please, enter your ID number: 20
  Account info:
   Frank        $200
 CONTINUE?(Y/N) y

  Please, enter choice(A, B, C, or  D): c
 Please, enter your ID number: 20
        How much do you want to deposit: 30
         Your new balance is: $230
 CONTINUE?(Y/N) y

  Please, enter choice(A, B, C, or  D): d
 Please, enter your ID number: 20
        How much do you want to withdraw: 120
         Your new balance is: $110
 CONTINUE?(Y/N) n
-------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

class BST;

int main()
{
	//declare identifiers
	BST bank_accounts;
	char Continue;
	int ID_num[6]; string Name[6]; float Balance[6];

	//retreive info from text file
	fstream File;
	File.open("CMPS385_9_info.txt", ios::in);
	for(int i=0; i<6; i++)
		File >> ID_num[i] >> Name[i] >> Balance[i];
	File.close();

	//build B.S. Tree
	for(int i=0; i<6; i++)
		bank_accounts.insert( ID_num[i], Name[i], Balance[i] );

	char Choice;
	cout<<"\t------F.O. Brenyah Bank LLC------\n";
	cout<<" A) Display all records\n";
	cout<<" B) Display name and balance\n";
	cout<<" C) Deposit\n";
	cout<<" D) Withdraw\n";

   do{
		cout<<"  Please, enter choice(A, B, C, or  D): "; 
		cin>>Choice;
		Choice = tolower(Choice);
		if( Choice == 'a' )
		{
			//display all bank acounts
			bank_accounts.Display();
			cout<<endl;
		}
	
		int id_temp;
	
		if( Choice == 'b' )
		{
			//get info when ID_num is entered
			id_temp = 0; //ID number holder
			cout<<" Please, enter your ID number: ";
			cin>>id_temp;
			bank_accounts.find_Account(id_temp);
		}
		
		if( Choice == 'c' )
		{
			//deposit money when ID_num is entered
			id_temp = 0;
			cout<<" Please, enter your ID number: ";
			cin>>id_temp;
			bank_accounts.do_Deposit(id_temp);
		}
	
		if( Choice == 'd' )
		{
			//withdraw money when ID_num is entered
			id_temp = 0;
			cout<<" Please, enter your ID number: ";
			cin>>id_temp;
			bank_accounts.do_Withdraw(id_temp);
		}

		cout<<" CONTINUE?(Y/N) "; cin>>Continue;
		Continue = tolower(Continue);
		cout<<endl;
   }while( Continue == 'y' );
	
	//end program
	system("PAUSE");
	return 0;
}
//
//class
class BST
{
private:
	struct NODE
	{
		int id; string name; float amount;
		NODE* left, *right;
	};
	NODE* root;
public:
	BST() {	root = NULL; } //constructor
	
	void insert( NODE* &P, int& x, string& y, float& z )
	{
		if( P == NULL )
		{
			P = new(NODE); 
			P->id = x; P->name = y; P->amount = z;
			P->left = P->right = NULL;
		}
		if( x < P->id)
			insert( P->left, x, y, z );
		
		if( x > P->id )
			insert( P->right, x, y, z );
	}

	void DisplayTree( NODE *P )
	{
		if( P != NULL )
		{
			DisplayTree(P->left);
			cout<< P->id <<"\t"<< P->name <<"\t$"<< P->amount <<'\n';
			DisplayTree(P->right);
		}
	}
	
	//call display member
	void Display() { DisplayTree(root); }

	//call insert member
	void insert( int x, string y, float z ) { insert(root, x, y, z); }

	//search for account info
	void Account_Search( NODE *&P, int x )
	{
		if( P == NULL )
			cout<<"\tAccount "<< x <<" does not exist.\n";
		else if( P->id == x )
		{
			cout<<"  Account info:\n";
			cout<<"   "<< P->name <<"\t$"<< P->amount <<endl;
		}
		else if( P->id < x )
			Account_Search( P->left, x );
		else
			Account_Search( P->right, x );
	}

	//search for balance info then deposit
	void Deposit_Search( NODE *&P, int x )
	{
		if( P == NULL )
			cout<<"\tAccount "<< x <<" does not exist.\n";
		else if( P->id == x )
		{
			int depo_temp = 0; //hold deposit
			cout<<"\tHow much do you want to deposit: ";
			cin>>depo_temp;
			P->amount = (P->amount + depo_temp);
			cout<<"\t Your new balance is: $"<< P->amount <<endl;
		}
		else if( P->id < x )
			Deposit_Search( P->left, x );
		else
			Deposit_Search( P->right, x );
	}

	//search for balance info then withdraw
	void Withdraw_Search( NODE *&P, int x )
	{
		if( P == NULL )
			cout<<"\tAccount "<< x <<" does not exist.\n";
		else if( P->id == x )
		{
			int wDRAW_temp = 0; //hold deposit
			cout<<"\tHow much do you want to withdraw: ";
			cin>>wDRAW_temp;
			P->amount = (P->amount - wDRAW_temp);
			cout<<"\t Your new balance is: $"<< P->amount <<endl;
		}
		else if( P->id < x )
			Deposit_Search( P->left, x );
		else
			Deposit_Search( P->right, x );
	}

	//call search  members
	void find_Account( int& x ) { Account_Search(root, x); }

	void do_Deposit( int& x ) { Deposit_Search(root, x); }

	void do_Withdraw( int& x ) { Withdraw_Search(root, x); }
};