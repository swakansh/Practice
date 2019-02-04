/* 
    Author - linpaws07 
*/
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define inf (int)1e9
#define f first
#define s second
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define scd(t) scanf("%d",&t)
#define sclld(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define memst(a, b) memset(a, (b), sizeof(a))
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rp(i,n) for(int i=0;i<(n);i++)
#define fr(i,a,b) for(int i=(a);i<(b);i++)
#define fre(i,a,b) for(int i=(a);i<=(b);i++)
#define frd(i,a,b) for(int i=(a);i>=(b);i--)
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n>>b)&1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }
auto start = high_resolution_clock::now();
inline void measure();

int md[100002];
string solve(string s, int d, int t) {
    string res = "";
    int ct = 0;
    frd(i, s.length() - 1, 0) {
        if((s[i] - '0') % 3 == d && ct < t) ct++;
        else    res += s[i];
    }
    reverse(res.begin(), res.end());
    while(res[0] == '0')  res.erase(res.begin());
    // cout << res.size() << "S" << endl;
    return res;
}

int main(){
    FAST
    //Do awesome things here
    string s;
    cin >> s;
    int sum = 0;
    rp(i, s.length()) {
        md[(s[i] - '0') % 3]++;
        sum +=  (s[i] - '0') % 3;
    }
    sum %= 3;
    // cout << md[0] << " " << md[1] << " " << md[2] << endl;
    if(sum == 0){
        cout << s << endl;
    }
    else if(sum == 1) {
        string res = "";
        if(md[1]) {
            string ans = solve(s, 1, 1);
            res = ans;     
        }
        if(md[2] >= 2) {
            string ans = solve(s, 2, 2);
            if(ans.size() > res.size()) res = ans;
        }
        if(res.size())  cout << res << endl;
        else if(s.find('0') != string::npos) cout << "0" << endl;
        else    cout << "-1" << endl;
    }
    else if(sum == 2) {
        string res = "";
        if(md[2]) {
            string ans = solve(s, 2, 1);
            res = ans;     
        }
        if(md[1] >= 2)  {
            string ans = solve(s, 1, 2);
            if(ans.size() > res.size()) res = ans;
        }
        if(res.size())  cout << res << endl;
        else if(s.find('0') != string::npos) cout << "0" << endl;
        else    cout << "-1" << endl;
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}