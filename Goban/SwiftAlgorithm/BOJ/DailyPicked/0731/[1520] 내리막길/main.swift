//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/31.
//

import Foundation

// 모든 방향으로 가는데, 해당 방향 visit 한적 있으면, 이동할때 적은 cost 라면 이동.

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let M = input[0]
let N = input[1]
var board: [[Int]] = []
for _ in 0..<M {
    let line = readLine()!.split(separator: " ").map{ Int($0)! }
    board.append(line)
}

let dy = [-1, 1, 0, 0]
let dx = [0, 0, -1, 1]
var stack: [(x: Int, y: Int, cost: Int)] = []
stack.append((x: 0, y: 0, cost: 0))
var visited = Array(repeating: Array(repeating: Int.max, count: N), count: M)

func BFS() {
    while !stack.isEmpty {
        let (x, y, cost) = stack.popLast()!
        let mCost = cost + board[y][x]
        for i in 0..<4 {
            let mx = x + dx[i]
            let my = y + dy[i]
            if 0..<M ~= my && 0..<N ~= mx && visited[my][mx] > mCost {
                visited[my][mx] = mCost
                stack.append((x: mx, y: my, cost: mCost))
            }
        }
    }
}
BFS()
print(visited[M-1][N-1])
