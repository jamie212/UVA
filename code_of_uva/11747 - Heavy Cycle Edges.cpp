#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int from, to, weight;
	bool operator < (const Edge other) const{
		return weight < other.weight;
	}
};
Edge edge[250000 + 5];
int parent[1000 + 5];
int n, m;
void init(){
	for(int i = 0 ; i<n ; i++){
		parent[i] = -1;
	}
}
int find_root(int x){
	int x_root = x;
	while(parent[x_root] > -1){
		x_root = parent[x_root];
	}
	return x_root;
}
bool do_union(int x, int y){
	int x_root = find_root(x);
	int y_root = find_root(y);
	if(x_root != y_root){
		if(parent[x_root] > parent[y_root]){
			parent[x_root] += parent[y_root];
			parent[y_root] = x_root;
		}
		else{
			parent[y_root] += parent[x_root];
			parent[x_root] = y_root;
		}
		return true;
	}
	else return false;
}
int main(){
	while(cin >> n >> m){
		if(n == 0 && m == 0) break;
		bool forest = true;	//no cycle
		bool first = true;	//first output
		init();
		for(int i = 0 ; i<m ; i++){
			cin >> edge[i].from >> edge[i].to >> edge[i].weight;
		}
		sort(edge, edge + m);
		for(int i = 0 ; i<m ; i++){	
			if(!do_union(edge[i].from, edge[i].to)){//has cycle
				if(first){
					printf("%d", edge[i].weight);
					first = false;
				}
				else{
					printf(" %d", edge[i].weight);
				}
				forest = false;	
			}
		}
		if(forest) printf("forest\n");
		else printf("\n");
	}
}