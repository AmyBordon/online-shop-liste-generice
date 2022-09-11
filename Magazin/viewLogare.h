#pragma once
#include "viewCustomer.h"
#include "viewAdmin.h"

struct ViewLogare {

private:
	ControlCustomer controlCustomers;
	ViewAdmin admin;
	ViewCustomer customer;

public:

	void meniu() {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Apasati tasta 1 pentru a va loga ca si client" << endl;
		cout << "Apasati tasta 2 pentru a va loga ca si administrator" << endl;
		cout << "Apasati tasta 3 pentru a va intregistra" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}

	void play() {

		int tasta;
		bool play = 1;

		while (play) {

			meniu();
			cin >> tasta;

			switch (tasta) {
			case 1:
				logareClient();
				break;
			case 2:
				admin.play();
				break;
			case 3:
				intrgistrare();
				break;
			default:
				cout << "NU ati introdus o tasta valida" << endl;
				break;

			}
		}
	}

	void logareClient() {

		string email, parola;

		cout << "Introduceti adresa de email" << endl;
		cin >> email;
		cout << "Introduceti parola" << endl;
		cin >> parola;
		if (controlCustomers.emailAndParolaValide(email, parola)) {
			customer.setLogat(controlCustomers.findByEmailAndParola(email, parola));
			customer.play();
		}
		else
			cout << "Nu ati introdus date valide" << endl;

	}


	

	void intrgistrare() {
		string nume, prenume, parola, email;
		int id;
		
		cout << "Introduceti numele" << endl;
		cin >> nume;
		cout << "Introduceti prenumele" << endl;
		cin >> prenume;
		cout << "Introduceti adresa de email" << endl;
		cin >> email;
		cout << "Introduceti parola" << endl;
		cin >> parola;
		id = controlCustomers.nextId();
		Customer c(id, email, parola, nume, prenume);
		controlCustomers.save();
	}

};