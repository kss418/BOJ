#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
constexpr ll MAX = 1010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], in[MAX], out[MAX];
ll d[MAX], num[MAX];
vector <ll> adj[MAX];
ll mod = 1000000007;
ll key = 31;

class _hash { // 0-based index
public:
    // ll mod[3] = { 1000000007, 998244353, 1000000009 };
    // ll key[3] = { 29, 31, 26 };
    ll mod, key, size, h;
    deque <ll> q;

    _hash() {}
    _hash(ll mod, ll key = 2) {
        this->mod = mod; this->key = key;
        this->size = 0; this->h = 0;
    }

    ll pow_mod(ll a, ll b, ll c) {
        if (!b) return 1;
        ll ret = pow_mod(a, b / 2, c) % c;

        if (b % 2) return ((ret * ret) % c * (a % c)) % c;
        return (ret * ret) % c;
    }

    ll prime_inv(ll a, ll b) {
        return pow_mod(a, b - 2, b);
    }

    ll inv(ll a, ll b, ll m) { // (a * b^-1) % m 반환 m == prime
        return (a % m * prime_inv(b, m) % m) % m;
    }

    ll mo(ll n) {
        if (n % mod >= 0) return n % mod;
        else return (n % mod) + mod;
    }

    void push_back(ll c){
        q.push_back(c);
        h *= key; h = mo(h);
        h += c; h = mo(h);
        size++;
    }

    void pop_back(){
        ll c = q.back(); q.pop_back();
        h -= c; h = mo(h);
        h *= inv(1, key, mod); h = mo(h);
        size--;
    }

    void push_front(ll c){
        q.push_front(c);
        h += pow_mod(key, size, mod) * c;
        h = mo(h); size++;
    }

    void pop_front(){
        ll c = q.front(); q.pop_front();
        h -= pow_mod(key, size - 1, mod) * c;
        h = mo(h); size--;
    }

    ll ret() {
        return mo(h);
    }
};

ll cnt = 0, suf[MAX], pre[MAX];
vector <ll> tr;
void dfs(ll cur, ll pre, ll dep){
    d[cur] = dep;
    in[cur] = ++cnt;
    tr.push_back(cur);
    ll l = INF, r = INF;
    sort(all(adj[cur]));
    for(auto& nxt : adj[cur]){
        if(nxt == pre) continue;
        dfs(nxt, cur, dep + 1);
        tr.push_back(cur);
    }

    out[cur] = ++cnt;
}

ll pow_mod(ll a, ll b, ll c) {
    if (!b) return 1;
    ll ret = pow_mod(a, b / 2, c) % c;

    if (b % 2) return ((ret * ret) % c * (a % c)) % c;
    return (ret * ret) % c;
}

ll prime_inv(ll a, ll b) {
    return pow_mod(a, b - 2, b);
}

ll inv(ll a, ll b, ll m) { // (a * b^-1) % m 반환 m == prime
    return (a % m * prime_inv(b, m) % m) % m;
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++){
        ll s, e; cin >> s >> e;
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    dfs(1, -1, 0);

    for(int i = 1;i <= n;i++) num[i] = d[i] * 1e10 + a[i];
    _hash a, b;
    a = { mod, key };
    b = { mod, key };
 
    for(int i = 1;i <= tr.size();i++){
        a.push_back(num[tr[i - 1]] % mod);
        pre[i] = a.ret();
    } 

    for(int i = tr.size();i >= 1;i--){
        b.push_back(num[tr[i - 1]] % mod);
        suf[i] = b.ret();
    } 

    vector <ll> result;
    for(int i = 1;i <= n;i++){
        bool flag = 1; 
        ll st = in[i], en = out[i] - 1;

        ll pp = pre[st - 1] * pow_mod(key, en - st + 1, mod) % mod;
        ll sp = suf[en + 1] * pow_mod(key, en - st + 1, mod) % mod;

        ll p = (pre[en] - pp + mod) % mod;
        ll s = (suf[st] - sp + mod) % mod;

        if(s != p) flag = 0;
        if(flag) result.push_back(i);
    }

    sort(all(result));
    cout << result.size() << "\n";
    for(auto& i : result) cout << i << " ";
    

    return 0;
}
