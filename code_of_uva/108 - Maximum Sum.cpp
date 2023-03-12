#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int num[n][n];
		for(int i = 0 ; i<n ; i++){
			for(int j = 0  ; j < n ; j++){
				cin>>num[i][j];
			}
		}
		for(int i = 0 ; i<n ; i++){
			for(int j = 0 ; j<n ; j++){
				if(j>0) num[i][j] += num[i][j-1];
				if(i>0) num[i][j] += num[i-1][j];
				if(i>0 && j>0) num[i][j] -= num[i-1][j-1];
			}
		}
		for(int i = 0 ; i<n ; i++){
			for(int j = 0  ; j < n ; j++){
				cout<<num[i][j];
			}
		}
	}
	
}
