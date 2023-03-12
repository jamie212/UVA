#include<bits/stdc++.h>
using namespace std;
map <string, int> ctr;
int main(){
	int cases;
	string str, city;
	stringstream s1;
	cin >> cases;
	cin.ignore();
	for(int i = 0 ; i<cases ; i++){
		getline(cin, str);
		s1.str("");
		s1.clear();
		s1<<str;
		s1>>city;
		if(ctr.count(city) == 0){
			ctr[city] = 1;
		}
		else ctr[city] ++;
	}
	for(auto it = ctr.begin() ; it != ctr.end() ; it++){
		cout << (*it).first << " " << (*it).second<<endl;
	}

}