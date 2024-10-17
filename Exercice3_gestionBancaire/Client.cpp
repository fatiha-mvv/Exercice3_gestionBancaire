#include "Client.h"
#include <iostream>
using namespace std;

//------> Constructeur avec parametre
Client::Client(string nom, string prenom, string tel, string adr, int age)
	:nom(nom),prenom(prenom),telephone(tel),adresse(adr),age(age)
{}


//------> Constructeur de recopie
Client::Client(const Client& cl)
	:nom(cl.nom), prenom(cl.prenom),
	telephone(cl.telephone), adresse(cl.adresse), age(cl.age)
{}


//------> Fonction d'affichage
void Client::afficher() const
{
	cout << " ********** Informations de client **********" << endl;
	cout << "nom: " << this->nom << endl;
	cout << "prenom: " << this->prenom << endl;
	cout << "age: " << this->age << endl;
	cout << "adresse: " << this->adresse << endl;
	cout << "telephone: " << this->telephone << endl;
	cout << " ***********************************" << endl;
}