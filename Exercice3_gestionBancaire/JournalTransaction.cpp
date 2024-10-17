#include "JournalTransaction.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//---------> Constructeur avec parametre
JournalTransaction::JournalTransaction(const string& nameFile) : nomFichier(nameFile)
{
    fichier = new ofstream(); // Allouer de la mémoire pour ofstream
    fichier->open(nomFichier, ios::app | ios::out); // Ouvrir le fichier
    if (!fichier->is_open()) {
        cerr << "Erreur: Impossible d'ouvrir le fichier: " << nomFichier << endl;
        delete fichier; // Libérer la mémoire
        fichier = nullptr;
    }
    else {
        cout << "Fichier ouvert avec succes." << endl;
    }
}

//---------> Constructeur de recopie
/*JournalTransaction::JournalTransaction(const JournalTransaction& j)
{
this->nomFichier = j.nomFichier;
this->fichier.open(this->nomFichier,iostream::app);//ouvrir le fichier again
if (!this->fichier.is_open()) 
  cerr << "Erreur: Impossible d'ouvrir le fichier" <<endl;
}*/



//------> Fonction ajouterTransaction
void JournalTransaction::ajouterTransaction(const string& infos)
{
if (this->fichier->is_open())
  *(this->fichier) << infos << endl;//ajout à la fin
else 
  cerr << "Erreur: Le fichier n'est pas ouvert." <<endl;
}


//-------> Fonction afficherHistorique()
void JournalTransaction::afficherHistorique() const
{
	// Ouvrir le fichier en mode lecture
	ifstream fichierLecture(this->nomFichier);
    string ligne;
    while (getline(fichierLecture, ligne))
        cout << ligne << endl; // Afficher chaque ligne du fichier
    fichierLecture.close();
}


//------> Destructeur
JournalTransaction::~JournalTransaction()
{
    if (fichier && fichier->is_open()) {
        fichier->close();
        delete fichier; // Libérer la mémoire
    }
}
