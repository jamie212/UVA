#include <iostream>
#include <sstream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	string str;
	stringstream s1;
	char alpha;
	int num;
	int ctr = 0;
	cin>>n;
	cin.ignore();
	for(int i = 0 ; i<n ; i++){
		getline(cin,str);
		int len = str.length();
		cout<<"Case "<<i+1<<": ";
		s1.str("");
    	s1.clear();
		s1<<str;
		while(true){
			
			s1>>alpha;
			if(s1.fail()){break;}
			s1>>num;
			while(ctr < num){
				cout<<alpha;
				ctr++;
			}
			ctr = 0;
		}
		cout<<endl;

	}
	return 0;
}