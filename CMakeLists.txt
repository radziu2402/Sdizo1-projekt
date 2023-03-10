cmake_minimum_required(VERSION 3.24)
project(Sdizo1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sdizo1 main.cpp DoublyLinkedList.cpp DoublyLinkedList.h Node.cpp Node.h DoublyLinkedList.h DynamicArray.h DynamicArray.cpp Tests.cpp Tests.h Time.cpp Time.h)
