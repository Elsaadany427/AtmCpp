/*
TITLE:		SIMPLE ATM MACHINE

PURPOSE:	Write a program that simulates as an atm machine

TASKS:		Create an account that has the ability to 
				1) Check checking account balance
				2) Check savings account balance
				3) Make transfers between each account
				4) Make deposits into accounts
				5) Make withdrawals from accounts

AUTHOR:		Heba

INSTRUCTIONS:	
			Enter pin number '1234'
			Checkings Account Balance = 100
			Savings Account Balance = 600
*/

#include<bits/stdc++.h>


// FUNCTIONS
void menu();

void account(int option);


using namespace std;

string AccountType[] = {"", "CHECKINGS", "SAVINGS"};

// to ask yes or no to exit

string response;

int AccountDetails[] = {
	1234,		// pin number
	100,		// checking account balance
	600,		// savings account balance
};

bool validatePin(int pin) {
	
	if (pin == AccountDetails[0]) {
		
		return true;
	} else {
		
		return false;
	}
}


bool AskForExit(string response) {
	
	if(response =="y" || response == "Y"){
		
		return true;
		
	} else if(response == "n" || response == "N"){
		
		string exit;
		
		cout << "\n\n\n\t Thank you for banking with us.";
		
		cin >> exit;
		
		return false;
	}

}

class AccountSettings {
	
	// Private Data
	private:
	
		int type;		// account type
		
		int balance;	// account balance
		
	public:
	
		// Constructor 
		AccountSettings(int type) {
			
			// type 1 = checkings
			// type 2 = savings
			
			// This operator to Access the data in private
			this->type = type;
			
			// Because This is an array 
			this->balance = AccountDetails[this->type];
		}
		
		int getWithdraw() {
			
			int withdrawAmount;
			
			cout << "Please enter amount to withdrawn:\n " << endl;
			
			cin >> withdrawAmount;

			// get account type
			
			// id we have more money
			if(withdrawAmount <= this->balance){
				
				int AccountBalance = ( this->balance -= withdrawAmount ) ;
				
				cout << "Dispensing... ";
				
				cout << "$"<< withdrawAmount << endl;
				
				// update the account balance
				
				AccountDetails[this->type] = AccountBalance;
				
				getBalance();

			}
			// if the money is less than withdrawAmount
			 else {
				cout << "Insufficent funds" << endl;
				getBalance();
			}

			return 0;
		}

		int getDeposit() {
			
			int depositAmount;
			
			cout << "Please enter an amount to deposit:\n" << endl;
			cin >> depositAmount;

			int AccountBalance = ( this->balance += depositAmount ) ;

			// update the account balance
			AccountDetails[this->type] = AccountBalance;

			cout << "\t$" << depositAmount << " was deposited into your account";
			
			getBalance();
			 
			return 0;
		}

		int getBalance() {
			
			string confirmBalance;
			
			// get the account type, and return balance
			
			cout << "Would you like to check your "<< AccountType[this->type] << " account balance? (y/n)\n" << endl;
			
			cin >> confirmBalance;
			
			if(confirmBalance=="y" || confirmBalance=="Y"){
				
				cout << "Your account balance is: $" << this->balance << endl;
			} 
			
			cout << "\n\nWould you like to continue (y/n)?\n";
			
			cin >> response;

			if (AskForExit(response) == true) {
				
				account(this->type); // return to account menu
			}

			return 0;
		}
};

void account(int option) {
	
		// account option = 1 (checkings)
		// account option = 2 (savings)
		
			cout << "\n\n" <<AccountType[option] << "--\n\t1. Check balance"
				<<"\n\t2. Withdraw from " << AccountType[option] 
				<<"\n\t3. Deposit to " << AccountType[option] 
				<<"\n\t4. --Return to Menu." << endl;

		// Pass in account type
		
		AccountSettings Account(option);  // make object 

		int selectMenu;
		
		cin >> selectMenu;
		
		switch(selectMenu){
			case 1:
				cout << Account.getBalance();
				break;
			case 2: 
				cout << Account.getWithdraw();
				break;
			case 3: 
				cout << Account.getDeposit();
				break;
			case 4:
				menu(); // return to main menu
				break;
			default:
				cout << "Would you like to continue (y/n)\n";
				cin >> response;
				AskForExit(response);
			
				if (AskForExit(response) == true) {
					menu(); // return to main menu
				} 
				break;
		}
}

void menu() {
	
	int option;
	
	cout << "\n\nMain Menu--" <<endl;
	
	cout << "\tPlease make a selection. " << endl;
	
	cout << "\t1. Checkings \n\t2. Savings \n\t3. Exit" << endl;
	
	cin >> option;
	
	switch(option){
		
		case 1: account(option); // checkings
			break;
		case 2: account(option); // savings
			break;
		default:
			cout << "Would you like to continue (y/n)\n";
			cin >> response;
			AskForExit(response);
			
			if (AskForExit(response)) {
				menu();
			} 
			break;
	}
}


// Begin MAIN

int main() {
	int pin;
	cout << "Welcome to Bank of Programming.\n\tPlease enter your pin number to access your account:" << endl;
	do {
		cin >> pin;

		if(validatePin(pin)) {
			menu(); // continue to main menu
		} else {
			cout << "Invalid pin. Please enter pin number:" << endl; 
		}
	} while (!validatePin(pin));

	return 0;
}
