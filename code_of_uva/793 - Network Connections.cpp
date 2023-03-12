#include <iostream>
#include <sstream>
using namespace std;
void initial(int x, int parent[]){
	for(int i = 0 ; i<x ; i++){
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
int check(int x, int y, int parent[]){
	int x_root = find_root(x, parent);
	int y_root = find_root(y, parent);
	if(x_root == y_root){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	string str;
	stringstream s1;
	int cases, n;
	char in;
	cin>>cases;
	cin.ignore();
	while(cases){
		cin>>n;
		cin.ignore();
		int success = 0, fail = 0;
		int temp_x, temp_y;
		int parent[n] = {0};
		initial(n, parent);
		while(getline(cin, str)){
			if(str == ""){break;}
			s1<<str;
			s1>>in;
			s1>>temp_x;
			s1>>temp_y;
			s1.clear();
			s1.str("");
			if(in == 'c'){
				do_union(temp_x, temp_y, parent);
			}
			else if(in == 'q'){
				if(check(temp_x, temp_y, parent) == 1){
					success++;
				}
				else{
					fail++;
				}
			}
		}
		cout<<success<<","<<fail<<endl;
		cases--;
		if(cases != 0){cout<<endl;}
	}
}