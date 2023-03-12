#include<bits/stdc++.h>
using namespace std;
vector <int> word;
vector <int> adj[26 + 5];
int refs[26 + 5];
string s;
string last;
bool have[26 + 5];
void TopologyOrder(){
	for(int i = 0 ; i<26 ; i++){
		int s = 0;
		while(s < 26 && refs[s] != 0){
			s++;
		}
		if(s == 26) break;
		refs[s] = -1;
		if(have[s]){
			word.push_back(s);
		}
		for(auto j : adj[s]){
			refs[j]--;
		}
	}
}
int main(){
	int ctr = 0, len;
	int count = 0;
	memset(refs, 0, sizeof(refs));
	while(cin >> s){
		if(s == "#") break;
		ctr++;
		if(ctr == 1){
			last = s;
			continue;
		}
		len = min(s.length(), last.length());
		for(int i = 0 ; i<len ; i++){
			if(s[i] != last[i]){
				adj[(int)(last[i]) - 65].push_back((int)(s[i]) - 65);
				refs[(int)(s[i]) - 65]++;
				have[(int)(last[i]) - 65] = true;
				have[(int)(s[i]) - 65] = true;
				count++; 
				break;
			}
			else{
				continue;
			}
		}
		last = s;
	}
	TopologyOrder();
	for(auto j : word){
		cout<< char(j+65);
	}
	cout<<endl;
	
}