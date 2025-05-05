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
constexpr ll MAX = 50101; // SET MAX SIZE
constexpr ll MOD = 998244353;

class node{
public:
    ll x, y, op;
    bool operator < (const node& ot) const{
        if(ot.x == x) return y < ot.y;
        return x < ot.x;
    }
};
vector <node> a;
map <ll, bool> cnt;
set <ll> num;

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        ll x, y, sp; cin >> x >> y >> sp;
        ll s = -sp * (x + 1), e = -sp * x;
        a.push_back({s, y, 1});
        a.push_back({e, y, -1});
    }
    sort(all(a));

    ll la = -1;
    for(auto& [x, y, op] : a){
        if(!num.empty() && la != x) cnt[abs(*num.begin())] = 1;
        la = x;

        if(op == 1) num.insert(y);
        else num.erase(num.find(y));
    }
    if(!num.empty()) cnt[abs(*num.begin())] = 1;

    ll result = 0;
    for(auto& [y, num] : cnt) result += num;
    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

