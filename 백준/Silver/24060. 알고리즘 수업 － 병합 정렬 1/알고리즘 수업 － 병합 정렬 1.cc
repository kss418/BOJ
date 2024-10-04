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
constexpr ll MAX = 101010101;
constexpr ll MOD = 998244353;
int cnt[MAX], seq = 1;
ll arr[501010], tmp[501010];


void merge(ll st, ll en){
    ll l = st;
    ll mid = (st + en) >> 1;
    ll r = mid + 1;
    ll cur = st;

    while(l <= mid && r <= en){
        if(arr[l] <= arr[r]) tmp[cur++] = arr[l++];     
        else tmp[cur++] = arr[r++];
    }

    while(l <= mid) tmp[cur++] = arr[l++];
    while(r <= en) tmp[cur++] = arr[r++];
    
    for(int i = st;i <= en;i++) {
        cnt[seq++] = tmp[i];
        arr[i] = tmp[i];
    }
}

void merge_sort(ll l, ll r){
    if(l >= r) return;
    ll mid = (l + r) >> 1;
    merge_sort(l, mid); merge_sort(mid + 1, r);
    merge(l, r);
}

int main() {
    fastio;

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> arr[i];
    
    merge_sort(1, n);
    if(!cnt[m]) cout << -1;
    else cout << cnt[m];


    return 0;
}