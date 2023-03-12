#include<bits/stdc++.h>
using namespace std;
int main(){
	int t, n, m, ctr = 0,a, b;
	int tro[110][110];
	int visit[110];
	int group[3];
	cin >> t;
	while(t--){
		ctr++;
		cin >> n >> m;
		memset(tro, 0, sizeof(tro));
		memset(visit, 0, sizeof(visit));
		memset(group, 0, sizeof(group));

		for(int i = 1 ; i<=m ; i++){
			cin >> a >> b;
			tro[a][b] = 1;
			tro[b][a] = 1;
		}
		int num = 0;
		for(int i = 1 ; i<=n ; i++){
			int temp1 = 0, temp2 = 0;
			for(int j = 1 ; j<=n ; j++){
				if(visit[j] == 1 && tro[i][j] == 1)	temp1++;
				if(visit[j] == 2 && tro[i][j] == 1) temp2++;
			}
			if(temp1 > temp2){
				visit[i] = 2;
				group[2]++;
				num += temp2;
			}
			else{
				visit[i] = 1;
				group[1]++;
				num += temp1;
			}
		}
		if(num <= m/2){
			printf("Case #%d: %d\n", ctr, group[1]);
			for(int i = 1 ; i <= n ; i++){
				if(visit[i]  == 1)cout << i << " ";
			}
			cout << endl;
		}
		else{
			printf("Case #%d: Impossible\n", ctr);
		}
		
		

	}
}        