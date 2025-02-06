# [Platinum IV] Hills - 16369 

[문제 링크](https://www.acmicpc.net/problem/16369) 

### 성능 요약

메모리: 394516 KB, 시간: 856 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 2월 6일 19:45:25

### 문제 설명

<p>Welcome to Innopolis city. Throughout the whole year, Innopolis citizens suffer from everlasting city construction.</p>

<p>From the window in your room, you see the sequence of n hills, where i-th of them has height a<sub>i</sub>. The Innopolis administration wants to build some houses on the hills. However, for the sake of city appearance, a house can be only built on the hill, which is strictly higher than neighbouring hills (if they are present). For example, if the sequence of heights is 5, 4, 6, 2, then houses could be built on hills with heights 5 and 6 only.</p>

<p>The Innopolis administration has an excavator, that can decrease the height of an arbitrary hill by one in one hour. The excavator can only work on one hill at a time. It is allowed to decrease hills up to zero height, or even to negative values. Increasing height of any hill is impossible. The city administration wants to build k houses, so there must be at least k hills that satisfy the condition above. What is the minimum time required to adjust the hills to achieve the administration’s plan?</p>

<p>However, the exact value of k is not yet determined, so could you please calculate answers for all k in range 1 ≤ k ≤ ⌈n/2⌉? Here ⌈n/2⌉ denotes n divided by two, rounded up.</p>

### 입력 

 <p>The first line of input contains the only integer n (1 ≤ n ≤ 5000)—the number of the hills in the sequence. Second line contains n integers a<sub>i</sub> (1 ≤ a<sub>i</sub> ≤ 100 000)—the heights of the hills in the sequence.</p>

### 출력 

 <p>Print exactly ⌈n/2⌉ numbers separated by spaces. The i-th printed number should be equal to the minimum number of hours required to level hills so it becomes possible to build i houses.</p>

