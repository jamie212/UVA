#include<bits/stdc++.h>
using namespace std;
int refs[100 + 5];
vector <int> ans;
vector <int> adj[100 + 5];
int n, m, f, t;		//n = number of node, m = line, from f to t
void TopologyOrder(){
	for(int i = 0 ; i<n ; i++){
		int s = 1;
		while(s <= n && refs[s] != 0){
			s++;
		}
		if(s > n) break;
		refs[s] = -1;
		ans.push_back(s);
		for(auto j : adj[s]){
			refs[j]--;
		}
	}
}
int main(){
	while(cin >> n >> m){
		memset(refs, 0, sizeof(refs));
		ans.clear();
		for(int i = 1 ; i<=n ; i++){
			adj[i].clear();
		}
		if(n == 0 && m == 0) break;
		for(int i = 0 ; i<m ; i++){
			cin >> f >> t;
			adj[f].push_back(t);
			refs[t]++;
		}
		TopologyOrder();
		for(auto j : ans){
			printf("%d ", j);
		}
		printf("\n");
	}
}