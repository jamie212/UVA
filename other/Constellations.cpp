#include<iostream>
#include<string>
using namespace std;
int main(){
	int ctr;
	int i;

	string constellations[13] = {"Capricornus", "Aquarius", "Pisces", "Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricornus"};
	int monthdate[13] = {101, 121, 219, 321, 421, 522, 622, 723, 824, 924, 1024, 1123, 1223};
	cin>>ctr;
	int mm,dd;
	for(i = 0 ; i <ctr ; i++){
		cin>>mm>>dd;
		int j = 0;
		while(mm * 100 + dd >= monthdate[j+1]){
			j++;
			
		}
		cout<<constellations[j]<<endl;
	}
}
