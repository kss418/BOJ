# [Platinum II] 빌라봉 - 8872 

[문제 링크](https://www.acmicpc.net/problem/8872) 

### 성능 요약

메모리: 29324 KB, 시간: 92 ms

### 분류

다이나믹 프로그래밍, 그래프 이론, 그리디 알고리즘, 그래프 탐색, 트리, 깊이 우선 탐색, 트리에서의 다이나믹 프로그래밍, 트리에서의 전방향 다이나믹 프로그래밍, 트리의 지름

### 제출 일자

2025년 7월 6일 17:53:03

### 문제 설명

<p>이 이야기는 세상의 태초에, IOI라는 것은 꿈꿀 수도 없었던 아주 먼 옛날에 생긴 일이다.</p>

<p>0, …, N - 1 까지 번호가 붙여진 N 개의 빌라봉(호수)이 있는 땅에 큰 뱀이 살고 있다. 이 땅에는 M 개의 길이 있고, 각각의 길은 한 쌍의 빌라봉을 연결하며, 이 길을 통해 뱀은 양방향으로 이동할 수 있다. 임의의 빌라봉 쌍은 길을 따라서 (직접 또는 간접적으로) 최대 하나의 경로로 연결이 되어 있다. 단, 어떤 빌라봉 쌍들은 연결되어 있지 않을 수도 있다 (즉, M ≤ N - 1 이다). 뱀이 하나의 길을 지나가는 데에는 며칠의 시간이 걸리는데, 이 시간은 길마다 다를 수 있다.</p>

<p>뱀의 친구 캥거루는 N - M - 1 개의 새로운 길을 만들어 뱀이 모든 빌라봉 쌍 사이를 오갈 수 있도록 하고 싶다. 캥거루는 임의의 두 빌라봉을 선택하여 그 사이에 길을 만들 수 있으며, 캥거루가 만든 길을 통행하는 데에는 항상 L 일이 걸린다.</p>

<p>캥거루는 또한 뱀이 최대한 빨리 이동할 수 있기를 원한다. 캥거루는 임의의 두 빌라봉 사이를 오가는데 드는 최대 시간이 최소가 되도록 길을 만들 것이다. 캥거루가 이렇게 길을 만든 뒤 뱀이 두 빌라봉 사이를 오가는데 드는 최대 시간을 계산하시오.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/9b6a5a7a-c614-4f14-a05a-b0877360a0e2/-/preview/" style="width: 362px; height: 271px;"></p>

<p>위 그림에는 N = 12 개의 빌라봉과 M = 8 개의 길이 있다. 새로 만들어지는 길을 뱀이 통행하는 데에는 2일이 걸린다고 가정하자 (즉, L = 2 이다). 그러면 캥거루는 아래와 같이 세 개의 길을 만들 수 있다.</p>

<ul>
	<li>빌라봉 1과 2 사이,</li>
	<li>빌라봉 1과 6 사이,</li>
	<li>빌라봉 4와 10 사이.</li>
</ul>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/3591f600-864b-48c7-ba8c-78ffe9311a6f/-/preview/" style="width: 362px; height: 271px;"></p>

<p>모든 길이 만들어진 뒤의 모습이 위 그림에 나타나 있다. 여기서 두 빌라봉 사이의 최대 통행 시간은 18일인데 (빌라봉 0과 11 사이), 이것이 가능한 가장 작은 값이다. 즉, 캥거루가 어떤 식으로 새로운 길을 만들더라도, 뱀이 통행하는 데 18일 이상이 걸리는 빌라봉 쌍이 항상 존재한다.</p>

### 입력 

 <p>첫째 줄에는 N, M, L이 주어진다. 둘째 줄부터 M개 줄에는 A[i] B[i] T[i]가 주어진다.</p>

<ul>
	<li>N: 빌라봉의 개수</li>
	<li>M: 이미 존재하는 길들의 개수</li>
	<li>L: 뱀이 새로 지어진 길을 통행하는데 걸리는 시간 (일 단위).</li>
	<li>A, B, T: 이미 존재하는 길들이 연결하는 빌라봉들과 각각을 통행하는데 걸리는 시간을 나타내는 길이가 M인 배열들. i 번째 길은 빌라봉 A[i1]과 B[i-1]을 이으며, 통행 시간은 양방향 모두 T[i-1]일이다.</li>
</ul>

### 출력 

 <p>첫째 줄에 모든 빌라봉이 연결되고 최대 통행시간이 최소가 되도록 N-M-1개의 길을 만든 뒤의 최대 통행 시간을 출력한다.</p>

