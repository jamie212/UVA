#include<iostream>
using namespace std;
int main(){
	string str;
	int count = 0;
	int len;
	while(getline(cin,str)){
		len = str.length();
		for(int i = 0 ; i<len ; i++){
			if(str[i] == '\"'){
				if(count == 0){
					cout<<"``";
					count++;
				}
				else if(count == 1){
					cout<<"''";
					count = 0;
				}
			}
			else{
					cout<<str[i];
				}
		}
		cout<<endl;
	}
	return 0;
}