# [Platinum I] Distance - 8222 

[문제 링크](https://www.acmicpc.net/problem/8222) 

### 성능 요약

메모리: 83224 KB, 시간: 324 ms

### 분류

수학, 정수론

### 제출 일자

2025년 12월 22일 15:54:46

### 문제 설명

<p>We consider the distance between positive integers in this problem, defined as follows. A single operation consists in either multiplying a given number by a prime number1 or dividing it by a prime number (if it does divide without a remainder). The distance between the numbers a and b, denoted d(a,b), is the minimum number of operations it takes to transform the number a into the number b. For example, d(69,42)=3.</p>

<p>Observe that the function d is indeed a distance function - for any positive integers a,b,  and c the following hold:</p>

<ul>
	<li>the distance between a number and itself is 0: d(a,a)=0,</li>
	<li>the distance from a to b is the same as from b to a: d(a,b), and</li>
	<li>the triangle inequality holds: d(a,b)+d(b,c) ≥ d(a,c).</li>
</ul>

<p>A sequence of n positive integers, a<sub>1</sub>,a<sub>2</sub>,…,a<sub>n</sub>, is given. For each number a<sub>i</sub> we have to determine j such that j≠i and d(a<sub>i</sub>,a<sub>j</sub>) is minimal.</p>

### 입력 

 <p>In the first line of standard input there is a single integer n (2 ≤ n ≤ 100,000). In the following n lines the numbers ai,a2,…,an (1 ≤ ai ≤ 1,000,000) are given, one per line.</p>

<p> </p>

### 출력 

 <p>Your program should print exactly n lines to the standard output, a single integer in each line. The i-th line should give the minimum j such that: 1 ≤ j ≤ n, j≠i and d(a<sub>i</sub>,a<sub>j</sub>)n is minimal.</p>

<p> </p>

