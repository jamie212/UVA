#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define PII pair<int, int>
const int maxn = 20005;
vector <PII> adj[maxn];
int c, n, m, s, t, x, y, w;
int dis[maxn];

void init(){
	for(int i = 0 ; i<n ; i++){
		adj[i].clear();
		dis[i] = INF;
	}
}
void Dijkstra(int cur){
	priority_queue <PII, vector<PII>, greater<PII>> pq;
	pq.push(make_pair(0, cur));
	while(!pq.empty()){
		int d; 
		tie(d, cur) = pq.top(); pq.pop();
		if(dis[cur] != INF) continue;
		dis[cur] = d;
		for(auto j: adj[cur]){
			if(dis[j.first] == INF){
				pq.push(make_pair(d + j.second, j.first));
			}
		}
	}
}
int main(){
	cin >> c;
	for(int cc = 1 ; cc<=c ; cc++){
		printf("Case #%d: ", cc);
		cin >> n >> m >> s >> t;
		init();
		for(int i = 0 ; i<m ; i++){
			cin >> x >> y >> w;
			adj[x].push_back(make_pair(y, w));
			adj[y].push_back(make_pair(x, w));
		}
		Dijkstra(s);
		if(dis[t] == INF) printf("unreachable\n");
		else cout << dis[t] << endl;
	}
}