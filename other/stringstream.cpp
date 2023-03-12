#include <iostream>
#include <sstream>
using namespace std;
int main(){
	stringstream s1;
	string str;
	string m;
	int d,y;
	char garbage;
	getline(cin,str);
	s1.str("");
	s1.clear();
	s1<<str;
	s1>>m;
	s1>>d;
	s1>>garbage;
	s1>>y;
	cout<<"Y:"<<y<<" M:"<<m<<" D:"<<d;
}