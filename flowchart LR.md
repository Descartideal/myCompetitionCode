flowchart LR
%% =========================
%% ACM / ICPC Knowledge DAG (>=100 nodes)
%% Copy into any Mermaid renderer (Markdown supported)
%% =========================

A0([Start: C++/Python Basics])

subgraph F[Foundations]
F01[Big-O & Complexity]
F02[Amortized Analysis]
F03[Recursion]
F04[Iterative Thinking]
F05[Bit Operations]
F06[STL Basics (vector/map/set)]
F07[Fast I/O]
F08[Sorting]
F09[Binary Search]
F10[Two Pointers]
F11[Prefix Sums]
F12[Difference Array]
F13[Coordinate Compression]
F14[Greedy Basics]
F15[Divide & Conquer]
end

subgraph DS[Data Structures]
D01[Arrays & Vectors]
D02[Linked List (concept)]
D03[Stack]
D04[Queue]
D05[Deque]
D06[Priority Queue / Heap]
D07[Hash Table]
D08[Ordered Set/Map (RB-tree)]
D09[Disjoint Set Union (DSU)]
D10[Fenwick Tree (BIT)]
D11[Segment Tree]
D12[Lazy Segment Tree]
D13[Sparse Table (RMQ)]
D14[Sqrt Decomposition]
D15[Mo's Algorithm]
D16[Treap]
D17[Splay Tree]
D18[Persistent Segment Tree]
D19[Persistent Fenwick (optional)]
D20[Li Chao Tree]
D21[Convex Hull Trick DS]
D22[Segment Tree Beats]
D23[Order-Statistic Tree (PBDS)]
D24[Bitset Optimization]
D25[Offline Queries & Sorting by Key]
D26[DSU Rollback]
D27[Merge-Sort Tree]
D28[Wavelet Tree]
D29[Cartesian Tree]
D30[Binary Indexed Tree 2D]
D31[Segment Tree 2D]
end

subgraph G[Graph Theory]
G01[Graph Representation]
G02[DFS]
G03[BFS]
G04[Topological Sort]
G05[Shortest Path Basics]
G06[Dijkstra]
G07[0-1 BFS]
G08[Bellman-Ford]
G09[Floyd-Warshall]
G10[Johnson's Algorithm]
G11[Minimum Spanning Tree]
G12[Kruskal]
G13[Prim]
G14[Union-Find for MST]
G15[Tree Basics (rooted)]
G16[LCA: Binary Lifting]
G17[LCA: Euler Tour + RMQ]
G18[Tree Diameter]
G19[Heavy-Light Decomposition (HLD)]
G20[Virtual Tree]
G21[DSU on Tree (Small-to-Large)]
G22[Centroid Decomposition]
G23[Long Chain Decomposition]
G24[Link-Cut Tree (LCT)]
G25[Strongly Connected Components]
G26[Kosaraju SCC]
G27[Tarjan SCC]
G28[2-SAT]
G29[Biconnected Components]
G30[Bridges & Articulation Points]
G31[Eulerian Trail/Circuit]
G32[Bipartite Graph Basics]
G33[Hopcroft–Karp Matching]
G34[Hungarian (Assignment)]
G35[Max Flow]
G36[Dinic]
G37[Min-Cost Max-Flow]
G38[Min-Cut / Max-Flow Min-Cut]
G39[Flow with Lower Bounds]
G40[Min-Cost Flow potentials]
G41[Directed MST (Edmonds)]
G42[Shortest Path DAG DP]
G43[Graph DP / Tree DP crossover]
end

subgraph DP[Dynamic Programming]
P01[DP Mindset & State Design]
P02[Memoization (DFS DP)]
P03[Knapsack 0/1]
P04[Unbounded Knapsack]
P05[Bounded Knapsack]
P06[Bitset Knapsack]
P07[LIS (O(n log n))]
P08[LCS / Edit Distance]
P09[Interval DP]
P10[DP on DAG]
P11[Tree DP]
P12[Rerooting DP]
P13[Digit DP]
P14[Probability DP]
P15[Expected Value Tricks]
P16[Bitmask DP]
P17[SOS DP]
P18[Divide&Conquer DP Opt]
P19[Knuth Optimization]
P20[Convex Hull Trick DP]
P21[Slope Trick]
P22[Monotone Queue Optimization]
P23[Aliens Trick (Lagrangian)]
P24[DP with FFT/NTT Convolution]
P25[DP with Meet-in-the-Middle]
end

subgraph M[Math]
M01[Modular Arithmetic]
M02[Fast Exponentiation]
M03[GCD & Euclid]
M04[Extended GCD]
M05[Mod Inverse]
M06[Mod Factorial / nCk]
M07[Combinatorics Precompute]
M08[Lucas Theorem]
M09[Chinese Remainder Theorem]
M10[Prime Sieve]
M11[Prime Factorization]
M12[Euler Phi Function]
M13[Möbius Function]
M14[Divisor Summatory / Harmonic Lemma]
M15[Inclusion-Exclusion]
M16[Generating Functions (basic)]
M17[Matrix Exponentiation]
M18[Linear Recurrence / Kitamasa]
M19[FFT Convolution]
M20[NTT Convolution]
M21[Polynomial Inversion/Exp/Log]
M22[Berlekamp–Massey]
M23[Gaussian Elimination]
M24[Linear Basis (XOR)]
M25[Discrete Log (BSGS)]
M26[Cipolla (sqrt mod p)]
M27[Primality Test (Miller-Rabin)]
M28[Factorization (Pollard Rho)]
M29[Game Theory (Nim, SG)]
M30[Burnside / Polya]
end

subgraph S[String Algorithms]
S01[String Basics & Indexing]
S02[Rolling Hash]
S03[KMP / Prefix Function]
S04[Z-Algorithm]
S05[Trie]
S06[Aho–Corasick]
S07[Suffix Array]
S08[LCP (Kasai)]
S09[Suffix Automaton]
S10[Palindromic Tree (Eertree)]
S11[Manacher]
S12[Minimal Rotation]
S13[Lyndon Decomposition (Duval)]
S14[String DP (pal/subseq)]
S15[Offline Pattern Queries]
end

subgraph CG[Computational Geometry]
C01[Geometry Basics (eps, types)]
C02[Vectors: dot/cross]
C03[Orientation / CCW]
C04[Line & Segment Intersection]
C05[Distance (point-line/segment)]
C06[Polygon Area (Shoelace)]
C07[Point in Polygon]
C08[Convex Hull]
C09[Rotating Calipers]
C10[Half-plane Intersection]
C11[Closest Pair of Points]
C12[Circle Intersections]
C13[Convex Polygon Tricks]
C14[Minkowski Sum]
C15[3D Geometry Basics]
end

subgraph Misc[Misc / Meta Techniques]
X01[Brute Force & Pruning]
X02[Backtracking]
X03[Meet-in-the-Middle]
X04[Randomized (hash/treap)]
X05[Binary Lifting (general)]
X06[Offline vs Online Strategy]
X07[Coordinate Geometry + Sweeping]
X08[Simulation & Implementation]
X09[Interactive Problems Tactics]
X10[Optimization: constant factors]
end

%% ============ Edges (Dependencies) ============
A0-->F01-->F02
A0-->F06-->F07
A0-->F08-->F09
A0-->F03-->F15
F04-->F10
F11-->F12-->F13
F14-->X01

%% DS deps
F06-->D01
D01-->D03-->D04-->D05
D01-->D06
F06-->D07
F06-->D08-->D23
D01-->D11-->D12-->D22
D01-->D10-->D30
D11-->D31
F08-->D25-->D15
D14-->D15
D11-->D27
D01-->D29
D11-->D18
D10-->D19
F15-->D28
F01-->D14
F05-->D24

%% Graph deps
D01-->G01
F03-->G02
G01-->G03
G02-->G15
G15-->G16
G15-->G17
G15-->G18
G16-->G19
D11-->G19
G16-->G20
G02-->G25
G25-->G26
G25-->G27
G27-->G28
G02-->G29-->G30
G03-->G31
G05-->G06
G03-->G07
G05-->G08-->G09-->G10
G11-->G12
G11-->G13
D09-->G14-->G12
G32-->G33
G32-->G34
G35-->G36-->G38
G36-->G37-->G40
G36-->G39
G04-->G42-->G10
G15-->G43

%% Tree advanced deps
G15-->G21
G15-->G22
G15-->G23
G15-->G24
D17-->G24
G21-->G23

%% DP deps
F03-->P02-->P01
F11-->P01
F15-->P18
P01-->P03-->P05
P03-->P04
P03-->P06
P01-->P07
P01-->P08
P01-->P09
G04-->P10
G15-->P11-->P12
P01-->P13
P01-->P14-->P15
F05-->P16-->P17
P01-->P22
P20-->P21
P01-->P20
P01-->P23
M19-->P24
X03-->P25

%% Math deps
F05-->M01
M01-->M02
M03-->M04-->M05-->M06-->M07
M07-->M08
M04-->M09
M10-->M11
M10-->M12
M10-->M13
F01-->M14
M07-->M15
M15-->M16
M02-->M17-->M18
M19-->M20-->M21-->M22
M01-->M23
F05-->M24
M05-->M25-->M26
M27-->M28
M29-->M30

%% Strings deps
S01-->S02
S01-->S03
S01-->S04
S01-->S05-->S06
S01-->S07-->S08
S07-->S09
S01-->S10-->S11
S01-->S12
S01-->S13
P01-->S14
D25-->S15

%% Geometry deps
C01-->C02-->C03
C03-->C04-->C05
C02-->C06
C06-->C07
C02-->C08-->C09
C08-->C13-->C14
C04-->C10
F15-->C11
C02-->C12
C02-->C15

%% Misc deps
F03-->X02
F15-->X03
F05-->X04
G16-->X05
D25-->X06
C02-->X07
F04-->X08
X08-->X10
