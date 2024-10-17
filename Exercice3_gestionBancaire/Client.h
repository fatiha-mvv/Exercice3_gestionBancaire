#pragma once
#include <iostream>
using namespace std;
class Client
{
private:
	string nom;
	string prenom;
	string telephone;
	string adresse;
	int age;

public:
	Client(string, string, string, string, int);
	Client(const Client&);
	void afficher()const;
};

