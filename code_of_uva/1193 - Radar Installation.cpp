#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, d, ctr = 0;
	double dis;
	bool can = true;
	while(cin>>n>>d){
		if(n == 0 && d == 0)break;
		ctr++;
		int x[n][2];			
		double area[n][2];			
		for(int i = 0 ; i<n ; i++){
			cin>>x[i][0]>>x[i][1];
			if(abs(x[i][1]) > d){
				can = false;
			}
		}
		if(can){
			for(int i = 0 ; i<n ; i++){
				//printf("dis : %lf\n", sqrt(d*d - x[i][1]*x[i][1]));
				
				dis = sqrt(d*d - x[i][1]*x[i][1]);
				area[i][0] = x[i][0] - dis;
				area[i][1] = x[i][0] + dis;
			}
			
			for(int i = 0 ; i<n-1 ; i++){
				for(int j = i+1 ; j<n ; j++){
					if(area[j][1] < area[i][1]){
						double templ = area[j][0];
						double tempr = area[j][1];
						area[j][0] = area[i][0];
						area[j][1] = area[i][1];
						area[i][0] = templ;
						area[i][1] = tempr;
					}
				}
			}
			for(int i = 0; i < n; i++){
				//printf("%lf\n", area[i][1]);
			}
			
			double start = area[0][1];			
			int set = 1;					
			for(int i = 1 ; i<n ; i++){	
				if(area[i][0]<=start){
					continue;
				}
				else{
					start = area[i][1];
					set++;
				}
			}
			cout<<"Case "<<ctr<<": "<<set<<endl;
		}
		else{
			cout<<"Case "<<ctr<<": -1"<<endl;
			
		}
		can = true;
	}
}