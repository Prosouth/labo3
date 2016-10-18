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
               cout << "Tu as fait 1" << endl;
               score_actuel = score_actuel - val;
               break;
            case 2: 
               cout << "Tu as fait 2" << endl;
               score_actuel = score_actuel - val;
               break;
            case 3: 
               cout << "Tu as fait 3" << endl;
               score_actuel = score_actuel - val;
               break;
            case 4: 
               cout << "Tu as fait 4" << endl;
               score_actuel = score_actuel - val;
               break;
            case 5: 
               cout << "Tu as fait 5" << endl;
               score_actuel = score_actuel - val;
               break;
            case 6: 
               cout << "Tu as fait 6" << endl;
               score_actuel = score_actuel - val;
               break;
            case 7: 
               cout << "Tu as fait 7" << endl;
               score_actuel = score_actuel - val;
               break;
            case 8: 
               cout << "Tu as fait 8" << endl;
               score_actuel = score_actuel - val;
               break;
            case 9: 
               cout << "Tu as fait 9" << endl;
               score_actuel = score_actuel - val;
               break;
            case 10: 
               cout << "Tu as fait 10" << endl;
               score_actuel = score_actuel - val;
               break;
            case 11: 
               cout << "Tu as fait 11" << endl;
               score_actuel = score_actuel - val;
               break;
            case 12: 
               cout << "Tu as fait 12" << endl;
               score_actuel = score_actuel - val;
               break;
            case 13: 
               cout << "Tu as fait 13" << endl;
               score_actuel = score_actuel - val;
               break;
            case 14: 
               cout << "Tu as fait 14" << endl;
               score_actuel = score_actuel - val;
               break;
            case 15: 
               cout << "Tu as fait 15" << endl;
               score_actuel = score_actuel - val;
               break;
            case 16: 
               cout << "Tu as fait 16" << endl;
               score_actuel = score_actuel - val;
               break;
            case 17: 
               cout << "Tu as fait 17" << endl;
               score_actuel = score_actuel - val;
               break;
            case 18: 
               cout << "Tu as fait 18" << endl;
               score_actuel = score_actuel - val;
               break;
            case 19: 
               cout << "Tu as fait 19" << endl;
               score_actuel = score_actuel - val;
               break;
            case 20: 
               cout << "Tu as fait 20" << endl;
               score_actuel = score_actuel - val;
               break;               
            default:
               cout << "Ta valeur n'a pas été trouvée" << endl;
         }
      }
      
 
     if(nombre_de_flechette_actuel == 3)
     {
        nombre_de_flechette_actuel == 1;
     }
     else
     {
        nombre_de_flechette_actuel++;
     }
   } while (score_actuel == 0);



   return EXIT_SUCCESS;
}