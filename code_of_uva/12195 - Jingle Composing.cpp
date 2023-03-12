#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	double sum = 0;
	int ctr = 0;
	while(getline(cin,str)){
		if(str[0] == '*'){break;}
		for(int i = 0 ; i<str.length() ; i++){
			if(str[i] == '/'){
				if(sum == 1){ctr++;}
				sum = 0;
			}
			if(str[i] == 'W'){sum += 1;}
			if(str[i] == 'H'){sum += 0.5;}
			if(str[i] == 'Q'){sum += 0.25;}
			if(str[i] == 'E'){sum += 0.125;}
			if(str[i] == 'S'){sum += 0.0625;}
			if(str[i] == 'T'){sum += 0.03125;}
			if(str[i] == 'X'){sum += 0.015625;}
		}
		cout<<ctr<<endl;
		ctr = 0;
	}
	return 0;
}