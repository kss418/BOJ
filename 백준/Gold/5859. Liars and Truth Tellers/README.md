# [Gold II] Liars and Truth Tellers - 5859 

[문제 링크](https://www.acmicpc.net/problem/5859) 

### 성능 요약

메모리: 2396 KB, 시간: 4 ms

### 분류

그래프 이론, 자료 구조, 분리 집합

### 제출 일자

2025년 5월 15일 12:47:38

### 문제 설명

<p>After spending so much time around his cows, Farmer John has started to understand their language.  Moreover, he notices that among his N cows (2 <= N <= 1000), some always tell the truth while others always lie.</p>

<p>FJ carefully listens to M statements (1 <= M <= 10,000) from his cows, each of the form "x y T", meaning that "cow x claims cow y always tells the truth" or "x y L", meaning that "cow x claims cow y always tells lies". Each statement involves a pair of different cows, and the same pair of cows may appear in multiple statements.  </p>

<p>Unfortunately, FJ believes he might have written down some entries in his list incorrectly, so there may not be a valid way to designate each cow as a truth teller or a liar that is consistent with all the M statements on FJ's list.  To help FJ salvage as much of his list as possible, please compute the largest value of A such that there exists a valid way to designate each cow as a truth teller or a liar in a manner that is consistent with the first A entries in FJ's list.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers, N and M.</li>
	<li>Lines 2..1+M: Each line is of the form "x y L" or "x y T", describing a statement made by cow x about cow y.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The maximum value of A such that the first A entries in FJ's list can be consistent with some assignment of "truth teller" or "liar" to the N cows.</li>
</ul>

