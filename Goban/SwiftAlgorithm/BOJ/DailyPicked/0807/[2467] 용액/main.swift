//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/07.
//

import Foundation

let n = Int(readLine()!)!

let liquid = readLine()!.split(separator: " ").map { Int(String($0))! }

var (start, end) = (0, n - 1)
var (a, b) = (Int.min, Int.max)
var sub = Int.max

solution()

func solution() {
    while start < end {
        let newLiquid = liquid[start] + liquid[end]
        
        // 최소값 나올때마다 업데이트
        if sub > abs(newLiquid) {
            sub = abs(newLiquid)
            a = liquid[start]
            b = liquid[end]
        }
        
        // 양수면 오른쪽 포인터 한칸 감소
        if newLiquid > 0 {
            end -= 1
        }
        // 음수면 왼쪽 포인터 한칸 증가
        else if newLiquid < 0 {
            start += 1
        }
        // 0이면 출력 후 종료
        else {
            print(liquid[start], liquid[end])
            return
        }
    }
    print(a, b)
}
