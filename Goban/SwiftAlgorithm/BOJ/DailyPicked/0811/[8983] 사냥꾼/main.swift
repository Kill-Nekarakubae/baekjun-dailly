//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/11.
//

import Foundation

// 사대가 주어졌을떄 잡을 수 있는 동물의 수를 구해야한다.
// 사대들이 커버하는 범위를 모두 합하여 걸러내기
// 사대 범위 안에 들어간다 -> x 좌표가 같은 평면에서 더 큰 y 값이 존재한다.

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (M, N, L) = (input[0], input[1], input[2])
var huntPosition = readLine()!.split(separator: " ").map{ Int($0)! }

// 동물의 x 좌표와 가장 가까운 사대를 찾아서 계산. 이분탐색?.
huntPosition.sort(by: <)

func canHunt(animalPosition: (x: Int, y: Int), huntPosition: Int) -> Bool {
    let distance = abs(huntPosition - animalPosition.x) + animalPosition.y
    return distance <= L
}

var answer = 0
for _ in 0..<N {
    let animalPosition = readLine()!.split(separator: " ").map{ Int($0)! }
    let animalPositionX = animalPosition[0]
    let animalPositionY = animalPosition[1]
    var start = 0
    var end = huntPosition.count - 1
    var minDiff = Int.max
    var minHuntXPostion = 0
    while start <= end {
        let mid = (start + end) / 2
        if huntPosition[mid] - animalPositionX <= 0 {
            start = mid + 1
        } else {
            end = mid - 1
        }
        let diff = abs(huntPosition[mid] - animalPositionX)
        if diff <= minDiff {
            minHuntXPostion = huntPosition[mid]
            minDiff = diff
        }
    }
    if canHunt(animalPosition: (x: animalPositionX, y: animalPositionY), huntPosition: minHuntXPostion) {
        answer += 1
    }
}

print(answer)
