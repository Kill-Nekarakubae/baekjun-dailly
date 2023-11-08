//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/07.
//

import Foundation

class DoublyLinkedList<T: Equatable> {
    class Node<T> {
        var prev: Node?
        var data: T?
        var next: Node?
        
        init(prev: Node? = nil, data: T? = nil, next: Node? = nil) {
            self.prev = prev
            self.data = data
            self.next = next
        }
    }
    private var head: Node<T>?
    private var tail: Node<T>?
    
    func append(data: T?) {
        if head == nil || tail == nil {
            head = Node(data: data)
            tail = head
            return
        }
        let newNode = Node(data: data)
        tail?.next = newNode
        newNode.prev = tail
        tail = newNode
    }
    
    func removeLast() {
        if head == nil || tail == nil { return }
        if head?.next == nil {
            head = nil
            tail = nil
            return
        }
        
        tail?.prev?.next = nil
        tail = tail?.prev
    }
    
    func searchNode(from data: T) -> Node<T>? {
        if head == nil || tail == nil { return nil }
        var node = head
        while node?.next != nil {
            if node?.data == data { break }
            node = node?.next
        }
        return node
    }
    
    func searchNodeFromTail(from data: T) -> Node<T>? {
        if head == nil || tail == nil { return nil }
        var node = tail
        while node?.prev != nil {
            if node?.data == data { break }
            node = node?.prev
        }
        return node
    }
    
}
