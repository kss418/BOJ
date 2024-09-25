#include <bits/stdc++.h>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ull = unsigned long long;
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MAX = 101;
constexpr ll MOD = 998244353;
class node{
public:
    bool operator<(node &ot){
        return a < ot.a;
    }
    ll a, h, w, n;
};
node arr[MAX];
ll track[MAX], dp[MAX];

int main() {
    fastio;

    cin >> n;
    for(int i = 1;i <= n;i++){
        ll a, h, w;
        cin >> a >> h >> w;
        arr[i] = {a,h,w,i};
    }
    sort(arr + 1, arr + n + 1);
    reverse(arr + 1, arr + n + 1);

    arr[0] = {INF, 0, INF, 0};
    for(int i = 1;i <= n;i++){
        auto& [ca, ch, cw, cn] = arr[i];
        for(int j = 0;j < i;j++){
            auto& [pa,ph,pw,pn] = arr[j];
            if(pw < cw) continue;
            if(dp[i] >= dp[j] + ch) continue;
            dp[i] = dp[j] + ch; track[i] = j;
        }
    }
    
    ll mx = 0, mxd = 0;
    for(int i = 1;i <= n;i++){
        if(mx >= dp[i]) continue;
        mx = dp[i]; mxd = i;
    }

    deque <ll> result;
    ll cur = mxd;
    while(mxd){
        result.push_back(arr[mxd].n);
        mxd = track[mxd];
    }

    cout << result.size() << "\n";
    for(auto& i: result) cout << i << "\n";


    return 0;
}