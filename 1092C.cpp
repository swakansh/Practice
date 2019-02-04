/* Author - linpaws07 */
#include <bits/stdc++.h>
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
const int inf = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
string str;
vector<char> ind(202);
multiset<string> mst;
map<string,vector<int> > st; 
vector<string> sl;
vector<string> sstr;    
int l,n;
bool cmp(string a,string b){
    return a.length()<b.length();
}
bool doit(string e){
    string cst="";
    rp(i,e.length()-1){
        cst+=e[i];
        if(mst.find(cst)!=mst.end()){
            mst.erase(mst.find(cst));
            ind[st[cst].back()]='P';
            st[cst].pop_back();
            if(st[cst].size()==0)
                st.erase(st.find(cst));
        }
    }    
    cst = "";
    frd(i,e.length()-1,1){
        cst=e[i]+cst;
        if(mst.find(cst)!=mst.end()){
            mst.erase(mst.find(cst));
            ind[st[cst].back()]='S';
            st[cst].pop_back();
            if(st[cst].size()==0)
                st.erase(st.find(cst));
        }
    }
    if(mst.size()==0)   return true;
    return false;
}
void print(){
    rp(i,2*n-2){
        cout<<ind[i];
    }
    cout<<endl;    
}
void reset(){
    mst.clear();
    st.clear();
    rp(i,2*n-2){
        mst.insert(sstr[i]);
        st[sstr[i]].pb(i);
    }
}
int main(){
    FAST
    cin>>n;
    rp(i,2*n-2){
        cin>>str;
        sstr.pb(str);
        if(str.length()==1||str.length()==n-1)   sl.pb(str);
        mst.insert(str);
        st[str].pb(i);
    }
    sort(sl.begin(),sl.end(),cmp);
    if(n==2){
        cout<<"PS"<<endl;
        return 0;
    }
    string a = sl[0],b=sl[1],c=sl[2],d=sl[3];
    string e = a+d;
    string f = c+b;  
    if(e==f){
        if(doit(e)){
            print();
            return 0;
        }
    }
    e = a+c;
    f = d+b;
    reset();
    if(e==f){
        if(doit(e)){
            print();
            return 0;
        }
    }
    e = b+c;
    f = d+a;
    reset();
    if(e==f){
        if(doit(e)){
            print();
            return 0;
        }
    }
    e = b+d;
    f = c+a;
    reset();
    if(e==f){
        if(doit(e)){
            print();
            return 0;
        }
    }
    return 0;
}