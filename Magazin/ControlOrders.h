#pragma once
#include <fstream>
#include "list.h"
#include "order.h"

struct ControlOrder {

private:
	List<Order> l;
public:

	ControlOrder() {

		this->load();
	}

	void load() {
		ifstream f("orders.txt");
		int id, cId, ammount;
		Order o;
		while (!f.eof()) {
			f >> id >> cId >> ammount;
			o.setAmmount(ammount);
			o.setCustomerId(cId);
			o.setId(id);
			l.addFinal(o);
		}
	}

	int nextId() {
		Node<Order>* it = l.getHead();

		if (l.getHead() == NULL)
			return 1;

		while (it->next!= NULL) {

			it = it->next;
		}
		return it->data.getId() + 1;
	}

	void adaugare(Order o) {

		l.addFinal(o);
	}

	string toSave() {
		Node<Order>* it = l.getHead();
		string s = "";
	
		while (it->next != NULL) {
			s += it->data.toSave();
			it = it->next;
			if (it != NULL)
				s += '\n';
		}
		return s;
	}

	void save() {

		ofstream g("orders.txt");
		g << toSave();
	}

};