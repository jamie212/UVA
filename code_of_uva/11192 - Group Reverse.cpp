#include <iostream>
#include<algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	int G, len;
	int n;
	while(true){
		cin>>G;
		if(G == 0){break;}
		cin>>str;
		len = str.length();
		n = len / G;
		for(int i = 0 ; i<G ; i++){
			for(int j = (i+1)*n-1 ; j>=i*n ; j--){
				cout<<str[j];
			}
		}
		cout<<endl;
	}
	
	return 0;
}