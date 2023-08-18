//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/18.
//

import Foundation

// 회전 초밥의 종류를 최대한 많이 먹어야한다.
// 초밥의 종류는 같을 수 있다 (번호로 표현)
// 생각나는 방법: quque 를 사용하여 초밥을 하나씩 추가하고 빼내면서 현재까지 먹은 초밥의 종류를 카운팅.
// 시간 복잡도 떄문에 한번 뒤집고 pop 하고 다시 뒤집는 방법을 이용해야할듯하다.

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, d, k, c) = (input[0], input[1], input[2], input[3] )
var sushiBelt: [Int] = []
for _ in 0..<N {
    let num = Int(readLine()!)!
    sushiBelt.append(num)
}

extension Collection {
    func customPopFirst() -> (popedCollection: [Self.Element], popedElement: Self.Element) {
        var reversedCollection = self.reversed()
        let popedElement = reversedCollection.removeLast()
        return (reversedCollection.reversed(), popedElement)
    }
}

var sushiEating: [Int] = []
var sushiDict: [Int:Int] = [:]
var answer = 0
if N <= k {
    print(d)
} else {
    // 스시 초기 셋팅
    for i in 0..<k {
        sushiEating.append(sushiBelt[i])
        sushiDict[sushiBelt[i], default: 0] += 1
    }
    if sushiDict[c, default: 0] == 0 {
        answer = sushiDict.keys.count + 1
    } else {
        answer = sushiDict.keys.count
    }
    for i in k..<N+k-1 {
        let headIdx = i%N
        let poped = sushiEating.customPopFirst()
        sushiDict[poped.popedElement, default: 0] -= 1
        if sushiDict[poped.popedElement, default: 0] == 0 {
            sushiDict.removeValue(forKey: poped.popedElement)
        }
        sushiDict[sushiBelt[headIdx], default: 0] += 1
        sushiEating = poped.popedCollection
        sushiEating.append(sushiBelt[headIdx])
        if sushiDict[c, default: 0] == 0 {
            answer = max(answer, sushiDict.keys.count + 1)
        } else {
            answer = max(answer, sushiDict.keys.count)
        }
    }
    print(answer)
}
