
#include "Account.h"

#include <iostream>
#include <cstring>

using namespace std;

namespace sict {

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

		double total = balance() + transaction;

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

		double total = m_balance - transaction;

		if (m_balance > total) {
			m_balance -= transaction;
			result = true;
		}
		else {
			result = false;
		}

		return result;
	}

	double Account::balance() const {
		return m_balance;
	}

}
