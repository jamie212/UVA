#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, N, ctr, tempctr;
	char arr[105];
	cin >> T;
	for(int k = 1 ; k <= T ; k++){
		ctr = 0;
		tempctr = 0;
		cin >> N;
		for(int i = 0 ; i<N ; i++){
			cin >> arr[i];
		}
		for(int i = 0 ; i<N-1 ; i++){
			if(arr[i] == '.') tempctr++;
			if(tempctr == 2){
				ctr++;
				arr[i+1]= '#';
				tempctr = 0;
			}
			if(arr[i] == '#' && tempctr == 1){
				ctr++;
				arr[i+1] = '#';
				tempctr = 0;
			}
		}
		if((arr[N-1] == '#' && tempctr == 1) || arr[N-1] == '.'){
			ctr++;
		}
		printf("Case %d: %d\n", k, ctr);
	}
}