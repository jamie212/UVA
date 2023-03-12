#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int i;
	int arr[n];
	for(i = 0 ;i <n ; i++)
	{
		cin>>arr[i];
	}
	for(i = 0 ;i <n ; i++)
	{
		if(arr[i] % 4 != 0){
			cout<<"The year "<<arr[i]<<" is not a leap year."<<endl;
		}
		else{
			if(arr[i] % 100 != 0){
				cout<<"The year "<<arr[i]<<" is a leap year."<<endl;
			}
			else
			{
				if(arr[i] % 400 == 0){
					cout<<"The year "<<arr[i]<<" is a leap year."<<endl;
				}
				else{
					cout<<"The year "<<arr[i]<<" is not a leap year."<<endl;
				}
			}
		}
	}
	


}