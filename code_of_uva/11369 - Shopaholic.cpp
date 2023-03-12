#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t, n, ctr = 0, sum = 0;
	cin>>t;
	for(int i = 0 ; i<t ; i++){
		cin>>n;
		int arr[n];
		for(int j = 0 ; j<n ; j++){
			cin>>arr[j];
		}
		sort(arr, arr + n);
		reverse(arr, arr+n);
		for(int k = 0 ; k<n ; k++){
			ctr++;
			if(ctr == 3){
				sum += arr[k];
				ctr = 0;
			}
		}
		cout<<sum<<endl;
		sum = 0;
		ctr = 0;

	}
	return 0;
}