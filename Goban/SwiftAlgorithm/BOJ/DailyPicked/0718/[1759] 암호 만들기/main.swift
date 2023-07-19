//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/18.
//

import Foundation

// 알파벳 순 정렬 -> 만들 수 있는 암호를 모두 만들어 최소 한개의 모음, 두개의 자음으로 구성되어있는지 확인한다.
// 구성 방법? 만들떄 선택 해서 만들거나 or 선택 안하고 넘어가거나. l 개를 넘어가면 탈락.

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let L = input[0]
let C = input[1]
let cTypes = readLine()!.split(separator: " ").map{ String($0) }
let sortedCtypes = cTypes.sorted()

func isVowel(_ str: String) -> Bool {
    for c in ["a", "e", "i", "o", "u"] {
        if str.contains(c) {
            return true
        }
    }
    return false
}

func DFS(password: String, cIndex: Int, vowelCnt: Int, consonantCnt: Int) {
    if password.count == L {
        if vowelCnt >= 1 && consonantCnt >= 2 {
            print(password)
        }
        return
    }
    if cIndex == C {
        return
    }
    var cVowelCnt = vowelCnt
    var cConsonantCnt = consonantCnt
    if isVowel(sortedCtypes[cIndex]) {
        cVowelCnt += 1
    } else {
        cConsonantCnt += 1
    }
    DFS(password: password + sortedCtypes[cIndex], cIndex: cIndex + 1, vowelCnt: cVowelCnt, consonantCnt: cConsonantCnt)
    DFS(password: password, cIndex: cIndex + 1, vowelCnt: vowelCnt, consonantCnt: consonantCnt)
}

DFS(password: "", cIndex: 0, vowelCnt: 0, consonantCnt: 0)
