//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/16.
//

//import Foundation
//
//// 4와 7로 이루어진 숫자를 좋아함.
//// 1: 4
//// 2: 7
//// 3: 44
//// 4: 47
//// 5: 74
//// 6: 77
//// 7: 444
//// 8: 447
//// 9: 474
//// 10: 477
//// 11: 744
//// 12: 747
//// 13: 774
//// 14: 777
//
//// 2 -> 4 -> 8
//// 2 -> 6 -> 14
//// 자리수가 늘어날때마다 2배씩 증가
//let k = Int(readLine()!)!
//var sum = 0
//var startIdx = 1
//var previousIdx = 1
//var previousNum = 1
//var numDigit = 1
//for i in 1...k {
//    numDigit = i
//    previousNum *= 2
//    sum += previousNum
//    if k <= sum {
//        startIdx = previousIdx
//        break
//    }
//    previousIdx = sum + 1
//}
//
//print("numDigit", numDigit)
//print("startIdx: ", startIdx)
//print("k: ", k)
//var answer = Array(repeating: 4, count: numDigit)
//while startIdx != k {
//    // 이진법 처럼 동작하는 로직
//    for i in stride(from: answer.count-1, through: 0, by: -1) {
//        if answer[i] == 4 {
//            answer[i] = 7
//            guard i+1 < answer.count else { break }
//            for j in i+1..<answer.count {
//                answer[j] = 4
//            }
//        }
//    }
//    startIdx += 1
//}
//print(answer.map{ String($0) }.joined())
// 시간초과

var N = Int(readLine()!)!
var k = 2
var sum = 2
while N > sum {
    k*=2
    sum += k
}
N -= sum-k
sum -= sum-k

var ans = ""
while sum > 2 {
    if sum/2 < N {
        N -= sum/2
        ans += "7"
    } else {
        ans += "4"
    }
    sum -= sum/2
}
if N == 1 { ans += "4" }
else { ans += "7" }

print(ans)
