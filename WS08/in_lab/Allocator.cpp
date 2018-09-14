#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	#define INTREST_RATE 0.05


	// TODO: Allocator function
	//

	//Creates the type of Account for a person by allocating new memory for it. 
	iAccount* CreateAccount(const char *type, double n_balance) {
		iAccount* acct = nullptr;
		
		//Compares to see what Account the user wants to have and Allocates memory for the new account
		//based on the new account. 
		if (type == "Savings") {
			acct = new SavingsAccount(n_balance, INTREST_RATE);
		}
		else {
			acct = nullptr;
		}

		return acct;
	}







}
