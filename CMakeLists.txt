cmake_minimum_required(VERSION 3.17)
project(NER)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
link_directories(library)

add_library(NER AutoProcessor/Sentence/SentenceAutoNER.cpp AutoProcessor/Sentence/SentenceAutoNER.h AutoProcessor/Sentence/TurkishSentenceAutoNER.cpp AutoProcessor/Sentence/TurkishSentenceAutoNER.h)

target_link_libraries(NER AnnotatedTree AnnotatedSentence)