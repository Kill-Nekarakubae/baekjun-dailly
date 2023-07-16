//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/16.
//

import Foundation

// 지훈이 먼저 이동 -> 불 확산
let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
let R = input[0]
let C = input[1]
var board: [[String]] = []
var jihunPositions: [(x: Int, y: Int, cnt: Int)] = []
var fireList: [(x: Int, y: Int)] = []
var visited = Array(repeating: Array(repeating: false, count: C), count: R)

let dx = [0,0,-1,1]
let dy = [-1,1,0,0]

for i in 0..<R {
    let line = readLine()!.map{ String($0) }
    for j in 0..<C {
        if line[j] == "J" {
            jihunPositions.append((x: j, y: i, cnt: 0))
        }
        if line[j] == "F" {
            fireList.append((x: j, y: i))
        }
    }
    board.append(line)
}
var tempJihunPositions: [(x: Int, y: Int, cnt: Int)] = []
var minCount = Int.max
func BFS() {
    // 가장자리인지 체크
    while !jihunPositions.isEmpty {
        var tempFireList: [(x: Int , y: Int)] = []
        for fire in fireList {
            for j in 0..<4 {
                let fx = fire.x + dx[j]
                let fy = fire.y + dy[j]
                if 0..<R ~= fy && 0..<C ~= fx {
                    if board[fy][fx] == "." {
                        board[fy][fx] = "F"
                        tempFireList.append((x: fx, y: fy))
                    }
                }
            }
        }
        fireList = tempFireList
        while !jihunPositions.isEmpty {
            let position = jihunPositions.removeFirst()
            let x = position.x
            let y = position.y
            let positionCnt = position.cnt
            visited[y][x] = true
            
            if y == 0 || y == R-1 {
                minCount = positionCnt + 1
                return
            } else if x == 0 || x == C-1 {
                minCount = positionCnt + 1
                return
            }

            for i in 0..<4 {
                let mx = x + dx[i]
                let my = y + dy[i]
                // jihun can move
                if 0..<R ~= my && 0..<C ~= mx && !visited[my][mx] && board[my][mx] == "." {
                    tempJihunPositions.append((x: mx, y: my, cnt: positionCnt + 1))
                    visited[my][mx] = true
                    board[my][mx] = "J"
                }
            }
        }
        jihunPositions = tempJihunPositions
        tempJihunPositions.removeAll()
    }

}
BFS()

if minCount == Int.max {
    print("IMPOSSIBLE")
} else {
    print(minCount)
}


//func DFS(x: Int, y:Int, fireList: [(x: Int, y: Int)] ,cnt: Int) {
//    // 가장자리인지 체크
//    if y == 0 || y == R-1 {
//        minCount = min(minCount, cnt+1)
//        return
//    } else if x == 0 || x == C-1 {
//        minCount = min(minCount, cnt+1)
//        return
//    }
//
//    var tempFireList: [(x: Int , y: Int)] = []
//    for fire in fireList {
//        for j in 0..<4 {
//            let fx = fire.x + dx[j]
//            let fy = fire.y + dy[j]
//            if 0..<R ~= fy && 0..<C ~= fx {
//                if board[fy][fx] == "."{
//                    board[fy][fx] = "F"
//                    tempFireList.append((x: fx, y: fy))
//                }
//            }
//        }
//    }
//
//    for i in 0..<4 {
//        let mx = x + dx[i]
//        let my = y + dy[i]
//        // jihun can move
//        if 0..<R ~= my && 0..<C ~= mx && board[my][mx] == "." {
//            board[my][mx] = "K"
//            DFS(x: mx, y: my, fireList: tempFireList, cnt: cnt + 1)
//            if minCount <= cnt + 1 {
//                return
//            }
//            board[my][mx] = "."
//            for firePosition in tempFireList {
//                board[firePosition.y][firePosition.x] = "."
//            }
//        }
//    }
//}
//
//DFS(x: jihunPosition.x, y: jihunPosition.y, fireList: fireList , cnt: 0)
//
//if minCount == Int.max {
//    print("IMPOSSIBLE")
//} else {
//    print(minCount)
//}
