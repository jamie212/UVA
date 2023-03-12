#include <iostream>
using namespace std;
int main(){
	int N;
	cin>>N;
	int e,f,c;
	int sum = 0;
	int left = 0;
	int bottle;
	for(int i = 0 ; i<N ; i++){
		cin>>e>>f>>c;
		bottle = e + f;

		while(bottle >= c){
			sum = sum + bottle / c;
			left = left + bottle % c;
			bottle = bottle / c;
		}
		if(left + bottle >= c){
			bottle = left + bottle;
			left = 0;
			while(bottle >= c){
			sum = sum + bottle / c;
			left = left + bottle % c;
			bottle = bottle / c;
			}
			cout<<sum<<endl;
		}
		else{cout<<sum<<endl;}
		sum = 0;
		left = 0;
		bottle = 0;
	}
}