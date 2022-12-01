// =================================================================
//
// File: main.cpp
// Author: Karla Alejandra Padilla González y Alejandra Cabrera Ruiz
// Date: 30 de noviembre de 2022
//
// =================================================================
#include <iostream>
#include <cstring>
#include <string>
#include "hash.h"

using namespace std;


unsigned int Hash1(const string h) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < h.size(); i++) {
		acum += (int) h[i];
	}
	return acum;
}

unsigned int Hash2(const string h) {
	return (unsigned int) h[0];
}


int main(int argc, char* argv[]) {
	int palabras = 0;
	int puestos = 0;
  //reading of inFile 
	cin >> palabras;
	cin >> puestos;
	
	HashTable<string, int> hash(palabras, string("empty"), Hash1); 

  //Gets the values asign to each word in order to calculate a salary
	for(int i = 0; i < palabras; i++){
		string palabra = "";
		int val = 0;

		cin >> palabra;
		cin >> val;

		hash.put(string(palabra),val);
	}

  //uses acum while comparing to calculate salary, o(n)
	for (int i = 0; i < puestos; i++){
		string actual = "";
		cin >> actual;
		int acum = 0;
		while(actual != "."){
			if (hash.contains(actual)){
        //returns pos
				acum += hash.get(actual);
			}
			cin >> actual;
		}
    //couts solution in the outFile
    cout << acum << "\n";
	}

}
