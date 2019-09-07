/////////////////////////////////////////////////////
//    UFRJ - IM/IMA
//    TMA-B
//    Mileny Loyolla
//    Vitor Pavani
//    Rodrigo Chueri
//    DATA: 06/09/2019
/////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include "mergesort.hpp"

namespace sort
{

/*
    Função de merge
*/
void merger(std::vector<csvio::index> &index , int l, int m, int r) 
{ 
    int i, j, k; 

    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    csvio::index L[n1], R[n2]; 
  
 
    for (i = 0; i < n1; i++) 
        L[i] = index[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = index[m + 1+ j]; 
  
   
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i].campo <= R[j].campo) 
        { 
            index[k] = L[i]; 
            i++; 
        } 
        else
        { 
            index[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        index[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        index[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* 
    Função de merge sort recursiva
*/
void mergeSort(std::vector<csvio::index> &index, int l, int r) 
{ 
    
    if (l < r) 
    { 

        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(index, l, m); 
        mergeSort(index, m+1, r); 
  
        merger(index, l, m, r); 
    } 
} 
/*
wrapper para chamar o merge sort passando apenas o index array
*/

void merge(std::vector<csvio::index> &index)
{
    mergeSort(index, 0, index.size());
}

} // namespace sort