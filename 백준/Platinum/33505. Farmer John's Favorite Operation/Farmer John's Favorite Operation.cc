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
ll f[MAX];
priority_queue <pll, vector <pll>, greater<pll>> pq;

void run(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    while(!pq.empty()) pq.pop();

    ll now = 0, diff = 0, pre = 0;
    for(int i = 1;i <= n;i++){
        f[i] = 0;
        ll l = a[i] % m, r = (m - a[i] % m + m) % m;
        if(l < r){
            now += l;
            diff--, pq.push({l, i});
        }
        else if(r < l){
            f[i] = 1;
            now += r;
            diff++; pq.push({m / 2 - r, i});
        }
        else{
            if(l == 0) diff++, pq.push({m / 2, i}), f[i] = 1;
            else if(m % 2){
                if((a[i] % m) % 2){
                    f[i] = 1; diff++;
                    pq.push({m / 2, i});
                }
                else{
                    f[i] = 2;
                    pq.push({1, i});
                }
            }
            else diff--, pq.push({m / 2, i}), f[i] = 0;

            now += l;
        }
    }

    result = now;
    while(!pq.empty()){
        auto [cur, idx] = pq.top(); pq.pop();
        if(cur >= m) break;
        now += diff * (cur - pre);
        pre = cur;

        if(m % 2){
            if(!f[idx]){
                f[idx] = 1, diff += 2;
                pq.push({cur + m / 2, idx});
            }
            else if(f[idx] == 1){
                f[idx] = 2, diff--;
                pq.push({cur + 1, idx});
            }
            else{
                f[idx] = 0, diff--;
                pq.push({cur + m / 2, idx});
            }
        }
        else{
            if(!f[idx]) f[idx] = 1, diff += 2;
            else f[idx] = 0, diff -= 2;
            pq.push({cur + m / 2, idx});
        }

        result = min(result, now);
    }

    cout << result << "\n";
}

int main() {
    fastio; cin >> t;
    while(t--) run();
    
    return 0;
}