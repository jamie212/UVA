#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	int n, d;
	char s;
	int sink[100];//1 = small, 0 = big, 2 = sink small
	int m[100];//distance
	char gar;
	int temp;
	cin>>t;
	int ctr = 1;
	while(t--){
		bool last = false;//small last jump or not
		int last_d = 0;//last rock dis
		int max = 0;
		cin>>n>>d;
		m[0] = 0;
		sink[0] = 0;
		m[n+1] = d;
		sink[n+1] = 0;
		for(int i = 1 ; i<=n ; i++){
			cin>>s>>gar>>m[i];
			if(s == 'S'){
				sink[i] = 1;}
			else{sink[i] = 0;}
		}

		for(int i = 1 ; i<=n+1 ; i++){//go
			if(sink[i] == 0){//big
				if(m[i] - last_d > max){
					max = m[i] - last_d;
				}
				last_d = m[i];
			}
			else if(sink[i] == 1){//small
				if(last == false){//last small didnt jump, can jump
					if(m[i] - last_d > max){
						max = m[i] - last_d;
					}
					last_d = m[i];
					sink[i] = 2;
					last = true;
				}
				else{//last small jumped, cant jump
					last = false;
				}
			}
		}
		last_d = m[n+1];

		for(int i = n ; i>=0 ; i--){//back
			if(sink[i] != 2){
				if(last_d - m[i] > max){
					max = last_d - m[i];
				}
				last_d = m[i];
			}
				
		}
		cout<<"Case "<<ctr<<": "<<max<<endl;
		ctr++;

		
		
	}
}