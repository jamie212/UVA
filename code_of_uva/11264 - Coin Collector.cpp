#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, n;
	cin>>T;
	while(T--){
		cin>>n;
		int num[n];//type of coin
		for(int i = 0 ; i<n ; i++){
			cin>>num[i];
		}
		int sum = 0;
		bool yes[n] ;
		for(int i = 0 ; i<n ; i++){
			yes[i] = true;
		}
		for(int i = 0 ; i<n-1 ; i++){
			if(yes[i]){
				sum += num[i];
				if(sum >= num[i+1]){
					yes[i] = false;	
					//cout<<"test";
					sum -= num[i];
				}
			}
		}
		int count = 0;
		for(int i = 0 ; i<n ; i++){
			if(yes[i]){count++;}
		}
		cout<<count<<endl;
	}                    
}
                                                   