#include<iostream>
using namespace std;

int main(){
	int r;//組數
	cin>>r;
	int ctr = 0;
	while(ctr<r){
		int s;//relatives數
		cin>>s;
		int arr[s];
		for(int j = 0 ; j<s ; j++){
			
			cin>>arr[j];
		}
		for(int k = 0 ; k<s-1 ; k++){
			for(int h = k=1 ; h<s ; h++){
				if(arr[k] > arr[h]){
					int temp = arr[k];
					arr[k] = arr[h];
					arr[h] = temp;
				}
			}
		}
		int live = arr[s/2];
		int ans = 0;
		for(int j = 0 ; j<s ; j++){
			if(live > arr[j]){
				ans = ans + (live - arr[j]);
			}
			else{
				ans = ans + (arr[j] - live);
			}
		}
		cout<<ans<<endl;
		ctr ++;
	}

	return 0;
}

