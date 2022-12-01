// =================================================================
//
// File: main.cpp
// Author: Alejandra Cabrera Ruiz A01704463
//             Karla Alejandra Padilla González
// Date: 27 de octubre
//
// =================================================================
#include <iostream>
#include "heap.h"
using namespace std;

int main(int argc, char* argv[]) {

  //It gets the n from the input file using cin instead of inFile
	int n;
  cin>>n;
  //Creates de structure Heap 
  Heap<int> Heap(n);
  
  for (int i=0; i < n; i++){
    int number;
    cin >> number;
    //using the method add the for loop addd each humber to the bst from the file
    Heap.add(number);
  }
  
  for (int i=0;i < n; i++){
    //orders
    Heap.pushDown(i);
  }
  
  int add=0;
  int count=0;

  //gets the minimum number of comparisons o(n)
  for( int i=0; i < n && Heap.length() > 1; i++){
    add = Heap.remove() + Heap.remove();
    Heap.toString();
    Heap.add(add);
    count += add-1;
  }
  //prints the final number of comparissons in the outFile
  cout << count<<"\n";
}
