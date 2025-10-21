#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 301010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], p[MAX], ind[MAX], result = 1;
vector <ll> adj[MAX];
deque <ll> q;

class _uf { 
public:
    ll n; vector <ll> p;
    vector <vector <ll>> arr;
    
    _uf(){}
    _uf(ll n) { 
        this->n = n;
        p.resize(n + 1, -1);
        arr.resize(n + 1);
    }

    ll find(ll num) { 
        if (p[num] == -1) return num;
        return p[num] = find(p[num]);
    }

    void merge(ll a, ll b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size(a) < size(b)) swap(a, b);
        p[b] = a;

        for(int i = 0;i < arr[b].size();i++){
            arr[a][i] = min(arr[b][i], arr[a][i]);
        }
    }

    ll size(ll num){ return arr[find(num)].size(); }
    bool same(ll a, ll b) { return find(a) == find(b); }
}; _uf uf1, uf2;

void init(ll cur = 1, ll pre = -1){
    if(pre != -1) p[cur] = pre, ind[pre]++;
    for(auto& nxt : adj[cur]){
        if(pre == nxt) continue;
        init(nxt, cur);
    }
}

void push(ll cur){
    ll f1 = uf1.find(cur), f2 = uf2.find(cur);
    ll ub1 = lower_bound(all(uf1.arr[f1]), a[cur]) - uf1.arr[f1].begin();
    ll ub2 = lower_bound(all(uf2.arr[f2]), -a[cur]) - uf2.arr[f2].begin();

    if(ub1 == uf1.arr[f1].size()) uf1.arr[f1].push_back(a[cur]);
    else uf1.arr[f1][ub1] = a[cur];
    
    if(ub2 == uf2.arr[f2].size()) uf2.arr[f2].push_back(-a[cur]);
    else uf2.arr[f2][ub2] = -a[cur];
}

void cal(ll l, ll r){
    ll fl = uf1.find(l), fr = uf2.find(r);
    vector <ll> &arr1 = uf1.arr[fl], &arr2 = uf2.arr[fr];
    bool ch = arr1.size() > arr2.size();
    if(ch) swap(arr1, arr2);
    for(int i = 0;i < arr1.size();i++){
        ll lb = lower_bound(all(arr2), -arr1[i]) - arr2.begin();
        result = max(result, lb + i + 1);
    }

    if(ch) swap(arr1, arr2);
}

void run(){
    cin >> n; uf1 = {n}, uf2 = {n};
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }

    init();
    for(int i = 1;i <= n;i++) if(!ind[i]) q.push_back(i);

    while(!q.empty()){
        auto cur = q.front(); q.pop_front();
        push(cur);

        ll nxt = p[cur];
        if(!nxt) continue;

        push(nxt); cal(cur, nxt); cal(nxt, cur);
        uf1.merge(cur, nxt); uf2.merge(cur, nxt);
        if(!--ind[nxt]) q.push_back(nxt);
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}