#include <bits/stdc++.h>
#include <ext/rope>
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
constexpr ll MAX = 1010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

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
    cin >> n; vector <ll> v;
    for(int i = 0;i < n;i++) cin >> a[i], v.push_back(a[i]);
    _kmp kmp(v); kmp.init(v);

    ll now = 2 * n - kmp.f[n - 1] - 1;
    cout << now << "\n";
    for(int i = 0;i < now;i++){
        for(int j = 0;j < now;j++){
            cout << a[(i + j) % n] << " ";
        }
        cout << "\n";
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}