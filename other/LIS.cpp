#include<bits/stdc++.h>
using namespace std;
vector <int> v;
vector <int> lisq;
int pos[100000];
void LIS(vector <int> &s){
	//if(!s.size()) return 0;
	int n;
	lisq.push_back(s[0]);
	for(int i = 1 ; i<s.size() ; i++){
		n = s[i];
		if(n > lisq.back()){
			lisq.push_back(n);
		}
		else{
			*lower_bound(lisq.begin(), lisq.end() , n) = n;
		}
	}
	printf("%d\n", lisq.size());
	for(auto j : lisq){
		printf("%d ", j);
	}
}
int main(){
	int t, n, p, q, ctr = 1, temp, maxlen = -1, len;
	cin>>t;				//case
	while(t--){
		cin >> n;		//how many number
		for(int i = 0 ; i<n ; i++){
			cin >> temp;
			v.push_back(temp);
		}
		LIS(v);
		//len = LIS(v);
		//printf("Case %d: %d\n", ctr++, len);
		v.clear();
		//num.clear();
		lisq.clear();
	}
}