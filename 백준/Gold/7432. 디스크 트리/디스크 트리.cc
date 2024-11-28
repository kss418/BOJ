#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 501; // SET MAX SIZE
constexpr ll MOD = 998244353;
string st[MAX], str[2010];

class _trie { // 0-based index
public:
    ll n, m, seq = 2;
    vector <vector<ll>> adj;
    vector <bool> chk;
    vector <ll> num;

    _trie(){}
    _trie(ll k, ll n, ll m = 26) { // 문자열 개수, 문자열 길이, 문자 개수
       this->m = m; this->n = n; 
       chk.resize(n * k + 1); adj.resize(n * k + 1);
       num.resize(n * k + 1);
    }

    void insert(string& s) { insert(move(tf(s))); }
    void insert(const vector <ll>& a){
        ll cur = 1;
        for(auto &i : a){
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!adj[cur][i]) adj[cur][i] = seq++;
            cur = adj[cur][i]; num[cur] = i;
        }
        chk[cur] = 1;
    }

    void erase(string& s) { erase(move(tf(s))); }
    void erase(const vector <ll>& a){
        ll cur = 1;
        for(auto &i : a){
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!adj[cur][i]) return;
            cur = adj[cur][i]; num[cur] = -INF;
        }
        chk[cur] = 0;
    }

    bool find(string& s) { return find(move(tf(s))); }
    bool find(const vector <ll>& a){
        ll cur = 1;
        for(auto &i : a){
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!adj[cur][i]) return 0;
            cur = adj[cur][i];
        }
        return chk[cur];
    }

    vector <ll> tf(string& s){  
        vector <ll> ret;
        for(auto& i : s) {
            if(i >= 'a') ret.push_back(i - 'a');
            else ret.push_back(i - 'A');
        }
        return ret;
    }
};

set <string> use;
map <string, ll> num;
void parsh(string& s){
    string cur;
    for(auto& i : s){
        if(i == '\\') use.insert(cur), cur.clear();
        else cur.push_back(i);
    }
    use.insert(cur);
}

_trie tri;
void insert(string& s){
    string cur; vector <ll> now;
    for(auto& i : s){
        if(i == '\\') now.push_back(num[cur]), cur.clear();
        else cur.push_back(i);
    }
    now.push_back(num[cur]);
    tri.insert(now);
}

void dfs(ll cur, ll dep = -1){
    for(int i = 0;i < dep;i++) cout << " ";
    if(cur != 1) cout << str[tri.num[cur]] << "\n";

    if(tri.adj[cur].empty()) return;
    for(int nxt = 0;nxt <= tri.m;nxt++){
        if(!tri.adj[cur][nxt]) continue;
        dfs(tri.adj[cur][nxt], dep + 1);
    }
}

int main() {
    fastio;

    cin >> n; 
    for(int i = 1;i <= n;i++) {
        cin >> st[i]; parsh(st[i]);
    }

    ll cnt = 0;
    for(auto& i : use) num[i] = ++cnt, str[cnt] = i;
    tri = {n, 40, cnt + 1};
    for(int i = 1;i <= n;i++) insert(st[i]);
    
    dfs(1);

     
    return 0;
}