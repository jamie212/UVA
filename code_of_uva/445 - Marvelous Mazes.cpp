#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	int ctr = 0;
	while(getline(cin, str)){
		for(int i = 0 ; i<str.length() ; i++){
			if(int(str[i]) >= 48 && int(str[i]) <= 57){
				ctr += int(str[i]) - 48;
			}
			else if(str[i] == '!'){
				cout<<endl;
			}
			else if(str[i] == 'b'){
				while(ctr--){
					cout<<" ";
				}
				ctr = 0;
			}
			else{
				while(ctr--){
					cout<<str[i];
				}
				ctr = 0;
			}
		}
		cout<<endl;
	}	
}