//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/03.
//

while let input = readLine() {
  let temp = input.split{$0==" "}.map{String($0)}
  let (text, needle) = (temp[1].map{String($0)},temp[0].map{String($0)})
  var tIdx = 0, nIdx = 0
  while tIdx < text.count && nIdx < needle.count {
    if text[tIdx] == needle[nIdx] { nIdx += 1 }
    tIdx+=1
  }
  print(nIdx == needle.count ? "Yes" : "No")
}
