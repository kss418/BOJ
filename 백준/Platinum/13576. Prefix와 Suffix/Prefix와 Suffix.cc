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
constexpr ll MAX = 101010; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> arr;
vector <pll> result;

class _z { // 0-based index
public:
    vector <ll> result, a; ll n;
    ll l = 0, r = 0;
        
    _z(){}
    _z(string& s) : _z(move(tf(s))){};
    _z(const vector <ll>& a){ 
        this->a = a; this->n = a.size();
        result.resize(n); init(); 
    }
    
    void init(){ // z array 계산
        result[0] = n;
        for(int i = 1;i < n;i++){
            if(i <= r) result[i] = min(r - i, result[i - l]);
            while(i + result[i] < n && a[i + result[i]] == a[result[i]]) result[i]++;
            if(i > r) l = i; r = max(r, i + result[i] - 1);
        }
    }
        
    vector <ll> tf(string& s){
        vector <ll> ret;
        for(auto& i : s) ret.push_back(i);
        return ret;
    }
    
    vector <ll> ret(){ return result; }
};

void run(){
    cin >> s; _z z(s);
    vector <ll> ret = z.ret();
    for(auto& i : ret) arr.push_back(i);
    sort(all(arr));

    for(int i = s.size() - 1;i >= 0;i--){
        if(i + ret[i] != s.size()) continue;
        result.push_back({ret[i], arr.end() - lower_bound(all(arr), ret[i])});
    }

    cout << result.size() << "\n";
    for(auto& [a, b] : result) cout << a << " " << b << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

