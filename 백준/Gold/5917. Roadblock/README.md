# [Gold II] Roadblock - 5917 

[문제 링크](https://www.acmicpc.net/problem/5917) 

### 성능 요약

메모리: 2792 KB, 시간: 4 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2025년 5월 29일 13:28:30

### 문제 설명

<p>Every morning, FJ wakes up and walks across the farm from his house to the barn.  The farm is a collection of N fields (1 <= N <= 100) connected by M bidirectional pathways (1 <= M <= 10,000), each with an associated length. FJ's house is in field 1, and the barn is in field N.  No pair of fields is joined by multiple redundant pathways, and it is possible to travel between any pair of fields in the farm by walking along an appropriate sequence of pathways.  When traveling from one field to another, FJ always selects a route consisting of a sequence of pathways having minimum total length.</p><p>Farmer John's cows, up to no good as always, have decided to interfere with FJ's morning routine.  They plan to build a pile of hay bales on exactly one of the M pathways on the farm, doubling its length.  The cows wish to select a pathway to block so that they maximize the increase in FJ's distance from the house to the barn.  Please help the cows determine by how much they can lengthen FJ's route.</p>

### 입력 

 <ul><li>Line 1: Two space-separated integers, N (1 <= N <= 100) and M (1 <= M <= 10,000).</li><li>Lines 2..1+M: Line j+1 describes the jth bidirectional pathway in terms of three space-separated integers: A_j B_j L_j, where A_j and B_j are indices in the range 1..N indicating the fields joined by the pathway, and L_j is the length of the pathway (in the range 1...1,000,000).</li></ul>

### 출력 

 <ul><li>Line 1: The maximum possible increase in the total length of FJ's shortest route made possible by doubling the length of a single pathway.</li></ul>

