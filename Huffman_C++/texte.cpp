//biblioth�ques
#include "texte.h" //linkage
#include <iostream> //d�finition the standard input/output stream objects
#include <queue> //container operator, des elements se ajoute � la fin et supprimer de la front
#include <cstring> //d�finition des m�thodes et des op�rateurs
#include <set> //stockage et r�cup�ration des donn�es
#include <iterator> //gestion des it�rateurs
#include <string> //gestion des chaines de caract�re
#include <fstream> //gestion des fichiers

using namespace std;

//constructeur
texte::texte(string ch){
    cout << "Constructeur" << endl;
    m_chaine = ch;
}
//deconstructeur
texte::~texte(){
    cout << "D�constructeur" << endl;
    //delete m_chaine;
}
//assesseur
void texte::setTexte(string chaine){
    m_chaine = chaine;
}
//mutateur
string texte::getTexte(){
    return m_chaine;
}
//La fonction afficherHuffman: construction de l'arbre de codage et afficher l'arbre avec chaque lettre correspondante � son code binaire
void texte::afficherHuffman(noeud* racine, string chaine){
    if (!racine) {
        return;
    }
    if (racine -> s_donnee != 't'){
        cout << racine -> s_donnee << ": " << chaine << endl;
        test = test + " " + chaine;
    }
    afficherHuffman(racine-> s_gauche, chaine + "0");
    afficherHuffman(racine-> s_droit, chaine + "1");
}

/* fonction Huffmancodes: cette derniere fonction nous permet de g�nerer des fr�quences en les triant puis faire la somme de deux plus petit noeuds.
Apr�s, on refait la m�me proc�dure avec le minimum prochain jusqu'au dernier caract�re pour avoir � la fin un arbre de fr�quences complet */
void texte::Huffmancodes(char d[], double f[], int taille){
    for (int i = 0; i < taille; i++)
    {
        q.push(new noeud(d[i], f[i]));
    }
    while (!q.empty())
    {
        min1 = q.top(); //choisir la fr�quence la plus petite
        q.pop(); //l'enlever du tableau pour choisir la prochaine plus petite fr�quence
        min2 = q.top();
        q.pop();
        double somme = min1->s_freq + min2->s_freq;
        inter = new noeud('t', somme); //un noeud interm�diaire contenant la somme des min1 et min2 et aussi pour lier les deux noeuds fils min1 et min2
        inter->s_gauche = min1;
        inter->s_droit = min2;
        q.push(inter);
    }
    afficherHuffman(q.top(), " ");
}
/* Conversion de la chaine � un tableau de caract�res en utilisant la collection set pour enlever la redondance ( le fait d'avoir plusieurs lettres repet�es dans la m�me chaine) */
int texte::conversion(char ch[20], string m_chaine, int taille){
    set<char> conv;
    int index = 0;
    for (unsigned int i = 0; i < m_chaine.size(); i++){
        conv.insert(m_chaine[i]); //Insertion du tableau dans le set
    }
    set<char>::iterator it = conv.begin();
    for (it; it != conv.end(); it++){
        index = distance(conv.begin(), it);
        ch[index] = *it; // Effectuer la conversion et remplissage du tableau par les r�sultats
    }
    return conv.size();
}
