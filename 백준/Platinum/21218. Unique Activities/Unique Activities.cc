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
ll idx;

class _hash { // 0-based index
public:
//  ll mod[3] = { 1000000007, 998244353, 1000000009 };
//  ll key[3] = { 29, 31, 26 };
    ll mod, key, size, h, all;
    vector <ll> mul;
    deque <ll> q, pre;

    _hash() {}
    _hash(ll key, ll mod, ll all) {
        this->mod = mod; this->key = key;
        this->size = 0; this->h = 0;
        this->all = all;

        mul.resize(all + 1); mul[0] = 1;
        for(int i = 1;i <= all;i++) mul[i] = (mul[i - 1] * key) % mod;
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

    void push_front(ll c){
        q.push_front(c);
        h += mul[size] * c;
        h = mo(h); size++;
    }

    void pop_front(){
        ll c = q.front(); q.pop_front();
        h -= mul[size - 1] * c;
        h = mo(h); size--;
    }

    ll ret() { return mo(h); }
    ll ret(ll a, ll b){
        if(a > b) swap(a, b);
        if(!a) return ret(b);
        return mo(pre[b] - mo(pre[a - 1] * mul[b - a + 1]));
    }
    ll ret(ll a){ return mo(pre[a]); }

    void clear(){
        size = 0; h = 0;
        q.clear(); pre.clear();
    }
};

class pair_hash{
public:
    size_t operator()(const pll& p) const{
        size_t h1 = std::hash<ll>{}(p.x);
        size_t h2 = std::hash<ll>{}(p.y);
        return h1 ^ h2;
    }
};
unordered_map <pll, ll, pair_hash> cnt;
vector <tll> arr;
_hash h1, h2;

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        h1.clear(); h2.clear();
        arr.clear(); cnt.clear();

        for(int i = 0;i < cur - 1;i++){
            h1.push_back(s[i] - 'A');
            h2.push_back(s[i] - 'A');
        }

        for(int i = cur - 1;i < s.size();i++){
            h1.push_back(s[i] - 'A');
            h2.push_back(s[i] - 'A');

            cnt[{h1.ret(), h2.ret()}]++;
            arr.push_back({i - cur + 1, h1.ret(), h2.ret()});

            h1.pop_front();
            h2.pop_front();
        }

        for(auto& [st, v1, v2] : arr){
            if(cnt[{v1, v2}] >= 2) continue;
            idx = st; return 1;
        }
        
        return 0;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo) / (T)2;
            if (f(mid)) hi = mid;
            else lo = mid + 1;
        }

        return lo;
    }
};

void run(){
    cin >> s;
    if(s.empty()) return;
    h1 = {29, 998244353, s.size()};
    h2 = {31, 1000000007, s.size()};

    _bs <ll> bs(1ll, s.size());
    ll len = bs.ret();
    for(int i = idx;i < idx + len;i++) cout << s[i];
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}