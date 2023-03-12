#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f;
const int maxn = 1000 + 5;
int c, n, m, x, y, t;
bool inq[maxn];
int dist[maxn], out[maxn];
vector <pair<int, int>> adj[maxn];

void init(){
	memset(inq, false, sizeof(inq));
	memset(out, 0, sizeof(out));
	for(int i = 0 ; i<n ; i++){
		dist[i] = INF;
		adj[i].clear();
	}
}

bool spfa(int sp){
	queue <int> q;
	q.push(sp);
	dist[sp] = 0;
	inq[sp] = true;
	while(!q.empty()){
		int u = q.front(); q.pop();
		inq[u] = false;
		out[u]++;
		if(out[u] > n) return false;
		for(auto j : adj[u]){
			int v = j.first;
			int w = j.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				if(inq[v]) continue;
				q.push(v);
				inq[v] = true;

			}
		}

	}
	return true;
}
int main(){
	cin >> c;
	while(c--){
		cin >> n >> m;
		init();
		for(int i = 0 ; i<m ; i++){
			cin >> x >> y >> t;
			adj[x].push_back(make_pair(y, t));
		}
		if(!spfa(0)) printf("possible\n");
		else printf("not possible\n");
	}
}