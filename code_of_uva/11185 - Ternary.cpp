#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	string str;
	stringstream s1;
	while(cin>>n){
		if(n < 0){break;}
		s1.str("");
		s1.clear();
		if(n == 0){str = "0";}
		while(n >= 1){
			int temp = n % 3;
			n = n / 3;
			s1<<temp;
		}
		s1>>str;
		for(int i = str.length()-1 ; i>=0 ; i--){
			cout<<str[i];
		} 
		cout<<endl;
	}
	return 0;
}