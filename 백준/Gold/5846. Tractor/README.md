# [Gold I] Tractor - 5846 

[문제 링크](https://www.acmicpc.net/problem/5846) 

### 성능 요약

메모리: 44924 KB, 시간: 144 ms

### 분류

그래프 이론, 자료 구조, 그래프 탐색, 이분 탐색, 분리 집합

### 제출 일자

2025년 5월 14일 10:10:43

### 문제 설명

<p>One of Farmer John's fields is particularly hilly, and he wants to purchase a new tractor to drive around on it.  The field is described by an N x N grid of non-negative integer elevations (1 <= N <= 500).  A tractor capable of moving from one grid cell to an adjacent cell (one step north, east, south, or west) of height difference D costs exactly D units of money.</p><p>FJ would like to pay enough for his tractor so that, starting from some grid cell in his field, he can successfully drive the tractor around to visit at least half the grid cells in the field (if the number of total cells in the field is odd, he wants to visit at least half the cells rounded up).  Please help him compute the minimum cost necessary for buying a tractor capable of this task.</p>

### 입력 

 <ul><li>Line 1: The value of N.</li><li>Lines 2..1+N: Each line contains N space-separated non-negative integers (each at most 1 million) specifying a row of FJ's field.</li></ul>

### 출력 

 <ul><li>Line 1: The minimum cost of a tractor that is capable of driving around at least half of FJ's field.</li></ul>

