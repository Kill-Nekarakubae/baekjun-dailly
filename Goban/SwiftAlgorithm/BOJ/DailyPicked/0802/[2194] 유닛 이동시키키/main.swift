//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/02.
//

import Foundation

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, M, A, B, K) = (input[0], input[1], input[2], input[3], input[4])
//var obstacles: [(x: Int, y: Int)] = []
// 0 통과 1 장애물 2 도착
var board: [[Int]] = Array(repeating: Array(repeating: 0, count: M+1), count: N+1)
for _ in 0..<K {
    let line = readLine()!.split(separator: " ").map{ Int($0)! }
    board[line[0]][line[1]] = 1
}
let start = readLine()!.split(separator: " ").map{ Int($0)! }
let end = readLine()!.split(separator: " ").map{ Int($0)! }
board[end[0]][end[1]] = 2

var deque: [(x: Int, y: Int, cnt: Int)] = []
deque.append((x: start[1], y: start[0], cnt: 0))

var visited = Array(repeating: Array(repeating: false, count: M+1), count: N+1)
var minCount = Int.max
let dy = [-1, 1, 0, 0]
let dx = [0, 0, -1, 1]
func BFS() {
    while !deque.isEmpty {
        let (x, y, cnt) = deque.removeFirst()
        visited[y][x] = true
        if board[y][x] == 2 {
            print(cnt)
            minCount = min(cnt, minCount)
            return
        }
        for k in 0..<4 {
            let mx = x + dx[k]
            let my = y + dy[k]
            if 1...N-A+1 ~= my && 1...M-B+1 ~= mx && !visited[my][mx] && board[my][mx] != 1{
                visited[my][mx] = true
                var isExist = true
                for i in my...my+(A-1) {
                    for j in mx...mx+(B-1) {
                        if 1...N ~= i && 1...M ~= j {
                            if board[i][j] == 1 {
                                isExist = false
                                break
                            }
                        } else {
                            isExist = false
                            break
                        }
                    }
                }
                if isExist {
                    deque.append((x: mx, y: my, cnt: cnt+1))
                }
            }
        }
    }

}
BFS()
if minCount == Int.max {
    print("-1")
}
