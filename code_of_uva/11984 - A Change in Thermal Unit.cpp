#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int C,F;
	float inF,sumF,ansC;
	for(int i = 0 ; i<t ; i++){
		cin>>C>>F;
		inF = C*9.0/5.0 + 32.0;
		sumF = inF + F;
		ansC = (sumF - 32.0) *5.0/9.0;
		//cout<<inF<<" "<<sumF<<" "<<ansC<<endl;
		cout<<"Case "<<i+1<<": ";
		printf("%.2f",ansC);
		cout<<endl;
	}
	return 0;
}