#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, d, r, temp, sum;
	vector <int> mor, eve;
	while(cin >> n >> d >> r){
		if(n == 0 && d == 0 && r == 0) break;
		mor.clear();eve.clear();;sum = 0;
		for(int i = 0 ; i<n ; i++){
			cin >> temp;
			mor.push_back(temp);
		}
		for(int i = 0 ; i<n ; i++){
			cin >> temp;
			eve.push_back(temp);
		}
		sort(mor.begin(), mor.end());
		sort(eve.begin(), eve.end());
		reverse(eve.begin(), eve.end());
		for(int i = 0 ; i<n ; i++){
			if(mor[i] + eve[i] > d){
				sum += r * (mor[i] + eve[i] - d);
			}
		}
		cout << sum << endl;
	}
}