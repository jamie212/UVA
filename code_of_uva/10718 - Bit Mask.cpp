#include <bits/stdc++.h>
using namespace std;
int main(){
	long long int N, L, U, M, t, temp;
	while(cin >> N >> L >> U){
		M = 0;
		for(int i = 31 ; i>=0 ; i--){
			t = (long long)1<<i;
			//temp = (M | t);
			if((N & t) == 0){
				if(M+t <= U){
					M += t;
				}
			}
			else{
				if(M + t - 1 < L){
					M += t;
				}
			}
		}
		printf("%lld\n", M);
	}

}