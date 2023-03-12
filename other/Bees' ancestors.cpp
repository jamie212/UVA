#include<iostream>
using namespace std;
int main(){
	int n;
	long long int arr[80];
	arr[0] = 1;
	arr[1] = 2;
	for(int i = 2 ; i<80 ; i++){
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	while(cin>>n){
		if(n == 0){ break; }	
		cout<<arr[n-1]<<endl;
	}
}