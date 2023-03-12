#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	int arr[10];
	bool order = true;
	cin>>n;
	cout<<"Lumberjacks:"<<endl;
	for(int i = 0 ; i<n ; i++){

		for(int j = 0 ; j<10 ; j++){
			cin>>arr[j];
		}
		for(int j = 0 ; j<9 ; j++){   //小到大排序
			if(arr[j] <= arr[j+1] && order == true){order = true;}
			else{order = false;}
		}	

		if(order == false){          
			order  = true;
			for(int j = 0 ; j<9 ; j++){
				if(arr[j] >= arr[j+1] && order == true){order = true;}
				else{order = false;}
			}
		}
		if(order == false){cout<<"Unordered"<<endl;}
		else{cout<<"Ordered"<<endl;}
		order = true;
	}
	return 0;
}


