#include<bits/stdc++.h>
using namespace std;

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		queue <int> index;
		queue <int> priority;
		priority_queue <int> pq;
		int n, m, temp, ans = 0;
		cin >> n >> m;
		for(int i = 0 ; i<n ; i++){
			index.push(i);
			cin >> temp;
			priority.push(temp);
			pq.push(temp);
		}
		while(true){
			if(priority.front() == pq.top()){
				ans++;
				if(index.front() == m){
					cout << ans << endl;
					break;
				}
				else{
					pq.pop();
					index.pop();
					priority.pop();	
				}s
			}
			else{
				index.push(index.front());
				index.pop();
				priority.push(priority.front());
				priority.pop();
			}
		}

	}
}