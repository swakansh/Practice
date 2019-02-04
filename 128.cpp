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

// kya chutiyapa code kiye ho!!

int key = 34943;
unordered_map<string, char> hex_map;

string cb(int num){
    string bin;
    while(num){
        bin = char(num % 2 + '0') + bin;
        num /= 2;
    }
    return bin;
}

void prepare_map(){
    fre(i, 0, 15){
        string cbs = cb(i);
        while(cbs.length() < 4){
            cbs = '0' + cbs;
        }
        hex_map[cbs] = (i <= 9 ? char(i + '0') : char(i - 10 + 'A'));
    }
}

string xorop(string s1, string s2) {
    string ans;
    rp(i, s1.length()){
        if(s1[i] == s2[i]) ans += '0';
        else    ans += '1';
    }
    return ans;
}

string convert_to_hex(string str) {
    while(str.length() < 16) {
        str = '0' + str;
    }
    int c = 0;
    string hex = "";
    for(int i = 0 ;i < str.length(); i += 4){
        hex += hex_map[str.substr(i, 4)];
        if(c & 1)   hex += ' ';
        c++;
    }
    return hex;
}

string mod2div(string s1, string s2) {
    string cur = s1.substr(0, s2.length());
    string zero = "";
    s1 += '0';
    rp(i, s2.length())  zero += '0';
    int ind = s2.length();
    while(ind < s1.length()){
        if(cur[0] == '1'){
            cur = xorop(cur, s2);
            cur = cur.substr(1);
        }
        else{
            cur = xorop(cur, zero);
            cur = cur.substr(1);
        }
        cur += s1[ind];
        ind += 1;
    }
    cur = cur.substr(0, cur.length() - 1);
    cout << cur << endl;
    return cur;
}

int main(){
    FAST
    //Do awesome things here
    string str;
    getline(cin, str);
    string d2 = cb(key);
    prepare_map();
    while(str.compare("#") != 0) {
        string d1 = "";
        rp(i, str.length()) {
            string d1s = cb(str[i]);
            while(d1s.length() < 8){
                d1s = '0' + d1s;
            }
            d1 += d1s;
        }
        rp(i, d2.length()) {
            d1 += '0';
        }
        cout << d1 << " " << d2 << endl;
        string rem = mod2div(d1, d2);
        cout << rem.length() << endl;
        cout << convert_to_hex(rem) << endl;
        cin >> str;
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}