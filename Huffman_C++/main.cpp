/*
Cours: programmation c++
étudiants: 💖Rania BEN DHIA💖
           💖Marwan AL OMARI💖
*/

//bibliothèques
#include <iostream>
#include <fstream>
#include "texte.h"
#include<string>
using namespace std;

int main(){
//premiere entrée qui est sous la forme des caractères pour afficher leurs frequences
    texte a("abcdef");
    int b;
    cout << "\n";
    cout << "Nos caractères: ";
    cout << "\n";
    //chaines des caractères correspondantes
    char ch[] = { 'a','b','c','d','e','f' };
    //fréquences des caractères
    double fr[] = { 5,3,7,1,10,2 };
    cout << "\n";
    cout << a.getTexte() << "  " << endl;
    cout << "\n";
    //construction de l'arbre de codage
    a.Huffmancodes(ch, fr, 6);// char, fréq, taille
    cout << "\n";
    cout << "affichage du code binaire:" << endl;
    cout << "\n";
    /* fichier d'entrée: input.txt qui contient une chaine de caractères pour la convertir et afficher le code binaire correspondant. */
    string filename = "input.txt"; //
    ifstream in(filename.c_str()); //lire le fichier
    if (!in){
        cout << "vous ne pouvez pas ouvrir le fichier.\n";
        return 0;
    }
    char mon_texte[255];
    while (!in.eof()){
        in.getline(mon_texte, 255);
        texte a2(mon_texte);
        char ch2 [1024];
        cout << "\n" << endl;
        cout << "notre chaine : \n" << "'" << a2.getTexte() << "'" << endl;
        b = a2.conversion(ch2, a2.getTexte(), taille);
        ch2[b];
        double fr2[] = { 4,5,2,9,3,1,8,6,7,0 };
        a2.Huffmancodes(ch2, fr2, b);
        cout << "\n";
        cout << "Les codes binaires associés aux caractères du fichier " << "< " << a2.getTexte() << " >" << " sont saisis selon l'ordre de fréquence : " << endl;
        cout << a2.test;
        cout << "\n";
    }
    in.close(); //fermer le fichier
}
