/* Author - linpaws07 */
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;
#define mod 1000000007
#define MAIN_N 1000000000
#define N 400012
#define HIGH 200002
#define LOW 1
#define ll long long int
#define pb push_back
#define f first
#define s second
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rp(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
const ll inf = (ll)1<<34;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

ll q,k;
int mn=0;
ll osum=0;
int st=200003,et=200002;
bool neg=false;
pair<ll,ll> ar[400012];

ll query(vector<int> & ind){
    ll cans = 0, gans = -inf; 
    rp(i,ind.size()){
        ll val = ar[ind[i]].s;
        cans = max(val,cans+val);
        gans = max(gans,cans);
    }
    if(ind.size()==0)   return 0;
    else return gans;
}

//Dynamic Segment Tree
struct MAIN_NODE{
    MAIN_NODE *l,*r;
    vector<int> ar;
    ll sum;
    MAIN_NODE(){
        l=r=NULL;
        sum=0;
    }
};

void main_add_node(MAIN_NODE * v, ll l, ll r,ll q_l, ll q_r, int val){
    //cout<<l<<" "<<r<<endl;
    if (l>r||q_r<l||q_l>r)
        return;
    (v->ar).pb(val);
    v->sum+=ar[val].s;
    if(l==r)    return;
    ll mid = (l+r)>>1;
    if (v->l == NULL)
        v->l = new MAIN_NODE();
    if (v->r == NULL)
        v->r = new MAIN_NODE();
    main_add_node(v->l, l, mid, q_l, q_r, val);
    main_add_node(v->r, mid+1, r, q_l, q_r, val);
}

void main_query_tree(MAIN_NODE * v,ll l,ll r,ll x,ll y,vector<int> & ind){
    if(v==NULL || x>y || x>r || y<l){
        return;
    }
    if(x<=l && r<=y){
        if(!neg){
            osum += v->sum;
            return;
        }
        rp(i,v->ar.size()){
            ind.pb(v->ar[i]);
        }
        return;
    }

    ll mid = (l + r) >> 1;
    main_query_tree(v->l,l,mid,x,y,ind);
    main_query_tree(v->r,mid+1,r,x,y,ind);
}



int main(){
    FAST
    cin>>q>>k;
    ll C=0;
    MAIN_NODE * root = new MAIN_NODE;
    rp(i,q){
        ll t,c,d;
        cin>>t;
        if(t==1){
            cin>>c>>d;
            c=(c^C);
            // cout<<1<<" "<<c<<" "<<d<<endl;
            ar[--st].f=c;
            ar[st].s=d;
            if(d<0) neg=true;
            main_add_node(root,0,MAIN_N,c,c,st);
            // cout<<"r: "<<root->ans<<endl;
        }
        else if(t==2){
            cin>>c>>d;
            c=(c^C);
            // cout<<2<<" "<<c<<" "<<d<<endl;
            ar[++et].f=c;
            ar[et].s=d;
            if(d<0) neg=true;
            main_add_node(root,0,MAIN_N,c,c,et);
        }
        else{
            ll cb;
            cin>>cb;
            cb=(C^cb);
            // cout<<3<<" "<<cb<<endl;
            osum = 0;
            vector<int> ind;    
            main_query_tree(root,0,MAIN_N,max((ll)1,cb-k),min((ll)MAIN_N,cb+k),ind);    
            ll qans = 0;
            if(!neg)    qans = osum;    
            else{
                sort(ind.begin(),ind.end());
                qans = max((ll)0,query(ind));
            }
            cout<<qans<<endl;
            // cout<<0<<endl;
            C=qans;
        }
    }
    delete root;
    return 0;
}