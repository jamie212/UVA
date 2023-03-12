#include <bits/stdc++.h>
using namespace std;
long long arr[1000005];
int main(){
	int t;
	cin >> t;
	long long m, n;
	int maxlen = 0;
	set <long long> s;
	while(t--){
		s.clear();
		maxlen = 0;
		cin >> m;
		for(int i = 0 ; i<m ; i++){
			cin >> arr[i];
		}
		int left = 0;
		for(int i = 0 ; i<m ; i++){
			while(s.count(arr[i])){
				s.erase(arr[left]);
				left++;
			}
			s.insert(arr[i]);
			maxlen = max(maxlen, i - left + 1);
		}
		
		cout << maxlen<<endl;
	}

}