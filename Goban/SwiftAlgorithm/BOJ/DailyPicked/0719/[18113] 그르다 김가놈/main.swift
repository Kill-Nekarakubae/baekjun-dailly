//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/19.
//

import Foundation

// P를 최대한 길게 -> 김밥 길이 <= k 라면 폐기
// 이분탐색. p 의 길이를 search
// 1 <= p < M

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let N = input[0]
let K = input[1]
let M = input[2]
var kbs: [Int] = []
for _ in 0..<N {
    kbs.append(Int(readLine()!)!)
}
var start = 1
var end = kbs.max()!
var answer = 0
while start <= end {
    let mid = (start + end) / 2
    var kbCnt = 0
    print("mid: \(mid)")
    for kbLength in kbs {
        // 폐기
        if kbLength <= K {
            print("폐기: \(kbLength)")
            continue
        }
        // 양쪽 자르기
        if kbLength >= 2*K {
            let newKbLength = kbLength - 2*K
            print("양쪽 자르기: 원래: \(kbLength) , 자르고: \(newKbLength)")
            kbCnt += newKbLength/mid
        }
        // 한쪽 자르기
        else {
            let newKbLength = kbLength - K
            print("한쪽 자르기: 원래: \(kbLength) , 자르고: \(newKbLength)")
            kbCnt += newKbLength/mid
        }
    }
    if kbCnt >= M {
        answer = mid
        start = mid + 1
    } else {
        end = mid - 1
    }
}
if answer == 0 {
    print("-1")
} else {
    print(answer)
}
