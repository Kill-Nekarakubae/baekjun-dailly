//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/31.
//

import Foundation

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let M = input[0]
let N = input[1]
var banner: [[Int]] = []
for _ in 0..<M {
    let line = readLine()!.split(separator: " ").map{ Int($0)! }
    banner.append(line)
}

let dy = [-1, 1, 0, 0, -1, -1, 1, 1]
let dx = [0, 0, -1, 1, -1, 1, -1, 1]
// 대각선
var answer = 0

func searchChar() {
    while !stack.isEmpty {
        let (x, y) = stack.popLast()!
        for i in 0..<8 {
            let my = y + dy[i]
            let mx = x + dx[i]
            if 0..<M ~= my && 0..<N ~= mx && banner[my][mx] == 1 {
                banner[my][mx] = 0
                stack.append((x: mx, y: my))
            }
        }
    }
    answer += 1
}

var stack: [(x: Int, y: Int)] = []
for i in 0..<M {
    for j in 0..<N {
        if banner[i][j] == 1 {
            stack.append((x: j, y: i))
            searchChar()
        }
    }
}
print(answer)
