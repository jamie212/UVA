#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	char ope;
	int id;
	set <int> s;
	int cnt = 0, maxcnt = 0;
	cin >> t;
	while(t--){
		cin >> ope >> id;
		
		if(ope == '+'){
			cnt++;
			s.insert(id);
		}
		else if(ope == '-'){
			if(!s.count(id)){
				maxcnt++;
			}
			else{
				cnt--;
				s.erase(id);
			}
		}
		maxcnt = max(maxcnt, cnt);
	}
	cout << maxcnt << endl;
}