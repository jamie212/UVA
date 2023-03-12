#include<iostream>
using namespace std;
int main(){
	int b1,b2,b3,g1,g2,g3,c1,c2,c3;
	int total;
	int sort[6] = {0};
	int min,minnum;
	while(cin>>b1>>g1>>c1>>b2>>g2>>c2>>b3>>g3>>c3){
		total = b1+g1+c1+b2+g2+c2+b3+g3+c3;
		sort[0] = total - b1 - g2 - c3;//BGC
		sort[1] = total - b1 - c2 - g3;//BCG
		sort[2] = total - g1 - b2 - c3;//GBC
		sort[3] = total - g1 - c2 - b3;//GCB
		sort[4] = total - c1 - b2 - g3;//CBG
		sort[5] = total - c1 - g2 - b3;//CGB
		min = sort[0];
		for(int i = 1 ; i<6 ; i++){
			if(sort[i] < min){
				min = sort[i];
				minnum = i;
			}
		}
		if(minnum == 0){cout<<"BGC "<<min;}
		else if(minnum == 1){cout<<"BCG "<<min<<endl;}
		else if(minnum == 2){cout<<"GBC "<<min<<endl;}
		else if(minnum == 3){cout<<"GCB "<<min<<endl;}
		else if(minnum == 4){cout<<"CBG "<<min<<endl;}
		else if(minnum == 5){cout<<"CGB "<<min<<endl;}
	}
}