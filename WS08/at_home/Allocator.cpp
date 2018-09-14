#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	// define interest rate
	//
	#define INTREST_RATE 0.05
	#define TRANSACTION_FEE 0.50
	#define MONTHLY_FEE 2.00


	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char *type, double n_balance) {
		iAccount* acct = nullptr;
	
		std::string acctType = type;
		
		if (acctType == "Savings") {

			acct = new SavingsAccount(n_balance, INTREST_RATE);

		}
		else if (acctType == "Chequing") {

			acct = new ChequingAccount(n_balance, TRANSACTION_FEE, MONTHLY_FEE);

		}
		else {
			acct = nullptr;
		}

		return acct;
	}

	iAccount::~iAccount() {
		
	}





}
