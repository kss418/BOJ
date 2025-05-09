# [Gold II] Wormholes - 9874 

[문제 링크](https://www.acmicpc.net/problem/9874) 

### 성능 요약

메모리: 2028 KB, 시간: 4 ms

### 분류

백트래킹, 브루트포스 알고리즘, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 5월 9일 14:13:37

### 문제 설명

<p>Farmer John's hobby of conducting high-energy physics experiments on weekends has backfired, causing N wormholes (2 <= N <= 12, N even) to materialize on his farm, each located at a distinct point on the 2D map of his farm.</p><p>According to his calculations, Farmer John knows that his wormholes will form N/2 connected pairs.  For example, if wormholes A and B are connected as a pair, then any object entering wormhole A will exit wormhole B moving in the same direction, and any object entering wormhole B will similarly exit from wormhole A moving in the same direction.  This can have rather unpleasant consequences.  For example, suppose there are two paired wormholes A at (0,0) and B at (1,0), and that Bessie the cow starts from position (1/2,0) moving in the +x direction.  Bessie will enter wormhole B, exit from A, then enter B again, and so on, getting trapped in an infinite cycle!</p><p>Farmer John knows the exact location of each wormhole on his farm.  He knows that Bessie the cow always walks in the +x direction, although he does not remember where Bessie is currently located.  Please help Farmer John count the number of distinct pairings of the wormholes such that Bessie could possibly get trapped in an infinite cycle if she starts from an unlucky position.</p>

### 입력 

 <ul><li>Line 1: The number of wormholes, N.</li><li>Lines 2..1+N: Each line contains two space-separated integers describing the (x,y) coordinates of a single wormhole.  Each coordinate is in the range 0..1,000,000,000.</li></ul>

### 출력 

 <ul><li>Line 1: The number of distinct pairings of wormholes such that Bessie could conceivably get stuck in a cycle walking from some starting point in the +x direction.</li></ul>

