#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int dp[maxn], A[maxn], ctr[maxn];
int main(){
	int cases, n, t;
	cin >> cases;
	for(int c = 1 ; c <= cases ; c++){
		printf("Case %d: ", c);
		cin >> n >> t;
		for(int i = 0 ; i<n ; i++){
			cin >> A[i];
		}
		t = t-1;
		memset(dp, 0, sizeof(dp));
		memset(ctr, 0, sizeof(ctr));
		for(int i = 0 ; i<n ; i++){
			for(int j = t ; j >= A[i] ; j--){
				if(ctr[j] < ctr[j - A[i]] + 1){
					dp[j] = dp[j - A[i]] + A[i];
					ctr[j] = ctr[j - A[i]] + 1;
				}
				else if(ctr[j] == ctr[j - A[i]] + 1){
					dp[j] = max(dp[j], dp[j - A[i]] + A[i]);
				}
			}
		}
		printf("%d %d\n", ctr[t] + 1, dp[t] + 678);
	}
}