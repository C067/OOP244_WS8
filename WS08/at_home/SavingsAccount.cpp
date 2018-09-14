
#include "SavingsAccount.h"
#include <iostream>
#include <cstring>
#include <iomanip>


using namespace std;

namespace sict {

	SavingsAccount::SavingsAccount(double n_balance, double rate) : Account(n_balance) {
		
		//Determine to see if the rate is above 0. If not, assign both the rate and the 
		//current balance to the account. Else, put the interest in a Safe Empty State.
		if (rate > 0) {
			interest = rate;
		}
		else {
			interest = 0.0;
		}

	}

	//Calculate the current balance after the deductions from month's end. 
	//Current Balance * interest on the account. 
	void SavingsAccount::monthEnd() {
		double total = balance() * interest;
		//Add the total to the account by crediting the account. 
		credit(total);
	}

	//Display the type of Account, the Balance, and the current Interest from the user. 
	void SavingsAccount::display(std::ostream& os) const {
		
		os << "Account type: Savings" << setprecision(2) << fixed << endl;
		os << "Balance: $" << balance() << endl;
		os << "Interest Rate (%): " << (interest *100 )<< endl;

	}

}
