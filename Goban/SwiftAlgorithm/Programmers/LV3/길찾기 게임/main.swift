//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/01.
//

import Foundation

func solution(_ nodeinfo:[[Int]]) -> [[Int]] {
    var sortedNodeinfo = nodeinfo.enumerated().map{ ($0+1, $1) }.sorted { lhs, rhs in
        if lhs.1[1] == rhs.1[1] {
            return lhs.1[0] > rhs.1[0]
        }
        return lhs.1[1] < rhs.1[1]
    }
    var parentNodes: [Node] = []
    var sameLevelNodes: [Node] = []
    while !sortedNodeinfo.isEmpty {
        let nodeInfo = sortedNodeinfo.removeLast()
        var node = Node(num: nodeInfo.0, x: nodeInfo.1[0], y: nodeInfo.1[1])
        sameLevelNodes.append(node)
        while !sortedNodeinfo.isEmpty && sortedNodeinfo.last!.1[1] == nodeInfo.1[1] {
            let sameLevelNode = sortedNodeinfo.removeLast()
            node = Node(num: sameLevelNode.0, x: sameLevelNode.1[0], y: sameLevelNode.1[1])
            sameLevelNodes.append(node)
        }
//         for node in sameLevelNodes {
//             for parentNode in parentNodes {
//                 if parentNode.left == nil {
//                     if parentNode.x > node.1[0] {
//                         parentNode
//                         continue
//                     }
//                 }
//                 if parentNode.right == nil {
                    
//                 }
//             }
//         }
        print(sameLevelNodes)
        sameLevelNodes = []
    }
    // 노드 생성의 규칙
    // 1. 가장 y 값이 큰 노드 = 가장 상위의 P 부모노드
    // 2. 왼쪽, 오른쪽: 부모 노드보다 작고 y 값이 가장 큰 노드 = p 부모 노드
    // 3. 범위: 왼쪽: 부모노드 < x, 오른쪽: 부모노드 > x
    // 반복해서 생성.
    //
    // 전위, 후위 순회 배열 생성
    // 전위 배열: 생성할때 그대로 추가. (왼쪽 -> 오른쪽으로 DFS 를 사용해서 생성)
    // 후위 배열: 왼쪽, 오른쪽 재귀. 배열 추가.
    return []
}

// func makeNodeGraph() -> Node {
//     // nodeinfo.
// }

class Node {
    let num: Int
    let x: Int
    let y: Int
    let parent: Node?
    let leftNode: Node?
    let rightNode: Node?
    
    init (num: Int, x: Int, y: Int, parent: Node? = nil, leftNode: Node? = nil, rightNode: Node? = nil) {
        self.num = num
        self.x = x
        self.y = y
        self.parent = parent
        self.leftNode = leftNode
        self.rightNode = rightNode
    }
}
