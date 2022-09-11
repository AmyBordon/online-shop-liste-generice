#pragma once
#include "ControlCustomers.h"
#include "ControlOrders.h"
#include "ControlOrderDetails.h"
#include "ControlProduct.h"


struct ViewCustomer {

private:
	Customer logat;
	ControlProduct controlProducts;
	ControlOrderDetails controlOrdersDetails;
	ControlOrder controlOrders;

	Order order;

public: ViewCustomer() {

		order.setId(controlOrders.nextId());
		order.setAmmount(0);
		order.setCustomerId(logat.getId());
	}
public:

	void setLogat(Customer l) {

		this->logat = l;
	}

	void meniu() {
		cout << "_________________________________________________________________" << endl;
		cout << "| Apasati tasta 1 pentru a adauga un produs la comanda          |" << endl;
		cout << "| Apasati tasta 2 pentru a vizualiza produsele din cos          |" << endl;
		cout << "| Apasati tasta 3 pentru a modifica cosul de cumparaturi        |" << endl;
		cout << "| Apasati tasta 4 pentru a vizualiza produsele                  |" << endl;
		cout << "| Apasati tasta 5 pentru a finaliza comanda                     |" << endl;
		cout << "|_______________________________________________________________|" << endl;
	}

	void play() {
		int tasta;
		bool p = 1;
		while (p) {
			meniu();
			cin >> tasta;
			switch (tasta) {

			case 1:
				addProdus();
				break;
			case 2:
				cos();
				break;
			case 3:
				modificareCos();
				break;

			case 4:
				controlProducts.afisare();
				break;

			case 5:
				final();
				p = 0;
				break;

			default:
				cout << "Nu ati introdus o tasta valida" << endl;
				break;
			}

		}
	}

	void addProdus() {
		string nume;
		int quantity;
		cout << "Introduceti numele produsului" << endl;
		cin >> nume;
		cout << "Introduceti numarul de bucati" << endl;
		cin >> quantity;
		OrderDetails o;
		Product p=controlProducts.findProductByNume(nume);

		if (controlProducts.numeValid(nume)) {

			if (p.getStock() < quantity)
				cout << "Nu s-a adaugat produsul, stocul este insuficient" << endl;
			else {
				o.setId(controlOrdersDetails.nextId());
				o.setOrderId(order.getId());
				o.setIdP(p.getID());
				o.setPrice(p.getPrice()*quantity);
				o.setQuantity(quantity);
				controlOrdersDetails.adaugare(o);
				p.setStock(p.getStock() - quantity);
				controlOrdersDetails.save();
				order.setAmmount(order.getAmmount() + o.getPrice());
			}
		}
		else
			cout << "Nu ati introdus un nume de produs valid" << endl;
	}
	
	void cos() {

		controlOrdersDetails.afisareProduseComanda(order.getId());
		cout << "Suma totala: " << order.getAmmount() << endl;

	}

	void meniuModificareCos() {
		cout << "Apasati tasta 0 pentru a inceta modificarile" << endl; 
		cout << "Apasati tasta 1 pentru a sterge un produs din cos" << endl;
		cout << "Apasati tasta 2 pentru a modifica cantitatea dintr-un anumit produs" << endl;
	}

	void modificareCos() {

		bool play=1;
		int tasta;
		while (play) {
			meniuModificareCos();
			cin >> tasta;
			switch (tasta) {

			case 1:
				stergereProdus();
				break;
			case 2:
				modificareCantitateProdus();
				break;

			case 0:
				play = 0;
			default:
				cout << "Nu ati introdus o tasta valida" << endl;

			}
		}
		
	}

	void stergereProdus() {
		string nume;
		cout << "introduceti numele produsului" << endl;
		cin >> nume;
		Product p = controlProducts.findProductByNume(nume);
		order.setAmmount(order.getAmmount() - p.getPrice() * controlOrdersDetails.findByProductAndOrderId(p, order.getId()).getQuantity());
		controlOrdersDetails.stergereByProductAndOrderId(p, order.getId());
		controlOrdersDetails.save();
		
	}

	void modificareCantitateProdus() {
		string nume;
		int quantity;
		cout << "Introduceti numele produsului" << endl;
		cin >> nume;
		Product p = controlProducts.findProductByNume(nume);
		cout << "Introduceti noua cantitate" << endl;
		cin >> quantity;
		OrderDetails o;

		if (quantity > p.getStock()+o.getQuantity()) {

			cout << "Modificarile nu au fost realizate, nu sunt " << quantity << " produse in stoc" << endl;
		}
		else {
			p.setStock(abs(o.getQuantity() - quantity));
			o.setQuantity(quantity);
		}

	}

	void final() {

		controlOrders.adaugare(order);
		controlOrders.save();


	}

};