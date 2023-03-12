#include<bits/stdc++.h>
using namespace std;
int table[100005];
int main(){
	int sum, temp, cases, x;
	fill(table, table+100005, 100000);
	for(int i = 1 ; i<=100000 ; i++){
		sum = i;
		temp = i;
		while(temp>=1){
			sum += temp % 10;
			temp /= 10;
		}
		table[sum] = min(table[sum], i);
	}
	//cout<<table[100000]<<endl;
	cin>>cases;
	for(int i = 0 ; i<cases ; i++){
		cin>>x;
		if(table[x] == 100000)cout<<"0"<<endl;
		else cout<<table[x]<<endl;
	}

}