//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/11.
//

import Foundation

// 모든 수식을 하나씩 끼워서 계산해보기

let N = Int(readLine()!)!
let numbers = readLine()!.split(separator: " ").map{ Int($0)! }
var operators = readLine()!.split(separator: " ").map{ Int($0)! }

enum Operators: Int {
    case plus = 0
    case minus = 1
    case multiply = 2
    case divide = 3
}

var currentNumber = numbers[0]
var minNum = Int.max
var maxNum = Int.min

func DFS(idx: Int) {
    if idx == N {
        minNum = min(minNum, currentNumber)
        maxNum = max(maxNum, currentNumber)
        return
    }
    for i in 0..<4 {
        if operators[i] != 0 {
            operators[i] -= 1
            let calOperator = Operators(rawValue: i)
            switch calOperator {
            case .plus:
                currentNumber += numbers[idx]
                DFS(idx: idx+1)
                currentNumber -= numbers[idx]
            case .divide:
                let tempNumber = currentNumber
                currentNumber /= numbers[idx]
                DFS(idx: idx+1)
                currentNumber = tempNumber
            case .minus:
                currentNumber -= numbers[idx]
                DFS(idx: idx+1)
                currentNumber += numbers[idx]
            case .multiply:
                let tempNumber = currentNumber
                currentNumber *= numbers[idx]
                DFS(idx: idx+1)
                currentNumber = tempNumber
            case .none:
                break
            }
            operators[i] += 1
        }
    }
}

DFS(idx: 1)

print(maxNum)
print(minNum)
