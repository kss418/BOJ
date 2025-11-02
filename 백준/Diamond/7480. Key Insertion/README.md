# [Diamond V] Key Insertion - 7480 

[문제 링크](https://www.acmicpc.net/problem/7480) 

### 성능 요약

메모리: 14604 KB, 시간: 172 ms

### 분류

자료 구조, 로프, 스플레이 트리, 문자열, 트리

### 제출 일자

2025년 11월 2일 19:13:39

### 문제 설명

<p>As an employee of the Macrohard Company, you have been asked to implement the new data structure that would be used to store some integer keys.</p>

<p>The keys must be stored in a special ordered collection that can be considered as an array <em>A</em>, which has an infinite number of locations, numbered starting from 1. Initially all locations are empty. The following operation must be supported by the collection: Insert(L, K), where L is the location in the array and K is some positive integer value.</p>

<p>The operation must be processed as follows:</p>

<ul>
	<li>If A[L] is empty, set A[L] ← K.</li>
	<li>If A[L] is not empty, perform Insert(L + 1, A[L]) and after that set A[L] ← K.</li>
</ul>

<p>Given N integer numbers L<sub>1</sub>, L<sub>2</sub>, ... , L<sub>N</sub> you have to output the contents of the array after a sequence of the following operations: Insert(L<sub>1</sub>, 1), Insert(L<sub>2</sub>, 2), ... , Insert(L<sub>N</sub>, N)</p>

### 입력 

 <p>The first line of the input file contains N — the number of Insert operations and M — the maximal position that can be used in the Insert operation (1 ≤ N ≤ 131 072, 1 ≤ M ≤ 131 072). Next line contains N integer numbers Li that describe Insert operations to be performed (1 ≤ L<sub>i</sub> ≤ M).</p>

### 출력 

 <p>Output the contents of the array after a given sequence of Insert operations. On the first line print W — the number of the greatest location that is not empty. After that output W integer numbers - A[1], A[2], ... , A[W]. Output zeroes for empty locations.</p>

