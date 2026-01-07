# [Diamond V] Separate String - 15525 

[문제 링크](https://www.acmicpc.net/problem/15525) 

### 성능 요약

메모리: 46040 KB, 시간: 220 ms

### 분류

다이나믹 프로그래밍, 자료 구조, 문자열, 트리, 해싱, 트라이, 아호-코라식, 라빈–카프

### 제출 일자

2026년 1월 7일 15:50:04

### 문제 설명

<p>You are given a string <em>t</em> and a set <em>S</em> of <em>N</em> different strings. You need to separate <em>t</em> such that each part is included in <em>S</em>.</p>

<p>For example, the following 4 separation methods satisfy the condition when <em>t</em> = <code>abab</code> and <em>S</em> = {<code>a</code>, <code>ab</code>, <code>b</code>}.</p>

<ul>
	<li><code>a</code>, <code>b</code>, <code>a</code>, <code>b</code></li>
	<li><code>a</code>, <code>b</code>, <code>ab</code></li>
	<li><code>ab</code>, <code>a</code>, <code>b</code></li>
	<li><code>ab</code>, <code>ab</code></li>
</ul>

<p>Your task is to count the number of ways to separate t. Because the result can be large, you should output the remainder divided by 1,000,000,007.</p>

### 입력 

 <p>The input consists of a single test case formatted as follows.</p>

<pre>N
s<sub>1</sub>
.
.
.
s<sub>N</sub>
t</pre>

<p>The first line consists of an integer <em>N</em> (1 ≤ <em>N</em> ≤ 100,000) which is the number of the elements of <em>S</em>. The following <em>N</em> lines consist of <em>N</em> distinct strings separated by line breaks. The <em>i</em>-th string <em>s<sub>i</sub></em> represents the <em>i</em>-th element of <em>S</em>. <em>s<sub>i</sub></em> consists of lowercase letters and the length is between 1 and 100,000, inclusive. The summation of length of <em>s<sub>i</sub></em> (1 ≤ <em>i</em> ≤ <em>N</em>) is at most 200,000. The next line consists of a string <em>t</em> which consists of lowercase letters and represents the string to be separated and the length is between 1 and 100,000, inclusive.</p>

### 출력 

 <p>Calculate the number of ways to separate and print the remainder divided by 1,000,000,007.</p>

