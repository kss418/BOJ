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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll a[MAX], result;

template <typename T = ll>
class _bs { // 0-based index
public:
    T l, r, num;
    _bs(T l, T r, T num) {
        this->l = l; this->r = r;
        this->num = num;
    }

    bool f(T cur) {
        return cur * cur <= num;
    }

    T ret() {
        T lo = l, hi = r, mid = -1;
        while (hi > lo) {
            mid = (hi + lo + 1) / (T)2;
            if (f(mid)) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};

bool p(ll now, ll cur){
    vector <ll> num, ten;
    while(now){
        num.push_back(now % cur);
        if(now % cur > 9) return 0;
        now /= cur;
    }

    now = m;
    while(now){
        ten.push_back(now % 10);
        now /= 10;
    }

    if(num.size() > ten.size()) return 1;
    if(num.size() < ten.size()) return 0;
    for(int i = num.size() - 1;i >= 0;i--){
        if(num[i] == ten[i]) continue;
        return num[i] > ten[i];
    }

    return 1;
}

void solve2(){
    for(int i = 1;i <= 9;i++){
        for(int j = 0;j <= 9;j++){
            if(10 * i + j < m) continue;
            ll now = n - j;
            if(now % i || now < 0) continue;
            ll b = now / i;
            if(b * i + j == n) result = max(result, now / i);
        }
    }
}

void solve3(){
    for(i128 i = 1;i <= 9;i++){
        for(i128 j = 0;j <= 9;j++){
            for(i128 k = 0;k <= 9;k++){
                if(100 * i + 10 * j + k < m) continue;
                i128 num = j * j - 4 * i * (k - (i128)n);
                if(num < 0) continue;
                
                _bs <i128> bs(1, num, num);
                i128 sq = bs.ret();
                if(sq * sq != num) continue;

                ll v = -j + sq;
                if(v % (2 * i)) continue;
                ll b = v / (2 * i);
                if(b * b * i + b * j + k == n) result = max(result, b);
            }
        }
    }
}

void run(){
    cin >> n >> m; 
    for(int i = 2;i <= 1010101;i++){
        if(!p(n, i)) continue;
        result = max<ll>(result, i);
    }

    if(m < 100) solve2();
    if(m < 1000) solve3();

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}