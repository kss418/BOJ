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
constexpr ll MAX = 501010; // PLZ CHK!
constexpr ll MOD = 998244353;
vector <pair<ll, char>> adj[MAX];
ll mod[3] = { 1000000007, 998244353, 1000000009 };
ll key[3] = {29, 31, 26};

class _hash { // 0-based index
public:
    ll mod, key, size, h;
    deque <ll> q, pre;

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
        pre.push_back(h); size++;
    }

    void pop_back(){
        ll c = q.back(); q.pop_back();
        h -= c; h = mo(h);
        h *= inv(1, key, mod); h = mo(h);
        if(!pre.empty()) pre.pop_back(); size--;
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

    ll ret() { return mo(h); }
    ll ret(ll a, ll b){
        if(a > b) swap(a, b);
        if(!a) return ret(b);
        return mo(pre[b] - mo(pre[a - 1] * pow_mod(key, b - a + 1, mod)));
    }
    ll ret(ll a){ return mo(pre[a]); }
};
_hash a[3], b[3];
ll result;

void dfs(ll cur){
    bool flag = 1; ll si = b[0].size - 1;
    for(int i = 0;i < 3;i++) {
        if(a[0].size > b[0].size) { flag = 0; break; }
        flag &= (a[i].ret() == b[i].ret(si - s.size() + 1, si));
    }
    result += flag;

    for(auto& i : adj[cur]){
        auto[nxt, c] = i;
        for(int j = 0;j < 3;j++) b[j].push_back(c);
        dfs(nxt);
        for(int j = 0;j < 3;j++) b[j].pop_back();
    }
}

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i < n;i++) {
        ll s, e; char c;
        cin >> s >> e >> c;
        adj[s].push_back({e, c});
    }
    for(int i = 0;i < 3;i++)  a[i] = b[i] = { mod[i], key[i] };

    cin >> s;
    for(auto& i : s){
        for(int j = 0;j < 3;j++) a[j].push_back(i);
    }

    dfs(1);
    cout << result;
    
    return 0;
}