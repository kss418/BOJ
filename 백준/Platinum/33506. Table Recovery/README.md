# [Platinum IV] Table Recovery - 33506 

[문제 링크](https://www.acmicpc.net/problem/33506) 

### 성능 요약

메모리: 25964 KB, 시간: 152 ms

### 분류

수학, 애드 혹, 해 구성하기

### 제출 일자

2025년 9월 4일 13:25:12

### 문제 설명

<p>Bessie has an $N\times N$ ($1\le N\le 1000$) addition table where the integer in the cell at row $r$ and column $c$ is $r+c$, for all $1\le r,c\le N$. For example, for $N=3$, the table would look like this:</p>

<pre>2 3 4
3 4 5
4 5 6
</pre>

<p>Unfortunately, Elsie got ahold of the table and permuted it by performing the following three types of operations as many times as she wanted.</p>

<ol>
	<li>Swap two rows</li>
	<li>Swap two columns</li>
	<li>Select two values $a$ and $b$ that are both present in the table, then simultaneously change every occurrence of $a$ to $b$ and every occurrence of $b$ to $a$.</li>
</ol>

<p>Elsie will always perform operations in increasing order of type; that is, she performs as many operations as she likes (possibly none) first of type $1$, then of type $2$, and finally of type $3$.</p>

<p>Help Bessie recover a possible state of the table after Elsie finished applying all of her operations of types $1$ and $2$, but before applying any operations of type $3$. There may be multiple possible answers, in which case you should output the lexicographically smallest one.</p>

<p>To compare two tables lexicographically, compare the first entries at which they differ, when reading both tables in the natural order (rows from top to bottom, left to right within a row).</p>

### 입력 

 <p>The first line contains $N$.</p>

<p>The next $N$ lines each contain $N$ integers, representing Bessie's addition table after Elsie has permuted it.</p>

### 출력 

 <p>The lexicographically minimum possible state of the table after all operations of types 1 and 2, but before any operations of type 3. It is guaranteed that the answer exists.</p>

