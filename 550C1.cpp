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
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if((s[i]-'0')%8==0){
            cout<<"YES"<<endl;
            cout<<s[i]<<endl;
            return 0;
        }
    }
    for(int i=0;i<s.length();i++){
        for(int j=i+1;j<s.length();j++){
            int n1 = s[i]-'0';
            int n2 = s[j] - '0';
            if((n1*10+n2)%8==0){
                cout<<"YES"<<endl;
                cout<<n1*10+n2<<endl;
                return 0;
            }
        }
    }
    for(int i=0;i<s.length();i++){
        for(int j=i+1;j<s.length();j++){
            for(int k=j+1;k<s.length();k++){
                int n1 = s[i]-'0';
                int n2 = s[j]-'0';
                int n3 = s[k]-'0';
                int num = n1*100+n2*10+n3;
                if(num%8==0){
                    cout<<"YES"<<endl;
                    cout<<num<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}