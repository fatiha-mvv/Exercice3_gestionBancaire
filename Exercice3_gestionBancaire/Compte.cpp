#include "Compte.h"
#include <iostream>
#include <string>

using namespace std;


//------> Constructeur avec parametres
Compte::Compte(int idd,Type_compte typeAcc, double soldee, Client c, JournalTransaction *j,double taux)
	:id(idd), typeCompte(typeAcc), solde(soldee), proprietaire(c),
	historique_journal(j), tauxInterets(taux)
{}


//------> Constructeur de recopie
Compte::Compte(Compte& c)
:id(c.id), typeCompte(c.typeCompte),solde(c.solde),proprietaire(c.proprietaire)
,historique_journal(c.historique_journal), tauxInterets(c.tauxInterets)
{}


//--------> Fonction afficherSoldeActuel
void Compte::consulterSolde() const
{
	cout << "le compte ayant id= " << this->id << " a le Solde: " << this->solde << endl;
}


//------> Fonction deposerArgent
bool Compte::deposerArgent(double montant)
{
	if (montant <= 0)
	{
		cout << "le montant saisit doit etre strictement positif" << endl;
		return false;
	}
	this->solde += montant;
	//enregistrer transaction
	this->historique_journal->ajouterTransaction("Depot de " + to_string(montant) + "DH");
	return true;
}


//------> Fonction retirerArgent
bool Compte::retirerArgent(double montant)
{
	//si un montant négatif a été saisit
	if (montant <= 0)
	{
		cout << "le montant saisit doit etre strictement positif" << endl;
		return false;
	}
	//si le solde est insuffisant
	if (this->solde < montant)
	{
		cout << "!! Resus de Retrait !! Le solde est insuffisant" << endl;
		return false;
	}
	//sinon
	this->solde -= montant;
	//enregistrer transaction
	this->historique_journal->ajouterTransaction("Retrait de " + to_string(montant) + "DH");
	return true;
}



//-------> Fonction transferer
bool Compte::transferer(double montant, Compte& destination)
{
	//si le retrait d'argent de compte courant a reussit
	if (this->retirerArgent(montant))
	{
		//deposer argent dans le compte destinataire
		destination.deposerArgent(montant);

		//enregistrer transaction
		this->historique_journal->ajouterTransaction
		("Transfert de " + to_string(montant) + "DH vers le compte ayant comme ID : " + to_string(destination.id));
		return true;
	}
	cout << "!! Transfert d'argent impossible !!" << endl;
	return false;
}


//-------> Fonction afficher
void Compte::afficher() const
{
	cout << "************ Informations du Compte ************** " << endl;
	cout << "ID : " << this->id << endl;
	cout << "Solde : " << this->solde << endl;
	if (typeCompte == EPARGNE) {
		cout << "Type de compte : Epargne" <<endl;
		cout << "Taux d'intérêt : " << this->tauxInterets << "%" <<endl;
	}
	else 
		cout << "Type de compte: Courant" <<endl;

	std::cout << "---> Historique des Transactions : " << std::endl;
	this->historique_journal->afficherHistorique();

	cout << "le proprietaire : " << endl;
	this->proprietaire.afficher();
	cout << "************************************************* " << endl;
}


//-------> destructeur
Compte::~Compte()
{}
