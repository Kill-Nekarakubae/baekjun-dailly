//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/15.
//

import Foundation

let N = Int(readLine()!)!
let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (A, B) = (input[0], input[1])
struct Node: Hashable {
    let x: Int
    let y: Int
    init(_ x: Int,_ y: Int) {
        self.x = x
        self.y = y
    }
}
var nodes = Set<Node>()
for _ in 0..<N {
    let node = readLine()!.split(separator: " ").map{ Int($0)! }
    nodes.insert(Node(node[0], node[1]))
}
var cnt = 0
for node in nodes {
    let rightUp = Node(node.x + A, node.y)
    let leftDown = Node(node.x, node.y + B)
    let rightDown = Node(node.x + A, node.y + B)
    if !nodes.contains(rightUp) || !nodes.contains(leftDown) || !nodes.contains(rightDown) {
        continue
    }
    cnt += 1
}

print(cnt)
