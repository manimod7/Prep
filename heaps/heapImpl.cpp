#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

void heapify_(int ar[], int idx, int n){

  if(idx >= n) return;

  int l = 2*idx + 1;
  int r = 2*idx + 2;
  int minIdx;

  // Find the minimum
  minIdx = (l >= n || ar[idx] <= ar[l])? idx: l;

  minIdx = (r >= n || ar[minIdx] <= ar[r])? minIdx: r;

  if(minIdx == idx)
    return;

  swap(ar[idx], ar[minIdx]);
  heapify_(ar, minIdx, n);

}

void deleteMin_(int ar[], int n){
  swap(ar[0], ar[n-1]);
  heapify_(ar, 0, n-1);
}

void heapSort_(int ar[], int n){
  // Get the Minimum
  // Delete it
  // Repeat
  int i, minElt, n1 = n;
  for(i = 0; i < n1; i++){
    minElt = ar[0];

    cout << minElt << " " << endl;

    deleteMin_(ar, n);
    n--;
  }

}

int getParent(int idx){
  return (idx-1)/2;
}

void insert_(int ar[], int elt, int n){
  ar[n] = elt;

  // Swap part of n with n if not in order
  int parent = getParent(n);
  int id = n;

  while(parent){
    if(ar[parent] > ar[id]){
      swap(ar[parent], ar[id]);
      id = parent;
      parent = getParent(parent);
    }
    else
      break;
  }

}

int main(){

  int n = 9;
  int ar[] = {1, 3, 34, 87, 43, 12, 32, 7, 90};

  // Convert it to a heap
  // O(n)
  int i;
  for(i = n/2; i >= 0; i--)
    heapify_(ar, i, n);

  // Get the minimum
  int minElt = ar[0];
  cout << "Minimum elt: " << minElt << endl;

  // Delete the minimum
  deleteMin_(ar, n);
  n--;

  // Get the Minimum
  minElt = ar[0];
  cout << "Next minimum elt: " << minElt << endl;

  // Insert an element
  insert_(ar, 5, n);
  n++;

  // Sort the array
  heapSort_(ar, n);

  return 0;

}
