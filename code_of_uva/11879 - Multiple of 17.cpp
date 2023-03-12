#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	int x = 0;
	while(getline(cin,str)){
		if(str[0] == '0'){break;}
		for(int i = 0 ; i<str.length() ; i++){
			x = x * 10 + (str[i] - 48) % 17;
			if(x / 17 >= 1){
				x = x % 17;
			}
		}
		if(x == 0){cout<<"1"<<endl;}
		//else{cout<<"no"<<endl;}
		else{cout<<"0"<<endl;}
		x =
	}
	return 0;
}