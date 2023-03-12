#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		vector<int> v[n];
		int startv;
		while(cin>>startv && startv != 0){
			int endv;
			while(cin>>endv && endv != 0){
				v[startv].push_back(endv);
			}
		}
	for(int i = 0 ; i<n ; i++){
		cout<<i<<" ";
		for(auto j : v[i]){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	}
}