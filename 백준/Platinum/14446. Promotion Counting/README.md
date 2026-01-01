# [Platinum II] Promotion Counting - 14446 

[문제 링크](https://www.acmicpc.net/problem/14446) 

### 성능 요약

메모리: 28084 KB, 시간: 116 ms

### 분류

자료 구조, 정렬, 트리, 세그먼트 트리, 오일러 경로 테크닉, 머지 소트 트리

### 제출 일자

2026년 1월 2일 00:42:59

### 문제 설명

<p> </p>

<p>The cows have once again tried to form a startup company, failing to remember from past experience that cows make terrible managers!</p>

<p>The cows, conveniently numbered 1…N (1 ≤ N ≤ 100,000), organize the company as a tree, with cow 1 as the president (the root of the tree). Each cow except the president has a single manager (its "parent" in the tree). Each cow i has a distinct proficiency rating, p(i), which describes how good she is at her job. If cow ii is an ancestor (e.g., a manager of a manager of a manager) of cow j, then we say j is a subordinate of i.</p>

<p>Unfortunately, the cows find that it is often the case that a manager has less proficiency than several of her subordinates, in which case the manager should consider promoting some of her subordinates. Your task is to help the cows figure out when this is happening. For each cow i in the company, please count the number of subordinates j where p(j)>p(i).</p>

<p> </p>

### 입력 

 <p>The first line of input contains N.</p>

<p>The next NN lines of input contain the proficiency ratings p(1)…p(N) for the cows. Each is a distinct integer in the range 1…1,000,000,000.</p>

<p>The next N−1 lines describe the manager (parent) for cows 2…N. Recall that cow 1 has no manager, being the president.</p>

<p> </p>

### 출력 

 <p>Please print N lines of output. The iith line of output should tell the number of subordinates of cow i with higher proficiency than cow i.</p>

