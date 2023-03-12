#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<char> st;
	int n;
	cin>>n;
	cin.ignore();
	string str;

	while(n--){
		while(!st.empty()){st.pop();}
		bool yes = true;
		getline(cin, str);
		//if(st.empty() == true){yes = true;}
		for(int i = 0 ; i<str.length() ; i++){
			if(str[i] == '(' || str[i] == '['){
				st.push(str[i]);
			}
			else if(str[i] == ')'){
				if(!st.empty() && st.top() == '('){st.pop();}
				else{
					yes = false;
					break;}
			}
			else if(str[i] == ']'){
				if(!st.empty() && st.top() == '['){st.pop();}
				else{
					yes = false;
					break;}
			}
		}
		if(yes == true && st.empty()){
			cout<<"Yes"<<endl;
		}
		else if(yes == false || !st.empty()){
			cout<<"No"<<endl;
		}
	}
}