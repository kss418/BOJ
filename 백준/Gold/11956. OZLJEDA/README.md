# [Gold I] OZLJEDA - 11956 

[문제 링크](https://www.acmicpc.net/problem/11956) 

### 성능 요약

메모리: 5160 KB, 시간: 76 ms

### 분류

누적 합

### 제출 일자

2025년 2월 6일 17:33:21

### 문제 설명

<p>Due to the frantical usage of the racket to kill flies, Marin has sustained a serious bodily injury known to the medical community as <em>epicondylitis lateralis humeri</em>. His grandma has advised smearing rakija over it, the doctor has prescribed a strong painkiller, but Marin has ignored every single advice and decided to look for the answer in integer sequences.</p>

<p>He has discovered a previously undiscovered sequence of integers and called it the <em>xorbonacci</em> sequence. The nth element in the sequence is denoted with x<sub>n</sub>. The sequence is defined recursively in the following way:</p>

<ul>
	<li>x<sub>1</sub> = a<sub>1</sub>,</li>
	<li>x<sub>2</sub> = a<sub>2</sub>,</li>
	<li>...</li>
	<li>x<sub>k</sub> = a<sub>k</sub>,</li>
	<li>x<sub>n</sub> = x<sub>n−1</sub> ⊕ x<sub>n−2</sub> ⊕ ... ⊕ x<sub>n−k</sub>, n > k</li>
</ul>

<p>Because of a reason only known to Marin, he determined that all his sorrows will go away if you answer his Q queries defined with numbers l and r. The answer to the query is represented with the value</p>

<ul>
	<li>x<sub>l</sub> ⊕ x<sub>l+1</sub> ⊕ ... ⊕ x<sub>r−1</sub> ⊕ x<sub>r</sub></li>
</ul>

<p>Help Marin and answer his queries.</p>

<p>Please note: The operation ⊕ is the operation of binary XOR.</p>

### 입력 

 <p>The first line of input contains the integer K (1 ≤ K ≤ 100 000) from the task.</p>

<p>The following line contains K integers that represent the first K elements in the xorbonacci sequence.</p>

<p>All numbers are smaller than 10<sup>18</sup>.</p>

<p>The following line contains the integer Q (1 ≤ Q ≤ 10<sup>6</sup>) from the task.</p>

<p>The ith of the following Q lines contains two integers l<sub>i</sub> and r<sub>i</sub> (1 ≤ l<sub>i</sub> ≤ r<sub>i</sub> ≤ 10<sup>18</sup>) that represent Marin’s ith query.</p>

### 출력 

 <p>Each of the following Q lines of output must contain the answers to Marin’s queries, the order being the same as the input.</p>

