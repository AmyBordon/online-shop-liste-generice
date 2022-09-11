#pragma once
#include "customer.h"
#include "list.h"
#include <fstream>

struct ControlCustomer {

private:
	List<Customer>l;
public:
	ControlCustomer() {
		this->load();
	}

	void load() {

		ifstream f("customers.txt");
		int id;
		string nume, prenume, parola, email;
		Customer c;
		while (!f.eof()) {
			f >> id >> nume >> prenume >> email >> parola;
			c.setEmail(email);
			c.setId(id);
			c.setNume(nume);
			c.setPrenume(prenume);
			c.setPassword(parola);
			l.addFinal(c);
		}
	}

	int nextId() {

		Node<Customer>* it = l.getHead();

		while (it->next != NULL) {
			it = it -> next;
		}
		return it->data.getId() + 1;
	}

	void adaugare(Customer c) {

		l.addFinal(c);
	}

	bool emailAndParolaValide(string email, string parola) {


		Node<Customer>* it = l.getHead();

		while (it != NULL) {
			if (it->data.getEmail() == email && it->data.getPassword() == parola)
				return 1;
			it = it->next;
		}
		return 0;
	}

	Customer findByEmailAndParola(string email, string parola) {

		Node<Customer>* it = l.getHead();

		while (it != NULL) {
			if (it->data.getEmail() == email && it->data.getPassword() == parola)
				return it->data;
			it = it->next;
		}
	}

	string toSave() {
		string s = "";
		Node<Customer>* it = l.getHead();

		while (it != NULL) {
			s += it->data.toSave();
			it = it->next;
			if (it != NULL)
				s += '\n';
			
		}
		return s;
	}

	void save() {

		ofstream g("customers.txt");
		g << toSave();
	}

};