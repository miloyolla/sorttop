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
void merger(std::vector<csvio::index> &index , int l, int m, int r) 
{ 
    int i, j, k; 

    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    csvio::index L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = index[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = index[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
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
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        index[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        index[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
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

void merge(std::vector<csvio::index> &index)
{
    mergeSort(index, 0, index.size());
}

} // namespace sort