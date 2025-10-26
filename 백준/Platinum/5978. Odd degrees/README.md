# [Platinum II] Odd degrees - 5978 

[문제 링크](https://www.acmicpc.net/problem/5978) 

### 성능 요약

메모리: 10696 KB, 시간: 48 ms

### 분류

그래프 이론, 그래프 탐색, 트리, 깊이 우선 탐색, 홀짝성

### 제출 일자

2025년 10월 26일 14:16:03

### 문제 설명

<p>The cows are being invaded! Their republic comprises N (1 <= N <= 50,000) towns that are connected by M (1 <= M <= 100,000) undirected paths between two towns A_i and B_i (1 <= A_i <= N; 1 <= B_i <= N; A_i != B_i; no duplicate paths will occur). However the republic is not necessarily connected--there may be pairs of towns that are unable to reach each other through the paths.</p>

<p>The cows know their invaders plan to conduct an inventory of every path within their republic, so they are willing to shut down various paths to make it as difficult as possible for their invaders to do so.</p>

<p>Please help the cows find a way to shut down a subset of the paths such that each town has an odd number of remaining paths connected to it, or determine if no such subset exists.</p>

<p>For example, consider the following cow republic:</p>

<pre>1---2
 \ /
  3---4</pre>

<p>If we keep the paths 1-3, 2-3, and 3-4, and remove the path 1-2, then towns 1, 2, and 4 will be an endpoint of exactly one path, whereas town 3 will be an endpoint of three paths:</p>

<pre>1   2
 \ /
  3---4</pre>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and M</li>
	<li>Lines 2..M+1: Line i+1 contains two space-separated integers: A_i and B_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer that is the number of paths to keep. If no subset exists output only a single line with the integer -1.</li>
	<li>Lines 2..K+1: Each line contains an index of an path to keep, in the range 1..M. These indices must be pairwise distinct.</li>
</ul>

<p> </p>

