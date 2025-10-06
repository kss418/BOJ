# [Gold II] Word Squared - 18548 

[문제 링크](https://www.acmicpc.net/problem/18548) 

### 성능 요약

메모리: 2164 KB, 시간: 68 ms

### 분류

해 구성하기

### 제출 일자

2025년 10월 6일 22:44:34

### 문제 설명

<p>Given a permutation of numbers from 1 to n, find a square matrix conforming to the following rules:</p>

<ol>
	<li>The matrix should include only numbers from the permutation;</li>
	<li>The given permutation should occur in every row of the matrix as a contiguous subsequence, read from left to right;</li>
	<li>The given permutation should occur in every column of the matrix as a contiguous subsequence, read from top to bottom;</li>
	<li>The matrix size is the smallest possible.</li>
</ol>

### 입력 

 <p>The first line of input is a positive integer n ≤ 500.</p>

<p>The second line of input consists of n space-separated integers: the permutation itself.</p>

### 출력 

 <p>The first line of output should be an integer m: the size of the matrix. The next m lines should list m consecutive rows of the matrix. Each of these lines should contain m integers separated by spaces: the values in the corresponding row.</p>

<p>The size m should be minimum possible. If there are several possible answers, print any one of them.</p>

