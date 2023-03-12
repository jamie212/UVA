#include<iostream>
using namespace std;
int main(){
	int t,num,sum = 0,ctr = 1;
	cin>>t;
	for(int i = 0 ; i<t ; i++){
		cin>>num;
		for(int j = 1 ; j<num ; j++){
			if(num % j == 0){
				sum = sum + j;
			}
		}
		if(sum < num){cout<<"deficient"<<endl;}
		else if(sum == num){cout<<"perfect"<<endl;}
		else if(sum > num){cout<<"abundant"<<endl;}
		sum = 0;
	}
}