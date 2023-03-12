#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;

    while(getline(cin, str)){
    	int ctr = 0;
        for(int i = 0 ; i<str.length() - 1 ; i++){
        	if(isalpha(str[i]) && !isalpha(str[i+1])){
        		ctr++;
        	}
        	
        }
        cout<<ctr<<endl;
    }
}
//(int(str[i]) >= 65 && int(str[i]) <= 90) || (int(str[i]) >= 97 && int(str[i]) <= 122)