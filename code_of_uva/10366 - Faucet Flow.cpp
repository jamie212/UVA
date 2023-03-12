#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
int LH, RH, L, R, LHi, RHi, lt, rt, h, sum, T, LTi, RTi;
int LW[maxn], RW[maxn];

int main(){
	while(cin >> L >> R){
		if(L == 0 && R == 0) break;
		LH = 0, RH = 0;
		sum = 0;
		lt = 0, rt = 0;
		L = (-L)/2;
		R = R/2;
		for(int i = L ; i>=0 ; i--){
			cin >> LW[i];
			if(LW[i] >= LH){
				LH = LW[i];
				LHi = i;
			}
		}
		for(int i = 0 ; i<=R ; i++){
			cin >> RW[i];
			if(RW[i] > RH){
				RH = RW[i];
				RHi = i;
			}
		}
		if(LH == RH){
			for(int i = L, h = LW[L] ; i>LHi ; i--){
				lt += h;
				h = max(h, LW[i - 1]);
			}
			for(int i = R , h = RW[R] ; i>RHi ; i--){
				rt += h;
				h = max(h, RW[i - 1]);
			}
			sum = min(lt, rt) * 2 + (RHi + LHi + 1) * LH;
		}
		else{
			T = min(LH, RH);	
			//LTi = 0, RTi = 0;	//從0開始往左右看第一個>=LH RH的
			for(int i = 0 ; i<L ; i++){
				if(LW[i] >= T){
					LTi = i;
					break;
				}
			}
			for(int i = 0 ; i<R ; i++){
				if(RW[i] >= T){
					RTi = i;
					break;
				}
			}
			//while(LTi < L && LW[LTi] < T) LTi++;
			//while(RTi < R && RW[RTi] < T) RTi++;
			if(RH > LH){		//左溢出
				for(int i = L, h = LW[L] ; i>LHi ; i--){
					lt += h;
					h = max(h, LW[i - 1]);
				}
				for(int i = RTi , h = T ; RW[i] <= T ; i++){
					rt += h;
					h = max(h, RW[i + 1]);
				}
				if(lt > rt) sum = (lt + rt) + (RTi + LTi + 1) * T;
				else sum = lt * 2 + (RTi + LTi + 1) * T;
			}
			if(LH > RH){		//右溢出
				for(int i = R, h = RW[R] ; i>RHi ; i--){
					rt += h;
					h = max(h, RW[i - 1]);
				}
				for(int i = LTi , h = T ; LW[i] <= T ; i++){
					lt += h;
					h = max(h, LW[i + 1]);
				}
				if(rt > lt) sum = (rt + lt) + (LTi + RTi + 1) * T;
				else sum = rt * 2 + (LTi + RTi + 1) * T;
			}
		}
		cout << sum * 2 << endl;
	}
}