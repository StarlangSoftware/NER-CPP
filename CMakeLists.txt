cmake_minimum_required(VERSION 3.17)
project(NER)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(annotated_tree REQUIRED)

add_library(NER src/AutoProcessor/Sentence/SentenceAutoNER.cpp src/AutoProcessor/Sentence/SentenceAutoNER.h src/AutoProcessor/Sentence/TurkishSentenceAutoNER.cpp src/AutoProcessor/Sentence/TurkishSentenceAutoNER.h)
target_link_libraries(NER annotated_tree::annotated_tree)