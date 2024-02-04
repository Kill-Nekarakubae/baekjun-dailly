//
//  LinkedList_Interview.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/07.
//

import Foundation

struct LinkedList<T: Equatable> {
    
    class Node<T> {
        var data: T?
        var next: Node?
        
        init(data: T?, next: Node? = nil) {
            self.data = data
            self.next = next
        }
    }
    
    var head: Node<T>?

    mutating func append(data: T?) {
        
        //head가 없는 경우 Node를 생성 후 head로 지정해준다
        if head == nil {
            head = Node(data: data)
            return
        }

        var node = head
        while node?.next != nil {
            node = node?.next
        }
        node?.next = Node(data: data)
    }
    
    mutating func insert(data: T?, at index: Int) {
        //head가 없는 경우 Node를 생성 후 head로 지정해준다
        if head == nil {
            head = Node(data: data)
            return
        }
        
        // insert 하는 index 까지 이동
        var node = head
        for _ in 0..<index-1 {
            if node?.next == nil { break }
            node = node?.next
        }
        
        // 노드긴 연결 바꿔주기
        let nextNode = node?.next
        node?.next = Node(data: data)
        node?.next?.next = nextNode
    }
    
    mutating func removeLast() {
        if head == nil { return }
        
        if head?.next == nil {
            head = nil
            return
        }
        
        var node = head
        while node?.next?.next != nil {
            node = node?.next
        }
        node?.next = nil
    }
    
    mutating func remove(at index: Int) {
        if head == nil { return }
        if index == 0 {
            head = head?.next
            return
        }
        
        var node = head
        for _ in 0..<index-1 {
            if node?.next?.next == nil { break }
            node = node?.next
        }
        
        node?.next = node?.next?.next
    }
    
    func searchNode(from data: T) -> Node<T>? {
        
        if head == nil { return nil }
        var node = head
        while node?.next != nil {
            if node?.data == data { return node }
            node = node?.next
        }
        if node?.data == data { return node } else {
            return nil
        }
    }
    
}
