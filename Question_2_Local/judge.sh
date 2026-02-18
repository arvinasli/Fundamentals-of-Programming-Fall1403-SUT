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
SOURCE_DIR="test"
OUTPUT_DIR="out"

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

run_single_test() {
    local i=$(( $1 + 1 ))
    TEST_DIR="$SOURCE_DIR/test${i}"
    ANSWER="$OUTPUT_DIR/output$i.txt"
    MY_OUTPUT="_test_env_/output.txt"

    # Remove the test environment directory if it exists and create a new one    
    rm -rf _test_env_ >/dev/null 2>&1
    mkdir -p _test_env_
    
    # Copy the input files and the test script to the test environment
    files=($(find "$TEST_DIR" -type f -name "text*.txt"))
    cp "${files[@]}" _test_env_/
    cp "$TEST_DIR/categories.txt" _test_env_/
    cp "$EXECUTABLE_FILE" _test_env_/

    # Run the executable withing the test environment
    (
        cd _test_env_
        files=($(find . -type f -name "text*.txt" | sort))
        timeout $TEST_TIMELIMIT "./$EXECUTABLE_FILE" categories.txt "${files[@]}" >output.txt 2>error_log
    )
    rv=$?

    # Check the output of the test
    if [ $rv -eq 124 ]; then
        echo -e "${BOLD}Test $i: ${YELLOW}Timeout after $TEST_TIMELIMIT seconds${NC}"
    elif [ $rv -ne 0 ]; then
        echo -e "${BOLD}Test $i: ${YELLOW}Runtime Error (Code $rv)${NC}"
    elif diff -q <(sed -e '$a\' "$MY_OUTPUT") <(sed -e '$a\' "$ANSWER") > /dev/null; then
        echo -e "${BOLD}Test $i: ${GREEN}Passed${NC}"
    else
        echo -e "${BOLD}Test $i: ${RED}Failed${NC}"

        # Uncomment the following lines to show the differences
        # echo -e "${MAGENTA}${BOLD}Differences:${NC}"
        # diff "$MY_OUTPUT" "$ANSWER"
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
        run_single_test "$1"
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
