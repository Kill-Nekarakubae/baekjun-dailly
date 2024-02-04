//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/10/19.
//

import Foundation

// 전위 순회한 결과를 준다.
// 트리의 구성:
// [50, 30, 98, 24, 45, 52, 5, 28, 60]
// 전위 순회시:
// 50 30 24, 5, 28, 45, 98, 52, 60
// 후위 순회시:
// 5, 28, 24, 45, 30, 60, 52, 98, 50

// 우선 생각나는 방법:
// 전위 순회결과에 따라 트리를 재구성
// -> 후위 순회 출력

// '검색' 트리의 특성을 이용.
// case1 작은값이 계속 나오면 -> 부모노드 왼쪽 서브트리에 계속 추가
// case2 큰값이 나오면 -> 부모노드 오른쪽 서브트리에 추가 (부모 노드로 계속 옮겨가면서)

// [50]
// [50, 30]
// [50, 30, 24] parent: 24
// [50, 30, 24, 5] parent: 5
// [50, 30, 24, 5, 28] 값이 증가 -> parent 를 상위로 옮김: 24
// [50, 30, 24, '45', 5, 28] 값이 증가 -> parent 를 상위로 옮김: 30
// [50, 30, '98', 24, 45, 5, 28] 값이 증가 -> parent 를 상위로 옮김: 50
// [50, 30, 98, 24, 45, 5, 28] parent: 98. 삽입 해야하는 서브 트리의 idx: 현재 parent의 idx*2 + 1

// 왼쪽 자식의 idx: idx*2 + 1
// 오른쪽 자식의 idx; idx*2 + 2
// 노드를 삽입할때 idx 보장이 되나..? -> 왼쪽 자식 idx로 삽입을 계속 한다면, 전위 순회라 보장이 될듯하기도.
// 근데 생각해보니 그냥 리스트로 이진 탐색 트리를 구성 못할듯하다;; Node 를 연결해서 만들어보자.

// 시간초과 난다고 합니다...
var preOrderList = [Int]()

while let input = readLine(), let n = Int(input) {
    preOrderList.append(n)
}

func binarySearch(low: Int, high: Int, target: Int) -> Int {
    var low = low, high = high
    
    while low < high {
        let mid = (low+high)/2
        print("low: \(low), high: \(high)")
        print("target: \(target), preOrderList: \(preOrderList[mid])")
        if target < preOrderList[mid] {
            high = mid
        } else {
            low = mid + 1
        }
    }
    return low
}

func postOrder(start: Int, end: Int) {
    if start >= end {return}
    let selectedIndex = binarySearch(low: start+1, high: end, target: preOrderList[start])
    postOrder(start: start+1, end: selectedIndex)
    postOrder(start: selectedIndex, end: end)
    print(preOrderList[start])
}

postOrder(start: 0, end: preOrderList.count)
