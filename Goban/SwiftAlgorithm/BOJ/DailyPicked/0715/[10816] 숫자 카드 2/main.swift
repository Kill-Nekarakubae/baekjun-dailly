//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/15.
//

import Foundation

let n = Int(readLine()!)!
// split 말고 components 쓰면 에러 ...!
let sangCards = readLine()!.split(separator: " ").map{ Int(String($0))! }
let m = Int(readLine()!)!
let countCards  = readLine()!.split(separator: " ").map{ Int(String($0))! }
var result: [Int] =  []
var dict: [Int: Int] = [:]

for i in sangCards {
    if dict.keys.contains(i) {
        dict[i]! += 1
    } else {
        dict[i] = 1
    }
}

for i in countCards {
    if dict.keys.contains(i) {
        result.append(dict[i]!)
    } else {
        result.append(0)
    }
}

var answer = ""
for i in result {
    answer += String(i) + " "
}
print(answer)

// 이분탐색 시간초과
//for i in 0..<m {
//    let target = countCards[i]
//    var start = 0
//    var end = n-1
//    var count = 0
//    while start <= end {
//        let mid =  (start + end) / 2
//        // 숫자가 일치하는 경우.
//        if target == -10 {
//
//        }
//        if sortedSangCards[mid] == target {
//            count += 1
//            if mid-1>=0 {
//                for k in stride(from: mid-1, through: 0, by: -1) {
//                    if sortedSangCards[k] == target {
//                        count += 1
//                    } else {
//                        break
//                    }
//                }
//            }
//
//            guard mid+1<n else { break }
//            for k in mid+1..<n {
//                if sortedSangCards[k] == target {
//                    count += 1
//                } else {
//                    break
//                }
//            }
//            break
//        } else if sortedSangCards[mid] > target {
//            end = mid - 1
//        } else {
//            start = mid + 1
//        }
//    }
//    answer.append(count)
//}
//
//print(answer.map{String($0)}.joined(separator: " "))
