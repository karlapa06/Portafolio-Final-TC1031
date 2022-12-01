// =================================================================
//
// File: main.cpp
// Author: Karla Alejandra Padilla González y Alejandra Cabrera Ruiz
// Date: 26 de noviembre de 2022
//This file contains the creation of a unweighted matrix graph to solve the problem given in the Activity 4.3
//
// =================================================================

//Definition of include 
#include <iostream>
#include <cstring>
#include "uGraph.h"
#include <string>
using namespace std;



int main(int argc, char* argv[]) {
  //lecture of inputs and n number
	int n;
	int cons;
	cin >> n;
  //creating an unweighted matrix graph
	UListGraph<string> uMatrix(n);

  //adding edges for the graph o(n)
	for (int i = 0; i < n; i++){
		  string city;
		  string city1;

		  cin >> city;
		  cin >> city1;

		  uMatrix.addEdge(city,city1);
		  uMatrix.addEdge(city1,city);
	};

	cin >> cons;

	int intento = 1;

	for (int i = 0; i < cons; i++){
		string puerto;
    int puertostotal = 0;
		int puertosvisitados = 0;
		int puertosnovisitados = 0;
		int MNP;


		cin >> puerto;
		cin >> MNP;

		set<string> edges = uMatrix.getConnectionFrom(puerto);
		set<string>::iterator itr;

		//using depth first search from uGraph
		edges = dfs(puerto, &uMatrix);

		for (itr = edges.begin(); itr != edges.end(); itr++) {
		puertostotal = puertostotal + 1;
		}

		set<string> temporal;
		set<string> visitados = uMatrix.getConnectionFrom(puerto);
		visitados.insert(puerto);
		set<string> opciones;

		set<string>::iterator itr2;
		set<string>::iterator itr3;
		set<string>::iterator itr4;
		
//using functions from uGraph O(n^2)
		for (int i = 0; i < MNP-1; i++){

			
			for (itr2 = visitados.begin(); itr2 != visitados.end(); itr2++){
				temporal = uMatrix.getConnectionFrom(*itr2);

				for (itr3 = temporal.begin(); itr3 != temporal.end(); itr3++){

					if(visitados.find(*itr3) == visitados.end()){
						opciones.insert(*itr3);
					}
				}
			}

			for (itr4 = opciones.begin(); itr4 != opciones.end(); itr4++){
				visitados.insert(*itr4);

		}
		}

		puertosvisitados = visitados.size();
		puertosnovisitados = puertostotal - puertosvisitados;
    
    //cout in the solution file 
		cout << "Case " << intento << ": " << puertosnovisitados << " ports not reachable from port "<< puerto <<" with MNP = " << MNP << ".\n";
		intento = intento + 1;
	}


}