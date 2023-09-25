//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/23.
//

import Foundation

// 2! = 2*1
// 3! = 3*2*1 = 6
// 4! = 4*3*2*1 = 24
// 5! = 5*4*3*2*1 = 70
// dp 메모라이제이션으로 1~N 까지의 연산 계산 및 저장
//

let n = Int(readLine()!)!
var answer = 1
for i in 1...n {
    answer *= i
    answer %= 10000000
    while (answer % 10 == 0) {
        answer /= 10
    }
}
print(answer%10)
