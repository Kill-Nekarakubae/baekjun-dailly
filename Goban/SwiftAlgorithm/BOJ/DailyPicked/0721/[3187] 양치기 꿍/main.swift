//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/21.
//

import Foundation

// 늑대 >= 양 -> 양 = 0
// 늑대 < 양 -> 늑대 = 0
// 영역 마다 늑대와 양의 수를 count 한다.
// for문으로 visited 점검, DFS 로 영역 모두 탐색, count.

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let R = input[0]
let C = input[1]
var board: [[String]] = []
var isVisited = Array(repeating: Array(repeating: false, count: C), count: R)
for _ in 0..<R {
    let line = readLine()!.map{String($0)}
    board.append(line)
}

let dx = [0,0,-1,1]
let dy = [-1,1,0,0]
func DFS(x: Int, y: Int) -> (shipCnt:Int, wolfCnt: Int){
    var positionStack: [(x: Int, y: Int)] = [(x:x, y: y)]
    isVisited[y][x] = true
    var shipCnt = 0
    var wolfCnt = 0
    while(!positionStack.isEmpty) {
        let position = positionStack.popLast()!
        for i in 0..<4 {
            let mx = position.x + dx[i]
            let my = position.y + dy[i]
            if 0..<R ~= my && 0..<C ~= mx && board[my][mx] != "#" && !isVisited[my][mx] {
                if board[my][mx] == "v" {
                    wolfCnt += 1
                } else if board[my][mx] == "k" {
                    shipCnt += 1
                }
                isVisited[my][mx] = true
                positionStack.append((x: mx, y: my))
            }
        }
    }
    // 남은 양과 늑대
    if wolfCnt >= shipCnt {
        shipCnt = 0
    } else {
        wolfCnt = 0
    }
    return (shipCnt, wolfCnt)
}

var remainWolf = 0
var remainShip = 0

for i in 0..<R {
    for j in 0..<C {
        if !isVisited[i][j] {
            // 탐색
            let result = DFS(x: j, y: i)
            remainShip += result.shipCnt
            remainWolf += result.wolfCnt
        }
    }
}

print("\(remainShip) \(remainWolf)")
