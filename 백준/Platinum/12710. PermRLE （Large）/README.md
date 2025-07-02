# [Platinum III] PermRLE (Large) - 12710 

[문제 링크](https://www.acmicpc.net/problem/12710) 

### 성능 요약

메모리: 10492 KB, 시간: 4348 ms

### 분류

비트마스킹, 다이나믹 프로그래밍, 비트필드를 이용한 다이나믹 프로그래밍

### 제출 일자

2025년 7월 2일 22:56:30

### 문제 설명

<p>You've invented a slight modification of the run-length encoding (RLE) compression algorithm, called PermRLE.</p>

<p>To compress a string, this algorithm chooses some permutation of integers between 1 and <strong>k</strong>, applies this permutation to the first <strong>k</strong> letters of the given string, then to the next block of <strong>k</strong> letters, and so on. The length of the string must be divisible by <strong>k</strong>. After permuting all blocks, the new string is compressed using RLE, which is described later.</p>

<p>To apply the given permutation <em>p</em> to a block of <strong>k</strong> letters means to place the <em>p[1]</em>-th of these letters in the first position, then <em>p[2]</em>-th of these letters in the second position, and so on. For example, applying the permutation {3,1,4,2} to the block "abcd" yields "cadb". Applying it to the longer string "abcdefghijkl" in blocks yields "cadbgehfkilj".</p>

<p>The permuted string is then compressed using run-length encoding. To simplify, we will consider the <em>compressed size</em> of the string to be the number of groups of consecutive equal letters. For example, the compressed size of "aabcaaaa" is 4; the first of the four groups is a group of two letters "a", then two groups "b" and "c" each containing only one letter, and finally a longer group of letters "a".</p>

<p>Obviously, the compressed size may depend on the chosen permutation. Since the goal of compression algorithms is to minimize the size of the compressed text, it is your job to choose the permutation that yields the smallest possible compressed size, and output that size.</p>

### 입력 

 <p>The first line of input gives the number of cases, <strong>N</strong>. <strong>N</strong> test cases follow.</p>

<p>The first line of each case will contain <strong>k</strong>. The second line will contain <strong>S</strong>, the string to be compressed.</p>

<p>Limits</p>

<ul>
	<li><strong>N</strong> = 20</li>
	<li><strong>S</strong> will contain only lowercase letters 'a' through 'z'</li>
	<li>The length of <strong>S</strong> will be divisible by <strong>k</strong></li>
	<li>2 ≤ <strong>k</strong> ≤ 16</li>
	<li>1 ≤ length of <strong>S</strong> ≤ 50000</li>
</ul>

### 출력 

 <p>For each test case you should output one line containing "Case #<strong>X</strong>: <strong>Y</strong>" (quotes for clarity) where <strong>X</strong> is the number of the test case and <strong>Y</strong> is the minimum compressed size of <strong>S</strong>.</p>

