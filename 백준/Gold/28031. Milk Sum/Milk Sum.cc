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
vector <pll> a;
ll sum[MAX], num[MAX], all;

bool cmp1(const pll& a, const pll& b){
    return a.first < b.first;
}

void run(){
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> num[i];
        a.push_back({num[i], i});
    }
    sort(all(a));

    for(int i = 1;i <= n;i++) {
        sum[i] = sum[i - 1] + a[i - 1].x;
        all += a[i - 1].x * i;
    }

    cin >> m;
    while(m--){
        ll idx, v, diff; cin >> idx >> v;
        auto org = lower_bound(all(a), make_pair(num[idx], 0), cmp1) - a.begin();
        if(num[idx] >= v){
            auto lb = upper_bound(all(a), make_pair(v, 0), cmp1) - a.begin();
            diff = sum[org] - sum[lb] - num[idx] * (org + 1) + v * (lb + 1);
        }
        else{
            auto lb = upper_bound(all(a), make_pair(v, 0), cmp1) - a.begin() - 1;
            diff = -(sum[lb + 1] - sum[org + 1]) + v * (lb + 1) - num[idx] * (org + 1); 
        }

        cout << all + diff << "\n"; 
    }
}

int main() {
    fastio; // cin >> t;
    while(t--) run(); 

    return 0;
}

