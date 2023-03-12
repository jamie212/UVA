#include <bits/stdc++.h>
using namespace std;
int m, k, maxp = 0, ctr;
long long sum;
int p[505];
vector <int> ans;
bool ok(int page){
	ctr = 0;
	long long temp = 0;
	for(int i = m-1 ; i>=0 ; i--){
		if(p[i] > page) return false;
		if(temp + p[i] > page){
			ctr++;
			temp = p[i];
		}
		else{
			temp += p[i];
		}
	}
	if(ctr >= k) return false;
	else return true;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		sum = 0;
		maxp = 0;
		cin >> m >> k;
		for(int i = 0 ; i<m ; i++){
			cin >> p[i];
			sum += p[i];
			maxp = max(maxp, p[i]);
		}
		long long L = 0, R = sum;
		int nowctr;
		while(L<R){
			int M = L + (R-L)/2;
			if(ok(M)){
				R = M;
				nowctr = ctr;
			}
			else L = M + 1;
		}
		long long temp = 0;
		ans.clear();
		for(int i = m-1 ; i>=0 ; i--){
			if(temp + p[i] > L){
				ans.push_back(-1);
				temp = p[i];
			}
			else temp += p[i]; 
			ans.push_back(p[i]);
		}
		reverse(ans.begin(), ans.end());
		int j = 1;
		for(int i = 0 ; i<k-1-nowctr ; i++){
			while(ans[j] == -1) j += 2;
			auto it = ans.begin();
			ans.insert(it + j,  -1);
		}
		for(int i = 0 ; i< ans.size() ; i++){
			if(ans[i] == -1) cout << " /";
			else{
				if(i != 0) cout << " ";
				cout << ans[i];
			}	
		}
		cout << endl;
	}
}