cmake_minimum_required(VERSION 3.20)


project(CPlusPlusBestC
	LANGUAGES CXX)
	

set(CMAKE_CXX_STANDARD 20)
	
set (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})

add_executable(main main.cpp TabRecord.cpp ArrayTable.cpp ScanTable.cpp SortTable.cpp "marks.h")
#TabRecord.cpp ArrayTable.cpp DatValue.cpp ScanTable.cpp SortTable.cpp Table.cpp TableTestKit.cpp