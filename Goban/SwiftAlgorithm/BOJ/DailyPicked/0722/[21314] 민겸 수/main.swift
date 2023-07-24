//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/22.
//

import Foundation

// 최대: 최대한 K 붙이기
// 최소: 최대한 M만 붙이기

let minkyumNum = readLine()!.map{ String($0) }
// 최대
var maxAnswer = ""
var mCnt = 0
for str in minkyumNum {
    if str == "K" {
        maxAnswer += "5"
        for _ in 0..<mCnt {
            maxAnswer += "0"
        }
        mCnt = 0
    } else {
        mCnt += 1
    }
}
if mCnt != 0 {
    for _ in 0..<mCnt {
        maxAnswer += "1"
    }
}
print(maxAnswer)

// 최소
var minAnswer = ""
mCnt = 0
for str in minkyumNum {
    if str == "M" {
        if mCnt == 0 {
            minAnswer += "1"
        }
        mCnt += 1
    } else {
        if mCnt > 1 {
            for _ in 0..<mCnt-1 {
                minAnswer += "0"
            }
        }
        mCnt = 0
        minAnswer += "5"
    }
}
if mCnt > 1 {
    for _ in 0..<mCnt-1 {
        minAnswer += "0"
    }
}
print(minAnswer)
