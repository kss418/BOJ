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
ll a[MAX], cnt[MAX];
multiset <ll> num;
multiset <pll> ms;
deque <ll> tmp;

void run(){
    cin >> n >> m >> k; 
    ms.clear(); tmp.clear(); num.clear();
    for(int i = 1;i <= n;i++) cnt[i] = 0;
    for(int i = 1;i <= m;i++) cin >> a[i], cnt[a[i]]++;

    ll now = 1;
    for(int i = 1;i <= m;i++){
        while(ms.size() > k - 1){
            auto lb = num.begin();
            tmp.push_back(*lb);
            ms.erase(ms.find({a[*lb], *lb}));
            num.erase(lb);
        }

        if(a[i] < now + k) cnt[a[i]]--;
        else{
            num.insert(i);
            ms.insert({a[i], i});
        }

        while(!cnt[now] && now < n) now++;

        while(!ms.empty()){
            auto lb = ms.lower_bound({now, 0});
            if(lb == ms.end()) break;

            if(lb->x < now + k) cnt[lb->x]--;
            else break;

            while(!cnt[now] && now < n) now++;
            num.erase(num.find(lb->y)); ms.erase(lb); 
        }
    }

    while(!ms.empty()){
        auto lb = ms.begin();
        tmp.push_back(lb->y);
        ms.erase(lb);
    }
    sort(all(tmp)); 

    while(1){
        while(!cnt[now] && now < n) now++;
        while(!tmp.empty() && ms.size() < k){
            ll idx = tmp.back(); tmp.pop_back();
            ms.insert({a[idx], idx});
        }

        auto lb = ms.lower_bound({now, 0});
        if(lb == ms.end() || lb->x >= now + k) break;
        cnt[lb->x]--; ms.erase(lb);
    }

    cout << (!ms.empty() || !tmp.empty() ? "NO" : "YES") << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}