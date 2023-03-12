#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	long long a,b,c;
	cin>>n;
	for(int i = 0 ; i<n ; i++){
		cin>>a>>b>>c;
		if((a + b) > c && (a + c) > b && (b + c) > a){
			if(a == b && b == c){cout<<"Case "<<i+1<<": "<<"Equilateral";}
			else if(a == b || a == c || b == c){cout<<"Case "<<i+1<<": "<<"Isosceles";}
			else{cout<<"Case "<<i+1<<": "<<"Scalene";}
		}
		else{cout<<"Case "<<i+1<<": "<<"Invalid";}
		cout<<endl;
	}
	return 0;
}