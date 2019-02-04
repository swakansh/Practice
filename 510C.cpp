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
int main(){
    FAST
    int n;
    cin >> n;
    vector<int> adj[26];
    vector<string> str(105);
    rp(i, n){
        cin >> str[i];
    }
    int flag[26] = {0};
    int pos = 1;
    bool aflag = false;
    rp(i, n - 1){
        int j = 0;
        while(j < str[i].length() && j < str[i + 1].length() && str[i][j] == str[i + 1][j])   j++;
        if(j >= str[i + 1].length() && j < str[i].length()) aflag = true;
        else if(j < str[i + 1].length() && j < str[i].length()) adj[str[i][j] - 'a'].pb(str[i + 1][j] - 'a');
    }
    if(aflag){
        cout << "Impossible" << endl;
        return 0; 
    }
    // do topological sorting
    priority_queue<int, vector<int>, greater<int>> pq;
    int indegree[26] = {0};
    rp(i, 26){
        for(int to : adj[i]){
            indegree[to]++;
        }
    }
    rp(i, 26){
        if(indegree[i] == 0)    pq.push(i);
    }
    string ans;
    while(!pq.empty()){
        int fr = pq.top();
        pq.pop();
        ans += char(fr + 'a');
        for(int to : adj[fr]){
            indegree[to]--;
            if(indegree[to] == 0)   pq.push(to);
        }
    }
    if(ans.length() < 26 || ans.length() > 26){
        cout << "Impossible" << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}