/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 3 - Convertisseur avec les entiers
 Fichier     : main.cpp
 Auteur(s)   : Sébastien Saez et Ayem Lagha
 Date        : 17 octobre 2016

 But         : Le but de ce laboratoire est de mettre en oeuvre un programme 
 *             qui compte les points pour un joueur au 501 double out, une 
 *             variante des fléchettes.

 Remarque(s) : 

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
         string lol = str;
         // atteint si la chaine a pu etre lue
         cout << "ICI c'est le traitement de la chaine" << endl;
         if(str[0] == 'd' || str[0] == 'D')
         {
            coefficient = 2;
            char toto = str[1] + str[2];
            cout << (int)toto << endl;
            cout << "je vois ton D" << endl;
         }
         if(str[0] == 't' || str[0] == 'T')
         {
            coefficient = 3;
            lol =  str[2];
            cout << stoi(lol) << endl;
            cout << "je vois ton T" << endl;
         }
      }

      if (str.empty()) 
      {
         // atteint si la chaine est vide
         cout << "Si la chaine est vide?";

      }

      stringstream ss(str); // flux qui lit depuis la chaine str
      // exactement comme cin lit depuis la console

      int val; // un entier

      if (ss >> val) 
      {
         // code atteint si l'entier val a pu etre lu depuis
         // le flux ss.
         // ICI c'est seulement les valeurs simples
         if(val >= 1 && val <= 20)
         {
               score_actuel = score_actuel - val;
               if(nombre_de_flechette_actuel >= 3)
               {
                  nombre_de_flechette_actuel = 1;
               }
               else
               {
                  nombre_de_flechette_actuel++;
               }
               break;               
         }
         else
         {
            cout << "La valeur n'a pas été trouvée" << endl;
         }
      }     
   } while (score_actuel != 0);


   return EXIT_SUCCESS;
}