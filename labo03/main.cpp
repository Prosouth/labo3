/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 3 - Convertisseur avec les entiers
 Fichier     : main.cpp
 Auteur(s)   : Sébastien Saez et Aymen Lagha
 Date        : 17 octobre 2016

 But         : Le but de ce laboratoire est de mettre en oeuvre un programme
 *             qui compte les points pour un joueur au 501 double out, une
 *             variante des fléchettes.

 Remarque(s) : Si l'utilisateur rentre des chiffres à virgule, on ne prend
 *             que la partie entière.

 Compilateur : g++ (GCC) 6.2.1
 -----------------------------------------------------------------------------------
 */
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// constantes
const unsigned int SCORE_AU_DEBUT = 501, FLECHETTES_MAX = 3;

// variables globales
unsigned int score_actuel = SCORE_AU_DEBUT;
int nombre_flechettes_total = 0;

int main() {
    unsigned int nombre_de_flechette_actuel = 1;
    unsigned int coefficient = 1;
    unsigned int score_de_volee_courant = 0;

    do
    {
        string str; // une chaine de caractères

        cout << "Score: " << score_actuel;
        cout << "  - Jouez la flechette " << nombre_de_flechette_actuel;
        cout << "/" << FLECHETTES_MAX << endl;


        if (cin >> str)
        {
            // atteint si la chaine a pu etre lue
            //recuperation de l'indication s'il est double ou triple
            char indice_de_coifficient = tolower(str[0]);
            //convertion en code ascii
            int val_premier_cractere = indice_de_coifficient;

            if (val_premier_cractere == 100 || val_premier_cractere == 116)
            {
                //on ecrase la premier caractere par le caractere zero pour puis
                //convertir apres avec la "stringstream"
                str[0] = '0';


                //recupere le reste de la chaine pour 
                //elimine la valeur 25 de triple
                string reste_de_chaine = "";
                reste_de_chaine += str[1];
                reste_de_chaine += str[2];


                if (indice_de_coifficient == 't' && !(reste_de_chaine == "25"))
                {

                    coefficient = 3;
                    //score_actuel = score_actuel - coefficient;
                }
                else
                {

                    if (indice_de_coifficient == 'd')
                    {

                        coefficient = 2;

                    }
                    else
                    {

                        str = "";
                    }

                }
            }
        }

        if (str.empty())
        {
            // atteint si la chaine est vide
            //cout << "Entree non valide" << endl;
            break;
        }

        stringstream ss(str); // flux qui lit depuis la chaine str
        // exactement comme cin lit depuis la console

        int val; // un entier


        if (ss >> val)
        {
            // code atteint si l'entier val a pu etre lu depuis
            // le flux ss.
            // ICI c'est seulement les valeurs simples
            unsigned int score_dun_coup = 0;

            if (val >= 0 && val <= 20)
            {
                score_dun_coup = coefficient * val;

                nombre_de_flechette_actuel++;
            }
            else
            {
                if ((val == 25) || (val == 25 && coefficient == 2))
                {
                    score_dun_coup = coefficient * val;
                    nombre_de_flechette_actuel++;

                }
                else
                {
                    nombre_flechettes_total--;
                    cout << "Entree non valide" << endl;
                }

            }


            coefficient = 1; //remettre les coefficient a valeur initialle

            int resultat_soustraction = score_actuel - score_dun_coup;
            if (resultat_soustraction == 0 || resultat_soustraction > 1)
            {
                score_de_volee_courant += score_dun_coup;
                score_actuel -= score_dun_coup;


            }
            else
            {
                if (score_dun_coup > score_actuel || resultat_soustraction < 2)
                {

                    score_actuel += score_de_volee_courant;
                    score_de_volee_courant = 0;
                }


                nombre_de_flechette_actuel = 1;
                cout << "Bust" << endl;
            }


            if (nombre_de_flechette_actuel > 3)
            {

                nombre_de_flechette_actuel = 1;

                score_de_volee_courant = 0;
            }

        }
        nombre_flechettes_total++;
    }
    while (score_actuel != 0);

    cout << "Score: " << score_actuel << " en " << nombre_flechettes_total;
    cout << " flechettes" << endl;
    cout << "Bravo!" << endl;
    return 0;
}
