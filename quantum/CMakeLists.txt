project(quantum)

set(HEADER_FILES
        headers/matrixOperation.h
        headers/quantumComputer.h
        headers/quantumGate.h
        headers/quantumGateOperation.h
        headers/qubitOperation.h
        )

set(SOURCE_FILES
        sources/matrixOperation.cpp
        sources/quantumComputer.cpp
        sources/quantumGate.cpp
        sources/quantumGateOperation.cpp
        sources/qubitOperation.cpp
        )

add_library(quantum STATIC ${SOURCE_FILES} ${HEADER_FILES})