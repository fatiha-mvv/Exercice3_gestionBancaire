#include <iostream>
#include "Compte.h"
#include <iostream>
using namespace std;
int main()
{

    //creation de deux clients
    Client cl1("nom1","prenom1","09887766","adresse1/",42);
    Client cl2("nom2", "prenom2", "0644755766", "adresse2/", 33);
    // Création de premier compte
    JournalTransaction* journal1 = new JournalTransaction("journal_1.txt");
    Compte compte1(1,COURANT, 1000.0,cl1,journal1,0.0);
    
    //tester les fonctions
    compte1.deposerArgent(200.0);
    compte1.retirerArgent(100.0);
    compte1.afficher();
    compte1.consulterSolde();

}

