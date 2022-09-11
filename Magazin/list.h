#pragma once
#include "node.h"
template <typename T>

struct List {
private:
	Node<T>* head = NULL;
public:

	void addFinal(T n) {

		if (head == NULL) {

			head = new Node<T>();
			head->data = n;
			head->next = NULL;
		}
		else {

			Node<T>* nou = new Node<T>();
			Node<T>* it = head;
			while (it->next != NULL)
				it = it->next;
			
			nou->next = NULL;
			nou->data = n;
			it->next = nou;
		}
	}

	void stergereStart() {

		head = head->next;
	}

	void stergerePoz(int poz) {

		if (poz == 0) {
			stergereStart();
		}
		else {

			Node<T>* it = head;
			int contor = 0;
			while (contor < poz-1) {
				it = it->next;
				contor++;
			}
			it->next = it->next->next;
		}
	}

	Node<T>* getHead() {
		return head;
	}

};