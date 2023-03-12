#include<iostream>
#include<cctype>
using namespace std;
int main(){
	char c;
	int len = 0;
	int count[256];
	while(cin>>c){
		len++;
		count[toupper(c)]++;
	}
	while(--len){
		for(c = 'A' ; c<='Z' ; c++){
			if(count[c] == len){
				cout<< c <<" "<< count[c] << endl;
			}
		}
	}
	return 0;
}