#include <iostream>
#include <sstream>
using namespace std;
int main(int argc, char const *argv[])
{
	string str, str1;
	stringstream s1;
	int num, sum = 0;
	while(getline(cin, str)){
		if(str[0] == '0'){break;}
		if(str.length() == 1){sum = str[0] - 48;}
		else{
			str1 = str;
			do{
				sum = 0;
				s1.str("");
   				s1.clear();
				for(int i = 0 ; i<str1.length() ; i++){
					sum += str1[i] - 48;
				}
				s1<<sum;
				s1>>str1;
			}while(str1.length() > 1);
			
		}
		cout<<sum<<endl;
		sum = 0;
	}
	return 0;
}