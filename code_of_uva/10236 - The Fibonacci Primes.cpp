#include<bits/stdc++.h>
using namespace std;
const int maxn = 250000;
const int maxp = 22000 + 5;
int fp[maxp];
bool visit[maxn];
int main(int argc, char const *argv[])
{	
	long long a = 0, b = 1, temp, i, j;
	int n, cnt;
	for(cnt = 1, i = 2 ; cnt<maxp ; i++){
		temp = a + b;
		a = b;
		b = temp;
		if(b >= 1e15){
			b /= 10;
			a /= 10;
		}
		if(!visit[i]){
			temp = b;
			while(temp >= 1e9){
				temp /= 10;
			}
			fp[cnt++] = temp;
			for(j = i*i ; j<maxn ; j += i){
				visit[j] = true;
			}
		}
	}
	fp[1] = 2;
	fp[2] = 3;
	while(cin >> n){
		cout << fp[n] << endl;
	}
	return 0;
}