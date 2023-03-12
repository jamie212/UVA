#include<bits/stdc++.h>
using namespace std;
int c[1000 + 5][1000 + 5];
struct Elephant{
	int id;
	int weight;
	int IQ;
	bool operator <(Elephant const other)const{
		return weight < other.weight;
	}
};
vector <Elephant> e;
vector <int> ans;
vector <int> x;
vector <int> y;
bool cmp1(Elephant e1, Elephant e2){
	if(e1.IQ == e2.IQ){
		if(e1.weight == e2.weight){
			return e1.id < e2.id;
		}
		else return e1.weight > e2.weight;
	}
	else return e1.IQ > e2.IQ;
}
bool cmp2(Elephant e1, Elephant e2){
	if(e1.weight == e2.weight){
		if(e1.IQ == e2.IQ){
			return e1.id < e2.id;
		}
		else return e1.IQ < e2.IQ;
	}
	else return e1.weight < e2.weight;
}
int main(){
	int k, n, m, ctr = 1;
	while(cin >> n >> m){
		e.push_back({ctr, n, m});
		ctr++;
	}
	sort(e.begin(), e.end(), cmp2);
	for(int i = 0 ; i < e.size() ; i++){
		x.push_back(e[i].id);
	}
	sort(e.begin(), e.end(), cmp1);
	for(int i = 0 ; i < e.size() ; i++){
		y.push_back(e[i].id);
	}
	m = x.size();
	n = y.size();
	for(int i = 0 ; i<=m ; i++){
			c[i][0] = 0;
			c[0][i] = 0;
	}
	for(int i = 1 ; i<=m ; i++){
		for(int j = 1 ; j<=n ; j++){
			if(x[i] == y[j]){
				c[i][j] = c[i-1][j-1] + 1;
				
			}
			else{
				c[i][j] = max(c[i-1][j], c[i][j-1]);
			}
		}
	}
	int i = m, j = n;
	while(true){
		if(x[i] == y[j]){
			ans.push_back(x[i]);
			i--;
			j--;
		}
		else{
			if(c[i-1][j] >= c[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
		if(i < 0 || j < 0) break;
	}
	printf("%d\n", ans.size());
	reverse(ans.begin(), ans.end());
	for(auto j : ans){
		printf("%d\n", j);
	}
	

}