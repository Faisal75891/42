#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

PIPEX="../circle2/pipex/pipex"

echo -e "${BLUE}╔════════════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║         PIPEX MEMORY LEAK & FD LEAK TEST           ║${NC}"
echo -e "${BLUE}╚════════════════════════════════════════════════════╝${NC}"

# Check if valgrind is installed
if ! command -v valgrind &> /dev/null; then
    echo -e "${RED}Error: valgrind is not installed${NC}"
    echo "Install with: sudo apt-get install valgrind"
    exit 1
fi

# Create test files
echo "Creating test files..."
echo -e "Hello World\nTest Line\nAnother Line" > infile.txt

# Test 1: Basic pipeline
echo -e "\n${YELLOW}Test 1: Basic Pipeline (2 commands)${NC}"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
    --error-exitcode=42 \
    $PIPEX infile.txt "cat" "wc -l" outfile.txt 2>valgrind1.log

if [ $? -eq 42 ]; then
    echo -e "${RED}✗ Memory leaks or FD leaks detected!${NC}"
    grep -A 5 "LEAK SUMMARY" valgrind1.log
    grep "Open file descriptor" valgrind1.log
else
    if grep -q "All heap blocks were freed" valgrind1.log; then
        echo -e "${GREEN}✓ No memory leaks${NC}"
    fi
    if ! grep -q "Open file descriptor" valgrind1.log; then
        echo -e "${GREEN}✓ No file descriptor leaks${NC}"
    else
        echo -e "${RED}✗ File descriptor leaks detected${NC}"
        grep "Open file descriptor" valgrind1.log
    fi
fi

# Test 2: Multiple pipes
echo -e "\n${YELLOW}Test 2: Multiple Pipes (4 commands)${NC}"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
    --error-exitcode=42 \
    $PIPEX infile.txt "cat" "cat" "cat" "wc -l" outfile.txt 2>valgrind2.log

if [ $? -eq 42 ]; then
    echo -e "${RED}✗ Memory leaks or FD leaks detected!${NC}"
    grep -A 5 "LEAK SUMMARY" valgrind2.log
else
    if grep -q "All heap blocks were freed" valgrind2.log; then
        echo -e "${GREEN}✓ No memory leaks${NC}"
    fi
    if ! grep -q "Open file descriptor" valgrind2.log; then
        echo -e "${GREEN}✓ No file descriptor leaks${NC}"
    else
        echo -e "${RED}✗ File descriptor leaks detected${NC}"
        grep "Open file descriptor" valgrind2.log
    fi
fi

# Test 3: here_doc
echo -e "\n${YELLOW}Test 3: here_doc${NC}"
echo -e "line1\nline2\nline3" | valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
    --error-exitcode=42 \
    $PIPEX here_doc EOF "cat" "wc -l" heredoc_out.txt 2>valgrind3.log

if [ $? -eq 42 ]; then
    echo -e "${RED}✗ Memory leaks or FD leaks detected!${NC}"
    grep -A 5 "LEAK SUMMARY" valgrind3.log
else
    if grep -q "All heap blocks were freed" valgrind3.log; then
        echo -e "${GREEN}✓ No memory leaks${NC}"
    fi
    if ! grep -q "Open file descriptor" valgrind3.log; then
        echo -e "${GREEN}✓ No file descriptor leaks${NC}"
    else
        echo -e "${RED}✗ File descriptor leaks detected${NC}"
        grep "Open file descriptor" valgrind3.log
    fi
fi

# Test 4: Error handling (missing file)
echo -e "\n${YELLOW}Test 4: Missing Input File (Error Handling)${NC}"
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
    --error-exitcode=42 \
    $PIPEX nonexistent.txt "cat" "wc -l" outfile.txt 2>valgrind4.log

if [ $? -eq 42 ]; then
    echo -e "${RED}✗ Memory leaks or FD leaks detected!${NC}"
    grep -A 5 "LEAK SUMMARY" valgrind4.log
else
    if grep -q "All heap blocks were freed" valgrind4.log; then
        echo -e "${GREEN}✓ No memory leaks (even with errors)${NC}"
    fi
    if ! grep -q "Open file descriptor" valgrind4.log; then
        echo -e "${GREEN}✓ No file descriptor leaks${NC}"
    fi
fi

# Summary
echo -e "\n${BLUE}╔════════════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║                  LEAK TEST SUMMARY                 ║${NC}"
echo -e "${BLUE}╚════════════════════════════════════════════════════╝${NC}"

TOTAL_LEAKS=0

for log in valgrind*.log; do
    if grep -q "definitely lost" $log; then
        lost=$(grep "definitely lost" $log | grep -oP '\d+(?= bytes)')
        if [ "$lost" != "0" ]; then
            ((TOTAL_LEAKS++))
        fi
    fi
done

if [ $TOTAL_LEAKS -eq 0 ]; then
    echo -e "${GREEN}🎉 ALL TESTS PASSED - NO MEMORY LEAKS!${NC}"
    echo -e "${GREEN}Your pipex is ready for evaluation!${NC}"
else
    echo -e "${RED}❌ Memory leaks detected in $TOTAL_LEAKS test(s)${NC}"
    echo -e "${YELLOW}Review the valgrind*.log files for details${NC}"
fi

echo -e "\n${BLUE}Detailed logs saved to:${NC}"
ls -1 valgrind*.log

echo -e "\n${YELLOW}Tip: To view detailed leak info, run:${NC}"
echo "cat valgrind1.log"

