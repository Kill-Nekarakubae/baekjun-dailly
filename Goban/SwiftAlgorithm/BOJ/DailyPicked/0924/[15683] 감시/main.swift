//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/24.
//

import Foundation
// 입력
let nm = readLine()!.split(separator: " ").map{ Int(String($0))! }
let (n,m) = (nm[0], nm[1])
var graph = [[Int]](repeating: [Int](repeating: 0, count: m), count: n)
for i in 0 ..< n {
    let input = readLine()!.split(separator: " ").map{ Int(String($0))! }
    graph[i] = input
}

// 풀이
var cctvList = [(Int,Int,Int)]()    // (cctv종류, x, y)
var originBlindCnt: Int = 0
for i in 0 ..< n {
    for j in 0 ..< m {
        if 1 <= graph[i][j], graph[i][j] <= 5 {
            cctvList.append((graph[i][j], i, j))
        } else if graph[i][j] == 0 {
            originBlindCnt += 1
        }
    }
}

let dx = [-1, 0, 1, 0]
let dy = [0, 1, 0, -1]

func watch(_ tempGraph: inout [[Int]], _ xy: (Int, Int), _ dir: Int) -> Int {
    var coverCnt = 0
    
    var nx = xy.0 + dx[dir]
    var ny = xy.1 + dy[dir]
    while 0 <= nx, nx < n, 0 <= ny, ny < m, tempGraph[nx][ny] != 6 {
        if tempGraph[nx][ny] == 0 {
            tempGraph[nx][ny] = -1
            coverCnt += 1
        }
        nx += dx[dir]
        ny += dy[dir]
    }
    
    return coverCnt
}

func cctvWatch(_ tempGraph: inout [[Int]], _ cctvNum: Int, _ xy: (Int, Int), _ dir: Int) -> Int {
    var coverCnt = 0
    
    switch cctvNum {
    case 1:
        coverCnt += watch(&tempGraph, xy, dir)
    case 2:
        coverCnt += watch(&tempGraph, xy, dir % 4)
        coverCnt += watch(&tempGraph, xy, (dir + 2) % 4)
    case 3:
        for i in 0 ..< 2 {
            coverCnt += watch(&tempGraph, xy, (dir + i) % 4)
        }
    case 4:
        for i in 0 ..< 3 {
            coverCnt += watch(&tempGraph, xy, (dir + i) % 4)
        }
    default:
        for i in 0 ..< 4 {
            coverCnt += watch(&tempGraph, xy, (dir + i) % 4)
        }
    }
    
    return coverCnt
}

var result = Int(1e9)
func dfs(_ depth: Int, _ tempGraph: [[Int]], _ coverCnt: Int) {
    // 종료 조건
    if depth == cctvList.count {
        let blindCnt = originBlindCnt - coverCnt
        result = min(result, blindCnt)
        return
    }
    
    var nowGraph = tempGraph
    let now = cctvList[depth]
    for d in 0 ..< 4 {
        let cctvNum = now.0
        let xy = (now.1, now.2)
        
        let nowCoverCnt = cctvWatch(&nowGraph, cctvNum, xy, d)
        dfs(depth + 1, nowGraph, coverCnt + nowCoverCnt)
        
        nowGraph = tempGraph
    }
}

dfs(0, graph, 0)

// 출력
print(result)
