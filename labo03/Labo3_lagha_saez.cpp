/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 3 - 501 double out
 Fichier     : Labo3_lagha_saez.cpp
 Auteur(s)   : Aymen Lagha et Sébastien Saez 
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

// constantes du jeu
const unsigned int SCORE_AU_DEBUT = 501, FLECHETTES_MAX = 3;



int main() {
   // variables globales
   int score_actuel = SCORE_AU_DEBUT,
       nombre_flechettes_total = 0; 
   unsigned int nombre_de_flechette_actuel = 1, coefficient = 1,
                score_de_volee_courante = 0;

    do
    {
        string str; // une chaine de caractères

        cout << "Score: " << score_actuel;
        cout << "  - Jouez la flechette " << nombre_de_flechette_actuel;
        cout << "/" << FLECHETTES_MAX << endl;

        if (cin >> str)
        {           
            // atteint si la chaîne a pu être lue            
            
            
            //conversion en code ASCII          
            int codeascii = str[0];
            if(codeascii== 68 || codeascii == 84 ){
                codeascii +=32;// conversion entre majuscule et minuscule
            }
           
            if (codeascii == 100 || codeascii == 116 )
            {
                // on ecrase la premier caractère par le caractère zéro afin
                // de le convertir par la suite avec "stringstream"
                str[0] = '0';

                string reste_de_chaine = "";
                reste_de_chaine += str[1];
                reste_de_chaine += str[2];

                if (codeascii == 116 && !(reste_de_chaine == "25"))
                {
                    coefficient = 3;                    
                }
                else
                {
                    if (codeascii == 100)
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
           cout << "Entree non valide" << endl;
        }

        stringstream ss(str); // flux qui lit depuis la chaine str
        // exactement comme cin lit depuis la console

        int valeur_tir;


        if (ss >> valeur_tir)
        {
            // code atteint si l'entier valeur_tir a pu etre lu depuis
            // le flux ss.
            // les valeurs simples sont traitées ici
            unsigned int score_dun_coup = 0;
            
            if ((valeur_tir >= 0 && valeur_tir <= 20)||(valeur_tir == 25)||(valeur_tir == 25 && coefficient == 2))
            {              
                score_dun_coup = coefficient * valeur_tir;
                nombre_de_flechette_actuel++;
            }
            else
            {                
                    nombre_flechettes_total--;
                    cout << "Entree non valide" << endl;            
            }          

            int resultat_soustraction = score_actuel - score_dun_coup;
           
            if ((resultat_soustraction == 0 && coefficient==2 )|| resultat_soustraction > 1)
            {                
                score_de_volee_courante += score_dun_coup;
                score_actuel -= score_dun_coup;               
            }
            else
            {
                if (score_dun_coup > score_actuel || resultat_soustraction < 2)
                {
                    score_de_volee_courante = 0;
                    nombre_de_flechette_actuel--;
                }
                //nombre_de_flechette_actuel = 1;
                cout << "Bust" << endl;
            }
            if (nombre_de_flechette_actuel > 3)
            {
                nombre_de_flechette_actuel = 1;
                score_de_volee_courante = 0;
            }
        }
         coefficient = 1; //remettre les coefficient a valeur initialle
        nombre_flechettes_total++;
    }
    while (score_actuel != 0);
    cout << "Score: " << score_actuel << " en " << nombre_flechettes_total;
    cout << " flechettes" << endl;
    cout << "Bravo!" << endl;
    return EXIT_SUCCESS;
}