#include<vector>
#include "header.h"
using namespace std;
template <class T>
void insertionSortMes(std::vector <T> &v){
  for(int i=0;i<v.size();i++){
    for(int j=i;j>0 && v[j].substr(3,4)<v[j-1].substr(3,4);j--){
      swap(v,j,j-1);
    }
  }
}
template <class T>
void insertionSortDia(std::vector <T> &v){
  for(int i=0;i<v.size();i++){
    for(int j=i;j>0 && v[j].substr(0,2)<v[j-1].substr(0,2);j--){
      swap(v,j,j-1);
    }
  }
}