//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/14.
//

import Foundation

// 0: 검은방, 1: 흰방
let n = Int(readLine()!)!
var rooms: [[Int]] = [Array(repeating: 0, count: n+1)]
for _ in 0..<n {
    let line = [0] + readLine()!.map{ Int(String($0))! }
    rooms.append(line)
}

var visitedCnt = Array(repeating: Array(repeating: Int.max, count: n+1), count: n+1)

// bestFirstSearch
// heap 으로 낮은대로 정렬 -> 개선사항.
var stack: [(cnt: Int, x: Int, y: Int)] = []
stack.append((cnt: 0, x: 1, y: 1))
let dy = [1, -1, 0, 0]
let dx = [0, 0, -1, 1]
var minCnt = Int.max

while !stack.isEmpty {
    let now = stack.removeLast()
    let (cnt, x, y) = (now.cnt, now.x, now.y)
    if cnt > minCnt {
        continue
    }
    if x == n && y == n {
        minCnt = min(minCnt, cnt)
        continue
    }
    for i in 0..<4 {
        let my = y + dy[i]
        let mx = x + dx[i]
        if 1...n ~= my && 1...n ~= mx {
            var visitCnt = cnt
            if rooms[my][mx] == 0 {
                visitCnt += 1
            }
            if visitedCnt[my][mx] <= visitCnt {
                continue
            }
            visitedCnt[my][mx] = visitCnt
            stack.append((cnt: visitCnt, x: mx, y: my))
        }
    }
    stack.sort { lhs, rhs in
        lhs.cnt > rhs.cnt
    }
}

print(minCnt)
