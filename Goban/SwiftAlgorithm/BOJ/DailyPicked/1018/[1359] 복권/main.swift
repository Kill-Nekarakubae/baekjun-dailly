//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/10/18.
//

import Foundation

// 2명이서 서로 다른 M 개의 수 뽑기 -> 적어도 K 개가 맞아야함.
// 최소 무조건 겹치는 수 -> K 를 감소.
// 겹치지 않는 나머지 수 / k = 뽑을 확률
// ex)
// 8개 중 2개를 뽑아서 1개가 겹칠 확률?
// 1. 모든 시행을 구해서 실제 겹친 횟수를 구한다.

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, M, K) = (input[0], input[1], input[2] )

// 지민의 모든 뽑기.
var result: [[Int]] = []
var stack = (1...N).enumerated().map { ([$0.element], $0.offset+1) }
while stack.count > 0 {
    let now = stack.removeLast()
    let elements = now.0
    let index = now.1
    if elements.count == M {
        result.append(elements)
        continue
    }
    guard index+1 <= N else { continue }
    
    for i in index+1...N {
        stack.append((elements + [i], i))
    }
}
// 다른 뽑기랑 검증
var parent = 0
var son = 0
for choice1 in result {
    for choice2 in result {
        parent += 1
        var choiceCnt = 0
        for element in choice1 {
            if choice2.contains(element) {
                choiceCnt += 1
            }
        }
        if choiceCnt >= K {
            son += 1
        }
    }
}
print(Double(son)/Double(parent))
