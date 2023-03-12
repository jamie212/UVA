#include <iostream>
using namespace std;
int main()
{
	char input;
	int sum = 0, ctr = 0;
	int flag;
	while(input = getchar()){
		if(input == '~'){break;}
		switch(input){
			case ' ':
				if(ctr == 1){
				flag = 1;
				}
				else if(ctr == 2){
				flag = 0;
				}
				ctr = 0;
				break;
			case '\n':
				if(ctr == 1){
				flag = 1;
				}
				else if(ctr == 2){
				flag = 0;
				}
				ctr = 0;
				break;
			case '0':
				ctr++;
				break;
			case '#':
				cout<<sum<<endl;
				sum = 0;
				break;
		}
		if(ctr>2){
			sum = sum * 2 + flag * 1;
		}
	}
	return 0;
}