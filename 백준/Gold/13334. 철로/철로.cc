#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

const ll MAX = 101010;
ll n, d, result;
pair <ll, ll> a[MAX];
priority_queue <ll, vector<ll>, greater<ll>> pq;

int main(){
    ios::sync_with_stdio(0); // fastio
    cin.tie(0), cout.tie(0); // fastio

    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i].first >> a[i].second;
        if(a[i].second > a[i].first) swap(a[i].first, a[i].second);
    }

    cin >> d;
    sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++){
        pq.push(a[i].second);
        while(!pq.empty() && pq.top() < a[i].first - d) pq.pop();
        result = max<ll>(result, pq.size());
    }

    cout << result;
    return 0;
}

