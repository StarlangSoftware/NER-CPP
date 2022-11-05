cmake_minimum_required(VERSION 3.17)
project(NER)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
set(CONAN_INCLUDE_DIRS_ANNOTATEDTREE "/Users/olcay/.conan/data/AnnotatedTree/1.0.0/_/_/package/e24f3a24ba1e5db53e914b9af88ac8896605cc13/include")

add_library(NER src/AutoProcessor/Sentence/SentenceAutoNER.cpp src/AutoProcessor/Sentence/SentenceAutoNER.h src/AutoProcessor/Sentence/TurkishSentenceAutoNER.cpp src/AutoProcessor/Sentence/TurkishSentenceAutoNER.h)
target_link_libraries(NER ${CONAN_LIBS})