#include<bits/stdc++.h>
using namespace std;
int cut[55];
int dp[55][55];
int do_dp(int left, int right){
	if(dp[left][right] >= 0) return dp[left][right];
	if(right - left == 1) return 0;
	int minx = 0xFFFFFFF;
	for(int k = left + 1 ; k < right ; k++){
		minx = min(minx, do_dp(left, k) + do_dp(k, right) + (cut[right] - cut[left]));
	}
	return dp[left][right] = minx;
}
int main(){
	int len, c, ans;
	while(cin >> len){
		if(len == 0)break;
		memset(dp, -1, sizeof(dp));
		memset(cut, 0, sizeof(cut));
		cin >> c;
		for(int i = 1 ; i<=c ; i++){
			cin >> cut[i];
		}
		cut[0] = 0;
		cut[c+1] = len;
		ans = do_dp(0, c+1);
		printf("The minimum cutting is %d.\n", ans);
	}
}