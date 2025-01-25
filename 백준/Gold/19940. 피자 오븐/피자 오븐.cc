#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define all(x) (x).begin(), (x).end()
#define x first 
#define y second
using namespace std; typedef long long ll;
using ld = long double; using pld = pair<ld, ld>;
using ull = unsigned long long; 
using pll = pair<ll, ll>; using tll = tuple<ll, ll, ll>;
ll n, m, k, t = 1; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 61; // SET MAX SIZE
constexpr ll MOD = 998244353;
vector <ll> dt = {-1, 1, -10, 10, 60};

class node{
public:
    ll a[5] = {};
    node() {}
    bool operator <=(const node& ot) const{
        int now = 0, nxt = 0;
        for(int i = 0;i < 5;i++) now += a[i], nxt += ot.a[i];
        if(now != nxt) return now < nxt;

        for(int i = 0;i < 5;i++){
            if(a[i] < ot.a[i]) return 1;
        }
        return 1;
    }
} cnt[MAX];
deque <pair<ll, node>> q;

node mx(){
    node ret; fill(ret.a, ret.a + 5, 100000000);
    return ret;
}

void bfs(){
    q.push_back({0, node()}); fill(cnt, cnt + MAX, mx());
    while(!q.empty()){
        auto[cur, cd] = q.front(); q.pop_front();
        if(cnt[cur].a[0] != 100000000) continue;
        cnt[cur] = cd;

        for(int i = 0;i < 5;i++){
            ll nxt = cur + dt[i];
            if(nxt < 0 || nxt >= MAX) continue;
            cd.a[i]++;
            q.push_back({nxt, cd});
            cd.a[i]--;
        }
    }
}

void run(){
    cin >> n; cout << cnt[n % 60].a[4] + (ll)(n / 60) << " ";
    for(int i = 3;i >= 0;i--) cout << cnt[n % 60].a[i] << " ";
    cout << "\n";
}

int main() {
    fastio; cin >> t; bfs();
    while(t--) run(); 

    return 0;
}

