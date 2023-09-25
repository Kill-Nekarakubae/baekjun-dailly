//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/14.
//

import Foundation
// 가장 큰 금액을 만들어라!
// dp[i] = i 만큼 돈을 사용했을때, 만들 수 있는 최대 방 번호?

// 문방구에서 파는 숫자 각각을 이용해서 dp[i] 를 갱신.
// 갱신 방법: dp[i] = [사들인 방번호]. 비교할때, 사들인 방 번호를 정렬해서 저장.
//

func checkIsBigger(from: String, to: String) -> Bool {
    let from = from.map{ String($0) }
    let to = to.map{ String($0) }
    if from.count > to.count {
        if from.first ?? "0" != "0" || (from.first ?? "0" == "0" && to.first ?? "0" == "0") {
            return true
        }
        return false
    } else if from.count < to.count {
        if from.first ?? "0" != "0" && to.first ?? "0" == "0" {
            return true
        }
        return false
    }
    for (i, j) in zip(from, to) {
        let fromNum = Int(i)!
        let toNum = Int(j)!
        if fromNum > toNum {
            return true
        } else if fromNum < toNum {
            return false
        }
    }
    return true
}

let N = Int(readLine()!)!
let P = readLine()!.split(separator: " ").map{ Int($0)! }
let M = Int(readLine()!)!
var dp: [String] = Array(repeating: "", count: M+1)
for i in stride(from: N-1, through: 0, by: -1) {
    let x = P[i]
    guard x<=M else { continue }
    for j in x...M {
        let newNum = dp[j-x] + String(i)
        var isBigger = checkIsBigger(from: newNum, to: String(i))
        if isBigger {
            isBigger = checkIsBigger(from: newNum, to: dp[j])
            if isBigger {
                dp[j] = newNum
            }
        } else {
            isBigger = checkIsBigger(from: String(i), to: dp[j])
            if isBigger {
                dp[j] = String(i)
            }
        }
    }
}
print(dp[M])


//
//var dp: [[String]] = Array(repeating: [], count: M+1)
//for i in 0..<N {
//    let value = P[i].0
//    let num = P[i].1
//    for j in 1...M {
//        var isBigger = checkIsBigger(from: dp[j-1].sorted(by: >), to: dp[j].sorted(by: >))
//        if isBigger {
//            dp[j] = dp[j-1]
//        }
//        if j-value >= 0 {
//            let newValueArr = dp[j-value] + [num]
//            isBigger = checkIsBigger(from: newValueArr.sorted(by: >), to: dp[j].sorted(by: >))
//            if isBigger {
//                dp[j] = newValueArr
//            }
//        }
//    }
//}
//
//print(dp[M].sorted(by: >).joined())
