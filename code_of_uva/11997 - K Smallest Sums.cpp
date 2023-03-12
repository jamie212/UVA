#include<bits/stdc++.h>
using namespace std;
int A[760];
int B[760];
struct Item{
	int sum;
	int b;
	Item(int s , int bb){
		sum = s;
		b = bb;
		}
	bool operator < (const Item& r) const{
		return sum > r.sum;					//pq原本是大排到小, override變小到大
	}
};
void merge(int* A, int* B, int k){
	priority_queue <Item> q;
	for(int i = 0 ; i<k ; i++){
		q.push(Item(A[i] + B[0], 0));
	}
	for(int i = 0 ; i<k ; i++){
		Item item = q.top();
		q.pop();
		A[i] = item.sum;
		int b = item.b;
		if(b + 1 < k){
			q.push(Item(item.sum - B[b] + B[b+1], b + 1));
		}
	}
}
int main(){
	int k;
	while(cin >> k){
		for(int i = 0 ; i<k ; i++){
			cin >> A[i];
		}
		sort(A, A + k);
		for(int i = 1 ; i<k ; i++){
			for(int i = 0 ; i<k ; i++){
				cin >> B[i];
			}
			sort(B, B + k);
			merge(A, B, k);
		}
		for(int i = 0 ; i<k ; i++){
			if(i == 0) printf("%d", A[i]);
			else{
				printf(" %d", A[i]);
			}
		}
		cout << endl;
	}
}