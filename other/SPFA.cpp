#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
const int maxn = 10000+5;

int n, m;
int dist[maxn], out[maxn];
bool inq[maxn];
//dist = distance, inq = inqueue, out
vector<pair<int, int>> adj[maxn];

void init()
{
	memset(dist, INF, sizeof(dist));
	memset(inq, 0, sizeof(inq));
	memset(out, 0, sizeof(out));
	for(int i = 0; i <= n;  i++){
		adj[i].clear();
	}
}

bool spfa(int sp)
{
	queue<int> q;
	q.push(sp);
	dist[sp] = 0; 
	inq[sp] = true;
	
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		inq[u] = false;	// pop point
		out[u]++;
		if(out[u] > n) return false; // negative cycle occurs

		for(auto j : adj[u]){
			int v = j.first;	// first is point, second is weight
			int w = j.second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				if(inq[v]) continue;

				inq[v] = true;	//push point
				q.push(v);
			}
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	// n nodes and m edges
	scanf("%d%d", &n, &m);
	init();	
	// make adjcent list
	int a, b, w;
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &a, &b, &w);
		adj[a].push_back(make_pair(b, w));
	}
	int sp = 0; // start point
	
	if(spfa(sp))
		for (int i = 0; i < n; i++) printf("dist %d: %d\n",i, dist[i]);
	else printf("can't reach.\n");
	return 0;
}