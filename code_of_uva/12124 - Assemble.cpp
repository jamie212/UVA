#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int t, ctr, p, q, n, b, maxq;
	string type, gar; 
struct Componenet{
	int price;
	int quality;
};
vector <Componenet> comp[maxn];
map <string, int> m;
bool ok(int q){
	int sum = 0, cheapest;
	for(int i = 0 ; i<ctr ; i++){
		cheapest = b+1;
		for(auto j : comp[i]){
			if(j.quality >= q){
				cheapest = min(cheapest, j.price);
			}
		}
		if(cheapest == b+1){
			return false;
		}
		sum += cheapest;
		if(sum > b){
			return false;
		}
	}
	return true;
}
int main(){
	cin >> t;
	while(t--){
		cin >> n >> b;
		m.clear();
		for(int i = 0 ; i<n ; i++){
			comp[i].clear();
		}
		ctr = 0;
		maxq = 0;
		for(int i = 0 ; i<n ; i++){
			cin >> type >> gar >> p >> q;
			if(!m.count(type)) m[type] = ctr++;
			comp[m[type]].push_back({p, q});
			maxq = max(maxq, q);
		}
		int L = 0, R = maxq; 
		while(L < R){
			int M = L + (R-L+1)/2;
			if(ok(M)){
				L = M;
			}
			else R = M-1;
		}
		cout << L << endl;
	}
}