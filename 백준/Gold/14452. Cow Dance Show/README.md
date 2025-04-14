# [Gold IV] Cow Dance Show - 14452 

[문제 링크](https://www.acmicpc.net/problem/14452) 

### 성능 요약

메모리: 3728 KB, 시간: 8 ms

### 분류

이분 탐색, 자료 구조, 매개 변수 탐색, 우선순위 큐

### 제출 일자

2025년 4월 14일 09:02:39

### 문제 설명

<p>After several months of rehearsal, the cows are just about ready to put on their annual dance performance; this year they are performing the famous bovine ballet "Cowpelia".</p>

<p>The only aspect of the show that remains to be determined is the size of the stage. A stage of size K can support K cows dancing simultaneously. The N cows in the herd (1 ≤ N ≤ 10,000) are conveniently numbered 1…N in the order in which they must appear in the dance. Each cow i plans to dance for a specific duration of time d(i). Initially, cows 1…K appear on stage and start dancing. When the first of these cows completes her part, she leaves the stage and cow K+1 immediately starts dancing, and so on, so there are always K cows dancing (until the end of the show, when we start to run out of cows). The show ends when the last cow completes her dancing part, at time T.</p>

<p>Clearly, the larger the value of K, the smaller the value of T. Since the show cannot last too long, you are given as input an upper bound T<sub>max</sub> specifying the largest possible value of T. Subject to this constraint, please determine the smallest possible value of K.</p>

### 입력 

 <p>The first line of input contains N and T<sub>max</sub>, where T<sub>max</sub> is an integer of value at most 1 million.</p>

<p>The next N lines give the durations d(1)…d(N) of the dancing parts for cows 1…N. Each d(i) value is an integer in the range 1…100,000.</p>

<p>It is guaranteed that if K=N, the show will finish in time.</p>

<p> </p>

### 출력 

 <p>Print out the smallest possible value of K such that the dance performance will take no more than T<sub>max</sub> units of time.</p>

