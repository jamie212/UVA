#include <iostream>
#include <string>
using namespace std;
int main(){
    int round;
    while(cin>>round){
        if(round == -1){break;}
        bool letter[26] = {false};
        bool guess[26] = {false};
        string sol;
        string ans;
        int ctr = 0;
        cin.ignore();
        getline(cin, sol);
        for(int i = 0 ; i<sol.length() ; i++){
            letter[int(sol[i]) - 97] = true;
        }
        getline(cin, ans);
        bool done = false;
        for(int i = 0 ; i<ans.length() ; i++){
            bool win = true;
            if(guess[int(ans[i]) - 97] == false){
                if(letter[int(ans[i]) - 97] == false){
                    ctr++;
                }
                else if(letter[int(ans[i]) - 97] == true){
                    letter[int(ans[i]) - 97] = false;
                }
                guess[int(ans[i]) - 97] = true;    
            }
            for(int i = 0 ; i<26 ; i++){
                if(letter[i] == true){
                    win = false;
                }
            }
            if(win == true){
                cout<<"Round "<<round<<endl<<"You win."<<endl;
                win = true;
                done = true;
                break;}
            if(ctr>=7){
                cout<<"Round "<<round<<endl<<"You lose."<<endl;
                done = true;
                break;
            }
        }
        if(done == false && ctr<7){
            cout<<"Round "<<round<<endl<<"You chickened out."<<endl;
        
        }
    }
}
