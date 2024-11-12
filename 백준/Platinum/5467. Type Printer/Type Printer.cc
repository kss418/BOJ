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
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 25010; // PLZ CHK!
constexpr ll MOD = 998244353;
string st[MAX];
ll d[MAX * 20];

template <typename T = ll>
class _trie { // 0-based index
public:
    ll n, m, seq = 2;
    vector <vector<T>> adj;
    vector <bool> chk;
    vector <char> c;

    _trie() {}
    _trie(ll k, ll n, ll m = 26) { // 문자열 개수, 문자열 길이, 문자 개수
       this->m = m; this->n = n; 
       chk.resize(n * k + 1); adj.resize(n * k + 1);
       c.resize(n * k + 1);
    }

    void insert(string& s){
        ll cur = 1;
        for(auto &st : s){
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!adj[cur][st - 'a']) adj[cur][st - 'a'] = seq++;
            cur = adj[cur][st - 'a'];
            c[cur] = st;
        }
        chk[cur] = 1;
    }

    bool find(string& s){
        ll cur = 1;
        for(auto &st : s){
            if(adj[cur].empty()) adj[cur].resize(m + 1);
            if(!adj[cur][st - 'a']) return 0;
            cur = adj[cur][st - 'a'];
        }
        return chk[cur];
    }
};

_trie arr;
ll dfs(ll cur, ll pre){
    ll ret = 1;
    for(auto nxt : arr.adj[cur]){
        if(nxt == pre) continue;
        if(!nxt) continue;
        ret = max(ret, dfs(nxt, cur) + 1);
    }

    return d[cur] = ret;
}

vector <char> result; ll cnt;
string now;

void solve(ll cur, ll pre){
    if(cur >= 2) result.push_back(arr.c[cur]); cnt++;
    if(cur >= 2) now.push_back(arr.c[cur]);
    if(cur >= 2 && arr.find(now)) result.push_back('P');
    
    vector <pll> vec;
    for(auto& nxt: arr.adj[cur]){
        if(!nxt) continue;
        if(nxt == pre) continue;
        vec.push_back({d[nxt], nxt});
    }
    sort(all(vec));

    for(auto& i : vec){
        auto[d, nxt] = i;
        solve(nxt, cur);
    }

    if(cur >= 2) now.pop_back();
    result.push_back('-');
}

int main() {
    fastio;

    cin >> n; arr = {MAX, 20};
    for(int i = 0;i < n;i++) cin >> st[i], arr.insert(st[i]);
    dfs(1, -1); solve(1, -1);

    while(!result.empty() && result.back() == '-') result.pop_back();
    cout << result.size() << "\n";
    for(auto& i : result) cout << i << "\n";
    
    
    return 0;
}