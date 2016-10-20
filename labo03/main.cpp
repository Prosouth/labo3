/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 3 - Convertisseur avec les entiers
 Fichier     : main.cpp
 Auteur(s)   : Sébastien Saez et Ayem Lagha
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

int main()
{
   unsigned int nombre_de_flechette_actuel = 1;
   unsigned int coefficient = 1;
   
   do {
      string str; // une chaine de caractères

      cout << "Score: " << score_actuel << "  - Jouez la flechette "
              << nombre_de_flechette_actuel << "/" << FLECHETTES_MAX << endl;

      if (cin >> str) 
      {
         // atteint si la chaine a pu etre lue
         cout << "ICI c'est le traitement de la chaine" << endl;
         switch (tolower(str[0])) {
            case 't':
               cout << "triple" << endl;
               coefficient = 3;
               score_actuel = score_actuel - coefficient;
               break;

            case 'd':
               cout << "double" << endl;
               coefficient = 2;
               
               break;

            default:
               cout << "wtf?" << endl;
               break;
         }
      }

      if (str.empty()) {
         // atteint si la chaine est vide
         cout << "Si la chaine est vide?";

      }

      stringstream ss(str); // flux qui lit depuis la chaine str
      // exactement comme cin lit depuis la console

      int val; // un entier

      if (ss >> val) {
         // code atteint si l'entier val a pu etre lu depuis
         // le flux ss.
         // ICI c'est seulement les valeurs simples
         if (val >= 1 && val <= 20) {
            score_actuel = score_actuel - val;
            (nombre_de_flechette_actuel >= 3) ? nombre_de_flechette_actuel = 1 :
                    nombre_de_flechette_actuel++;
            nombre_flechettes_total++;

         } else {
            cout << "La valeur n'a pas été trouvée" << endl;
         }
      }
   } while (score_actuel != 0);


   return EXIT_SUCCESS;
}


