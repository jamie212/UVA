#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m, temp, sum;
	priority_queue <int, vector<int>, greater<int>> dra;
	vector <int> kni;
	while(cin >> n >> m){
		if(n == 0 && m == 0) break;
		for(int i = 0 ; i<n ; i++){
			cin >> temp;
			dra.push(temp);
		}
		kni.clear();
		for(int i = 0 ; i<m ; i++){
			cin >> temp;
			kni.push_back(temp);
		}
		sum = 0;
		sort(kni.begin(), kni.end());
		for(int i = 0 ; i<m ; i++){
			if(!dra.empty() && kni[i] >= dra.top()){
				dra.pop();
				sum += kni[i];
			}
		}
		if(!dra.empty()){
			printf("Loowater is doomed!\n");
			while(!dra.empty())dra.pop();
		} 
		else cout << sum << endl;

	}
}