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
 *             que la partie entière. On voulait implémenter un message d'erreur 
 *             si on rentre "z30" par exemple mais la manière dont codecheck fait
 *             les tests nous aurait fait échouer nos tests. Du coup, si on rentre
 *             z30, on a aucun retour à l'utilisateur et rien ne change.
 
 Compilateur : g++ (GCC) 6.2.1
 -----------------------------------------------------------------------------------
 */
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

// constantes du jeu
const unsigned int SCORE_AU_DEBUT = 501,
                   FLECHETTES_MAX = 3;
const char LETTRE_D_MAJ = 'D',
           LETTRE_D_MIN = 'd',
           LETTRE_T_MAJ = 'T',
           LETTRE_T_MIN = 't',
           CONVERSION_MINUSCULE = 32;

int main()
{
   // variables globales
   int score_actuel = SCORE_AU_DEBUT,
       nombre_flechettes_total = 0;
   unsigned int nombre_de_flechette_actuel = 1,
                coefficient = 1,
                score_de_volee_courante = 0;
   do 
   {
      string str; // une chaine de caractères

      cout << "Score: " << score_actuel;
      cout << "  - Jouez la flechette " << nombre_de_flechette_actuel;
      cout << "/" << FLECHETTES_MAX << endl;

      // atteint si la chaîne a pu être lue            
      if (cin >> str) 
      {
         // premier caractère de la string entrée          
         char premier_caractere = str[0];
         
         // si la première lettre correspond à D ou T, on la convertit
         if (premier_caractere == LETTRE_D_MAJ || premier_caractere == LETTRE_T_MAJ) 
         {
            premier_caractere += CONVERSION_MINUSCULE; // conversion entre majuscule et minuscule
         }
		// si la première lettre correspond à d ou t
         if (premier_caractere == LETTRE_D_MIN || premier_caractere == LETTRE_T_MIN) 
         {
            // on écrase le premier caractère par le caractère zéro afin
            // de le convertir par la suite avec "stringstream"
            str[0] = '0';
            
            // permet d'assigner les coefficients aux bonnes lettres
            switch(premier_caractere)
            {
               case LETTRE_T_MIN:
                  coefficient = 3;
                  break;
               case LETTRE_D_MIN:
                  coefficient = 2;
                  break;
               default:
                  str = "";
                  break;
            }
         }
      }

      // atteint si la chaine est vide
      if (str.empty()) 
      {
         cout << "Entree non valide" << endl;
      }

      stringstream ss(str); // flux qui lit depuis la chaîne str

      int valeur_tir; // variable utilisée pour recevoir la valeur du tir

      //si l'entier valeur_tir a pu être lu depuis le flux ss
      if (ss >> valeur_tir) {
         unsigned int score_dun_coup = 0;

         // Traitement des valeurs simples uniquement
         if ((valeur_tir >= 0 && valeur_tir <= 20) || 
             (valeur_tir == 25 && (coefficient == 1 || coefficient == 2)) ||
             (valeur_tir == 25 && coefficient == 2)) 
         {
            score_dun_coup = coefficient * valeur_tir;
            nombre_de_flechette_actuel++;
            nombre_flechettes_total++;
         } 
         else // autrement l'entrée est invalide
         {
            cout << "Entree non valide" << endl;
         }

         int resultat_actuel = score_actuel - score_dun_coup;

         // si le résultat est supérieur à 1 ou qu'on gagne par un double
         if ((resultat_actuel == 0 && coefficient == 2) || resultat_actuel > 1) 
         {
            score_de_volee_courante += score_dun_coup;
            score_actuel -= score_dun_coup;
         } 
         else // on bust et on remet le score de la volée courante à 0 + fléchettes à 1
         {      
            score_actuel += score_de_volee_courante;
            score_de_volee_courante = 0;
            nombre_de_flechette_actuel = 1;
            cout << "Bust" << endl;
         }
         
         // si on a joué les 3 fléchettes, on remet le score de volée à 0 + fléchettes à 1
         if (nombre_de_flechette_actuel > 3) 
         {
            nombre_de_flechette_actuel = 1;
            score_de_volee_courante = 0;
         }
      }
      coefficient = 1; // on remet les coeff. à la valeur initiale après le traitement
   } 
   while (score_actuel != 0); // Tant qu'on a pas gagné

   //Affichage final
   cout << "Score: " << score_actuel << " en " << nombre_flechettes_total;
   cout << " flechettes" << endl;
   cout << "Bravo!" << endl;

   return EXIT_SUCCESS;
}
