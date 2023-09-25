//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/14.
//

import Foundation

// 플로이드 워샬
let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, M) = (input[0], input[1])
var board: [[Int]] = [[]]
for _ in 0..<N {
    let line = [0] + readLine()!.split(separator: " ").map{ Int($0)! }
    board.append(line)
}
var people: [[Int]] = []
for _ in 0..<M {
    let line = readLine()!.split(separator: " ").map{ Int($0)! }
    people.append(line)
}
for i in 1...N {
    for j in 1...N {
        for k in 1...N {
            if board[j][i] == 0 || board[i][k] == 0 {
                continue
            }
            board[j][k] = min(board[j][i] + board[i][k], board[j][k])
        }
    }
}

for person in people {
    let (a, b, c) = (person[0], person[1], person[2])
    if board[a][b] <= c {
        print("Enjoy other party")
    } else {
        print("Stay here")
    }
}
