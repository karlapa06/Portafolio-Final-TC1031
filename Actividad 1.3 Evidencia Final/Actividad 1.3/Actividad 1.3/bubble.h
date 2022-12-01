#include <iostream>
#include <vector>
#include <string>
//en header.h esta la funcion swap
#include "header.h"
using namespace std;

//compara limitando a las posiciones de 3 a 4 que corresponden a los valores del mes
template <class T>
void bubbleSortMes(std::vector<T> &v) {
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j].substr(3,4) > v[j + 1].substr(3,4)){
				swap(v, j, j + 1);
			}
		}
	}
}

//compara limitando a las posiciones de 0 a 1 que corresponder a los valores del dia, el guion es la posicion 2
template <class T>
void bubbleSortDia(std::vector<T> &v) {
	for(int i = v.size() - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(v[j].substr(0,2) > v[j + 1].substr(0,2)){
				swap(v, j, j + 1);
			}
		}
	}
}
