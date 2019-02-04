#include <iostream>
using namespace std;
#define ll long long int
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int main(){
    FAST
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int ans[20]={0,-1,-1,-1,1,-1,1,-1,2,1,2,-1,3,2,3,2,4,3,4,3};
        if(n<20){
            cout<<ans[n]<<endl;
        }
        else{
            if(n%4==0)  cout<<n/4<<endl;
            else if(n%4==1) cout<<(n/4-2)+1<<endl;
            else if(n%4==2) cout<<(n/4-1)+1<<endl;
            else    cout<<(n/4-3)+2<<endl;
        }
    }
    return 0;
}