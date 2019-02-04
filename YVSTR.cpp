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

vector<pair<ll, ll> > vc[26][26];
vector<string> ar;
        
ll calculate(int i, int j){
    if(vc[i][j].size() == 0)    return (ll)0;
    ll ans = 0; 
    sort(vc[i][j].begin(), vc[i][j].end(), cmp);
    vector<pair<ll, ll> > temp;
    temp.pb(vc[i][j][0]);
    int l = 0;
    fr(k, 1, vc[i][j].size()){
        if(vc[i][j][k].f <= temp[l].f && vc[i][j][k].s > temp[l].s){
            temp.pb(vc[i][j][k]);
            l++;
        }
    }
    temp.pb({0, 0});
    rp(k, temp.size() - 1){
        ans = ans + (temp[k].f - temp[k + 1].f) * temp[k].s;
    }
    return ans;
}
int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string sr, str;
        cin >> sr;
        str += sr[0];
        ar.clear();
        rp(i, 26){
            rp(j, 26){
                vc[i][j].clear();
            }
        }
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
        rp(i, ar.size() - 1){
            vc[ar[i][0] - 'a'][ar[i + 1][0] - 'a'].pb({ar[i].length(), ar[i + 1].length()});
        }
        rp(i, 26){
            rp(j, 26){
                if(i != j)
                    ans =  ans + calculate(i, j);
            }
        }
        cout << ans << endl;
    }
    return 0;
}