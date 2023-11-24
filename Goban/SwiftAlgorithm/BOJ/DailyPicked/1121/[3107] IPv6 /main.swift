//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/21.
//

import Foundation


// 1번 조건 먼저 복원
// : 을 기준으로 자르면?

var IPv6 = String(readLine()!)
var cuttedIPv6 = IPv6.split(separator: ":").map{ String($0) }
let originCnt = 8 - cuttedIPv6.count
if originCnt != 0 {
    var IPv6Arr = IPv6.map{ String($0) }
    var conscutive = 0
    for i in 0..<IPv6Arr.count {
        if IPv6Arr[i] == ":" {
            conscutive += 1
        } else {
            conscutive = 0
        }
        if conscutive == 2 {
            let insertIdx = i - 1
            IPv6Arr.remove(at: i)
            IPv6Arr.remove(at: i-1)
            for _ in 0..<originCnt {
                IPv6Arr.insert(":0000:", at: insertIdx)
            }
            IPv6 = IPv6Arr.joined()
            break
        }
    }
}
cuttedIPv6 = IPv6.split(separator: ":").map{ String($0) }
var answer: String = ""
var originIPv6: [String] = []
for node in cuttedIPv6 {
    let strArr = node.map{ String($0) }
    let conscutive = 4 - strArr.count
    let newNode = Array(repeating: "0", count: conscutive) + strArr
    originIPv6.append(newNode.joined())
}

answer = originIPv6.joined(separator: ":")
print(answer)
