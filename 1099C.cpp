/* Author - linpaws07 */
#include<bits/stdc++.h>
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
    string s;
    cin >> s;
    int k, ct = 0, can = 0;
    cin >> k;
    int len = s.length();
    bool rep = false;
    rp(i, len - 1){
        if(s[i] >= 'a' && s[i] <= 'z'){
            if(s[i + 1] != '?' && s[i + 1] != '*')  ct++;
            if(s[i + 1] == '*')     rep = true;
            if(s[i + 1] == '?')     can++;
        }            
    }
    if(s[len - 1] >= 'a' && s[len - 1] <= 'z')    ct++;
    if(k < ct || !rep && k > ct + can )
        cout << "Impossible" << endl;
    else{
        string ans;
        int req = k - ct;
        rp(i, len - 1){
            if(s[i] >= 'a' && s[i] <= 'z'){
                if(s[i + 1] != '?' && s[i + 1] != '*')
                    ans += s[i];
                else{
                    if(s[i + 1] == '?' && req){
                        ans += s[i];
                        req--;
                    }
                    else{
                        while(req){
                            ans += s[i];
                            req--;
                        }
                    }
                }
            }
        }
        if(s[len - 1] >= 'a' && s[len - 1] <= 'z')  ans += s[len - 1];
        cout << ans << endl;
    }
    return 0;
}