#pragma once
#include "ControlCustomers.h"
#include "ControlOrders.h"
#include "ControlProduct.h"

struct ViewAdmin {

private:
	ControlProduct controlProducts;
	string parola="informatica";
	

public:

	string  getParola() {
		return parola;
	}

	void setParola(string parola) {
		this->parola=parola;
	}



	void meniu() {

		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "+ Apasati tasta 1 pentru a adauga un produs                         +" << endl;
		cout << "+ Apasati tasta 2 pentru a sterge un produs                         +" << endl;
		cout << "+ Apasati tasta 3 pentru a modifica pretul unui produs              +" << endl;
		cout << "+ Apasati tasta 4 pentru a modifica stocul unui produs              +" << endl;
		cout << "+ Apasati tasta 5 pentru a vedea produsele care nu mai sunt in stoc +" << endl;
		cout << "+ Apasati tasta 6 pentru a vedea toate produsele                    +" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	}

	void play() {

		int tasta;
		bool play = 1;
		string parola;

		cout << "Introduceti parola" << endl;
		cin >> parola;
		if (parola == getParola()) {

			while (play) {

				meniu();
				cin >> tasta;
				switch (tasta) {

				case 1:
					addProdus();
					break;
				case 2:
					stergereProdus();
					break;

				case 3:
					modificarePret();
					break;

				case 4:
					modificareStoc();
					break;

				case 5:
					controlProducts.afisareProduseStoc0();
					break;

				case 6:
					controlProducts.afisare();

				default:
					cout << "Nu ati introdus o tasta valida" << endl;
					break;
				}
			}
		}
		else
			cout << "Parola incorecta" << endl;
	}

	void addProdus() {

		string nume;
		double pret;
		int stoc;

		cout << "Introduceti numele" << endl;
		cin >> nume;
		cout << "Introduceti pretul" << endl;
		cin >> pret;
		cout << "Introduceti stocul" << endl;
		cin >> stoc;

		Product p;
		p.setID(controlProducts.nextId());
		p.setName(nume);
		p.setPrice(pret);
		p.setStock(stoc);
		controlProducts.adaugare(p);
		controlProducts.save();
	}

	void stergereProdus() {

		int id;

		cout << "Introduceti id-ul produsului" << endl;
		cin >> id;
		controlProducts.stergere(controlProducts.findPozById(id));
		controlProducts.save();
	}

	void modificarePret() {

		int id;
		double pret;

		cout << "Introduceti id-ul produsului" << endl;
		cin >> id;
		cout << "Introduceti noul pret" << endl;
		cin>> pret;
		Product p=controlProducts.findProductById(id);
		p.setPrice(pret);
		controlProducts.save();
		
	}

	void modificareStoc() {

		int id, stoc;

		cout << "Introduceti id-ul produsului" << endl;
		cin >> id;
		cout << "Introduceti noul stoc" << endl;
		cin >> stoc;

		Product p = controlProducts.findProductById(id);
		p.setStock(stoc);
		controlProducts.save();

	}

};