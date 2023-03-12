#include <iostream>
using namespace std;
void Swap(int *x, int *y);
int main(int argc, char const *argv[]){
  int n;
  cin>>n;
  int arr[n];
  int min,mindex;
  for(int i = 0 ; i<n ; i++){
  cin>>arr[i];
  }
  for(int i = 0 ; i<n-1 ; i++){
  min = arr[i];
    for(int j = i+1 ; j<n ; j++){
      if(arr[j] < min){
      min = arr[j];
      mindex = j;
      }
    }
  Swap(&arr[i],&arr[mindex]);
  }
  for(int i = 0 ; i<n ; i++){
  cout<<arr[i]<<" ";
  }
  return 0;
}
void Swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}