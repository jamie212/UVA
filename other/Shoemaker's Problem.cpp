#include <bits/stdc++.h>
using namespace std;
struct work{
	int time;
	int fine;
	int id;
};
bool cmp(work a, work b){
	if(double(a.fine) / double(a.time) == double(b.fine) / double(b.time)){
		return a.id < b.id;
	}
  	else return double(a.fine) / double(a.time) > double(b.fine) / double(b.time);
}

int main(){
	int T, N;
	work arr[1005];
	cin >> T;
	while(T--){
		cin >> N;
		for(int i = 0 ; i<N ; i++){
			cin >> arr[i].time >> arr[i].fine;
			arr[i].id = i+1;
		}
		sort(arr, arr + N, cmp);
		for(int i = 0 ; i<N ; i++){
			cout << arr[i].id ;
			if(i != N-1) cout <<" ";
		}
		cout << endl;
		if(T != 0) cout << endl;
	}
}