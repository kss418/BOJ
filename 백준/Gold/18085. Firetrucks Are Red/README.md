# [Gold III] Firetrucks Are Red - 18085 

[문제 링크](https://www.acmicpc.net/problem/18085) 

### 성능 요약

메모리: 48524 KB, 시간: 208 ms

### 분류

자료 구조, 분리 집합, 그래프 이론, 최소 스패닝 트리

### 제출 일자

2024년 10월 17일 17:41:14

### 문제 설명

<p>Lily is fascinated by numbers. She believes the whole world revolves around them, and that everything is connected by numbers. Her friends, Alice, Bob, Charlie and Diane, are not convinced. But she gives them an example:</p>

<blockquote>
<p>Alice lives in house number 25 on her street, but that is exactly Bob’s age. Bob is born on June 4th, and Charlie was his parents’ fourth child. Finally, Diane has five fingers on her left hand, which happens to be the same as the number of toes that Bob has on his right foot!</p>
</blockquote>

<p>This shows that her friends are all connected—either directly or indirectly—by numbers. But she still has to convince her family as well as her coworkers.</p>

<p>Given a group of n individuals, and a set of numbers that describe each individual, help Lily come up with a proof that shows that everyone in this group is either directly or indirectly connected by numbers, or determine that this is not possible.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer n (2 ≤ n ≤ 2 · 10<sup>5</sup>), the number of individuals in the group. The individuals are numbered from 1 to n.</li>
	<li>n lines, describing the individuals in the group. The ith such line starts with an integer m<sub>i</sub> (1 ≤ m<sub>i</sub> ≤ 2 · 10<sup>5</sup>), the number of numbers that describe individual i. The remainder of the line has m<sub>i</sub> distinct integers d<sub>i,1</sub>, . . . , d<sub>i,m<sub>i</sub></sub> (1 ≤ d<sub>i,j</sub> ≤ 10<sup>9</sup> for each j), the set of numbers that describe individual i.</li>
</ul>

<p>It is guaranteed that the sum over all m<sub>i</sub> is at most 2 · 10<sup>5</sup>.</p>

### 출력 

 <p>Output a proof in the form of n − 1 lines, each of which contains three integers p, q and r, where p and q are distinct individuals that are both described by the number r. Using only these relations, it must be possible to show that any pair of individuals in the group are connected either directly or indirectly.</p>

<p>If no such proof exists, output “impossible”. If there are multiple proofs, you may output any one of them.</p>

