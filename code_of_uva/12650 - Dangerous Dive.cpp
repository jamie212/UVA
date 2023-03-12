#include <iostream>
using namespace std;
int main(){
	int N,R;
	int returnnum;
	
	while(cin>>N>>R){
		int allnum[N];
		for(int i = 1 ; i<=N ; i++){
			allnum[i-1] = i;
		}
		for(int i = 0 ; i<R ; i++){
		cin>>returnnum;
			for(int j = 0 ; j<N ; j++){
				if(returnnum == allnum[j]){allnum[j] = 0;}
			}
		}
		if(N == R){cout<<"*";}
		else{
			for(int i = 0 ; i<N ; i++){
				if(allnum[i] != 0){cout<<i+1<<" ";}
			}
		}
		cout<<endl;
	}
}