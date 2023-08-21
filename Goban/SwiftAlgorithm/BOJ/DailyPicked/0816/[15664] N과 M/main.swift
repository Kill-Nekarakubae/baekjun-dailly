//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/16.
//

var nums = readLine()!.split(separator: " ").map {Int(String($0))!}
var numbers = readLine()!.split(separator: " ").map {Int(String($0))!}
numbers.sort()
var selected = [String]()

func DFS(start: Int) {
    if selected.count == nums[1] {
        print(selected.joined(separator: " "))
        return
    }
    var temp = ""
    for num in start..<nums[0] {
        if temp != String(numbers[num]) {
            selected.append(String(numbers[num]))
            temp = String(numbers[num])
            DFS(start: num+1)
            selected.removeLast()
        }
    }
}

DFS(start:0)
