#pragma once
#include "product.h"
#include "list.h"
#include <fstream>

struct ControlProduct{

private:
	List<Product> l;
public:

	ControlProduct() {

		this->load();
	}

	void load() {

		Product p;
		int id, stock;
		string name;
		double price;
		ifstream f("products.txt");

		while (!f.eof()) {

			f >> id >> name >> price >> stock;
			p.setPrice(price);
			p.setName(name);
			p.setID(id);
			p.setStock(stock);
			l.addFinal(p);
		}
	}

	bool numeValid(string nume) {

		Node<Product>* it = l.getHead();

		while (it != NULL) {
			if (it->data.getName() == nume) {
				return true;
				
			}
			it = it->next;
		}
		return 0;
	}

	Product findProductByNume(string nume) {

		Node<Product>* it = l.getHead();

		while (it!=NULL) {
			if (it->data.getName() == nume) {
				return it->data;
			}
			it = it->next;
		}

	}

	string findNumeById(int id) {


		Node<Product>* it = l.getHead();

		while (it != NULL) {
			if (it->data.getID() == id) {
				return it->data.getName();
			}
			it = it->next;
		}
	}

	void afisare() {

		Node<Product>* it = l.getHead();

		while (it != NULL) {
			cout << "***********************************" << endl;
			cout << it->data.descriere();
			cout << "***********************************" << endl;
			it = it->next;
		}
	}

	int nextId() {

		Node<Product>* it = l.getHead();

		while (it->next != NULL) {

			it = it->next;
		}
		return it->data.getID() + 1;
	}

	void adaugare(Product p) {

		l.addFinal(p);
	}

	string toSave() {
		string s = "";
		Node<Product>* it = l.getHead();

		while (it != NULL) {
			s += it->data.toSave();
			it = it->next;
			if (it != NULL)
				s += '\n';
		}
		return s;
	}

	void save() {
		ofstream g("products.txt");
		g << toSave();
	}

	int findPozById(int id) {
		int contor = 0;
		Node<Product>* it = l.getHead();

		while (it != NULL) {
			if (it->data.getID() == id)
				return contor;
			it = it->next;
			contor++;
		}
	}

	Product findProductById(int id) {
		Node<Product>* it = l.getHead();

		while (it != NULL) {
			if (it->data.getID() == id)
				return it->data;
			it = it->next;
			
		}
	}

	void stergere(int poz) {

		l.stergerePoz(poz);
	}

	void afisareProduseStoc0() {

		Node<Product>* it = l.getHead();

		while (it != NULL) {

			if (it->data.getStock() == 0)
				cout << it->data.descriere();
			it = it->next;
		}
	}

	void afisareProduseStoc() {

		Node<Product>* it = l.getHead();

		while (it != NULL) {

			if (it->data.getStock())
				cout << it->data.descriere();
			it = it->next;
		}
	}
};