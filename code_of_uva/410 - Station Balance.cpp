#include<bits/stdc++.h>
using namespace std;

int main(){
	int C, S, ctr;
	int counter = 0;
	while(cin >> C >> S){
		vector<int> v[1000];
		counter++;
		cout<<"Set #"<<counter<<endl;
		
		int arr[S];
		for(int i = 0 ; i<C ; i++){
			v[i].clear();
		}
		for(int i = 0 ; i < S ; i++){
			cin>>arr[i];
		}
		sort(arr, arr + S);
		reverse(arr, arr + S);
		/*for(int i = 0 ; i < S ; i++){
			cout<<arr[i]<<" ";
		}*/
		int k = 0, index = 0;
		bool forward = true;
		while(k<S){
			v[index].push_back(arr[k]);
			k++;
			if(forward){
				index++;
				if(index == C){
					forward = false;
					index = C - 1;
				}
			}
			else{
				index--;
			}

		}

		for(int i = 0 ; i<C ; i++){
			cout<<" "<<i<<":";
			for(int j = 0 ; j<v[i].size() ; j++){
				if(j == v[i].size() - 1)cout<<v[i][j];
				else{
					cout<<" "<<v[i][j];
				}
			}
			cout<<endl;
		}
		cout<<"IMBALANCE = ";
		double im = 0.0;
		int arrsum = 0;
		double AM;
		for(int i = 0 ; i<S ;i++){
			arrsum += arr[i];
		}
		AM = double(arrsum) / C;
		for(int i = 0 ; i < C ; i++){
			int c_sum = 0;
			for(auto j : v[i]){
				c_sum += j;
			}
			im += abs(c_sum - AM);
		}
		printf("%.5lf", im);
		cout<<endl<<endl;
	}
	
}
/*if(S % 2 == 1){
			v[0].push_back(arr[0]);
			ctr = 1;
			for(int i = 1 ; i<C ; i++){
				v[i].push_back(arr[ctr]);
				ctr++;
			}
			for(int i = C-1 ; i>0 ; i--){
				v[i].push_back(arr[ctr]);
				ctr++;
			}
		}
		else if(S % 2 == 0){
			ctr = 0;
			for(int i = 0 ; i<C ; i++){
				v[i].push_back(arr[ctr]);
				ctr++;
			}
			for(int i = C-1 ; i>=0 ; i--){
				v[i].push_back(arr[ctr]);
				ctr++;
			}
		*/