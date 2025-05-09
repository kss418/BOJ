# [Gold III] Milk Scheduling - 9869 

[문제 링크](https://www.acmicpc.net/problem/9869) 

### 성능 요약

메모리: 5300 KB, 시간: 0 ms

### 분류

자료 구조, 그리디 알고리즘, 우선순위 큐, 정렬

### 제출 일자

2025년 5월 9일 13:47:47

### 문제 설명

<p>Farmer John has N cows that need to be milked (1 <= N <= 10,000), each of which takes only one unit of time to milk.</p><p>Being impatient animals, some cows will refuse to be milked if Farmer John waits too long to milk them.  More specifically, cow i produces g_i gallons of milk (1 <= g_i <= 1000), but only if she is milked before a deadline at time d_i (1 <= d_i <= 10,000).  Time starts at t=0, so at most x total cows can be milked prior to a deadline at time t=x.</p><p>Please help Farmer John determine the maximum amount of milk that he can obtain if he milks the cows optimally.</p>

### 입력 

 <ul><li>Line 1: The value of N.</li><li>Lines 2..1+N: Line i+1 contains the integers g_i and d_i.</li></ul>

### 출력 

 <ul><li>Line 1: The maximum number of gallons of milk Farmer John can obtain.</li></ul>

