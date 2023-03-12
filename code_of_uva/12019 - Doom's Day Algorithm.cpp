#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	cin>>n;
	int M,D;
	int dd = 1;
	int date[12] = {10,21,14,4,9,6,11,8,5,10,7,12};
	string day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	//monday 1/10, 2/21 3/14, 4/4, 5/9, 6/6, 7/11, 
	//       8/8, 9/5, 10/10, 11/7, 12/12
	for(int i = 0 ; i<n ; i++){
		cin>>M>>D;
		for(int j = 0 ; j<12 ; j++){
			if(M == j+1){
				if(D<date[j]){
				dd = 1 - (date[j] - D);
					while(dd<=0){dd += 7;}
				}	
				else if(D>date[j]){
				dd = 1 + (D - date[j]);
					while(dd>7){dd -= 7;}
				}
				else{dd = 1;}
			}
		}
		cout<<day[dd - 1]<<endl;
	}
	return 0;
}