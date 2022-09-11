#pragma once
using namespace std;
#include <string>
#include <iostream>

struct OrderDetails {

private: 
	int id;
	int orderId;
	int idP;
	double price;
	int quantity;


public:

	OrderDetails() {


	}

	OrderDetails(int id, int orderId, int idP, double price, int quantity) {

		this->id = id;
		this-> orderId = orderId;
		this->idP = idP;
		this->price = price;
		this->quantity = quantity;
	}

	void setId(int id) {
		this->id = id;
	}
	int getId() {
		return id;
	}

	void setIdP(int idP) {
		this->idP = idP;
	}
	int getIdP() {
		return idP;
	}

	void setPrice(double price) {

		this->price = price;
	}
	double getPrice() {

		return price;
	}

	void setQuantity(int quantity) {
		this->quantity = quantity;
	}
	int getQuantity() {
		return quantity;
	}

	void setOrderId(int orderId) {
		this->orderId = orderId;
	}
	int getOrderId() {
		return orderId;
	}

	string descriere() {
		string s = "";
		s += "Id: " + to_string(id) + '\n';
		s += "Id produs: " + to_string(idP) + '\n';
		s += "Id comanda: " + to_string(orderId) + '\n';
		s += "Pret produs: " + to_string(price) + '\n';
		s += "Cantitate: " + to_string(quantity) + '\n';
		return s;

	}
	string toSave() {
		return to_string(id) + ' ' + to_string(orderId) + ' ' + to_string(idP) + ' ' + to_string(price) + ' ' + to_string(quantity);
	}

};