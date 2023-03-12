#include<bits/stdc++.h>
using namespace std;
int arr[1440+5];
int main(){
	int c, n, t, m, time, ctr, count, trip;//ctr trip, count n
	cin >> c;
	while(c--){
		cin >> n >> t >> m;
		trip = 0;
		for(int i = 0 ; i<m ; i++){
			cin >> arr[i];
		}
		time = 0;
		ctr = 1;
		if(m <= n){
			trip = 1;
			for(int i = 0 ; i<m ; i++){
				time = max(arr[i], time);
			}
			time += t*2;
		}
		else if(m % n == 0){
			trip = m / n;
			for(int i = 0 ; i <m ; i++){
				time = max(time , arr[i]);
				//cout <<time;
				if(ctr == n){
					time += 2*t;
					ctr = 1;

				}
				else{
					ctr++;
				}
			}
		}
		else{
			trip = m/n + 1;
			time = arr[m % n-1] + t*2;
			for(int i = m % n ; i<m ; i++){
				time = max(time , arr[i]);
				if(ctr == n){
					time += 2*t;
					ctr = 1;

				}
				else{
					ctr++;
				}
			}
		}
	time -= t;
	cout <<  time <<" "<< trip<<endl;

	}
}