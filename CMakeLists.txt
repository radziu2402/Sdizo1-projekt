cmake_minimum_required(VERSION 3.24)
project(Sdizo1)

set(CMAKE_CXX_STANDARD 17)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

add_executable(Sdizo1 main.cpp DoublyLinkedList.cpp DoublyLinkedList.h ListNode.cpp ListNode.h DoublyLinkedList.h DynamicArray.h DynamicArray.cpp Tests.cpp Tests.h Time.cpp Time.h BinaryHeap.cpp BinaryHeap.h BinaryHeap.h RedBlackTree.cpp RedBlackTree.h FromFileTests.cpp FromFileTests.h)
