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
constexpr ll MAX = 201010; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll num[MAX], ind[MAX], result;
map <ll, ll> cnt; map <ll, bool> v;
deque <ll> q;

bool chk(ll a, ll b){
    if(b % 2) return 1;
    b >>= 1ll;
    return a != b;
}

void run(){
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++){
        ll v; cin >> v >> num[i];
        cnt[num[i]] = v;
    }

    for(int i = 1;i <= n;i++){
        if(cnt.count(m - num[i])) ind[i]++;
        if(m != k && cnt.count(k - num[i])) ind[i]++;

        if(ind[i] == 1) q.push_back(num[i]);
    }

    while(!q.empty()){
        ll cur = q.front(); q.pop_front();
        if(v[cur]) continue; v[cur] = 1;

        if(chk(cur, m) && cnt.count(m - cur)){
            ll mn = min(cnt[m - cur], cnt[cur]);
            cnt[m - cur] -= mn;
            cnt[cur] -= mn;
            result += mn;

            if(chk(cur, k)) q.push_back(m - cur);
        }

        if(m != k && chk(cur, k) && cnt.count(k - cur)){
            ll mn = min(cnt[k - cur], cnt[cur]);
            cnt[k - cur] -= mn;
            cnt[cur] -= mn;
            result += mn;

            if(chk(cur, m)) q.push_back(k - cur);
        }
    }

    for(int i = 1;i <= n;i++){
        if(num[i] * 2 != m && num[i] * 2 != k) continue;
        result += cnt[num[i]] / 2;
    }

    cout << result;
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}