#include <iostream>
#include <sstream>
#include<cstring>
using namespace std;
//int countleap(int x);
bool isleap(int y);
int main(){
	int t;
	cin>>t;
	int firstD, firstY, secondD, secondY;
	string str1, str2, firstM, secondM;
	stringstream s1;
	stringstream s2;
	char garbage;
	int ctr1,ctr2;
	cin.ignore();
	for(int i = 0 ; i<t ; i++){
		s1.str("");
    	s1.clear();
    	s2.str("");
    	s2.clear();
    	getline(cin,str1);
    	getline(cin,str2);
    	s1<<str1;
    	s1>>firstM;
    	s1>>firstD;
    	s1>>garbage;
    	s1>>firstY;
    	s2<<str2;
    	s2>>secondM;
    	s2>>secondD;
    	s2>>garbage;
    	s2>>secondY;
    	//ctr1 = countleap(firstY);
    	//ctr2 = countleap(secondY);
    	ctr1 = firstY/4 - firstY/100 + firstY/400;
    	ctr2 = secondY/4 - secondY/100 + secondY/400;
    	if((firstM[0] == 'J' && firstM[1] == 'a' && isleap(firstY) == true) || (firstM[0] == 'F' && firstD != 29 && isleap(firstY) == true)){
    		ctr1--;
    	}
    	if((secondM[0] == 'J' && secondM[1] == 'a' &&isleap(secondY) == true) || (secondM[0] == 'F' && secondD != 29 && isleap(secondY) == true)){
    		ctr2--;
    	}
    	//if(secondM[0] == 'F' && secondD == 29){ctr2++;}
    	if(firstM[0] == 'F' && firstD == 29 && isleap(firstY) == true){ctr2++;}
    	cout<<"Case "<<i+1<<": "<<ctr2 - ctr1<<endl;
    	s1.str("");
    	s1.clear();
    	s2.str("");
    	s2.clear();
	}
}
/*int countleap(int x){
	int counter = 0;
	for(int i = 1 ; i<=x ; i++){
		if(isleap(i) == true){
			counter++;
		}
	}
	return counter;
}*/
bool isleap(int y){
	if(y % 4 == 0){
		if(y % 100 == 0){
			if(y % 400 == 0){return true;}
			else{return false;}
		}
		else{return true;}
	}
	else{return false;}
}