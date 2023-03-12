#include <iostream>
#include <sstream>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	int ctr = 1;
	string temp;
	int now,next;
	stringstream s1;
	while(getline(cin,str)){
		if(str[0] == 'E'){break;}
		int len = str.length();
		now = len;
		//cout<<now<<" ";
		if(len == 1 && str[0] == '1'){cout<<"1"<<endl;}
		else{
			while(true){
			//ctr++;
			s1.str("");
    		s1.clear();
			s1<<now;
			s1>>temp;
			next = temp.length();
				if(now == next){
					ctr++;
				cout<<ctr<<endl;
				break;
				}
				else{
					ctr++;
				now = next;
				//cout<<ctr<<" "<<temp<<" "<<next<<endl;
				}
			}
		}
		
		ctr = 1;
		
	}
	return 0;
}