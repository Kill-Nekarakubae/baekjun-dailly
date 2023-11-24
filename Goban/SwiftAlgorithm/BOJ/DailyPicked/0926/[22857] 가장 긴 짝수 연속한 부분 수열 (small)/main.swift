//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/26.
//

import Foundation

// 연속되는 수열의 길이를 계산한다 (홀수가 나올떄까지 카운팅?)
// 투포인터로 옮겨가면서 계산

let t = readLine()!.split(separator: " ").map{Int(String($0))!}
let (N,K) = (t[0],t[1])
let S = readLine()!.split(separator: " ").map{Int(String($0))!}

var (start, end) = (0,0)
var deleteCount = S[start] % 2 == 0 ? 0 : 1
var maxLen = S[start] % 2 == 0 ? 1 : 0

while end < N-1 {
    end += 1
    
    if S[end] % 2 != 0 {
        deleteCount += 1
        
        while deleteCount > K {
            if S[start] % 2 != 0 {
                deleteCount -= 1
            }
            start += 1
        }
    }
    
    maxLen = max(maxLen, end - start + 1 - deleteCount)
}

print(maxLen)
