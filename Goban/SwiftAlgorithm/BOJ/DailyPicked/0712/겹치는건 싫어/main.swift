//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/12.
//

import Foundation

// 슬라이딩 윈도우?
// 같은 숫자를 dict 에 기록.
// 추가된 숫자의 중복이 k 이상이면, 중복숫자가 빼질때 까지 앞의 숫자를 제거 (수열의 길이 -1)
let input1 = readLine()!.components(separatedBy: " ").map{ Int(String($0))! }
let n = input1[0]
let k = input1[1]
let numSequence = readLine()!.components(separatedBy: " ").map{ Int(String($0))! }
var sequenceTailIndex = 0
var sequenceHeadIndex = 0
var numDict: [Int: Int] = [:]
var maxLength = 0
for i in numSequence {
    sequenceHeadIndex += 1
    if numDict[i] != nil {
        numDict[i]! += 1
        if numDict[i]! > k {
            while numDict[i]! > k {
                numDict[numSequence[sequenceTailIndex]]! -= 1
                sequenceTailIndex += 1
            }
        }
    } else {
        numDict[i] = 1
    }
    maxLength = max(maxLength, sequenceHeadIndex - sequenceTailIndex)
}
print(maxLength)
