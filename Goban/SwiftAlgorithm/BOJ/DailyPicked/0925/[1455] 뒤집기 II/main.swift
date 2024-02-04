//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/25.
//

import Foundation

// 뒤집는 곳을 어떻게 선정하는가.
// 가장 모서리에서 안쪽으로 ->->
// 모서리의 같은 레벨에서는 순서 상관 x

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, M) = (input[0], input[1])
var board: [[Int]] = [[]]
for _ in 0..<N {
    let line = [0] + readLine()!.map{ Int(String($0))! }
    board.append(line)
}

var corner = (N, M)
func checkIsCompleted() -> Bool {
    for i in 1...N {
        for j in 1...M {
            if board[i][j] == 1 {
                return false
            }
        }
    }
    return true
}

func reverseBoard(a: Int, b: Int) {
    for i in 1...a {
        for j in 1...b {
            board[i][j] = board[i][j] == 0 ? 1 : 0
        }
    }
}
var count = 0
func solution() {
    // 세로
    for i in stride(from: corner.0, through: 1, by: -1) {
        for j in stride(from: corner.1, through: 1, by: -1) {
            if board[i][j] == 1 {
                count += 1
                reverseBoard(a: i, b: j)
                if checkIsCompleted() {
                    return
                }
            }
        }
    }
}

solution()
print(count)
