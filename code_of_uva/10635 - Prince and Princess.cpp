#include<bits/stdc++.h>
using namespace std;
map <int, int> num;
vector <int> v;
//int arr[100000];
int LIS(vector <int> &s){
	if(!s.size()) return 0;
	vector <int> lisq;
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
	return lisq.size();
}
int main(){
	int t, n, p, q, ctr = 1, temp, maxlen = -1, len;
	cin>>t;
	while(t--){
		cin >> n >> p >> q;
		for(int i = 1 ; i<=p+1 ; i++){
			cin >> temp;
			num[temp] = i;
		}
		for(int i = 0 ; i<=q ; i++){
			cin >> temp;
			if(num.count(temp)){
				v.push_back(num[temp]);
			}
		}
		len = LIS(v);

		/*for(int i = 0 ; i<v.size() ; i++){
			arr[i] = 1;
		}
		for(int i = 1 ; i<v.size() ; i++){
			for(int j = 0 ; j<i ; j++){
				if(v[j] < v[i]){
					arr[i] = max(arr[i], arr[j] + 1);
					maxlen = max(maxlen, arr[i]);
				}
			}
		}*/
		printf("Case %d: %d\n", ctr++, len);
		v.clear();
		num.clear();
	}
}