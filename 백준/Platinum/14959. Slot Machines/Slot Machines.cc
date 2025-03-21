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
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> a;
ll rk = INF, rp = INF;

class _kmp { // 0-based index
public:
    vector <ll> f, v; ll n;

    _kmp(){}
    _kmp(string& s) : _kmp(move(tf(s))){};
    _kmp(const vector <ll>& v){ this->v = v; this->n = v.size(); }

    void init(const vector <ll>& m){ // fail 함수 계산
        ll nxt = 0; f.clear(); f.resize(m.size(), 0);
        for(int cur = 1;cur < m.size();cur++){
            while(nxt && m[cur] != m[nxt]) nxt = f[nxt - 1];
            if(m[cur] == m[nxt]) f[cur] = ++nxt;
        }
    }
    
    vector <ll> ret(string& s){ return ret(move(tf(s)));}
    vector <ll> ret(const vector <ll>& m){ // index 반환
        init(m); vector <ll> r;
        ll nxt = 0;
        for(int cur = 0;cur < n;cur++){
            while(nxt && v[cur] != m[nxt]) nxt = f[nxt - 1];
            if(v[cur] == m[nxt]) nxt++;
            if(nxt == m.size()){
                r.push_back(cur - nxt + 1);
                nxt = f[nxt - 1];
            }
        }

        return r;
    }

    vector <ll> tf(string& s){
        vector <ll> ret;
        for(auto& i : s) ret.push_back(i);
        return ret;
    }
};

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> m, a.push_back(m);
    reverse(all(a)); _kmp kmp(a); kmp.init(a);

    vector <ll>& f = kmp.f;
    for(int i = 0;i < n;i++){
        ll k = n - i - 1, p = i + 1 - f[i];
        if(rk + rp > k + p) rk = k, rp = p;
        else if(rk + rp == k + p && p < rp) rk = k, rp = p;
    }

    cout << rk << " " << rp;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

