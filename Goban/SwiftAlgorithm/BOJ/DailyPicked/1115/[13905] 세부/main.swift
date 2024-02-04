//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/15.
//

import Foundation

let NM = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, M) = (NM[0], NM[1])
let se = readLine()!.split(separator: " ").map{ Int($0)! }
let (s, e) = (se[0], se[1])

var bridges: [(h1: Int, h2: Int, k: Int)] = []
for _ in 0..<M {
    let bridge = readLine()!.split(separator: " ").map{ Int($0)! }
    let h1 = bridge[0]
    let h2 = bridge[1]
    let k = bridge[2]
    bridges.append((h1: h1, h2: h2, k: k))
}
bridges.sort { lhs, rhs in
    lhs.k > rhs.k
}
var unions = Array(repeating: -1, count: N+1)
var minCnt = Int.max
func root(of n:Int) -> Int{
    if unions[n] < 0 {return n}
    unions[n] = root(of: unions[n])
    return unions[n]
}

func union(a:Int, b:Int, k:Int){
    let rootA = root(of: a)
    let rootB = root(of: b)
    if rootA == rootB{ return }
    unions[rootB] = rootA
    minCnt = min(minCnt, k)
}

for bridge in bridges {
    if root(of: s) == root(of: e) {
        break
    }
    union(a: bridge.h1, b: bridge.h2, k: bridge.k)
}
print(root(of: s)==root(of: e) ? minCnt:0)
