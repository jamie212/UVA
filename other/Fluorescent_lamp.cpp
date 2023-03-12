//NCPU模擬賽 6/27 D
#include<bits/stdc++.h>
using namespace std;
struct Item{
	int from;
	int to;
	int cost;
	bool operator < (const Item other)const{
		return from < other.from;
	}
};
vector <Item> v;
long long shortest[100005];
int main(){
	int N, L, t1, t2, t3;
	while(cin >> N >> L){
		v.clear();
		for(int i = 0 ; i<N ; i++){
			cin >> t1 >> t2 >> t3;
			v.push_back({t1, t2, t3});
		}
		sort(v.begin(), v.end());
		memset(visited, 0, sizeof(visited));
		shortest[0] = 0;
		for(int i = 1 ; i<=L ; i++){
			shortest[i] = 0x3F3F3F3F;
		}
		for(int i = 0 ; i<N ; i++){
			for(int j = v[i].from ; j < v[i].to ; j++){
					shortest[v[i].to] = min(shortest[j] + v[i].cost, shortest[v[i].to]);
			}
		}
		cout << shortest[L] << endl;
	}
}