/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 17 octobre 2016, 10:01
 */
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

/*
 * 
 */
//constante 
const unsigned int SCORE_AU_DEBUT = 501;


//Variable Globale
unsigned int score_actuel = SCORE_AU_DEBUT;
int main() 
{

    
    cout<< "Score: " << score_actuel <<"  - Jouez la flechette " << << endl;

    string str; // une chaine de caractères

    if (cin >> str) 
        {
        // atteint si la chaine a pu etre lue
    }

    if (str.empty()) 
    {
        // atteint si la chaine est vide
        
    }

    stringstream ss(str); // flux qui lit depuis la chaine str
    // exactement comme cin lit depuis la console

    int val; // un entier

    if (ss >> val) {
        // code atteint si l'entier val a pu etre lu depuis
        // le flux ss.
    }
    return 0;
}

