//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/17.
//

import Foundation

// 모든 배열을 하나씩 확인.
// 답변과 일치하면 resultCnt += 1

let N = Int(readLine()!)!
var resultCount = 0
var questions: [Int] = []
var answers: [(strike: Int, ball: Int)] = []

for _ in 0..<N {
    let line = readLine()!.split(separator: " ").map{ Int(String($0))! }
    questions.append(line[0])
    answers.append((strike: line[1], ball: line[2]))
}

func checkIsValid(num: Int) -> Bool {
    let numArray = String(num).map{ Int(String($0))! }
    let containZero = numArray.contains(0)
    let overLap = Set(numArray).count != numArray.count
    return !containZero && !overLap
}

func getStrikeBall(a: Int, b: Int) -> (Int, Int) {
    let aArray = String(a).map{ Int(String($0))! }
    let bArray = String(b).map { Int(String($0))! }
      var strike = 0
      var ball = 0
      
      for i in 0..<3 {
          guard aArray.contains(bArray[i]) else { continue }
          if i == aArray.firstIndex(of: bArray[i]) {
              strike += 1
          } else {
              ball += 1
          }
      }
    return (strike, ball)
}

func checkIsCorrect(num: Int) -> Bool {
    for i in 0..<N {
        let ans = getStrikeBall(a: num, b: questions[i])
        if ans != answers[i] {
            return false
        }
    }
    return true
}


for i in 123...987 {
    if checkIsValid(num: i) {
        if checkIsCorrect(num: i) {
            resultCount += 1
        }
    }
}

print(resultCount)
