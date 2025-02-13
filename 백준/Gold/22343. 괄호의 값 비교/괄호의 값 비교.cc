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
constexpr ll MAX = 3010101; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll num[MAX], cnt[MAX][2];

void cal(string& s, ll idx){
    ll now = 0;
    for(auto& i : s){
        if(i == '(') now++;
        else{
            if(!num[now]) cnt[now][idx]++;
            num[now - 1]++;
            num[now] = 0; now--;
        }
    }

    for(int i = 0;i < MAX;i++){
        if(!cnt[i][idx]) continue;
        cnt[i + 1][idx] += cnt[i][idx] / 2;
        cnt[i][idx] %= 2;
    }
}

void cmp(){
    for(int i = MAX - 1;i >= 0;i--){
        if(cnt[i][0] == cnt[i][1]) continue;
        if(cnt[i][0]) cout << ">\n";
        else cout << "<\n";
        return;
    }
    cout << "=\n";
}

void run(){
    string a, b; cin >> a >> b;
    memset(cnt, 0, sizeof(cnt));
    cal(a, 0); cal(b, 1); cmp();
}

int main() {
    fastio; cin >> t;
    while(t--) run(); 

    return 0;
}

