#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101010;
int a[MAX];

int binary_search(int x, int size){
    int lo = 0, hi = size - 1; // A의 크기가 size이므로 hi = size - 1
    int ret = -1; // A에 x가 존재하지 않을 경우 -1 반환

    while(lo <= hi){ // 시작점이 끝점보다 커지면 종료
        int mid = (hi + lo) / 2; // 중간값
        if(a[mid] == x){ // 현재 값이 탐색하고 있는 값이면
            ret = mid; break; // 정답은 mid, while문 종료
        }
        // 현재 값이 탐색하고 있는 값보다 크면 
        if(a[mid] > x) hi = mid - 1; // mid 이상의 인덱스에는 x가 없음
        else lo = mid + 1; // 아니면 mid 이하의 인덱스에는 x가 없음
    }
    
    return ret;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    for(int i = 0;i < n;i++) cin >> a[i];
    sort(a, a + n);

    int m; cin >> m;
    while(m--){
        int x; cin >> x;
        int ret = binary_search(x, n);
        if(ret == -1) cout << 0 << "\n";
        else cout << 1 << "\n";
    }
 
    return 0;
}

