#pragma once
#include "orderDetails.h"
#include "ControlProduct.h"
#include "list.h"
#include <fstream>

struct ControlOrderDetails {

private:
	ControlProduct p;
	List<OrderDetails>  l;
public:

	ControlOrderDetails() {
		this->load();
	}

	void load() {
		ifstream f("ordersdetails.txt");
		int id, idP, quantity, orderId;
		double price;
		OrderDetails o;
		while (!f.eof()) {

			f >> id >>orderId>> idP >> price >> quantity;
			o.setId(id);
			o.setIdP(idP);
			o.setPrice(price);
			o.setQuantity(quantity);
			o.setOrderId(orderId);
			l.addFinal(o);
		}

	}

	int nextId() {

		Node<OrderDetails>* it = l.getHead();
		if (l.getHead() == NULL)
			return 0;
		while (it->next != NULL) {

			it = it->next;
		}
		return it->data.getId() + 1;
	}

	void adaugare(OrderDetails o) {

		l.addFinal(o);
	}

	void afisareProduseComanda(int orderId) {

		Node<OrderDetails>* it = l.getHead();

		while (it != NULL) {

			if (it->data.getOrderId() == orderId) {

				cout << "Numele produsului: " << p.findNumeById(it->data.getIdP()) << endl;
				cout << "Pretul produsului: " << it->data.getPrice() << endl;
				cout << "Numarul de bucati: " << it->data.getQuantity() << endl<<endl;
				
			}
			it = it->next;
		}
	}

	string toSave() {
		string s = "";
		Node<OrderDetails>* it = l.getHead();

		while (it != NULL) {
			s += it->data.toSave();
			it = it->next;
			if (it != NULL)
				s += '\n';
		}
		return s;
	}

	void save() {

		ofstream g("ordersDetails.txt");
		g << toSave();
	}

	int findPozByProductAndOrderId(Product p, int orderId) {
		Node<OrderDetails>* it = l.getHead();

		int contor = 0;

		while (it!= NULL) {

			if (it->data.getIdP() == p.getID() && orderId == it->data.getOrderId())
				return contor;
			contor++;
			it = it->next;
		}
	}

	void stergereByProductAndOrderId(Product p, int orderId) {

		l.stergerePoz(findPozByProductAndOrderId(p, orderId));

	}

	OrderDetails findByProductAndOrderId(Product p, int orderId) {

		Node<OrderDetails>* it = l.getHead();

		while (it != NULL) {

			if (it->data.getOrderId() == orderId && it->data.getIdP() == p.getID())
				return it->data;
			it = it->next;
		}


	}

};