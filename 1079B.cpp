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
int main(){
    FAST
    string str;
    cin >> str;
    int ch[6][21] = {0};
    int len = str.length();
    // cout << len << endl;
    int r = len / 20;
    int c = 20;
    int rem = len % 20;
    if(rem){
        rem = 20 - rem;
        r++;
        if(r == 1){
            c = len;
        }
        else{
            // cout << rem << " " << r << endl;
            while(rem >= r){
                rem -= (r);
                c--;
            }
            fr(i, 1, rem){
                ch[i][c] = -1;
            }
        }
    }
    int ct = 0;
    cout << r << " " << c << endl;
    fre(i, 1, r){
        fre(j, 1, c){
            if(ch[i][j] ==  -1) cout << "*";
            else if(ct < len)    cout << str[ct++];
            else    cout << "*";
        }
        cout << endl;
    }
    return 0;
}