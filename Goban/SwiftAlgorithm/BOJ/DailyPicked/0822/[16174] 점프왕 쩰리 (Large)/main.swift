//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/22.
//

import Foundation

// DFS 로 탐색. 
let N = Int(readLine()!)!
var board: [[Int]] = [[]]
for _ in 0..<N {
    let line = [0] + readLine()!.split(separator: " ").map{ Int($0)! }
    board.append(line)
}
var isVisited = Array(repeating: Array(repeating: Array(repeating: false, count: N+1), count: N+1), count: 2)

let dy = [0, 1]
let dx = [1, 0]
var canClear = false

func DFS(x: Int, y: Int) {
    if x == N && y == N {
        canClear = true
        return
    }
    
    let canMove = board[y][x]
    for i in 0..<2 {
        let my = y + dy[i]*canMove
        let mx = x + dx[i]*canMove
        
        if 1...N ~= my && 1...N ~= mx && !isVisited[i][my][mx] && !canClear {
            isVisited[i][my][mx] = true
            DFS(x: mx, y: my)
        }
    }
}

DFS(x: 1, y: 1)

if canClear {
    print("HaruHaru")
} else {
    print("Hing")
}
