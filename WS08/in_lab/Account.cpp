
#include "Account.h"

#include <iostream>
#include <cstring>

using namespace std;

namespace sict {

	//Constructor, implementing the current balance on the current account. If the balance is
	//below 0 the object is set in a Safe Empty State.
	Account::Account(double n_balance) {

		if (n_balance > 0) {
			m_balance = n_balance;
		}
		else {
			m_balance = 0.0;
		}

	}

	bool Account::credit(double transaction) {
		bool result = true;

		//Calculate the price of how much the transaction will cost.
		double total = balance() + transaction;

		//Compare to see if the transaction is above 0. This means that the 
		//transaction was sucessful. 
		if (total >= 0) {
			m_balance += transaction;
			result = true;
		}
		else {
			result = false;
		}

		return result;
	}

	bool Account::debit(double transaction) {
		bool result = true;

		//Calculate the total balance. The current balance - the cost of the transaction. 
		double total = m_balance - transaction;

		//Compare to see if the total of the transaction is not greater than the current balance.
		//If the total is greater the transaction can not go through.
		if (m_balance > total) {
			m_balance -= transaction;
			result = true;
		}
		else {
			result = false;
		}

		return result;
	}

	//Returns the current balance in the account
	double Account::balance() const {
		return m_balance;
	}

}
