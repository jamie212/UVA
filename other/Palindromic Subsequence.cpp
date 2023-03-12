#include<bits/stdc++.h>
using namespace std;
string dp[1005][1005];
string str;
int len;
int main(){
	while(getline(cin, str)){
		len = str.length();
		for(int j = 0 ; j<len ; j++){	//init
			for(int i = 0 ; i<len ; i++){
				if(j == 0) dp[i][i+j] = str[i];
				else dp[i][i+j] = "";
				if(i+j == len-1) break;
			}
		}
		for(int j = 1 ; j<len ; j++){	//init
			dp[j][j-1] = "";
		}
		for(int j = 1 ; j<len ; j++){
			for(int i = 0 ; i<len ; i++){
				if(str[i] == str[i+j]){
					dp[i][i+j] = str[i] + dp[i+1][i+j-1] + str[i+j];
				}
				else{
					if(dp[i][i+j-1].length() == dp[i+1][i+j].length()){
						dp[i][i+j] = min(dp[i][i+j-1], dp[i+1][i+j]);
					}
					else if(dp[i][i+j-1].length() > dp[i+1][i+j].length()){
						dp[i][i+j] = dp[i][i+j-1];
					}
					else if(dp[i][i+j-1].length() < dp[i+1][i+j].length()){
						dp[i][i+j] = dp[i+1][i+j];
					}
				}
				if(i+j == len-1) break;
			}
		}
		cout << dp[0][len-1]<<endl;
	}
	
}