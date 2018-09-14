// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double n_balance, double n_transfee, double n_mon_fee) : Account(n_balance) {
		if (n_transfee > 0 && n_mon_fee > 0) {
			transfee = n_transfee;
			mon_fee = n_mon_fee;
		}
		else {
			transfee = 0.0;
			mon_fee = 0.0;
		}
	}


	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double transaction) {
		bool result = true;
		double total = balance() + transaction;

		if (total >= 0) {
			result = true;
			transaction -= transfee;
			Account::credit(transaction);

		}
		else {
			result = false;
		}

		return result;
	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double transaction) {
		bool result = true;
		double total = balance() + transaction;

		if (balance() > transaction) {
			result = true;
			transaction += transfee;
			Account::debit(transaction);
		}
		else {
			result = false;
		}

		return result;
	}


	// monthEnd debits month end fee
	//
	void ChequingAccount::monthEnd() {
		debit(mon_fee);
	}


	// display inserts account information into ostream os
	//
	void ChequingAccount::display(std::ostream& os) const {

		os << "Account type: Chequing" << setprecision(2) << fixed << endl;
		os << "Balance: $" << balance() << endl;
		os << "Per Transaction Fee: " << transfee << endl;
		os << "Monthly Fee: " << mon_fee << endl;

	}



}