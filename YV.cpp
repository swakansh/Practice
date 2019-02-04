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

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.f > b.f || (a.f == b.f && a.s > b.s);
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string sr;
        cin >> sr;
        vector<string> ar;
        string str;
        str += sr[0];
        fr(i, 1, sr.length()){
            if(sr[i] != sr[i - 1]){
                ar.pb(str);
                str = sr[i];
            }
            else
                str += sr[i];
        }
        ar.pb(str);
        ll ans = 0;
        map<char, ll> m;
        rp(i, ar.size()){
            if(m.find(ar[i][0]) != m.end())
                m[ar[i][0]] = max(m[ar[i][0]], (ll)ar[i].length());
            else
                m[ar[i][0]] = (int)ar[i].length();
        }
        for(auto ar : m){
            ans += m[ar.f];
        }
        if(ar.size() == 1){
            cout << ans << endl;
            continue;
        }
        map<string, vector<pair<ll, ll > > > mp, mpo;
        rp(i, ar.size() - 1){
            string key;
            key += ar[i][0];
            key += ar[i + 1][0];
            mp[key].pb({ar[i].length(), ar[i + 1].length()});
        }
        for(auto ar : mp){
            sort(mp[ar.f].begin(), mp[ar.f].end(), cmp);
            mpo[ar.f].pb(mp[ar.f][0]);
            int l = 0;
            for(int i = 1; i < mp[ar.f].size(); i++){
                if((mp[ar.f])[i].s > (mpo[ar.f])[l].s){
                    mpo[ar.f].pb(mp[ar.f][i]);
                    l++;
                }
            }
            mpo[ar.f].pb({0, 0});
        }
        for(auto ar : mpo){
            for(int i = 0; i < (ar.s).size() - 1; i++){
                ans = ans + ((ar.s)[i].f - (ar.s)[i + 1].f) * (ar.s)[i].s;
            }
        }
        cout << ans << endl;
    }
    return 0;
}