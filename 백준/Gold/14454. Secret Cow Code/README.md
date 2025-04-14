# [Gold IV] Secret Cow Code - 14454 

[문제 링크](https://www.acmicpc.net/problem/14454) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

재귀

### 제출 일자

2025년 4월 14일 11:41:46

### 문제 설명

<p> </p>

<p>The cows are experimenting with secret codes, and have devised a method for creating an infinite-length string to be used as part of one of their codes.</p>

<p>Given a string s, let F(s) be s followed by s "rotated" one character to the right (in a right rotation, the last character of s rotates around and becomes the new first character). Given an initial string s, the cows build their infinite-length code string by repeatedly applying F; each step therefore doubles the length of the current string.</p>

<p>Given the initial string and an index N, please help the cows compute the character at the Nth position within the infinite code string.</p>

<p> </p>

### 입력 

 <p>The input consists of a single line containing a string followed by N. The string consists of at most 30 uppercase characters, and N ≤ 10<sup>18</sup>.</p>

<p>Note that N may be too large to fit into a standard 32-bit integer, so you may want to use a 64-bit integer type (e.g., a "long long" in C/C++).</p>

### 출력 

 <p>Please output the Nth character of the infinite code built from the initial string. The first character is N=1.</p>

