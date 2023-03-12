#include <iostream>
using namespace std;
void initial(int n, int parent[]){
	for(int i = 0 ; i<n ; i++){
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
void do_union(int x, int y, int parent[], int money[]){
	int x_root = find_root(x, parent);
	int y_root = find_root(y, parent);
	if(x_root != y_root){
		parent[x_root] = y_root;
		money[y_root] += money[x_root];
	}
}
int check(int x, int parent[], int money[]){
	int x_root = find_root(x, parent);
	if(money[x_root] == 0){
		return 0;
	}
	else{
		return 1;
	}
}
int main()
{
	int t, n, m;
	cin>>t;
	while(t){
		cin>>n>>m;
		bool ans = 1;
		int money[n];
		int temp_x, temp_y;
		int parent[n];
		int x, y, z;
		initial(n, parent);
		for(int i = 0 ; i<n ; i++){
			cin>>money[i];
		}
		for(int i = 0 ; i<m ; i++){
			cin>>temp_x>>temp_y;
			do_union(temp_x, temp_y, parent, money);
		}
		for(int i = 0 ; i<n ; i++){
			if(check(i, parent, money) == 1){
				ans = 0;
			}
		}
		if(ans == 1){
			cout<<"POSSIBLE"<<endl;
		}
		else{
			cout<<"IMPOSSIBLE"<<endl;
		}
		t--;
	}
	return 0;
}