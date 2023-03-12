#include <bits/stdc++.h>
using namespace std;
int main(){
	int t; cin >> t;
	string str;
	double total;
	map <string, double> m;
	map <string, double> ans;
	bool first = true;
	cin.ignore();
	cin.ignore();
	while(t--){
		total = 0;
		m.clear();

		ans.clear();
		while(getline(cin, str) && str != ""){
			if(!m.count(str)){
				m[str] = 1;
			}
			else{
				m[str]++;
			}
			total ++;
		}
		if(first){
			first = false;
		}
		else{
			cout << endl;
		}
		for(auto elem : m){
			ans[elem.first] = elem.second / total * 100;
		}
		for(auto elem : ans){
			cout << elem.first;
			printf(" %.4lf\n", elem.second);
		}
	}
}