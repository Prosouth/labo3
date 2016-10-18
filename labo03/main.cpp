/*
 -----------------------------------------------------------------------------------
 Laboratoire : Laboratoire 3 - Convertisseur avec les entiers
 Fichier     : main.cpp
 Auteur(s)   : Sébastien Saez et Adam Zouari
 Date        : 10 octobre 2016

 But         : Le but de ce laboratoire est de mettre en oeuvre un programme 
 *             permettant d'afficher des nombres entiers dans la base 
 *             de notre choix (entre 2 et 36)

 Remarque(s) : Cette version fonctionne uniquement avec des entiers

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


   do {
      string str; // une chaine de caractères

      cout << "Score: " << score_actuel << "  - Jouez la flechette "
           << nombre_de_flechette_actuel << "/" << FLECHETTES_MAX << endl;
      
      if (cin >> str) 
      {
         // atteint si la chaine a pu etre lue
         cout << "ICI c'est le traitement de la chaine" << endl;
         if(str[0] == '$')
         {
            cout << "Je t'ai reconnu frère" << endl;
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
         switch(val)
         {
            case 1: 
            case 2: 
            case 3: 
            case 4: 
            case 5: 
            case 6: 
            case 7: 
            case 8: 
            case 9: 
            case 10: 
            case 11: 
            case 12: 
            case 13: 
            case 14: 
            case 15: 
            case 16: 
            case 17: 
            case 18: 
            case 19: 
            case 20: 
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
            default:
               cout << "Ta valeur n'a pas été trouvée" << endl;
         }
      }     
   } while (score_actuel != 0);


   return EXIT_SUCCESS;
}