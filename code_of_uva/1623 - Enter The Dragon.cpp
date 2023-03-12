#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int cases, n, m, last;
int f[MAXN], a[MAXN], ans[MAXN], lake[MAXN];

int find(int x){					//find first day not rain after day x
	if(f[x] == x) return x;
	else{
		f[x] = find(f[x]);
		return f[x];
	}
}
bool check(){
	int x;
	for(int i = 1 ; i<=n ; i++){
		lake[i] = 0;
	}
	for(int i = 1 ; i<=m ; i++){
		if(a[i] == 0) continue;
		else{
			x = find(lake[a[i]]);	//x = 上次被灌滿之後的第一次沒下雨
			if(x <= i){
				ans[x] = a[i];		//ans[x] = 神龍在x天要喝a[i]湖
				f[x] = find(x+1);	//把f[x]更新為x+1天後第一次沒下雨的日子
			}
			else return false;
			lake[a[i]] = i;
		}
	}
	return true;
}
int main(){
	cin >> cases;
	while(cases--){
		cin >> n >> m;
		for(int i = 1 ; i <= m ; i++){
			cin >> a[i];
			ans[i] = 0;
		}
		f[m + 1] = m + 1;
		last = m + 1;
		for(int i = m ; i>=0 ; i--){
			if(a[i] == 0 && i != 0){
				last = i;
			}
			f[i] = last;
		}
		if(!check()){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
			for(int i = 1 ; i<=m ; i++){
				if(a[i] == 0) cout << ans[i] << " ";
			}
			cout << endl;
		}

	}
}