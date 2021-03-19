#pragma once
#include <ostream>
using namespace std;

class Dulce
{
private:
	int cod;
	char* nume;
	float pret;
public:
	Dulce();
	Dulce(int cod,const char* nume, float pret);
	Dulce(const Dulce& d);
	~Dulce();
	int getCod();
	char* getNume();
	float getPret();
	void setCod(int cod);
	void setNume(const char* nume);
	void setPret(float pret);
	Dulce& operator=(const Dulce& d);
	bool operator==(const Dulce& d);
	bool operator!();
	friend ostream& operator<<(ostream& oc, const Dulce& d);
	friend istream& operator>>(istream& is, Dulce& d);
};
