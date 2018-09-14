
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"
#include <iostream>

namespace sict {
	class SavingsAccount : public Account {
	private:
		double interest;
	public:
			// TODO: constructor initializes balance and interest rate
		SavingsAccount(double, double);

			// TODO: perform month end transactions
		void monthEnd();

			// TODO: display inserts the account information into an ostream			
		void display(std::ostream&) const;
	};
}
#endif