cmake_minimum_required(VERSION 3.21)
project(StringAlgorithmsAnalysis)

set(CMAKE_CXX_STANDARD 17)

add_executable(StringAlgorithmsAnalysis main.cpp Algorithms/NaiveAlgorithm.cpp Algorithms/NaiveAlgorithm.h Utils/StringAlgorithmUtils/AlgorithmsInfo.cpp Utils/StringAlgorithmUtils/StringGenerator.cpp Utils/StringAlgorithmUtils/AlgorithmExecutor.cpp Utils/FileUtils/CSVWriter.cpp Utils/InterfaceUtils/ConsoleInputReader.cpp Utils/InterfaceUtils/InfoPrinter.cpp Utils/TimeUtils/TimerGuard.cpp Utils/TimeUtils/TimerGuard.h Algorithms/KMPOptimizedAlgorithm.cpp Algorithms/KMPOptimizedAlgorithm.h Algorithms/KMPAlgorithm.cpp Algorithms/KMPAlgorithm.h Utils/StringAlgorithmUtils/ResultChecker.cpp)
