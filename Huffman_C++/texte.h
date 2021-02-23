#ifndef TEXTE_H
#define TEXTE_H
#include <iostream>
#include <queue>
#include <string>
#include <set>
using namespace std;
//structuration du noeud
struct noeud{ 
    char s_donnee; //caractère à coder
    double s_freq; //fréquence du caractere
    noeud* s_gauche; //fils gauche
    noeud* s_droit; //fils droit
    noeud(char d, double f){
        s_gauche = NULL;
        s_droit = NULL;
        this->s_donnee = d;
        this->s_freq = f;
     };
};
struct compare{
    bool operator() (noeud* gauche, noeud* droit){
        return (gauche->s_freq > droit->s_freq);
    }
};
class texte{
private:
    string m_chaine;
    noeud* min1, * min2, * inter;
    priority_queue <noeud*, vector<noeud*>, compare> q;
    void afficherHuffman(noeud*, string);
public:
    texte(string ch);
    ~texte();
    string getTexte();
    void setTexte(string chaine);
    void Huffmancodes(char d[], double[], int taille);
    int conversion(char ch[20], string m_chaine, int taille);
    string test = "";
    void filetext(ifstream infile);
};
#endif // TEXTE_H
