//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/04.
//

import Foundation
// 액자 테이블.

var gallery: [(num: Int, age: Int)] = []
let N = Int(readLine()!)!
let K = Int(readLine()!)!
let candidates = readLine()!.split(separator: " ").map{ Int($0)! }
var candidated: [Int: Int] = [:]


for (idx, candidate) in candidates.enumerated() {
    if candidated[candidate] == nil {
        if gallery.count == N {
            // 최소 추천
            gallery.sort { lhs, rhs in
                if candidated[lhs.num]! == candidated[rhs.num]! {
                    return lhs.age > rhs.age
                }
                return candidated[lhs.num]! > candidated[rhs.num]!
            }
            let removePic = gallery.popLast()!
            candidated[removePic.num] = nil
            gallery.append((num: candidate, age: idx))
            candidated[candidate] = 0
        }
        // 빈 경우
        else {
            // 새롭게 개제된다
            candidated[candidate] = 0
            gallery.append((num: candidate, age: idx))
        }
    } else {
        candidated[candidate]! += 1
    }
}

gallery.sort(by: { lhs, rhs in
    return lhs.num < rhs.num
})

print(gallery.map{ String($0.num) }.joined(separator: " "))
