# [Platinum V] Parcel - 8017 

[문제 링크](https://www.acmicpc.net/problem/8017) 

### 성능 요약

메모리: 65292 KB, 시간: 520 ms

### 분류

자료 구조, 분리 집합, 스택

### 제출 일자

2025년 7월 1일 17:32:18

### 문제 설명

<p>We are given a square-shaped field. The field has a side of length n and it is divided into n^2 squares of side 1. Each square is either arable or waste land. We delimit a parcel in the field. The parcel ought to be a rectangle and to consist of only arable squares. The area of the parcel is equal to the area of the corresponding rectangle. We seek for a parcel of the largest area.</p>

<p>Write a program which:</p>

<ul>
	<li>reads from the standard input the description of the field,</li>
	<li>computes the area of the largest parcel (there may be more than one such a parcel),</li>
	<li>writes to the standard output the computed area.</li>
</ul>

### 입력 

 <p>In the first line of the standard input there is one integer n, 1 ≤ n ≤ 2,000. In the successive n lines there are descriptions of squares that compose successive rows of the field. Each of those lines comprises n numbers 0 or 1, separated by single spaces. The numbers describe successive squares in the row: 0 denotes an arable square and 1 denotes a waste square.</p>

### 출력 

 <p>Your program should write one integer in the first and only line of the standard output. The number should be the area of the largest parcel. If all the squares are waste and there is no parcel, your program should give the answer 0.</p>

