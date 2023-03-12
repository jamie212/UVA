#include<bits/stdc++.h>
using namespace std;
int main(){
	priority_queue<int, vector<int>, greater<int> > pq;
	int n, ctr, temp;
	while(cin>>n && n){
		ctr = 0;
		for(int i = 0 ; i<n ; i++){
			cin>>temp;
			pq.push(temp);
		}
		while(pq.size() > 1){

			int sum = pq.top();
			pq.pop();
			sum += pq.top();
			pq.pop();
			ctr += sum;
			pq.push(sum);
		}
		cout<<ctr<<endl;
		pq.pop();
		
	}
}