#include "dulce.h"
#include <cstddef>
#include <string.h>
#include <istream>
#include <ostream>
#include <iostream>
Dulce::Dulce()
{
	this->cod = 0;
	this->nume = NULL;
	this->pret = 0;
}

Dulce::Dulce(int cod, const char* nume, float pret)
{
	this->cod = cod;
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, 1 + strlen(nume), nume);
	this->pret = pret;
}

Dulce::Dulce(const Dulce& d)
{
	this->cod = d.cod;
	this->nume = new char[strlen(d.nume) + 1];
	strcpy_s(this->nume, 1 + strlen(d.nume), d.nume);
	this->pret = d.pret;
}

Dulce::~Dulce()
{
	if (this->nume)
	{
		delete[] this->nume;
		this->nume = NULL;
	}
}


int Dulce::getCod()
{
	return this ->cod;
}

char* Dulce::getNume()
{
	return this->nume;
}

float Dulce::getPret()
{
	return this->pret;
}

void Dulce::setCod(int cod) {
	this->cod = cod;
}

void Dulce::setNume(const char* nume)
{
	if (this->nume) {
		delete[] this->nume;
	}
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
}

void Dulce::setPret(float pret) {
	this->pret = pret;
}

Dulce& Dulce::operator=(const Dulce& d) {
	this->setCod(d.cod);
	this->setNume(d.nume);
	this->setPret(d.pret);
	return *this;
}

bool Dulce:: operator==(const Dulce& d) {
	return strcmp(this->nume, d.nume) == 0 && this->cod == d.cod && this->pret== d.pret;
}

bool Dulce::operator!()
{
	if (this->cod == NULL && (this->nume == NULL || strlen(this->nume) == 0))
	{
		return true;
	}
	return false;
}

ostream& operator<<(ostream& oc, const Dulce& d)
{
	oc << d.cod << " " << d.nume << " " << d.pret;
	return oc;
}

istream& operator>>(istream& is, Dulce& d)
{
	if (&is == &cin)
	{
		cout << "Dati varsta: ";
	}
	int cod;
	is >> cod;

	if (&is == &cin)
	{
		cout << "Dati numele: ";
	}
	char* nume = new char[20];
	is >> nume;

	if (strlen(nume) == 0)
	{
		d.setNume("");
		return is;
	}

	if (&is == &cin)
	{
		cout << "Dati pret: ";
	}
	int pret;
	is >> pret;
	
	d.setCod(cod);
	d.setNume(nume);
	d.setPret(pret);
	delete[] nume;
	return is;
}
