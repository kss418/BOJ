# [Gold III] Meeting Place - 5971 

[문제 링크](https://www.acmicpc.net/problem/5971) 

### 성능 요약

메모리: 3888 KB, 시간: 0 ms

### 분류

최소 공통 조상, 트리

### 제출 일자

2025년 6월 4일 12:54:35

### 문제 설명

<p>Bessie and Jonell are great friends. Since Farmer John scrambles where the cows graze every day, they are sometimes quite far from each other and can't talk.</p>

<p>The pastures and paths on FJ's farm form a 'tree' structure. Each pasture has exactly one distinct path to any other pasture, and each pasture (except pasture #1, the 'root') also has a single parent node.</p>

<p>Bessie and Jonell have decided that they will always meet at the closest pasture that that is both an ancestor of Jonell's pasture and of Bessie's pasture.</p>

<p>FJ created a map of his N (1 <= N <= 1,000) pastures (conveniently numbered 1..N) that tells the parent P_i (1 <= P_i <= N) of each pasture except pasture 1, which has no parent.</p>

<p>FJ has released his daily grazing schedule for the next M (1 <= M <= 1,000) days, so Bessie and Jonell are deciding where they should meet each day for gossip. On day k, Bessie is in pasture B_k (1 <= B_k <= N) and Jonell is in pasture J_k (1 <= J_k <= N).</p>

<p>Given a map and schedule, help Bessie and Jonell find their meeting places.</p>

<p>Consider, for example, the following farm layout:</p>

<pre>                            Pasture      Parent Pasture
             [1]           ---------    ----------------
            / | \              1              ---
           /  |  \             2               1 
         [2] [3] [6]           3               1
         /        | \          4               2
        /         |  \         5               8
      [4]        [8]  [9]      6               1
                /   \          7               8
               /     \         8               6
             [5]     [7]       9               6</pre>

<p>Here are the meeting places that Bessie and Jonell would choose given a six day schedule of their initial grazing locations:</p>

<pre>              Bessie      Jonell       Meeting Place
             --------    --------     ---------------
                 2           7               1
                 4           2               2
                 1           1               1
                 4           1               1
                 7           5               8
                 9           5               6</pre>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and M</li>
	<li>Lines 2..N: Line i contains a single integer that describes the parent of pasture i:  P_i</li>
	<li>Lines N+1..N+M: Line k+N describes Bessie and Jonell's respective pastures with two space-separated integers: B_k and J_k</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Lines 1..M: Line j contains the meeting place Bessie and Jonell would use for line j+N of the input</li>
</ul>

<p> </p>

