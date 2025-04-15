# [Gold III] Hoof, Paper, Scissors (Gold) - 14450 

[문제 링크](https://www.acmicpc.net/problem/14450) 

### 성능 요약

메모리: 59524 KB, 시간: 472 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 4월 15일 12:27:00

### 문제 설명

<p>You have probably heard of the game "Rock, Paper, Scissors". The cows like to play a similar game they call "Hoof, Paper, Scissors".</p>

<p>The rules of "Hoof, Paper, Scissors" are simple. Two cows play against each-other. They both count to three and then each simultaneously makes a gesture that represents either a hoof, a piece of paper, or a pair of scissors. Hoof beats scissors (since a hoof can smash a pair of scissors), scissors beats paper (since scissors can cut paper), and paper beats hoof (since the hoof can get a papercut). For example, if the first cow makes a "hoof" gesture and the second a "paper" gesture, then the second cow wins. Of course, it is also possible to tie, if both cows make the same gesture.</p>

<p>Farmer John wants to play against his prize cow, Bessie, at N games of "Hoof, Paper, Scissors" (1 ≤ N ≤ 100,000). Bessie, being an expert at the game, can predict each of FJ's gestures before he makes it. Unfortunately, Bessie, being a cow, is also very lazy. As a result, she tends to play the same gesture multiple times in a row. In fact, she is only willing to switch gestures at most K times over the entire set of games (0 ≤ K ≤ 20). For example, if K=2, she might play "hoof" for the first few games, then switch to "paper" for a while, then finish the remaining games playing "hoof".</p>

<p>Given the sequence of gestures FJ will be playing, please determine the maximum number of games that Bessie can win.</p>

### 입력 

 <p>The first line of the input file contains N and K.</p>

<p>The remaining N lines contains FJ's gestures, each either H, P, or S.</p>

### 출력 

 <p>Print the maximum number of games Bessie can win, given that she can only change gestures at most K times.</p>

