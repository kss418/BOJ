# [Platinum III] 물탱크 - 15972 

[문제 링크](https://www.acmicpc.net/problem/15972) 

### 성능 요약

메모리: 99788 KB, 시간: 1236 ms

### 분류

너비 우선 탐색, 자료 구조, 데이크스트라, 그래프 이론, 그래프 탐색, 우선순위 큐, 최단 경로

### 제출 일자

2025년 1월 18일 14:40:55

### 문제 설명

<p>세로 길이가 <em>N</em>, 가로 길이가 <em>M</em>, 높이가 <em>H</em>인 물탱크가 있다. <em>N</em>, <em>M</em>, <em>H</em>는 모두 양의 정수이다. <그림 1>은 세로 길이가 2, 가로 길이가 3, 높이가 5인 물탱크 모양을 보여준다. <그림 1>에서 보듯이 물탱크 내부는 가로와 세로로 벽이 설치되어 있는데, 내부 각 칸(즉 사각기둥 모양)의 세로와 가로 길이는 1이고 높이는 <em>H</em>가 되도록 벽이 설치되어 있다. 이 물탱크를 위에서 내려다보면 <그림 2>와 같이 각 칸이 정사각형인 격자 모양이 된다. 물탱크 각 칸의 벽에는 물 높이 조정을 위해 구멍이 뚫려 있을 수 있다. 각 칸에는 네 개의 벽이 있는데, 각 벽 내부에는 최대 한 개의 구멍이 뚫려 있을 수 있다. 단, 모서리엔 구멍이 없다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8560275d-76f2-4881-b05a-d6b72f63bdb2/-/preview/" style="width: 182px; height: 209px;"></p>

<p style="text-align: center;"><그림 1></p>

<p><그림 1>에서 구멍이 있는 높이는 바닥을 기준으로 표시되어 있다. 구멍의 위치를 위에서 보면 <그림 2>처럼 보이는데 이는 물탱크를 위에서 보았을때 어느 벽, 어떤 높이에 구멍이 뚫려 있는지를 알려주며, <그림 1>에선 표시 하기 어려운 물탱크의 구멍 위치도 표시한다. <그림 2>에서 보듯이 물탱크 내부 벽에도 구멍이 있을 수 있다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/02f91c8f-6834-4def-8f74-9e3af33e4c9e/-/preview/" style="width: 298px; height: 218px;"><br>
<그림 2></p>

<p>물탱크에 물을 채울 땐, 모든 구멍을 마개로 막아 물이 새지 못하도록 한 후, 격자의 각 칸 위에 설치된 급수 장치를 통해 물탱크 전체를 물로 채운다. 물이 꽉 찬 후에 구멍을 막고 있는 모든 마개를 제거하면 물이 구멍을 통해 인접한 방이나 외부로 흘러나가게 된다. 어느 정도 시간이 지나면 물이 더 이상 흘러 나가지 않게 되고, 그 때 물탱크 격자의 각 칸에 남아 있는 물의 높이는 서로 다를 수 있다.</p>

<p>참고로, <그림 2>에서 보인 물탱크의 각 칸에 남아 있는 물의 높이를 나타내면 <그림 3>의 괄호 속의 수치와 같다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/92ad0a93-213c-4719-b025-b6d9847fbaba/-/preview/" style="width: 193px; height: 146px;"><br>
<그림 3></p>

<p>벽의 두께를 무시할 때, 물탱크에 남아 있는 물의 총량(부피)을 계산하는 프로그램을 작성하시오.</p>

### 입력 

 <p>표준 입력으로 다음 정보가 주어진다. 첫 번째 줄에는 물탱크의 세로 길이, 가로 길이, 높이를 나타내는 세 양의 정수 <em>N</em>, <em>M</em>, <em>H</em>가 차례로 주어진다.</p>

<p>다음 줄에는 첫 번째 가로 벽에 설치된 구멍 정보를 나타내는 <em>M</em>개의 정수가 주어진다. 각 정수는 왼쪽부터 시작하여 순서대로 각 칸의 구멍 높이를 의미한다. 구멍의 높이는 0 이상 <em>H</em>미만의 정수이다. 해당 벽에 구멍이 없는 경우는 –1로 표시한다. 이어지는 줄엔 두 번째 가로 벽에 설치된 구멍 정보가 주어지고, 이런 식으로 <em>N</em>+1 줄에 걸쳐 가로 벽에 설치된 모든 구멍에 대한 정보가 주어진다.</p>

<p>이어지는 줄에는 첫 번째 가로 벽을 공유하는 칸들(<그림 2>에서 맨 윗줄의 칸들)의 세로 벽에 설치된 구멍 정보를 나타내는 <em>M</em>+1개의 정수가 주어진다. 각 정수는 첫 번째 세로 벽부터 시작하여 차례로 각 세로 벽의 구멍 높이를 나타낸다. 그 다음 줄에는 그 다음에 있는 칸들의 세로 벽에 설치된 구멍 정보가 주어진다. 이런 식으로 <em>N</em>줄에 걸쳐 세로 벽에 설치된 모든 구멍 정보가 주어진다.</p>

<p>참고로, 입출력 예에서 보인 첫 번째 예제는 <그림 2>에서 보인 경우에 대응된다.</p>

### 출력 

 <p>물이 더 이상 흘러 나가지 않는 시점에 물탱크에 남아 있는 물의 총량(부피)을 표준 출력으로 출력한다.</p>

