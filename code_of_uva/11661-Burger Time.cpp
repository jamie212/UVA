#include<iostream>
using namespace std;
int main(){
	int n;
	string str;
	while(cin>>n){
		if(n == 0){break;}
		cin.ignore();
		bool Ron = false;
		bool Don = false;
		int ctr = 0;
		int ans;
		int min = 2147483647;
		string str;
		getline(cin,str);
		for(int i = 0 ; i<n ; i++){
			if(str[i] == 'Z'){min = 0;}
			if(str[i] == '.'){
				if(Ron == true || Don == true){ctr++;}
			}
			if(str[i] == 'R' && Don == true){
				ctr++;
				Don = false;
				if(ctr<min){min = ctr;}
				ctr = 0;
				Ron = true;
			}
			if(str[i] == 'R' && Don == false){
				ctr = 0;
				Ron = true;
			}
			if(str[i] == 'D' && Ron == true){
				ctr++;
				Ron = false;
				if(ctr<min){min = ctr;}
				ctr = 0;
				Don = true;
			}
			if(str[i] == 'D' && Ron == false){
				ctr = 0;
				Don = true;
			}
		}
		cout<<min<<endl;
	}
}