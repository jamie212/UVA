#include <iostream>
#include<cmath>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,t;
	float d,temp,x,max = 0.0;
	cin>>n;
	for(int i = 0 ; i<n ; i++){
		cin>>t;
		int arr[t][2];
		for(int j = 0 ; j<t ; j++){
			cin>>arr[j][0]>>arr[j][1];
		}
		for(int j = 0 ; j<t ; j++){
			for(int k = j+1 ; k<t-1 ; k++){
				temp = (arr[j][0] - arr[k][0]) * (arr[j][0] - arr[k][0]) + (arr[j][1] - arr[k][1]) * (arr[j][1] - arr[k][1]);
				d = sqrt(temp);
				if(d > max){
					x = d*10000 - int(d * 10000) - 0.5;
					if(x<0){x = -x;}
					if(x>0.01){max = d;}
				}
			}
		}
		
		cout<<"Case #"<<i+1<<": "<<endl;
		if(max == 0.0){cout<<"Send Kurdy"<<endl;}
		else{
			printf("%.4f",max);
		cout<<endl;
		}
		

	}
	return 0;
}