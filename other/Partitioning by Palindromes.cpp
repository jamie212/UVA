#include<bits/stdc++.h>
using namespace std;
const int maxn = 0x3f3f3f3f;
int n, len;
string str;
int dp[1005];
char arr[1005];
bool Palindrome(int L, int R){
	while(L<R){
		if(arr[L] == arr[R]){
			L++;
			R--;
		}
		else return false;
	}
	return true;

}
int main(){
	cin >> n;
	cin.ignore();
	while(n--){
		getline(cin, str);
		len = str.length();
		fill(dp, dp + 1005, maxn);
		dp[0] = 0;
		for(int i = 1 ; i<=len ; i++){
			arr[i] = str[i-1];
		}
		for(int i = 1 ; i<=len ; i++){
			for(int j = 1 ; j<=i ; j++){
				if(Palindrome(j, i)){
					dp[i] = min(dp[i], dp[j-1] + 1);
					
				}
			}
		}
		cout << dp[len] << endl;
		
	}
}



