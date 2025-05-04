# [Gold II] Cow Routing - 10673 

[문제 링크](https://www.acmicpc.net/problem/10673) 

### 성능 요약

메모리: 151720 KB, 시간: 160 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2025년 5월 4일 15:24:22

### 문제 설명

<p>Tired of the cold winter weather on her farm, Bessie the cow plans to fly to a warmer destination for vacation.  Unfortunately, she discovers that only one airline, Air Bovinia, is willing to sell tickets to cows, and that these tickets are somewhat complicated in structure.</p>

<p>Air Bovinia owns N planes (1 <= N <= 1000), each of which flies on a specific "route" consisting of two or more cities.  For example, one plane might fly on a route that starts at city 1, then flies to city 5, then flies to city 2, and then finally flies to city 8.  No city appears multiple times in a route.  If Bessie chooses to utilize a route, she can board at any city along the route and then disembark at any city later along the route.  She does not need to board at the first city or disembark at the last city.  Each route has a certain cost, which Bessie must pay if she uses any part of the route, irrespective of the number of cities she visits along the route.  If Bessie uses a route multiple times during her travel (that is, if she leaves the route and later comes back to use it from antoher city), she must pay for it each time it is used.</p>

<p>Bessie would like to find the cheapest way to travel from her farm (in city A) to her tropical destination (city B). Please help her decide what is the minimum cost she must pay, and also the smallest number of individual flights she must use take to achieve this minimum cost.</p>

### 입력 

 <p>The first line of input contains A, B, and N, separated by spaces.  </p>

<p>The next 2N lines describe the available routes, in two lines per route. The first line contains the cost of using the route (an integer in the range 1..1,000,000,000), and the number of cities along the route (an integer in the range 1..100).  The second line contains a list of the cities in order along the route.  Each city is identified by an integer in the range 1..1000.  Note that the cost of an itinerary can easily add up to more than can fit into a 32-bit integer, so you should probably use 64-bit integers (e.g., "long long" integers in C/C++).</p>

### 출력 

 <p>Output the minimum cost of an itinerary that Bessie can use to travel from city A to city B, as well as the minimum number of individual flights required to achieve this minimum cost.  If there is no solution, output "-1 -1" (quotes for clarity) on a single line.</p>

<p> </p>

