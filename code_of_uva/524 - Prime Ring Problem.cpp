#include<bits/stdc++.h>
using namespace std;
int primenum[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int ans[20], visit[20];
int n;
bool isPrime(int x){
	for(auto y : primenum){
		if(x == y) return true;
	}
	return false;
}
void doPrimeRing(int C, int N, int visit[]){
	if(C == N){
		if(!isPrime(ans[C] + 1)) return;
		for(int i = 1 ; i<=N ; i++){
			if(i == 1)printf("%d", ans[i]);
			else printf(" %d", ans[i]);
		}
		printf("\n");
		return;
	}
	else{
		for(int i = 2 ; i<=N ; i++){
			if(visit[i]) continue;
			if(isPrime(ans[C] + i)){
				ans[C+1] = i;
				visit[i] = 1;
				doPrimeRing(C + 1, N, visit);
				visit[i] = 0;
			}
		}
	}
}
int main(){
	int count = 1;
	while(cin >> n){
		if(count != 1){printf("\n");}
		printf("Case %d:\n", count++);
		ans[1] = 1;
		memset(visit, 0, sizeof(visit));
		doPrimeRing(1, n, visit);
	}
	return 0;
}