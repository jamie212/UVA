#include<bits/stdc++.h>
using namespace std;
struct Item{
	int Q_num, period, time;
	bool operator < (const Item &a)const{
		return (time > a.time || (time == a.time && Q_num > a.Q_num));
	}
};
int main(){
	priority_queue <Item> pq;
	string garbage;
	while(cin>>garbage){
		if(garbage[0] == '#') break;
		Item item;
		scanf("%d %d", &item.Q_num, &item.period);
		item.time = item.period;
		pq.push(item);
	}
	int k;
	cin>>k;
	while(k--){
		Item ans = pq.top();
		printf("%d\n", ans.Q_num);
		pq.pop();
		ans.time += ans.period;
		pq.push(ans);

	}
	
	
}
