#include <iostream>
#include <string>
using namespace std;
int main(){
	int row;
	while(cin>>row){
		if(row == 0){break;}
		int ctr[row] = {0};
		cin.ignore();
		for(int r = 0 ; r<row ; r++){
			string str;
			getline(cin, str);
			
			for(int i = 0 ; i<25 ; i++){
				if(str[i] == 'X'){ctr[r]++;}
			}
		}
		int max = 0;
		for(int i = 0 ; i<row ; i++){
			if(ctr[i] > max){max = ctr[i];}
		}
		int sum = 0;
		for(int i = 0 ; i<row ;i++){
			sum += max - ctr[i];
		}
		cout<<sum<<endl;
	}
}