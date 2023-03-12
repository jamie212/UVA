#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	char one[3] = {'o','n','e'};
	char two[3] = {'t','w','o'};
	char three[5] = {'t','h','r','e','e'};
	string str;
	int len;
	int ans;
	int ctr = 0,twoctr = 0;
	cin.ignore();
	for(int i = 0 ; i<n ; i++){
		getline(cin,str);
		len = str.length();
		if(len == 5){
			ans = 3;
		}
		else if(len == 3){
			for(int j = 0 ; j<3 ; j++){
				if(str[j] == one[j]){
					ctr++;
				}
			}
			if(ctr >= 2){ans = 1;}
			else{ans = 2;}
		}
		cout<<ans<<endl;
		ctr =
	}
	return 0;
}