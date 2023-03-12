#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,sum = 0,ctr = 1,count = 0;
	bool ans = true;
	while(cin>>n){
		int arr[n];
		int temp;
		for(int i = 0 ; i<n ; i++){
			cin>>arr[i];
			sum += arr[i];
		}
		for(int i = 0 ; i<n-1 ; i++){
			if(arr[i]>arr[i+1]){ans = false;}
		}
		bool list[sum] = {false};
		for(int i = 0 ; i<n ; i++){
				if(list[arr[i]] == true){
					ans = false;
				}
				else{
					list[arr[i]] = true;
					for(int k = 0 ; k<arr[i] ; k++){
						if(list[k] == true){
							list[arr[i] + k] = true;
						}
					}
					
				}

		}
		cout<<"Case #"<<ctr<<": ";
		for(int j = 0 ; j<n ; j++){
			if(j == n - 1){
				cout<<arr[j]<<endl;
			}
			else{
				cout<<arr[j]<<" ";
			}

		}
		if(ans == false){
			cout<<"This is not an A-sequence."<<endl;
		}
		else{
			cout<<"This is an A-sequence."<<endl;
		}

		ctr++;
		for(int j = 0 ; j<sum ; j++){
			list[j] = false;
		}
		sum = 0;
		ans = true;

	}
	return 0;
}