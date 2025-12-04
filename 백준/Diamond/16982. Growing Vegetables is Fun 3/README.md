# [Diamond V] Growing Vegetables is Fun 3 - 16982 

[문제 링크](https://www.acmicpc.net/problem/16982) 

### 성능 요약

메모리: 8848 KB, 시간: 8 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 12월 4일 15:02:56

### 문제 설명

<p>JOI-kun, an expert of home garden, grows vegetables of Joy grass in his home garden. In his garden, there are N flowerpots aligned in the east-west direction. These flowerpots are numbered by 1, . . . , N from the west end. There are N Joy grasses. In each flowerpot, there is one Joy grass planted.</p>

<p>In the spring, JOI-kun noticed that, against his expectations, Joy grasses had yielded leaves of various colors. Additionally, he discovered that Joy grasses had not grown as much as expected. He looked up books, and found the following facts:</p>

<ul>
	<li>There are 3 kinds of Joy grasses, yielding red, green, or yellow leaves.</li>
	<li>If Joy grasses with the same leaf color are closely placed, their growth is prevented.</li>
</ul>

<p>Therefore, JOI-kun decided to rearrange flowerpots so that no Joy grasses with the same leaf color adjoin Flowerpots are so heavy that JOI-kun can only swap two Joy grasses in neighboring flowerpots in a single operation. In other words, what JOI-kun can do in a single operation is choosing an arbitrary flowerpot i (1 ≤ i ≤ N −1) and then swapping Joy grasses in flowerpots i and i + 1.</p>

<p>Write a program which, given the number of Joy grasses and the colors of them, calculates the minimum number of operations which are required to rearrange Joy grasses so that no Joy grasses with the same leaf color adjoin.</p>

### 입력 

 <p>Read the following data from the standard input.</p>

<pre>N
S</pre>

<p>S is a string of length N. Its i-th (1 ≤ i ≤ N) character is <code>R</code>, <code>G</code>, and <code>Y</code> if the leaf color of the Joy grass in flowerpot i is red, green, and yellow, respectively.</p>

### 출력 

 <p>Write a line containing the minimum number of required operations to the standard output. If it is impossible to rearrange Joy grasses so that no Joy grasses with the same leaf color adjoin, write −1 instead.</p>

