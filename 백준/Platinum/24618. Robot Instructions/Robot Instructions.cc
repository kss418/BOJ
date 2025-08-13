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
using ull = unsigned ll;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 44; // SET MAX SIZE
constexpr ll MOD = 998244353;
pll a[MAX];
ll result[MAX];
ll sx1[1ll << 21], sx2[1ll << 21];
ll sy1[1ll << 21], sy2[1ll << 21];
ll cnt[1ll << 21];

class h{
public:
    ull operator() (const pll& p) const{
        ull a = hash<ll>{}(p.x);
        ull b = hash<ll>{}(p.y);
        return a * 239 + b;
    }
};
unordered_map <pll, array<ll, 21>, h> num;

void run(){
    ll x, y; cin >> n >> x >> y;
    for(int i = 0;i < n;i++) cin >> a[i].x >> a[i].y;

    for(int i = 1;i < (1ll << (n / 2));i++){
        ll pre = i & (i - 1);
        ll l = __builtin_ctz(i);
        sx1[i] = sx1[pre] + a[l].x;
        sy1[i] = sy1[pre] + a[l].y;
        cnt[i] = cnt[pre] + 1;

        num[{sx1[i], sy1[i]}][cnt[i]]++;
        if(sx1[i] == x && sy1[i] == y) result[cnt[i]]++;
    }

    for(int i = 1;i < (1ll << (n - (n / 2)));i++){
        ll pre = i & (i - 1);
        ll l = __builtin_ctz(i) + n / 2;
        sx2[i] = sx2[pre] + a[l].x;
        sy2[i] = sy2[pre] + a[l].y;
        cnt[i] = cnt[pre] + 1;

        ll nx = x - sx2[i], ny = y - sy2[i];
        if(sx2[i] == x && sy2[i] == y) result[cnt[i]]++;

        auto it = num.find({nx, ny});
        if(it == num.end()) continue;

        const auto& arr = it->y;
        for(int j = cnt[i] + 1;j <= n;j++){
            if(j - cnt[i] > 20) break;
            result[j] += arr[j - cnt[i]];
        }
    }

    for(int i = 1;i <= n;i++) cout << result[i] << "\n";
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}