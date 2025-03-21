# [Platinum V] 회전 테이블 - 2518 

[문제 링크](https://www.acmicpc.net/problem/2518) 

### 성능 요약

메모리: 26172 KB, 시간: 68 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 2월 17일 13:34:51

### 문제 설명

<p>현이네 가족은 3명이다. 현이네 가족은 주말마다 찾아가는 단골 중식당이 있다. 현이네 가족이 오면 식당에서는 N개의 요리를 회전 테이블에 같은 간격으로 올려준다. 각 요리 접시에는 시계 방향으로 1부터 N까지 번호가 붙여져 있다. N은 항상 3의 배수이다. N=3k라고 할 때, 테이블에서 아빠 자리는 1번 요리가 놓인 곳이고, 엄마 자리는 k+1번 요리, 현이 자리는 2k+1번 요리가 놓인 곳이다. 아래 그림은 N=9일 때 식사를 시작하기 전에 요리가 놓여 있는 예를 보여준다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8ea39fb9-653c-4556-8e2e-2508c23d626a/-/preview/" style="width: 332px; height: 255px;"></p>

<p>가족 각자는 먹고 싶어 하는 요리의 순서를 가지고 있다. 예를 들면, 아빠는 3번, 7번, 1번 순서로 요리를 먹고 싶어 하고, 엄마는 2번, 4번, 1번, 2번 순서로, 현이는 9번, 5번, 6번, 5번 순서로 요리를 먹고 싶어 할 수 있다. 같은 요리를 여러 번 먹어도 되지만, 반드시 순서대로 먹는다. 또한 요리 접시가 자기 바로 앞에 올 때만 식사할 수 있다. 그래서 테이블을 회전시켜가면서 식사를 해야 한다. 각 요리는 여러 번 먹을 수 있을 만큼 충분하다.</p>

<p>자기 바로 오른쪽에 놓인 요리 접시가 자기 앞으로 오도록 테이블을 돌리는 경우에 테이블을 시계방향으로 1칸 돌린다고 말하고, 바로 왼쪽에 놓인 요리 접시가 자기 앞으로 오도록 회전시키는 것을 반시계방향으로 1칸 돌린다고 말한다. </p>

<p>아빠가 혼자 (3, 7, 1) 순서로 식사를 하려면, 테이블을 반시계방향으로 2칸 돌려서 3번 요리를, 그 다음 4칸을 돌려서 7번 요리를, 그 다음 3칸을 돌려서 1번 요리를 먹으면 된다. 이 경우 테이블을 총 9칸 돌려서 식사를 마치게 된다.</p>

<p>아빠가 (3, 7, 1), 엄마가 (2, 4, 1, 2), 현이가 (9, 5, 6, 5) 순서로 식사를 한다고 하자. 아빠, 엄마, 현이가 차례대로 한사람씩 식사를 마친 후에 그 다음 사람이 식사를 하는 방식을 아래 순서와 같이 나타낼 수 있다. 이 순서에서 L과 R은 각각 테이블을 시계방향과 반시계방향으로 1칸 돌리는 것을 의미한다. 이 방식으로는 가족 모두 식사를 마치기 위해 테이블을 총 27칸 돌려야 한다.</p>

<p style="text-align: center;"><code>RRRRRRRRRLLRRLLLRRRRRLLLLRL</code></p>

<p>만일 아래에 표시된 순서대로 테이블을 회전시켜 가면서 식사를 한다면 테이블을 13칸만 돌려도 가족 모두 식사를 마칠 수 있다. </p>

<p style="text-align: center;"><code>RRRRRRRRRLLLR</code></p>

<p>가족 모두가 식사를 마치는데 필요한 테이블 회전 칸수의 최솟값을 구하는 프로그램을 작성하시오. </p>

### 입력 

 <p>첫째 줄에는 요리의 개수를 나타내는 정수 N (3 ≤ N ≤ 300,000)이 주어진다. N은 항상 3의 배수이다. 둘째 줄부터 넷째 줄에는 아빠, 엄마, 현이 순서대로 각 줄마다 한 사람씩 먹고 싶어 하는 요리 순서의 길이 p<sub>i</sub>가 주어지고 이어서 p<sub>i</sub>개의 요리 번호가 빈칸을 사이에 두고 주어진다(i = 1, 2, 3). 정수 p<sub>i</sub>는 1 이상 100 이하이고, 요리 번호는 1과 N 사이의 정수이며 같은 번호가 나올 수도 있다.</p>

### 출력 

 <p>첫째 줄에 현이네 가족이 식사를 마치는데 필요한 테이블 회전 칸수의 최솟값을 출력한다. </p>

