#include <bits/stdc++.h>
using namespace std;
int main(){
	string str;
	stringstream s1;
	int n;
	vector <int> v;
	map <int, int> m;
	while(scanf("%d", &n) != EOF){
		if(m.count(n)){
			m[n]++;
		}
		else{
			m[n] = 1;
			v.push_back(n);
		}
	}
	for(auto j : v){
		cout << j << " " << m[j] << endl;
	}
}