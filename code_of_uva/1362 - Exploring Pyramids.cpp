#include<bits/stdc++.h>
using namespace std;
const int maxn  = 300 + 10;
long long d[maxn][maxn];
char s[maxn];
long long dp(int i, int j){
	if(i == j) return 1;
	if(s[i] != s[j]) return 0;
	long long &ans = d[i][j];
	if(ans >= 0) return ans;
	ans = 0;
	for(int k = i + 2 ; k<=j ; k++){
		ans = (ans + (long long)dp(i+1, k-1) * (long long)dp(k, j)) % 1000000000;
	}
	return ans;
}
int main(){
	while(scanf("%s", s) != EOF){
		memset(d, -1, sizeof(d));
		printf("%lld\n", dp(0, strlen(s)-1));
	}
}