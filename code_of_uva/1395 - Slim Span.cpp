#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
#define INF 0x3f3f3f3f
int n, m, u, v, w;
int p[maxn];
struct Edge{
	int from, to, weight;
	bool operator < (const Edge other){
		return weight < other.weight;
	}
}E[maxn * maxn];
void init(){
	for(int i = 1 ; i<=n ; i++){
		p[i] = -1;
	}
}
int find_root(int x){
	return p[x] < 0 ? x : (p[x] = find_root(p[x]));
}
bool do_union(int x, int y){
	int x_root = find_root(x);
	int y_root = find_root(y);
	if(x_root != y_root){
		if(p[x_root] < p[y_root]){
			p[x_root] += p[y_root];
			p[y_root] = x_root;
		}
		else{
			p[y_root] += p[x_root];
			p[x_root] = y_root;
		}
		return true;
	}
	return false;
}
int from, to, mmin, mmax, slimness = INF, edge_cnt;
bool have_ans = false;
int main(){
	while(cin >> n >> m){
		if(n == 0 & m == 0) break;
		for(int i = 0 ; i<m ; i++){
			cin >> E[i].from >> E[i].to >> E[i].weight;
		}
		sort(E, E + m);
		slimness = INF;
		for(int i = 0 ; i <= m - (n-1) ; i++){
			edge_cnt = 0;
			mmin = INF;
			mmax = 0;
			init();
			for(int j = i ; j < m ; j++){
				
				if(do_union(E[j].from, E[j].to)){
					mmin = min(mmin, E[j].weight);
					mmax = max(mmax, E[j].weight);
					edge_cnt ++;
					if(edge_cnt == n-1) break;
				}
			}
			if(edge_cnt == n-1){

				slimness = min(slimness, mmax - mmin);
			}
		}
		if(slimness == INF) cout << "-1" << endl;
		else cout << slimness <<endl;

	}
}