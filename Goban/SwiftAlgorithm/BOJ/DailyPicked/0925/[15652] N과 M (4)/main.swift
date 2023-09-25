//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/25.
//

import Foundation

// 사전순으로 증가 -> 백트래킹으로 구현.

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, M) = (input[0], input[1])
var answer: [Int] = []

func backTraking(num: Int) {
    if answer.count == M {
        print(answer.map{ String($0) }.joined(separator: " ") )
        return
    }
    for i in num...N {
        answer.append(i)
        backTraking(num: i)
        answer.removeLast()
    }
}

backTraking(num: 1)
