#pragma once
using namespace std;
#include <string>
#include <iostream>
struct Order {

private:
	int id;
	int customerId;
	double ammount;
public:

	Order() {

	}

	Order(int id, int customerId, double ammount) {
		this->id = id;
		this->customerId = customerId;
		this->ammount = ammount;
	}

	void setId(int id) {
		this->id = id;
	}
	int getId() {
		return id;
	}

	void setCustomerId(int customerId) {
		this->customerId = customerId;
	}
	int getCustomerId() {
		return customerId;
	}

	void setAmmount(double ammount) {
		this->ammount = ammount;
	}
	double getAmmount() {
		return ammount;
	}

	string descriere() {
		string s = "";
		s += "Id comanta: " + to_string(id) + '\n';
		s += "Id client: " + to_string(customerId) + '\n';
		s += "Pret final: " + to_string(ammount) + '\n';
		return s;
	}

	string toSave() {
		
		return to_string(id) + ' ' + to_string(customerId) + ' ' + to_string(ammount);
	}
};