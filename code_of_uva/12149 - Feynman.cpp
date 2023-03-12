#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	int sum = 0;
	while(cin>>n){
		if(n ==0){break;}
		for(int i = 1 ; i<=n ; i++){
			sum = sum + i*i;
		}
		cout<<sum<<endl;
		sum = 0;
	}
	return 0;
}