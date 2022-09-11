#pragma once
#include <iostream>
using namespace std;
#include <string>


struct Product {

private:
	int id;
	string name;
	double price;
	int stock;

public:

	Product() {

	}

	Product(int id, string name, double price, int stock) {
		this->id = id;
		this->name = name;
		this->price = price;
		this->stock = stock;
	}

	void setID(int id) {
		this->id = id;
	}
	int getID() {
		return id;
	}

	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}

	void setPrice(double price) {
		this->price = price;
	}
	double getPrice() {
		return price;
	}

	void setStock(int stock) {
		this->stock = stock;
	}
	int getStock() {
		return stock;
	}

	string descriere() {
		string s = "";
		s += "Id-ul produsului: " + to_string(id) + '\n';
		s += "Numele produsului: " + name + '\n';
		s += "Pretul produsului: " + to_string(price) + '\n';
		s += "Stocul produsului: " + to_string(stock) + '\n';
		return s;
	}

	string toSave() {
		return to_string(id) + ' ' + name + ' ' + to_string(price) + ' ' + to_string(stock);
	}

};
