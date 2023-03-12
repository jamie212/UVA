#include <iostream>
using namespace std;
void initial(int n, int parent[]){
	for(int i = 0 ; i<n ; i++){
		parent[i] = -1;
	}
}
int find_root(int x, int parent[]){
	int x_root = x;
	while(parent[x_root - 1] != -1){
		x_root = parent[x_root - 1];
	}
	return x_root;
}
void do_union(int x, int y, int parent[]){
	int x_root = find_root(x, parent);
	int y_root = find_root(y, parent);
	if(x_root != y_root){
		parent[x_root - 1] = y_root;
	}
}
int main()
{
	int n, m;
	int ctr = 1;
	while(cin>>n>>m){
		int parent[n] = {0};
		int count = 0;
		int temp_x, temp_y;
		if(n == 0 && m== 0){break;}
		initial(n, parent);
		for(int i = 0 ; i<m ; i++){
			cin>>temp_x>>temp_y;
			do_union(temp_x, temp_y, parent);
		}
		for(int i = 0 ; i<n ; i++){
			if(parent[i] == -1){
				count++;
			}
		}
		cout<<"Case "<<ctr<<": "<<count<<endl;
		count = 0;
		ctr++;
	}
	return 0;
}