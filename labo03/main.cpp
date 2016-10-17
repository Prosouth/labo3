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
int main(int argc, char** argv) {


    string str; // une chaine de caractères

    if (cin >> str) {
        // atteint si la chaine a pu etre lue
    }

    if (str.empty()) {
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

