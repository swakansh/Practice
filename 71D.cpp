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
typedef long int ii;
typedef unsigned long int uii;
typedef long long int ll;
typedef unsigned long long int ull;
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
inline void check(ll & a){ a %= mod; if(a < 0) a += mod; }
auto start = high_resolution_clock::now();
inline void measure();

string str[20][20];
int st[256];
char rev[4], crank[15];
int n, m;
bool check(int i, int j, bool pr = false){
    int suit[4] = {0};
    int rank[15] = {0};
    fr(k, i , i + 3){
        fr(l, j, j + 3){
            suit[st[str[k][l][1]]]++;
            rank[st[str[k][l][0]]]++;
        }
    }
    if(suit[0] == 9 || suit[1] == 9 || suit[2] == 9 || suit[3] == 9)    return 1;
    fre(i, 2, 14){
        if(rank[i] > 1) return 0;
    }
    return 1;
}
pair<bool, pair<pii, pii> > is_solvable(bool pr){
    vector<pii> vec;
    rp(i, n){
        rp(j, m){
            if(i + 3 > n || j + 3 > m)    continue;
            if(check(i, j, pr)) vec.pb({i, j});
        }
    }
    rp(i, vec.size()){
        fr(j, i + 1, vec.size()){
            if(abs(vec[i].f - vec[j].f) >= 3 || abs(vec[i].s - vec[j].s) >= 3)    return {true, {{vec[i].f + 1, vec[i].s + 1}, {vec[j].f + 1, vec[j].s + 1}}};
        }
    }
    return {false, {{0,0},{0,0}}};
}
int cards[4][15];
int main(){
    FAST
    //Do awesome things here
    cin >> n >> m;
    st['C'] = 0, st['D'] = 1, st['H'] = 2;st['S'] = 3;st['2'] = 2;st['3'] = 3;st['4'] = 4;st['5'] = 5;
    st['6'] = 6;
    st['7'] = 7;
    st['8'] = 8;
    st['9'] = 9;
    st['T'] = 10;
    st['J'] = 11;
    st['Q'] = 12;
    st['K'] = 13;
    st['A'] = 14;
    rev[0] = 'C';
    rev[1] = 'D';
    rev[2] = 'H';
    rev[3] = 'S';
    crank[2] = '2';
    crank[3] = '3';
    crank[4] = '4';
    crank[5] = '5';
    crank[6] = '6';
    crank[7] = '7';
    crank[8] = '8';
    crank[9] = '9';
    crank[10] = 'T';
    crank[11] = 'J';
    crank[12] = 'Q';
    crank[13] = 'K';
    crank[14] = 'A';
    bool joker = false;
    vector<pii> jpos;
    rp(i, n){
        rp(j, m){
            cin >> str[i][j];
            if(str[i][j][0] == 'J' && (str[i][j][1] == '1' || str[i][j][1] == '2')){
                joker = true;
                jpos.pb({i, j});
                continue;
            }
            cards[st[str[i][j][1]]][st[str[i][j][0]]]++;
        }
    }
    vector<string> ms(0);
    rp(i, 4){
        fr(j, 2, 15){
            if(cards[i][j] == 0){
                string mis = "";
                mis += crank[j];
                mis += rev[i];
                ms.pb(mis);
            }
        }
    }
    if(joker){
        if(jpos.size() == 1){
            string j1 = str[jpos[0].f][jpos[0].s];
            rp(i, ms.size()){
                str[jpos[0].f][jpos[0].s] = ms[i];
                bool pr = false;
                // if(ms[i] == "2H")   pr = true;
                pair<bool, pair<pii, pii > > ans = is_solvable(pr);
                if(ans.f){
                    cout << "Solution exists." << endl;
                    cout << "Replace " << j1 << " with " << ms[i] << "." << endl;
                    cout << "Put the first square to (" << ans.s.f.f << ", " << ans.s.f.s << ")." << endl;
                    cout << "Put the second square to (" << ans.s.s.f << ", " << ans.s.s.s << ")." << endl;
                    return 0;
                } 
            }
            cout << "No solution." << endl;
            return 0;
        }
        else{
            string j1 = str[jpos[0].f][jpos[0].s];
            string j2 = str[jpos[1].f][jpos[1].s];
            rp(i, ms.size()){
                fr(j, i + 1, ms.size()){
                    str[jpos[0].f][jpos[0].s] = ms[i];
                    str[jpos[1].f][jpos[1].s] = ms[j];
                    pair<bool, pair<pii, pii > > ans = is_solvable(false);
                    if(ans.f){
                        cout << "Solution exists." << endl;
                        if(j1 == "J1")  cout << "Replace " << j1 << " with " << ms[i] << " and " << j2 << " with " << ms[j] << "." << endl;
                        else cout << "Replace " << j2 << " with " << ms[j] << " and " << j1 << " with " << ms[i] << "." << endl;
                        cout << "Put the first square to (" << ans.s.f.f << ", " << ans.s.f.s << ")." << endl;
                        cout << "Put the second square to (" << ans.s.s.f << ", " << ans.s.s.s << ")." << endl;
                        return 0;
                    }
                    str[jpos[1].f][jpos[1].s] = ms[i];
                    str[jpos[0].f][jpos[0].s] = ms[j];
                    ans = is_solvable(false);
                    if(ans.f){
                        cout << "Solution exists." << endl;
                        if(j1 == "J1")  cout << "Replace " << j1 << " with " << ms[j] << " and " << j2 << " with " << ms[i] << "." << endl;
                        else cout << "Replace " << j2 << " with " << ms[i] << " and " << j1 << " with " << ms[j] << "." << endl;
                        cout << "Put the first square to (" << ans.s.f.f << ", " << ans.s.f.s << ")." << endl;
                        cout << "Put the second square to (" << ans.s.s.f << ", " << ans.s.s.s << ")." << endl;
                        return 0;
                    }            
                }
            }
            cout << "No solution." << endl;
        }
    }
    else{
        pair<bool, pair<pii, pii > > ans = is_solvable(false);
        if(ans.f){
            cout << "Solution exists." << endl;
            cout << "There are no jokers." << endl;
            cout << "Put the first square to (" << ans.s.f.f << ", " << ans.s.f.s << ")." << endl;
            cout << "Put the second square to (" << ans.s.s.f << ", " << ans.s.s.s << ")." << endl;
            return 0;
        }
        cout << "No solution." << endl;
    }
    return 0;
}


inline void measure(){
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
}