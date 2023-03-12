#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	set <int> s;
	while(t--){
		int n, k;
		cin >> n >> k;
		s.clear();
		s.insert(k);
		long long int temp = k;
		int max = k;
		long long int temp2;
		while(true){
			temp2 = temp*temp;
			while(temp2 >= pow(10, n)){
				temp2 /= 10;
			}
			if(s.count(temp2) == 0){
				s.insert(temp2);
				if(temp2 > max){
					max = temp2;
				}
				temp = temp2;
			}
			else{
				break;

			}	
		}
		cout<<max<<endl;
	}
}