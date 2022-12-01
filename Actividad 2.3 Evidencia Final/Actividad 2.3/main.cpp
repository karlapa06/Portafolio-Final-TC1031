// =================================================================
//
// File: main.cpp
// Author: 
// Alejandra Cabrera Ruiz A01704463
// Karla Alejandra Padilla González A01705331
// Date: 18 de octubre de 2022
//
// =================================================================
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "insertionSort.h"
#include "list.h"
using namespace std;

int main(int argc, char *argv[]) {
  int n;
  string prefix;
  ifstream inFile;
  ofstream outFile;
  inFile.open(argv[1]);
  outFile.open(argv[2]);

  inFile>>n>>prefix;

  string datos[n];
  for(int i=0;i<n;i++){
    getline(inFile,datos[i]);
  }

  vector<string> coincidencias;
  //hace push back a las coincidencias con el prefix
  for(int i=0;i<n;i++){
    if((datos[i][17]==prefix[0])&&(datos[i][18]==prefix[1])&&(datos[i][19]==prefix[2])){
			coincidencias.push_back(datos[i]);
		}
  }
  insertionSortDia(coincidencias);
  insertionSortMes(coincidencias);  

  
  DoubleLinkedList<string> Mlist;
  DoubleLinkedList<string> Rlist;
  vector<string> months={
    "jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"
  };
  int monthac=0;

  for(int mesactual=1;mesactual<=12;mesactual++){
    Mlist.clear();
    Rlist.clear(); 
    for(int i=0;i<coincidencias.size();i++){
      if(stoi(coincidencias[i].substr(3,2))==mesactual && coincidencias[i].substr(15,1)=="M"){
        Mlist.push_back(coincidencias[i]);
      }
      else if(stoi(coincidencias[i].substr(3,2))==mesactual && coincidencias[i].substr(15,1)=="R"){
        Rlist.push_back(coincidencias[i]);
      }
    
  }
    outFile<<months[monthac]<<"\n";
    outFile<<"M "<<Mlist.length()<<": "<<Mlist.toString()<<" \n";
    outFile<<"R "<<Rlist.length()<<": "<<Rlist.toString()<<" \n";
    
    monthac++;
  }
  inFile.close();
  outFile.close();
    
  }
  