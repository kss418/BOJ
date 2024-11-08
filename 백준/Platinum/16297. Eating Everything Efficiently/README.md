# [Platinum V] Eating Everything Efficiently - 16297 

[문제 링크](https://www.acmicpc.net/problem/16297) 

### 성능 요약

메모리: 431796 KB, 시간: 456 ms

### 분류

방향 비순환 그래프, 다이나믹 프로그래밍, 그래프 이론, 위상 정렬

### 제출 일자

2024년 11월 8일 16:00:27

### 문제 설명

<p>Margriet A. is in pizza heaven! She has bought a oneday access pass to Pizza World. Pizza World is a food festival, where all stands have their own special type of pizza. Margriet would really like to try many different types of pizza, but she thinks that she can only eat two pizzas in total. Therefore, she has come up with a cunning plan: at each stall she visits she decides whether she wants to buy this pizza or not. At the first stall where she decides to make a purchase, she will buy and eat exactly one pizza. At the second one, she will buy and eat half a pizza, and at the third she will eat one quarter of a pizza, etc.. Therefore, at the k th stall where she decides to buy some pizza, she will eat 1/2<sup>k−1</sup> th part of a pizza. This way she makes sure that she will never get full!</p>

<p>In order to ensure that the flow of people in the park is adequate, the pizza stalls are connected by one-way paths, and to make sure that everyone will leave the festival, it is made impossible to visit a pizza stall more than once. However, every stall can be reached from the stall at the entrance, which is the stall with number 0.</p>

<p>Of course, Margriet has her own taste: she will like some pizzas more than others. Eating pizza from a stall will give her a certain amount of satisfaction which is equal to Margriet’s personal stall satisfaction number multiplied by the fraction of a whole pizza she eats there. Her total satisfaction is the sum of satisfactions of every stall she visits. Can you help Margriet plot a route between the pizza stalls that satisfies her the most?</p>

### 입력 

 <ul>
	<li>Two integers 1 ≤ n ≤ 5 · 10<sup>5</sup> and 0 ≤ m ≤ 5 · 10<sup>5</sup> , the number of pizza stalls and the number of one way connections.</li>
	<li>The second line has n integers c<sub>0</sub>, . . . , c<sub>n−1</sub>, 0 ≤ c<sub>i</sub> ≤ 10<sup>9</sup>, the amount of enjoyment Margriet gets from eating one pizza at stall i.</li>
	<li>The next m lines each contain 2 integers 0 ≤ s < n and 0 ≤ t < n, indicating a one way path from stall s to stall t. No connection will appear twice in the input.</li>
</ul>

### 출력 

 <p>Print the maximal amount of enjoyment Margriet can reach at the pizza fair. Your answer will be considered correct if it differs from the actual answer by at most 10<sup>−6</sup> absolutely or relatively.</p>

