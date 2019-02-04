#include<bits/stdc++.h>
using namespace std;
int main (){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin >> n >> m;
        if (m < n-1){
            cout <<"Impossible";
            continue;
        }
        vector<pair<int ,int > > ans;
        for(int i =1 ; i <=n  && m; i++)
            for(int j=i+1 ; j<=n && m ; j++)
                if (__gcd(i,j)==1)
                    ans.push_back({i,j}),m--;
        if (m != 0){
            cout <<"Impossible";
            continue;
        }
        cout << "Possible"<<endl;
        for(int i =0 ; i <ans.size() ; i++)
            cout <<ans[i].first <<' ' <<ans[i].second << endl;
    }
    return 0;
}