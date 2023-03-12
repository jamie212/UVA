#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, temp;
	stack <int> st;
	queue <int> q;
	while(cin >> n){
		if(n == 0) break;
		while(true){
			cin >> temp;
			if(temp == 0) break;
			q.push(temp);
			for(int i = 1 ; i<n ; i++){
				cin >> temp;
				q.push(temp);
			}
			for(int i = 1; i<=n ; i++){
				st.push(i);
				while(!st.empty() && q.front() == st.top()){
					q.pop();
					st.pop();
				}
			}
			if(st.empty()){
				cout<< "Yes"<<endl;
			}
			else{
				cout<<"No"<<endl;
			}
			while(!st.empty()) st.pop();
			while(!q.empty()) q.pop();
		}
		cout << endl;
	}
}