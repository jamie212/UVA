#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	int up = 10;
	int low = 1;
	bool honest = true;
	while(cin >> n){
		if(n == 0) break;
		cin.ignore();
		getline(cin, s);
		if(s == "too high" && n<=up){
			up = n - 1;
		}
		else if(s == "too low" && n>=low){
			low = n + 1;
		}
		if(up < low){
			honest = false;
		}
		if(s == "right on"){
			if(n <= up && n >= low && honest){
				cout<< "Stan may be honest" << endl;
			}
			else if(n>up || n<low || !honest){
				cout<<"Stan is dishonest" << endl;
			}
			up = 10;
			low = 1;
			honest = true;
		}
	}
	 
}