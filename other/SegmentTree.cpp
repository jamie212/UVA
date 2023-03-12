#include <bits/stdc++.h>
using namespace std;
int B[8] = {18, 17, 13, 19, 15, 11, 20, 87};
typedef vector<int> vi;
vi A (B, B + 8);
vi ST;

void ST_Build(vi &ST, const vi &A, int vertex, int L, int R){
  if(L == R) ST[vertex] = L;
  else{
    int nL = vertex * 2, nR = vertex * 2 + 1;
    ST_Build(ST, A, nL, L, L + (R - L) / 2);
    ST_Build(ST, A, nR, L + (R - L) / 2 + 1, R);
    int indexL = ST[nL], indexR = ST[nR];
    int valueL = A[indexL], valueR = A[indexR];
    ST[vertex] = valueL <= valueR ? indexL : indexR;
  }
}

void ST_Creation(vi &ST, const vi &A){
  int len = 4 * A.size();
  ST.assign(len, 0);
  ST_Build(ST, A, 1, 0, A.size()-1);
}
int query(int vertex, int L, int R, int qL, int qR){
  int ans = 0x7fffffff, temp, mid = (L + R) / 2;
  if(qL <= L && R <= qR) return ST[vertex];
  if(qL <= mid){
    temp = query(vertex * 2, L, mid, qL, qR);
    //printf("%d %d\n", ans, A[ans]);
    ans = A[ans] <= A[temp] ? ans : temp;
  }
  if(qR > mid){
    temp = query(vertex * 2 + 1, mid + 1, R, qL, qR);
    ans = A[ans] <= A[temp] ? ans : temp;
  }
  return ans;
}

int main(int argc, char const *argv[]){
  ST_Creation(ST, A);
  //for(auto i : ST) printf("%d ", i);
  printf("%d\n", A[query(1, 0, 7, 2, 5)]);
  //vi TEST;
  //TEST.push_back(0);
  //TEST.push_back(2);
  //printf("%d\n", TEST[0x7fffffff]);
  return 0;
}
