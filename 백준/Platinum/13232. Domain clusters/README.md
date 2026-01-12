# [Platinum V] Domain clusters - 13232 

[문제 링크](https://www.acmicpc.net/problem/13232) 

### 성능 요약

메모리: 4152 KB, 시간: 20 ms

### 분류

그래프 이론, 강한 연결 요소

### 제출 일자

2026년 1월 12일 16:01:41

### 문제 설명

<p>We are analyzing how the domains on the Internet connect to each other. A domain is the part of a URL that comes before the / character. Examples of domains are: twitter.com, aipo.computing.dcu.ieor google.com. A domain d1 is connected to a domain d2 if there is a link from d1 to d2 or if d1 is connected to a domain d3 and d3 is connected to d2. We consider that a domain is connected to itself. In the following structure of domains:</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13232/1.png" style="height:218px; width:365px"></p>

<ul>
	<li>D1 is connected to D2, D3 (through D2), D4 and D5 (through D3).</li>
	<li>D2 is connected to D3, D4 (through D3) and D5 (through D3).</li>
	<li>D3 is connected to D2, D4 and D5.</li>
	<li>D4 is not connected to any other domain.</li>
	<li>D5 is connected to D2, D3 (through D2) and D4 (through D3).</li>
</ul>

<p>We want to obtain the biggest subset of domains S where each domain in S is connected to all the other domains in S. In the example above we have the following subsets that meet this criteria:</p>

<ul>
	<li>D1: Connected to itself.</li>
	<li>D2, D3, D5: We can arrive from D2 to D3 and D5, from D3 to D2 and D5 and from D5 to D2 and D3.</li>
	<li>D4: Connected to itself.</li>
</ul>

<p>Please, given the links of the Internet, compute the size of the biggest subset.</p>

### 입력 

 <p>The first line will contain an integer D representing the number of domains. The names of the domains will be integers from 1 to D. (1 ≤ D ≤ 5000)</p>

<p>The second line will contain an integer L representing the number of links between domains. The following L lines will contain two integers each. The first integer is the source of the link and the second is the destination. Remember that a link from A to B does not imply a link from B to A and that every domain is connected to itself without the need of an explicit link. No link will appear more than once. (0 ≤ L ≤ D<sup>2</sup>)</p>

### 출력 

 <p>The size of the biggest subset of domains that meet the criteria above. If two or more subsets are tied for the biggest size, print the size of any of them.</p>

