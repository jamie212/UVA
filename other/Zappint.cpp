#include<iostream>
using namespace std;
int main(){
	int x,y;
	int min, max;
	int ans;
	while(cin>>x>>y){
		if(x == -1 && y == -1){
			break;
		}
		if(x<y){
			min = x;
			max = y;
		}
		else if(x>y){
			min = y;
			max = x;
		}
		if(x == y){
			ans = 0;
		}
		else if((max - min) > (100 - max + min)){
			ans = 100 - max + min;
		}
		else if((max - min) <= (100 - max + min)){
			ans = max - min;
		}
		cout<<ans<<endl;
		ans = 0;
	}
}