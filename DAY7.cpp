#include<bits/stdc++.h>
#define ll int
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
#define maxx 66000
vector<ll> fuct(ll value) {
    vector<ll> ans;
    for(int i=0;i<16;i++) {
        ll m = ((ll)1<<i);
        ll x = (value | m);
        if(x != value && x < maxx)
        ans.push_back(x);
    }
    return ans;
}

int main() {    
    fast
    vector<ll>v[maxx];
    bool hash[maxx];
    memset(hash,false,sizeof hash);
    queue<ll>que;
    que.push(0);
    ll k=1;
    while(que.empty()==false){
        ll  upper = que.front();
        que.pop();     
        vector<ll> temp = fuct(upper);
        for(int i=0;i<temp.size();i++) {
            v[upper].push_back(temp[i]);
            if(hash[temp[i]]==false)
            que.push(temp[i]);
            hash[temp[i]]=true;
        }
    }
    ll t; 
    cin >> t;
    while(t--) {
        unordered_map<ll,vector<ll>> mapu;
        ll m ; 
        cin>>m;
        ll ar[m+1];
        for(ll i=0;i<m;i++)
            cin>>ar[i];
        for(int i=0;i<m;i++) { 
            vector<ll>v1  = mapu[ar[i]]; 
            ll last_index= v1.size()-1;
            
            if(last_index>=0 && ar[v1[last_index]] == ar[i])
            continue;

            queue<ll> q;
            q.push(ar[i]);
            map<ll,ll> check;
            v1.push_back(i);
            
            while(!q.empty())
            {
                ll top=q.front();
                q.pop();
                
                if(mapu[top].size()==v1.size())
                {
                    vector<ll>v2  = mapu[top]; 
                    ll last_ind   = v2.size()-1;
                    
                    if(ar[v2[last_ind]]>ar[i])
                    mapu[top]=v1;
                    else
                    continue;
                    
                }
                
                if(mapu[top].size()<v1.size())
                mapu[top]=v1;
                else
                continue;
                    
                for(int i1=0;i1<v[top].size();i1++)
                {
                    if(check[v[top][i1]]==0)
                    {
                        if(mapu[v[top][i1]].size()<v1.size())
                        q.push(v[top][i1]);
                        else if(mapu[v[top][i1]].size()==v1.size())
                        {
                            vector<ll>v2  = mapu[v[top][i1]]; 
                            ll last_ind   = v2.size()-1;
                    
                            if(ar[v2[last_ind]]>ar[i])
                            q.push(v[top][i1]);
                        }
                    }
                    
                    check[v[top][i1]]++;                                     
                } 

            }
        }
        vector<ll> ans;
        for(auto itr=mapu.begin();itr!=mapu.end();itr++)
        {
                if(mapu[itr->first].size()>ans.size())
                    ans=mapu[itr->first];
        } 
        if(ans.size()>1)
        {
                cout<<ans.size()<<endl;
            for(ll i:ans)
                cout<<i+1<<" ";
                cout<<endl;
        }
        else
        cout<<1<<endl<<1<<endl;
    }
    return 0;
}