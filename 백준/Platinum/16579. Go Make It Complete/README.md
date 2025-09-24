# [Platinum II] Go Make It Complete - 16579 

[문제 링크](https://www.acmicpc.net/problem/16579) 

### 성능 요약

메모리: 2672 KB, 시간: 88 ms

### 분류

자료 구조, 그리디 알고리즘, 매개 변수 탐색, 우선순위 큐

### 제출 일자

2025년 9월 24일 13:45:20

### 문제 설명

<p>Andi has a network G with N machines and M links; each link connects exactly two different machines. Due to some circumstances, Andi has to make his network “complete”, i.e. every machine is directly linked to every other machine. This means Andy has to add a new link between any pair of machines which are not already directly linked.</p>

<p>In order to accomplish his goal, Andi outsources the work to a company, Go. Go accepts any work order on a network G with a requested integer k, i.e. go(G, k). The way Go works: First, it creates a list L containing all pair of machines which are not yet directly linked. Then, Go evaluates each pair of machines (a, b) from L and create a new link between them if δ<sub>a</sub> +δ<sub>b</sub> ≥ k. Note that δ<sub>a</sub> is the degree of machine a, i.e. the number of links a has at the time of evaluation. Similarly, δ<sub>b</sub> is for machine b.</p>

<p>The problem with Go’s procedure is it evaluates each pair of machines in the order appeared in L. For example, let G be a network with N = 4 machines (machine 1, 2, 3, and 4) and M = 3 links; the links are {(1, 2),(2, 3),(3, 4)}. The degree of each machine before a work order is requested is: δ<sub>1</sub> = 1, δ<sub>2</sub> = 2, δ<sub>3</sub> = 2, δ<sub>4</sub> = 1, or simply can be written as [1, 2, 2, 1]. Let say a work order with k = 3 is requested (go(G, 3)).</p>

<p>Consider these two lists:</p>

<ul>
	<li>L<sub>1</sub> = ((1, 4),(1, 3),(2, 4)).

	<ul>
		<li class="problem-16579-li-x">Evaluate (1, 4) and don’t create a new link since δ<sub>1</sub> + δ<sub>4</sub> = 1 + 1 = 2. The degree is still [1, 2, 2, 1].</li>
		<li class="problem-16579-li-o">Evaluate (1, 3) and create a new link since δ<sub>1</sub> + δ<sub>3</sub> = 1 + 2 = 3. The degree becomes [2, 2, 3, 1].</li>
		<li class="problem-16579-li-o">Evaluate (2, 4) and create a new link since δ<sub>2</sub> + δ<sub>4</sub> = 2 + 1 = 3. The degree becomes [2, 3, 3, 2].</li>
	</ul>
	</li>
</ul>

<p>The final result is a network with 5 links, which is not complete as it misses the (1, 4) link.</p>

<ul>
	<li>L<sub>2</sub> = ((2, 4),(1, 3),(1, 4)).

	<ul>
		<li class="problem-16579-li-o">Evaluate (2, 4) and create a new link since δ<sub>2</sub> + δ<sub>4</sub> = 2 + 1 = 3. The degree becomes [1, 3, 2, 2].</li>
		<li class="problem-16579-li-o">Evaluate (1, 3) and create a new link since δ<sub>1</sub> + δ<sub>3</sub> = 1 + 2 = 3. The degree becomes [2, 3, 3, 2].</li>
		<li class="problem-16579-li-o">Evaluate (1, 4) and create a new link since δ<sub>1</sub> + δ<sub>4</sub> = 2 + 2 = 4. The degree becomes [3, 3, 3, 3].</li>
	</ul>
	</li>
</ul>

<p>The final result is a network with 6 links and complete.</p>

<p>As we can see, L<sub>2</sub> produces a complete network, while L<sub>1</sub> is not.</p>

<p>Ordering a work to Go can be very expensive with lower k, thus, Andi has to make k as high as possible while maintaining the possibility that a complete network can be achieved with k. In other words, Andi wants the highest k such that there exists L such that go(G, k) can produce a complete network, and for any j (j > k), there is no valid L for go(G, j) which can produce a complete network. Your task in this problem is to find such k.</p>

### 입력 

 <p>Input begins with a line containing two integers: N M (2 ≤ N ≤ 500; 0 ≤ M < N×(N−1)/2) representing the number of machines and the number existing links, respectively. The machines are numbered from 1 to N. The next M lines, each contains two integers: a<sub>i</sub> b<sub>i</sub> (1 ≤ a<sub>i</sub> < b<sub>i</sub> ≤ N) representing an existing link connecting machine a<sub>i</sub> and b<sub>i</sub>. You are guaranteed that each pair (a<sub>i</sub>, b<sub>i</sub>) will appear at most once in the input.</p>

### 출력 

 <p>Output contains an integer k in a line, as requested.</p>

