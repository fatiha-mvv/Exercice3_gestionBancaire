#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class JournalTransaction
{
private:
	string nomFichier; //nom de fichier
	//flux de fichier ou les transaction vont être enregistrées
	ofstream *fichier;
public:
	//constructeur qui va ouvrir le fichier en mode append (ajout)
	JournalTransaction(const string& nomFichier);

	//constructeur de recopie
	JournalTransaction(const JournalTransaction&)=delete;

	//destructeur pour fermer le fichier
	~JournalTransaction();

	//methode pour ajouter de contenue au fichier
	//generalement enregistrer une transaction
	void ajouterTransaction(const string&);

	// afficher l'historique du Compte
	void afficherHistorique()const;
};

