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
#define MOD 1000000007
#define ll long long int
#define pb push_back
#define f first
#define s second
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
const int INF = 1<<29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
map<string,pair<string,bool> > dp;
int flag[1000];
pair<string,bool> solve(string s){
    if(dp.find(s)!=dp.end()){
        return dp[s];
    }
    if(s.length()<=3){
        int num=0;
        for(int i=0;i<s.length();i++){
            num=num*10+(s[i]-'0');
        }
        if(flag[num]!=-1){
            return {to_string(flag[num]),true};
        }
        else{
            return {" ",false};
        }
    }
    int num=0;
    for(int i=s.length()-3;i<s.length();i++){
        num=num*10+(s[i]-'0');
    }
    if(num%8==0){
        return {s,true};
    }
    else{
        for(int i=s.length()-3;i<s.length();i++){
            string cpy(s);
            for(int j=i+1;j<s.length();j++){
                cpy[j-1]=s[j];
            }
            cpy=cpy.substr(0,cpy.length()-1);
            pair<string,bool> ans = solve(cpy);
            if(ans.s){
                dp[s]=ans;
                return ans;
            }
        }
    }
    return {" ",false};
}
int main(){
    for(int i=0;i<1000;i++){
        flag[i]=-1;
    }
    for(int i=0;i<1000;i+=8){
        flag[i]=i;
    }
    for(int i=10;i<100;i++){
        if(flag[i]!=-1) continue;
        if(flag[i%10]!=-1){
            flag[i]=flag[i%10];
            continue;
        }
        if(flag[i/10]!=-1){
            flag[i]=flag[i/10];
            continue;
        }
        flag[i]=-1;
    }
    for(int i=100;i<1000;i++){
        if(flag[i]!=-1) continue;
        if(flag[i/10]!=-1){
            flag[i]=flag[i/10];
            continue;
        }
        if(flag[i%100]!=-1){
            flag[i]=flag[i%100];
            continue;
        }
        if(flag[i/100*10+i%10]!=-1){
            flag[i]=flag[i/100*10+i%10];
            continue;
        }
        flag[i]=-1;
    }
    string s;
    cin>>s;
    if(s.length()<=3){
        int num=0;
        for(int i=0;i<s.length();i++){
            num=num*10+(s[i]-'0');
        }
        if(flag[num]!=-1){
            cout<<"YES"<<endl;
            cout<<flag[num]<<endl;
            return 0;
        }
    }
    pair<string,bool> ans = solve(s);
    if(ans.s){
        cout<<"YES"<<endl;
        cout<<ans.f<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}