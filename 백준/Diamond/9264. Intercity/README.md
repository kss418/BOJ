# [Diamond V] Intercity - 9264 

[문제 링크](https://www.acmicpc.net/problem/9264) 

### 성능 요약

메모리: 123436 KB, 시간: 1280 ms

### 분류

그래프 이론, 그래프 탐색, 이분 탐색, 너비 우선 탐색

### 제출 일자

2025년 6월 27일 23:45:17

### 문제 설명

<p>A couple of years ago the Ukrainian Railway System seemed to be very convenient. For any two cities there was a direct train (don't be confused with "directed"), which travelled between them. Anyone had to pay only B UAH (the local currency) to get from his current place to the desired destination. </p>

<p>But not long ago great changes happened in Ukraine. A lot of new trains have been launched. Each of the new trains replaced an old one and the cost of its journey has been established to A UAH. So there is a single direct train (new or old) which still runs between any pair of cities now. Each train runs in both directions and the cost of the journey doesn’t depend on it.</p>

<p>There are N large cities in Ukraine and you live in the city number 1. You want to get to the city number N, and you look for the cheapest way of going there, regardless of the number of transfers.</p>

### 입력 

 <p>The first line contains four integers N, K, A and B (2 ≤ N ≤ 500000, 0 ≤ K ≤ 500000, 1 ≤ A, B ≤ 500000), which are the number of cities, the number of new trains, the new cost of the journey and the old cost of the journey. K lines follow. Each of them contains two integers u<sub>i</sub> and v<sub>i</sub> (1 ≤ u<sub>i</sub>, v<sub>i</sub> ≤ N) which means that a new train is launched between city u<sub>i</sub> and city v<sub>i</sub>. u<sub>i</sub> and v<sub>i</sub> don't coincide. Every pair of cities appears at most once.</p>

### 출력 

 <p>Single integer P which is the cost of the cheapest way to go from city 1 to city N.</p>

