#!/bin/bash

# Constants for formatting and colors
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
YELLOW='\033[1;33m'
BOLD='\033[1m'
NC='\033[0m'

TOTAL_TESTS=3
TEST_TIMELIMIT=5
SOURCE_FILE="main.c"
EXECUTABLE_FILE="main"

compile_source() {
    echo -e "#include <stdlib.h>\nint system(const char *command){exit(100);}" >_temp.c
    echo -e "${BOLD}Compiling source code...${NC}"
    gcc -o "$EXECUTABLE_FILE" _temp.c "$SOURCE_FILE"
    if [ $? -ne 0 ]; then
        echo -e "${RED}${BOLD}Compilation failed!${NC}"
        rm _temp.c
        exit 1
    fi
    rm _temp.c
    echo -e "${GREEN}${BOLD}Compilation successful!${NC}"
}

test_single_case() {
    local i=$(( $1 + 1 ))
    INPUT_FILE="in/input${i}.txt"
    EXPECTED_OUT_FILE="out/output${i}.txt"
    MY_OUTPUT="_test_env_/output.txt"

    # Remove the test environment directory if it exists and create a new one
    rm -rf _test_env_ >/dev/null 2>&1
    mkdir -p _test_env_

    # Copy the input file and the executable to the test environment
    cp "$INPUT_FILE" _test_env_/input.txt
    cp "$EXECUTABLE_FILE" _test_env_/

    # Run the executable withing the test environment
    (
        cd _test_env_
        timeout $TEST_TIMELIMIT "./$EXECUTABLE_FILE" >/dev/null 2>error_log
    )
    rv=$?

    # Check the output of the test
    if [ $rv -eq 124 ]; then
        echo -e "${BOLD}Test $i: ${YELLOW}Timeout after $TEST_TIMELIMIT seconds${NC}"
    elif [ $rv -ne 0 ]; then
        echo -e "${BOLD}Test $i: ${YELLOW}Runtime Error (Code $rv)${NC}"
    elif diff -q <(sed -e '$a\' "$MY_OUTPUT") <(sed -e '$a\' "$EXPECTED_OUT_FILE") >/dev/null; then
        echo -e "${BOLD}Test $i: ${GREEN}Passed${NC}"
    else
        echo -e "${BOLD}Test $i: ${RED}Failed${NC}"

        # Uncomment the following lines to show the differences
        # echo -e "${MAGENTA}${BOLD}Differences:${NC}"
        # diff <(sed -e '$a\' "$MY_OUTPUT") <(sed -e '$a\' "$EXPECTED_OUT_FILE")
        rv=1
    fi

    # Note: Comment the following line for debugging
    rm -rf _test_env_

    return $rv
}

if [ $# -eq 1 ]; then
    if [ "$1" -eq -1 ]; then
        compile_source
    else
        test_single_case "$1"
        exit $?
    fi
else
    correct=0
    "$0" -1   # Compile the source code
    for ((i=0; i<TOTAL_TESTS; i++)); do    
        # Call the judge with the test number
        # Increment the correct counter if the test passes
        "$0" $i && ((correct++))
    done

    rm "$EXECUTABLE_FILE"
    
    echo -e "${CYAN}${BOLD}--------------------------------${NC}"
    if [ $correct -eq $TOTAL_TESTS ]; then
        echo -e "${GREEN}${BOLD}$correct/$TOTAL_TESTS tests passed${NC}"
    elif [ $correct -eq 0 ]; then
        echo -e "${RED}${BOLD}$correct/$TOTAL_TESTS tests passed${NC}"
    else
        echo -e "${YELLOW}${BOLD}$correct/$TOTAL_TESTS tests passed${NC}"
    fi
fi
