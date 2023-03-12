#include<bits/stdc++.h>
using namespace std;
int main(){
	int pack[7]; 
	while(true){
		int zero = 0;
		for(int i = 1 ; i<7 ; i++){
			cin>>pack[i];
			if(pack[i] == 0){zero++;}		
		}
		if(zero == 6){break;}
		int ans = pack[6] + pack[5] + pack[4] + pack[3]/4;
		int one[7] = {0, 0, 0, 0, 0, 0, 0};
		int two[7] = {0, 0, 0, 0, 0, 0, 0};
		one[5] = 11 * pack[5];
		two[4] = 5 * pack[4];
		if(pack[3] % 4 == 3){
			two[3] = 1;
			one[3] = 5;
			ans++;
		}
		else if(pack[3] % 4 == 2){
			two[3] = 3;
			one[3] = 6;
			ans++;
		}
		else if(pack[3] % 4 == 1){
			two[3] = 5;
			one[3] = 7;
			ans++;
		}
		int twosum = 0, onesum = 0;
		for(int i = 1 ; i<7 ; i++){
			twosum += two[i];
		}
		for(int i = 1 ; i<7 ; i++){
			onesum += one[i];
		}
		if(twosum >= pack[2]){
			onesum += 4 * (twosum - pack[2]);
			pack[2] = 0;
			//if(pack[3] % 4 > 0){ans++;} 
		}
		else{
			pack[2] -= twosum;
			while(pack[2] >= 9){
				ans ++;
				pack[2] -= 9; 
			} 
			if(pack[2]>0)
			{ans ++;//2*2                       
			onesum += 36 - 4 * pack[2];}
		}
		if(onesum >= pack[1]){
			pack[1] = 0;
		}
		else{
			pack[1] -= onesum;
			while(pack[1] >= 36){
				ans++;
				pack[1] -= 36;
			}
			if(pack[1] > 0){ans++;}
		}
		cout<<ans<<endl;
	}
	
}