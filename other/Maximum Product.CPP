#include<bits/stdc++.h>
using namespace std;
int main(){
	int N, ctr = 1;
	int arr[20];
	while(cin >> N){
		bool neg = true;
		memset(arr, 0, sizeof(arr));
		for(int i = 0 ; i<N ; i++){
			cin >> arr[i];
		}
		long long temp = 1, maxtemp = 1;
		for(int i = 0 ; i<N ; i++){
			temp = 1;
			for(int j = i ; j<N ; j++){
				temp *= arr[j];
				if(temp >= 1) neg = false;
				maxtemp = max(maxtemp, temp);
			}

		}
		if(neg) maxtemp = 0;
		printf("Case #%d: The maximum product is %lld.\n",ctr++, maxtemp);
		cout << endl;
	}
}