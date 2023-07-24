//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/22.
//

import Foundation

// 리프 노드까지의 간선의 depth 를 탐색
let N = Int(readLine()!)!
var graph: [[Int]]  = Array(repeating: [] ,count: N+1)
var visited = Array(repeating: false, count: N+1)
for _ in 0..<N-1 {
    let info = readLine()!.split(separator: " ").map{ Int($0)! }
    graph[info[0]].append(info[1])
    graph[info[1]].append(info[0])
}

var stack: [(depth: Int, node: Int)] = []
stack.append((0, 1))
visited[1] = true
var totalDepthCnt = 0
while !stack.isEmpty {
    let element = stack.removeLast()
    let depth = element.depth
    let node = element.node
    
    var isLeaf = true
    for nextNode in graph[node] {
        if !visited[nextNode] {
            isLeaf = false
            visited[nextNode] = true
            stack.append((depth: depth + 1, node: nextNode))
        }
    }
    if isLeaf {
        totalDepthCnt += depth
    }
}

if totalDepthCnt % 2 == 1 {
    print("Yes")
} else {
    print("No")
}
