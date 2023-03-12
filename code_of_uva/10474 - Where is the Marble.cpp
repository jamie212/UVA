#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, q, temp;
	vector <int> v;
	vector <int> ::iterator it;
	int ctr = 0;
	while(cin>>n>>q){
		ctr++;
		
		v.clear();
		if(n == 0 || q == 0)break;
		cout<<"CASE# "<<ctr<<":"<<endl;
		for(int i = 0 ; i<n ; i++){
			cin>>temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		for(int i = 0 ; i<q ; i++){
			cin>>temp;
			it = find(v.begin(), v.end(), temp);
			if(it != v.end()){
				printf("%d found at %d\n", temp, it - v.begin() +1);
			}
			else{
				printf("%d not found\n", temp);
			}
		}
	}
}