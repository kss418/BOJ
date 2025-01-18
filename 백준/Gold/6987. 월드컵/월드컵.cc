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
ll n, m, k, t = 4; string s;

constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr ll MINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll MAX = 6; // SET MAX SIZE
constexpr ll MOD = 998244353;
ll w[MAX], l[MAX], d[MAX], result;
vector <ll> arr;

void bt(){
    if(result) return; ll cur = arr.size();
    if(cur == 15){ 
        for(int i = 0;i < 6;i++){
            if(w[i] || d[i] || l[i]) return;
        }
        result = 1; return; 
    }

     ll cnt = 0, sum = 0;
    while(sum <= cur) sum += 5 - cnt, cnt++;
    cnt--; sum -= 5 - cnt;
    ll a = cnt, b = cur - sum + cnt + 1;

    for(int i = 0;i < 3;i++){
        if(!i) w[a]--, l[b]--;
        else if(i == 1) d[a]--, d[b]--;
        else l[a]--, w[b]--;

        arr.push_back(i);
        if(w[a] >= 0 && d[a] >= 0 && l[a] >= 0){
            if(w[b] >= 0 && d[b] >= 0 && l[b] >= 0) bt();
        }
        arr.pop_back();

        if(!i) w[a]++, l[b]++;
        else if(i == 1) d[a]++, d[b]++;
        else l[a]++, w[b]++;
    }
}

void run(){
    for(int i = 0;i < 6;i++) cin >> w[i] >> d[i] >> l[i];
    arr.clear(); result = 0; bt();
    cout << result << " ";
}

int main() {
    fastio; // cin >> t;
    while(t--) run();
    
    return 0;
}