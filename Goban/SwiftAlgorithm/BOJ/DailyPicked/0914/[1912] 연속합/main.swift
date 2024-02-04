//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/14.
//

import Foundation

// 연속합 중 가장 큰 수를 구하는 법:
// 연속으로 선택을 하느냐 안하느냐?

let _ = Int(String(readLine()!))!
let numbers = readLine()!.split(separator: " ").map({Int(String($0))!})
let maxValue = numbers.max()!
if maxValue < 0 {
    print(maxValue)
} else {
    var result: Int = 0
    var now: Int = 0

    for i in numbers {
        now += i
        if now < 0 {
            now = 0
        }
        if result < now {
            result = now
        }
    }
    print(result)
}
