/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define f first
#define s second
#define pi pair<int, int>
#define pl pair<ll, ll>
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

int ar[100002];

void find_longest_increasing_subsequence(int size){
    int len[100002] = {0}, pind[100002] = {0};
    len[0] = 1;
    pind[0] = -1;
    int olen = 1, oind = 0;
    fr(i, 1, size){
        int clen = 1, ind = -1;
        fr(j, 0, i){
            if(ar[i] > ar[j]){
                if(1 + len[j] > clen){
                    clen = 1 + len[j];
                    ind = j;
                }
            }
        }
        len[i] = clen;
        pind[i] = ind;  
        if(len[i] >  olen){
            olen = len[i];
            oind = i;
        }
    }
    cout << "Max hits: " << olen << endl;
    vector<int> ans;
    while(oind != -1){
        ans.pb(ar[oind]);
        oind = pind[oind];
    }
    reverse(ans.begin(), ans.end());
    for(int a : ans){
        cout << a << endl;
    }
}
int main(){
    FAST
    int t;
    string inp;
    getline(cin, inp);
    t = stoi(inp);
    getline(cin, inp);
    while(t--){
        string n;
        int i = 0;
        while(getline(cin, n)){
            if(n == "")  break;
            ar[i] = stoi(n);
            // cout << ar[i] << endl;
            i++;
        }
        find_longest_increasing_subsequence(i);
        if(t) cout << endl;
    }
    return 0;
}