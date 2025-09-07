#include <bits/stdc++.h>
using namespace std;

/*
  ____ ___  ______   __  ____   _    ____ _____ _____        
 / __/ _ \|  _ \ \ / / |  _ \ / \  / ___|   _| ____|
| |  | | | | |) \ V /  | |) / _ \ \___ \ | | |  _|  
| || || |  __/ | |   |  __/ ___ \ ___) || | | |__ 
 \\/||||   || //   \\/ || ||
 / ___|  _ \| ____\ \      / /                        
| |   | |_) |  _|  \ \ /\ / /                         
| ||  _ <| |__  \ V  V /                          
 \|| \\|  \/\_/                           
  __
<(o )___
 ( ._> /
  `---'
  
*/
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    ll a = 0; ll b = 0;
    ll tempA = 0, tempB = 0;
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        tempA = (ll)tempA + a;
    }
    for (int j = 0; j < n; j++) {
        cin >> b;
        tempB = (ll)tempB + b;
    }

    if (tempB == tempA) {
        cout<<"Mabar"<<endl;
    } else if (tempB > tempA) {
        cout<<"Pak Ganesh"<<endl;
    } else {
        cout<<"Pak Chanek"<<endl;
    } 
    
    

}