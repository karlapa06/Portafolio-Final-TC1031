#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "insertionSort.h"
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
  for(int i=0;i<n;i++){
    if((datos[i][17]==prefix[0])&&(datos[i][18]==prefix[1])&&(datos[i][19]==prefix[2])){
			coincidencias.push_back(datos[i]);
		}
  }
  insertionSortDia(coincidencias);
  insertionSortMes(coincidencias);  
  
  for(int i=0;i<coincidencias.size();i++){
    outFile<<coincidencias[i]<<"\n";
  }
  
  }
  