#include<bits/stdc++.h>
using namespace std;
void initial(int parent[]){
	for(int i = 0 ; i<100000 ; i++){
		parent[i] = -1;
	}
}
int find_root(int x, int parent[]){
	int x_root = x;
	while(parent[x_root] != -1){
		x_root = parent[x_root];
	}
	return x_root;
}
int do_union(int x, int y, int parent[]){
	int x_root = find_root(x, parent);
	int y_root = find_root(y, parent);
	if(x_root == y_root){
		return 1;
	}
	else if(x_root != y_root){
		parent[x_root] = y_root;
		return 0;
	}
}
int main(){
	int parent[100000] = {0};
	int x, y;
	initial(parent);
	int ctr = 0;
	while(cin>>x){
		if(x == -1){
			cout<<ctr<<endl;
			ctr = 0;
			initial(parent);
		}
		else{
			cin>>y;
			if(do_union(x, y, parent) == 1){
				ctr++;
			}
			//cout<<ctr<<" ";
		}
			
		
		

	}
}
