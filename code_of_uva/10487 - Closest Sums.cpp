#include <iostream>
#include <algorithm>
using namespace std;
int binary_search(int n , int arr[], int find){
	int upper = n - 1;
	int lower = 0;
	bool ans = 0;
	while(lower <= upper){
		int mid = (upper + lower) / 2;
        if(find > arr[mid]) lower = mid + 1;
        else if(find < arr[mid]) upper = mid - 1; 
        else if(find == arr[mid]){
        	ans = 1; 
        	break;
        }
	}
	if(ans == 1){
		return find;
	}
	else if(ans == 0){
		if(upper < 0) return arr[0];
  	  	else if(lower > n - 1) return arr[n - 1];
  		else return abs(arr[lower]-find) > abs(arr[upper]-find) ? arr[upper] : arr[lower];
	}

}
int main()
{
	int all_sum[100000] = {0};
	int n, m;
	int ctr = 1;
	while(cin>>n){
		if(n == 0){break;}
		int arr[n] = {0};
		int count = 0;
		for(int i = 0 ; i<n ; i++){
			cin>>arr[i];
		}
		sort(arr, arr+n);
		for(int i = 0 ; i < n-1 ; i++){
            for(int j = i+1 ; j < n ; j++){
                all_sum[count++] = arr[i] + arr[j];
            }
        }
        cin>>m;
        int q;
      	cout<<"Case "<<ctr<<":"<<endl;
        for(int i = 0 ; i<m ; i++){
        	cin>>q;
        	cout<<"Closest sum to "<<q<<" is ";
        	cout<<binary_search(count, all_sum, q)<<endl;
        }
        ctr++;
	}
	return 0;
}