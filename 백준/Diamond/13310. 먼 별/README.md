# [Diamond V] 먼 별 - 13310 

[문제 링크](https://www.acmicpc.net/problem/13310) 

### 성능 요약

메모리: 5904 KB, 시간: 692 ms

### 분류

볼록 껍질, 기하학, 회전하는 캘리퍼스, 삼분 탐색

### 제출 일자

2024년 11월 26일 12:54:43

### 문제 설명

<p>가상의 우주에 있는 KOI 별에서 바라보는 밤하늘에는 밝게 빛나는 많은 별이 있다. 이 별에 살고있는 고등학생 나정보는 고정된 카메라로 매일 밤 자정에 하늘 사진을 찍고 있는데, 특이하게도 찍힌 별들은 2차원 평면의 정수 좌표로 항상 표현된다.</p>

<p>날마다 찍은 사진을 비교해 보니 어떤 별은 항상 같은 좌표에 있고, 어떤 별은 일정한 속도로 이동하고 있다. 이때 별의 이동 속도는 [dx, dy]로 표시되는데 dx는 하루 동안의 x축 좌표 변화량, dy는 하루 동안의 y축 좌표 변화량을 나타내며 역시 둘 다 정수이다.</p>

<p>당연하게도 각 별의 속도는 다른 별과 무관하고, 별들은 언제든 서로 겹칠 수 있다(단, 실제로 충돌하는 것은 아님). 이동하지 않는 별의 속도는 [0, 0]이다. </p>

<p>예를 들어, 아래 사진은 나정보가 처음(촬영일 0)으로 찍은 사진으로, 별 A의 좌표는 (0, 0), 별 B의 좌표는 (5, 0), 그리고 별 C의 좌표는 (3, -3)이다.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13309/1.png" style="height:213px; width:208px"></p>

<p>다음 사진은 하루 뒤(촬영일 1)에 찍은 사진으로, 세 개의 별의 좌표가 (2, 0), (4, 0), 그리고 (4, -2)로 바뀌었다.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13309/2.png" style="height:210px; width:209px"></p>

<p>즉, 별 A의 속도는 [2, 0], 별 B의 속도는 [-1, 0], 별 C의 속도는 [1, 1]이다. 따라서 처음 사진을 찍은 날부터 이틀 뒤(촬영일 2)에 찍은 사진에서는 세 별의 좌표가 (4, 0), (3, 0), (5, -1)이 될 것이다.</p>

<p>나정보는 좌표 상에서 가장 멀리 떨어진 두 별의 거리를 매일 기록하고 있다. 두 별의 x좌표의 차이가 p이고 y좌표의 차이가 q인 두 별의 거리는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msqrt><mjx-sqrt><mjx-surd><mjx-mo class="mjx-sop"><mjx-c class="mjx-c221A TEX-S1"></mjx-c></mjx-mo></mjx-surd><mjx-box style="padding-top: 0.131em;"><mjx-msup><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45D TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: 0.289em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2B"></mjx-c></mjx-mo><mjx-msup space="3"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D45E TEX-I"></mjx-c></mjx-mi><mjx-script style="vertical-align: 0.289em; margin-left: 0.051em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-script></mjx-msup></mjx-box></mjx-sqrt></mjx-msqrt></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msqrt><msup><mi>p</mi><mn>2</mn></msup><mo>+</mo><msup><mi>q</mi><mn>2</mn></msup></msqrt></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\sqrt{p^2+q^2}\)</span></mjx-container> 으로 정의한다. 예를 들어, 촬영일 0의 사진에서 가장 멀리 떨어진 두 별은 별 A와 별 B이고 그 때 거리는 5이며, 촬영일 1의 사진에서 가장 멀리 떨어진 두 별은 별 A와 별 C로 거리는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msqrt><mjx-sqrt><mjx-surd><mjx-mo class="mjx-n"><mjx-c class="mjx-c221A"></mjx-c></mjx-mo></mjx-surd><mjx-box style="padding-top: 0.163em;"><mjx-mn class="mjx-n"><mjx-c class="mjx-c38"></mjx-c></mjx-mn></mjx-box></mjx-sqrt></mjx-msqrt></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msqrt><mn>8</mn></msqrt></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\sqrt{8}\)</span></mjx-container> 이다.</p>

<p>별들의 초기 좌표와 속도, 마지막 촬영일이 주어졌을 때, 가장 멀리 떨어진 두 별의 거리가 최소인 촬영일과 그 때 거리의 제곱값을 구하는 프로그램을 작성하시오. 단, 이런 촬영일이 여러 날인 경우에는 그 중에서 가장 처음 찍은 촬영일을 구하시오.</p>

<p>앞의 예에서 마지막 촬영일이 3이라면, 각 촬영일의 최대 거리가 5(촬영일 0), <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msqrt><mjx-sqrt><mjx-surd><mjx-mo class="mjx-n"><mjx-c class="mjx-c221A"></mjx-c></mjx-mo></mjx-surd><mjx-box style="padding-top: 0.163em;"><mjx-mn class="mjx-n"><mjx-c class="mjx-c38"></mjx-c></mjx-mn></mjx-box></mjx-sqrt></mjx-msqrt></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msqrt><mn>8</mn></msqrt></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\sqrt{8}\)</span></mjx-container> (촬영일 1), <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msqrt><mjx-sqrt><mjx-surd><mjx-mo class="mjx-n"><mjx-c class="mjx-c221A"></mjx-c></mjx-mo></mjx-surd><mjx-box style="padding-top: 0.163em;"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-box></mjx-sqrt></mjx-msqrt></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msqrt><mn>5</mn></msqrt></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\sqrt{5}\)</span></mjx-container> (촬영일 2), 4(촬영일 3)가 되어 그 중 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msqrt><mjx-sqrt><mjx-surd><mjx-mo class="mjx-n"><mjx-c class="mjx-c221A"></mjx-c></mjx-mo></mjx-surd><mjx-box style="padding-top: 0.163em;"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-box></mjx-sqrt></mjx-msqrt></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msqrt><mn>5</mn></msqrt></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\sqrt{5}\)</span></mjx-container>가 최소이므로 촬영일 2와 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msqrt><mjx-sqrt><mjx-surd><mjx-mo class="mjx-n"><mjx-c class="mjx-c221A"></mjx-c></mjx-mo></mjx-surd><mjx-box style="padding-top: 0.163em;"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c></mjx-mn></mjx-box></mjx-sqrt></mjx-msqrt></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msqrt><mn>5</mn></msqrt></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">\(\sqrt{5}\)</span></mjx-container> 의 제곱값인 5를 구하면 된다.</p>

### 입력 

 <p>표준 입력으로 다음 정보가 주어진다. 첫 번째 줄에는 별의 개수를 나타내는 정수 N (2 ≤ N ≤ 30,000)과 마지막 촬영일을 나타내는 정수 T (0 ≤ T ≤ 10<sup>7</sup>)가 주어진다. 다음 N 개의 줄에 각 별의 좌표 (x, y)와 속도 [dx, dy]를 나타내는 네 개의 정수가 주어진다 (|x|, |y| ≤ 10<sup>7</sup>이고 |dx|, |dy| ≤ 100). 이때 동일한 좌표의 별이 입력으로 들어올 수도 있다.</p>

### 출력 

 <p>표준 출력으로 다음 정보를 출력한다. 첫 번째 줄에는 가장 멀리 떨어진 두 별의 거리가 최소인 촬영일을 출력한다. 단, 이런 촬영일이 여럿 존재한다면 가장 빠른 촬영일을 출력한다. 두 번째 줄에는 그 때 거리의 제곱값을 정수로 출력한다.</p>

