//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/10/24.
//

import Foundation

/*
 let N = Int(readLine()!)!
 // 1. 이중 for 문으로 탐색 (시간초과 우려)
 var answer = 0
 for i in 1...N {
     var sum = 0
     for j in i...N {
         sum += j
         if sum == N {
             answer += 1
             break
         }
     }
 }
 print(answer)
 
 시간초과
 */

// 2. 투포인터

let N = Int(readLine()!)!
var answer = 0
var a = 0
var b = 0
var sum = 0
let baseArray = (1...N).map{ $0 }
while(b < baseArray.count) {
    sum += baseArray[b]
    b += 1
    if sum == N {
        answer += 1
    } else if sum > N {
        while sum > N && a < b {
            sum -= baseArray[a]
            a += 1
        }
        if sum == N {
            answer += 1
        }
    }
}
print(answer)
