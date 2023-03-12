#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,num;
	cin>>n;
	for(int i = 0 ; i<n ; i++){
		cin>>num;
		if(num % 3 == 1){cout<<"NO"<<endl;}
		else{cout<<"YES"<<endl;}
	}
	/*int x,sum;
	for(int i = 0 ; i<11 ; i++){
		int x = i;
		while(x>0){
			sum = sum + x%10;
			x = x/10;
		}
		if(sum % 3 == 0){cout<<i<<" "<<"YES";}
		else{cout<<i<<" "<<"NO";}
	}*/
	return 0;
}