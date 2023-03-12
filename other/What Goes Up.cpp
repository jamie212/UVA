#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e8 + 5;
const int minn = -2147483648;
int n, ctr = 0, ans,  maxind, temp;
int LIS[maxn], FROM[maxn], LISV[maxn];
vector <long long> A;
vector <long long> printout;
long long maxtemp;
int main(){
	while(scanf("%d", &n)!=EOF){
		A.push_back(n);
		ctr++;
	}
	LIS[0] = 1;
	FROM[0] = -1;
	ans = 1;
	fill(LISV, LISV + ctr, maxn);
	LISV[1] = 0;
	for(int i = 1 ; i<ctr ; i++){
		maxtemp = minn;
		maxind = -1;
		for(int j = 1 ; j<=ans ; j++){
			if(A[i] > A[LISV[j]] && A[LISV[j]] > maxtemp){
				maxtemp = A[LISV[j]];
				maxind = LISV[j];
			}
		}
		if(maxind == -1){
			LIS[i] = 1;
			FROM[i] = -1;
		}
		else{
			LIS[i] = LIS[maxind] + 1;
			FROM[i] = maxind;
		}
		if(LISV[LIS[i]] == maxn){
			ans++;
			LISV[LIS[i]] = i;
		}
		else if(A[i] < A[LISV[LIS[i]]]){
			LISV[LIS[i]] = i;
		}
	}
	cout << ans << endl << "-" << endl;
	temp = LISV[ans];
	for(int i = ctr-1 ; i>=0 ; i--){
		if(i == temp){
			printout.push_back(A[i]);
			temp = FROM[i];
		}
	}
	reverse(printout.begin(), printout.end());
	for(auto j : printout) cout << j << endl;

}



