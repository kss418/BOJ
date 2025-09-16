# [Platinum III] Canal - 17522 

[문제 링크](https://www.acmicpc.net/problem/17522) 

### 성능 요약

메모리: 16136 KB, 시간: 700 ms

### 분류

이분 탐색, 두 포인터

### 제출 일자

2025년 9월 16일 12:41:03

### 문제 설명

<p>It is quite recent that more people started to settle in Aissippissi, a small town located in a flat and dry desert. Aissippissi is still under development, and the government planned to construct a canal across the town. The canal will consist of two long and narrow waterways, stretching north-to-south and east-to-west, respectively, and crossing at some point. For the residents in Aissippissi, the canal will be very helpful for many purposes, so easy access to the canal is a very important criterion in its design.</p>

<p>The issue is where to put the canal, as the distance to the canal varies a lot for the residents depending on locations of the canal. You came up with an idea to resolve the issue: you want to locate the canal of two waterways such that the maximum distance to the canal over all houses is minimized.</p>

<p>Given the coordinates of <em>n</em> houses in Aissippissi, write a program that computes the best canal location that minimizes the maxmium distance to the canal from all the <em>n</em> houses and outputs the corresponding distance.</p>

<p>You may assume that <em>n</em> houses are points lying in the plane with the <em>x</em>- and <em>y</em>-axes, so that the <em>x</em>-axis is along the west-to-east direction and the <em>y</em>-axis along the south-to-north direction. Hence, the two waterways of the canal are regarded as two straight lines in the plane, being parallel to the <em>x</em>-axis and to the <em>y</em>-axis, respectively. The crossing point can be any point in the plane. In addition, the waterways can pass through some houses as they will be built a bit below the ground level. The distance from a house to the canal is the direct distance to the closer waterway of the canal on the plane. Hence, the distance from any house exactly on either waterway to the canal should be zero.</p>

### 입력 

 <p>Your program is to read from standard input. The input starts with a line containing an integer <em>n</em> (1 ≤ <em>n</em> ≤ 300,000), where <em>n</em> is the number of houses in Aissippissi. In the following <em>n</em> lines, each line contains two integers, which range inclusively from −10<sup>9</sup> to 10<sup>9</sup>, representing the <em>x</em>- and <em>y</em>-coordinates, respectively, of each of the <em>n</em> houses. Note that there may be two or more houses with the same coordinates.</p>

### 출력 

 <p>Your program is to write to standard output. Print exactly one line consisting of a real number, rounded to the first decimal place, that represents the maximum distance from the houses to the best canal which minimizes the maximum distance.</p>

