cmake_minimum_required(VERSION 3.17)
project(NER)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(NER src/AutoProcessor/Sentence/SentenceAutoNER.cpp src/AutoProcessor/Sentence/SentenceAutoNER.h src/AutoProcessor/Sentence/TurkishSentenceAutoNER.cpp src/AutoProcessor/Sentence/TurkishSentenceAutoNER.h)
target_link_libraries(NER ${CONAN_LIBS})