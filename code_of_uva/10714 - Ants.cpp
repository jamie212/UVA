#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
	int cases;
	cin >> cases;
	while(cases--){
		int len, n;
		cin >> len >> n;
		int min = 0x7fffffff, maxant = 0;
		int latest = 0;  
		int ant[n],shortest = 0x7fffffff,  earliest = 0;
		for(int i = 0 ; i<n ; i++){
			cin >> ant[i];
			if(ant[i] <= len/2){
				earliest = max(earliest,ant[i]);
				latest = max(latest, len - ant[i]);
			}
			else if(ant[i] > len/2){
				earliest = max (earliest, len - ant[i]);
				latest = max(latest, ant[i]);
			}
			
		}
		cout << earliest <<" "<< latest << endl;
		
	}
}