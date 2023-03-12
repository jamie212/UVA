#include <bits/stdc++.h>
using namespace std;
int main(){
	string str,word;
	set <string> s;

	while(getline(cin, str)){
		for(int i = 0 ; i<str.length() ; i++){
	    	if (isalpha(str[i])){
	    		str[i]=tolower(str[i]);
	    	}
	    	else str[i]=' ';
	    }
	    stringstream s1;
	    s1 << str;
	    while(s1 >> word){
	    	s.insert(word);
	    }
		
	}
	for(auto elem : s){
		cout <<elem<< endl;
		
	}
}