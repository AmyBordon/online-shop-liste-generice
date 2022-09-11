#pragma once
#include <string>
using namespace std;
#include <iostream>

struct Customer {
private:
	int id;
	string email;
	string password;
	string nume;
	string prenume;


public:

	Customer() {

	}

	Customer(int id, string email, string password, string nume, string prenume) {

		this->id = id;
		this->email = email;
		this->nume = nume;
		this->prenume = prenume;
	}


	void setId(int id) {
		this->id = id;
	}
	int getId() {
		return id;
	}

	void setEmail(string email) {

		this->email = email;
	}
	string getEmail() {
		return email;
	}

	void setPassword(string password) {
		this->password = password;
	}
	string getPassword() {
		return password;
	}

	void setNume(string nume) {
		this->nume = nume;
	}
	string getNume() {
		return nume;
	}

	void setPrenume(string prenume) {
		this->prenume = prenume;
	}
	string getPrenume() {
		return prenume;
	}

	string descriere() {
		string s = "";
		s += "Id client: " + to_string(id) + '\n';
		s + "Nume: " + nume + '\n';
		s += "Prenume: " + prenume + '\n';
		s += "Email: "+email + '\n';
		return s; 
	}

	string toSave() {
		return to_string(id) + ' ' + nume + ' ' + prenume + ' ' + email + ' ' + password;
	}

};