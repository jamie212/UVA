#include <iostream>
using namespace std;
void initialise(int N, int parent[], int count[]){
	int i;
	for(int i = 0 ; i<N ; i++){
		parent[i] = -1;
		count[i] = 1;
	}
}
int find_root(int x,int parent[]){
	int x_root = x;
	while(parent[x_root - 1] != -1){
		x_root = parent[x_root - 1];
	}
	return x_root;
}
void do_union(int x, int y, int parent[], int count[]){
	int x_root = find_root(x, parent);
	int y_root = find_root(y, parent);
	if(x_root != y_root){
		parent[x_root - 1] = y_root;
		count[y_root - 1] += count[x_root - 1];
	}
}
int find_count(int N, int count[]){
	int max = 0;
	for(int i = 0 ; i<N ; i++){
		if(count[i] > max){
			max = count[i];
		}
	}
	return max;
}
int main()
{
	int t, N, M;
	cin>>t;
	while(t){
		cin>>N>>M;
		int temp_x, temp_y;
		int parent[N] = {0};
		int count[N] = {0};
		int max;
		initialise(N, parent, count);
		for(int i = 0 ; i<M ; i++){
			cin>>temp_x>>temp_y;
			do_union(temp_x, temp_y, parent, count);
		}
		max = find_count(N, count);
		cout<<max<<endl;
		t--;
	}
	return 0;
}