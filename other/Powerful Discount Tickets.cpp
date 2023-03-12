#include <iostream>
#include <queue>
using namespace std;
int main(){
	int N, M;
	long long temp, sum = 0;
	priority_queue <long long> pq;
	cin >> N >> M;
	for(int i = 0 ; i<N ; i++){
		cin >> temp;
		pq.push(temp);
	}
	while(M--){
		temp = pq.top();
		pq.pop();
		temp /= 2;
		pq.push(temp);
	}
	while(N--){
		temp = pq.top();
		pq.pop();
		sum += temp;
	}
	cout << sum << endl;


}