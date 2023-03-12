#include<bits/stdc++.h>
using namespace std;
struct Item{
	int h, w;
};
bool sortpaper(const Item &i1, const Item &i2){
	if(i1.h == i2.h){
		return i1.w > i2.w;
	}
	return i1.h > i2.h;
}
int main(){
	Item item[6];
	int count = 0, m, n;
	while(cin >> item[0].h >> item[0].w){
		if(item[0].h < item[0].w){
			swap(item[0].h, item[0].w);
		}
		for(int i = 1 ; i<6 ; i++){
			cin >> item[i].h >> item[i].w;
			if(item[i].h < item[i].w){
				swap(item[i].h, item[i].w);
			}
		}
		sort(item, item + 6, sortpaper);
		if(item[0].h != item[1].h || item[0].w != item[1].w || item[2].h != item[3].h || item[2].w != item[3].w || item[4].h != item[5].h || item[4].w != item[5].w){
			printf("IMPOSSIBLE\n");
		}
		else if(item[0].h != item[2].h || item[0].w != item[4].h || item[2].w != item[4].w){
			printf("IMPOSSIBLE\n");
		}
		else{
			printf("POSSIBLE\n");
		}

		
	}
}