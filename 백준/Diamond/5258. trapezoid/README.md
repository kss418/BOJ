# [Diamond V] trapezoid - 5258 

[문제 링크](https://www.acmicpc.net/problem/5258) 

### 성능 요약

메모리: 55736 KB, 시간: 428 ms

### 분류

값 / 좌표 압축, 자료 구조, 다이나믹 프로그래밍, 가장 긴 증가하는 부분 수열 문제, 세그먼트 트리, 스위핑

### 제출 일자

2025년 7월 1일 17:12:36

### 문제 설명

<p>Consider two arbitrarily chosen horizontal lines. A trapezoid T<sub>i</sub> between these lines has two vertices situated on the upper line and the other two vertices on the lower line (see figure below). We will denote by a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub> and d<sub>i</sub> the upper left, upper right, lower left and respectively lower right vertices of the trapezoid T<sub>i</sub>. A subset S of trapezoids is called independent if no two trapezoids from S intersect.</p>

<p>Determine the cardinality of the largest independent set of trapezoids (the largest set means the set with most elements). Also find the count of different independent sets with maximum cardinality. Find this count modulo 30013.</p>

### 입력 

 <p>The first line of input contains one integer N – the number of trapezoids. Each of the next N lines contains four integers a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub> and d<sub>i</sub>. No two trapezoids have a common vertex (corner).</p>

### 출력 

 <p>The only line of output should contain two numbers separated by space: firstly, the cardinality of the largest independent set; secondly, the count of different independent sets with maximum cardinality modulo 30013.</p>

