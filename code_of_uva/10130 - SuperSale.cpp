#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
struct Item{
	int price;
	int weight;
};
vector <Item> item;
int main(){
	int t1, t2, temp_w, temp_v, ans;
	int T, N, G, MW;
	cin >> T;
	while(T--){
		ans = 0;
		item.clear();
		item.push_back({0, 0});
		cin >> N;
		for(int i = 0 ; i<N ; i++){
			cin >> t1 >> t2;
			item.push_back({t1, t2});
		}
		cin >> G;
		while(G--){
			cin >> MW;
			for(int i = 0 ; i<=N ; i++){//row - i
				temp_w = item[i].weight;
				temp_v = item[i].price;
				for(int w = 0 ; w<=MW ; w++){
					if(i == 0 || w == 0){
						dp[w][i] = 0;
						continue;
					}
					if(temp_w <= w){
						dp[w][i] = max(dp[w][i-1], dp[w - temp_w][i-1] + temp_v);
					}
					else{
						dp[w][i] = dp[w][i-1];
					}
				}
			}
			ans += dp[MW][N];
		}
		cout << ans << endl;
	}
}