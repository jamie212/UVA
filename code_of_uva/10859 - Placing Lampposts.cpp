#include<bits/stdc++>
using namespace std;
const int maxn = 1000 + 10;
int N, M;
vector<int> v[maxn];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>N>>M;
		for(int i = 0 ; i<N ; i++){
			v[i].clear();
		}
		while(M--){
			cin>>temp1>>temp2;
			v[temp1].push_back(temp2);
			v[temp2].push_back(temp1);		
		}

	}
}