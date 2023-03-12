#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	vector <pair<int, int>> v;

	while(cin >> k){
		v.clear();
		int count = 0;
		for(int y = k+1 ; y<=k*2 ; y++){
			if((k * y) % (y - k) == 0){
				int x = (k * y) / (y - k);
				v.push_back(make_pair(x, y));
				count++;
			}
		}
		cout << count <<endl;
		for(auto j : v){
			printf("1/%d = 1/%d + 1/%d\n", k, j.first, j.second);
		}	
	}
}