#include<bits/stdc++.h>
using namespace std;
int main(){
	stack <long long> maxst;
	stack <long long> minst;
	stringstream s1;
	string str;
	int cases;
	char ope;
	long long minsum , maxsum, temp, num;
	cin >> cases;
	cin.ignore();
	while(cases--){
		minsum = 0 , maxsum = 1;
		getline(cin, str);
		s1.clear();
		s1.str("");
		s1 << str;
		s1 >> num;
		minst.push(num);
		maxst.push(num);
		while(s1 >> ope){
			s1 >> num;
			if(ope == '*'){
				maxst.push(num);
				temp = minst.top();
				minst.pop();
				num *= temp;
				minst.push(num);
			}
			else if(ope == '+'){
				minst.push(num);
				temp = maxst.top();
				maxst.pop();
				num += temp;
				maxst.push(num);
			}
		}
		while(!minst.empty()){
			minsum += minst.top();
			minst.pop();
		}
		while(!maxst.empty()){
			maxsum *= maxst.top();
			maxst.pop();
		}
		printf("The maximum and minimum are %lld and %lld.\n", maxsum, minsum);
	}
}