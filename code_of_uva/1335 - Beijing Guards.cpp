#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000+5;
int gift[maxn],l[maxn],r[maxn];
int n;
bool test(int p){
	int x = gift[1];
	int y = p-gift[1];
	l[1] = x;		//left take how many
	r[1] = 0;
	for(int i = 2 ; i<=n ; i++){
		if(i % 2 == 1){	//odd take left->right
			r[i] = min(y-r[i-1], gift[i]);
			l[i] = gift[i] - r[i];
		}
		else{			//even take right->left
			l[i] = min(x - l[i-1], gift[i]);
			r[i] = gift[i] - l[i];
		}
	}
	return l[n] == 0;
}
int main(){
	while(cin>>n){
		if(n == 0)break;
		for(int i = 1 ; i<=n ; i++){
			cin>>gift[i];
		}
		gift[n+1] = gift[1];
		if(n == 1){
			printf("%d\n", gift[1]);
			continue;
		}
		//even guard
		int L = 0;
		for(int i = 1 ; i<=n ; i++){
			//cout<<r[i] <<endl;
			L = max(L, gift[i] + gift[i+1]);
		}
		
		
		if(n % 2 == 1){			//odd guard
			int R = 0, M;
			for(int i = 1 ; i<=n ; i++){
				R = max(gift[i] * 3, R);
			}
			while(L<R){
				M = L + (R-L)/2;
				if(test(M))R = M;
				else L = M+1;
			}
			
		}
		cout<<L<<endl;
	}
}