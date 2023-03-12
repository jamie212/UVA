#include <iostream>
#include <cstring>
using namespace std;
void fail(char *pat);
int main(int argc, char const *argv[])
{
 char arr[8] = {'a','b','a','a','b','a','a','b'};
 char *s = arr;
 fail(s);
 cout << *s;
 return 0;
}
void fail(char *pat)
{
  int i, j;
  int n = strlen(pat);
  int failure[n];
  failure[0] = -1;
  for (j = 1; j < n; j++) {
    i = failure[j-1];
    cout <<"for_____ "<< "i " << i << " failure[j-1] :" << failure[j-1] << endl;
   while (pat[j] != pat[i+1]&&(i >= 0)) {
     i = failure[i];
     cout << "while___ "<< "i " << i << " failure[i] :" << failure[i] << endl;
    }
    if (pat[j] == pat[i+1]) {
     failure[j] = i+1;
  cout << "if______ " << "j " << j << " failure[j] :" << failure[j] << endl;  
    }
    else{
     failure[j] = -1;
     cout << "else____ " << "j " << j << " failure[j] :" << failure[j] << endl;
    } 
   }
}