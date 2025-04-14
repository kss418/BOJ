#include <bits/stdc++.h>
#include <ext/rope>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first 
#define y second
using namespace std; using ll = long long;
using ld = long double; using pld = pair<ld, ld>;
using i128 = __int128_t; using f128 = __float128; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX];

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r;
    _bs(T l, T r) {
        this->l = l; this->r = r;
    }

    bool f(T cur) {
        ll now = 0, mx = 0;
        priority_queue <ll, vector<ll>, greater<ll>> pq;

        for(int i = 1;i <= n;i++){
            pq.push(now + a[i]);
            while(pq.size() >= cur){
                now = pq.top();
                mx = max(mx, now);
                pq.pop();
            }
        }

        while(!pq.empty()){
            mx = max(mx, pq.top());
            pq.pop();
        }

        return mx <= m;
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
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];

    _bs <ll> bs(1, 10101);
    cout << bs.ret();
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}