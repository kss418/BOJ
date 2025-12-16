# [Platinum I] Ball Alignment - 20036 

[문제 링크](https://www.acmicpc.net/problem/20036) 

### 성능 요약

메모리: 18920 KB, 시간: 144 ms

### 분류

이분 탐색, 값 / 좌표 압축, 다이나믹 프로그래밍, 정렬

### 제출 일자

2025년 12월 16일 15:34:14

### 문제 설명

<p>Balls are placed on a curved structure as shown in Figure A.1, and each ball has a number written on it. Due to the law of gravity, all balls naturally gather near the lowest spot of the structure. The permitted action to change the position of the balls is to “pick a ball, lift it up, and place it on the far left or on the far right”. This action will naturally change the location of some balls due to the law of gravity.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/c79fce05-4ed4-47c1-859c-ae4141065a8b/-/preview/" style="width: 427px; height: 88px;"></p>

<p style="text-align: center;">Figure A.1</p>

<p>Figure A.2 shows how the locations of the balls change when the marked ball 5 was picked up in Figure A.1 and placed on the far right.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/570aa792-039d-4467-9d77-384d14024dcf/-/preview/" style="width: 409px; height: 92px;"></p>

<p style="text-align: center;">Figure A.2</p>

<p>When <em>n</em> balls are arranged on a curved structure we want to sort the numbers written on the balls in non- decreasing order by repeating the permitted actions. In Figure A.2, if ball 7 is picked up and placed on the far right and ball 2 far left, all the numbers on balls are sorted in non-decreasing order.</p>

<p>Given an arrangement of <em>n</em> balls, write a program which helps to rearrange all the numbers written on the balls in non-decreasing order by selecting minimum number of balls and relocating them through the permitted actions.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer <em>n</em> (1 ≤ <em>n</em> ≤ 10<sup>5</sup>), which denotes the number of balls. Each of the following <em>n</em> lines contains an integer <em>v</em> (1 ≤ <em>v</em> ≤ 10<sup>9</sup>), which is the number written on a ball. Notice that some balls may have the same number written on them.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line. The line should contain the minimum number of balls picked up and relocated to align all the numbers written on the <em>n</em> balls in non-decreasing order.</p>

