//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/10/30.
//

import Foundation

// 플로이드 와샬 -> 모든 간선의 최소 길이를 구함
// 각각의 노드에서 도시마다 왕복시간을 구함
// 구한 왕복 시간의 합이 최소가 되는 도시를 선정.
// p: [[Int]] = 도시의 그래프

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, M) = (input[0], input[1])
var p = Array(repeating: Array(repeating: Int.max, count: N+1), count: N+1)
for _ in 0..<M {
    let line = readLine()!.split(separator: " ").map{ Int($0)! }
    let (a, b, cost) = (line[0], line[1], line[2])
    p[a][b] = cost
}

let K = Int(readLine()!)!
var firendsCity: [Int] = []
readLine()!.split(separator: " ").map{ Int($0)! }.forEach { city in
    firendsCity.append(city)
}

for k in 1...N {
    for i in 1...N {
        for j in 1...N {
            if p[i][k] == Int.max || p[k][j] == Int.max {
                continue
            }
            if i == j {
                p[i][j] = 0
                continue
            }
            p[i][j] = min(p[i][j], p[i][k] + p[k][j])
        }
    }
}

var roundTime: [[Int]] = Array(repeating: [Int](), count: N+1)

for city in firendsCity {
    for j in 1...N {
        if p[city][j] != Int.max && p[j][city] != Int.max {
            roundTime[j].append(p[city][j] + p[j][city])
        }
    }
}

var answer: [Int] = []
var minSum = Int.max
for i in 1...N {
    let timeSum = roundTime[i].max()!
    if minSum >= timeSum {
        if minSum > timeSum {
            answer.removeAll()
        }
        minSum = min(minSum, timeSum)
        answer.append(i)
    }
}

print(answer.sorted(by: <).map{ String($0) }.joined(separator: " "))
