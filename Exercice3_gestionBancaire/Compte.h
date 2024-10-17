#pragma once
#include "Client.h"
#include "JournalTransaction.h"


//------> enumeration pour representer types des comptes
enum Type_compte
{
	COURANT, EPARGNE
};


//------> Classe Compte
class Compte
{

private:
	//les attributs
	int id;
	Type_compte typeCompte;
	double tauxInterets; //pour Type_Compte == EPARGNE
	double solde;
	Client proprietaire;
	JournalTransaction *historique_journal;
public:
	//tauxInterets est initialisé à 0 car il est utilisé uniquement pour les comptes épargne
	//constructeur avec parametres
	Compte(int,Type_compte, double, Client, JournalTransaction*,double tauxInterets=0.0);
	//constructeur de recopie
	Compte(Compte&);
	//les methodes
	void consulterSolde()const;
	bool deposerArgent(double montant);
	bool retirerArgent(double montant);
	bool transferer(double montant,Compte& destination);
	void afficher()const;
	//destructeur
	~Compte();
};

