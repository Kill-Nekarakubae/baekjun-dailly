//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/11.
//

import Foundation

// DFS
// 방향 3가지, 전에 왔던 위치도 저장 필요.
// 크기가 작아서 따로 뭔가 처리는 안해도 될듯함.

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let N = input[0]
let M = input[1]
var board: [[Int]] = []
for _ in 0..<N {
    let line = readLine()!.split(separator: " ").map{ Int($0)! }
    board.append(line)
}

let dx = [-1, 0, 1]
let dy = [1, 1, 1]

enum Direction: Int {
    case leftDown = 0
    case center = 1
    case rightDown = 2
    case whatever = 3
}

var minConsume = Int.max

func DFS(x: Int, y: Int, direction: Direction, consume: Int) {
    // 완료조건
    if y == N-1 {
        minConsume = min(minConsume, consume)
        return
    }
    for i in 0..<3 {
        let mx = x + dx[i]
        let my = y + dy[i]
        if 0..<N ~= my && 0..<M ~= mx {
            if Direction(rawValue: i) != direction {
                DFS(x: mx, y: my, direction: Direction(rawValue: i)!, consume: consume + board[my][mx])
            }
        }
    }
}

for start in 0..<M {
    DFS(x: start, y: 0, direction: .whatever, consume: board[0][start])
}
print(minConsume)
