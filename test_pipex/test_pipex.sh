#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

PIPEX="../circle2/pipex/pipex"
PASS=0
FAIL=0

# Create test files
echo "Creating test files..."
echo -e "Hello World\nThis is a test\nAnother line\nTest line" > infile.txt
echo -e "apple\nbanana\napricot\navocado\ncherry" > fruits.txt

# Function to run test
run_test() {
    local test_name="$1"
    local pipex_cmd="$2"
    local shell_cmd="$3"
    
    echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
    echo -e "${YELLOW}Test: $test_name${NC}"
    echo -e "${BLUE}Pipex: $pipex_cmd${NC}"
    echo -e "${BLUE}Shell: $shell_cmd${NC}"
    
    # Run pipex
    eval "$pipex_cmd" 2>pipex_err.txt
    pipex_exit=$?
    
    # Run shell equivalent
    eval "$shell_cmd" 2>shell_err.txt
    shell_exit=$?
    
    # Compare outputs
    if diff -q pipex_out.txt shell_out.txt >/dev/null 2>&1; then
        echo -e "${GREEN}✓ Output matches${NC}"
        ((PASS++))
    else
        echo -e "${RED}✗ Output differs${NC}"
        echo "Pipex output:"
        cat pipex_out.txt 2>/dev/null || echo "(no output)"
        echo "Shell output:"
        cat shell_out.txt 2>/dev/null || echo "(no output)"
        ((FAIL++))
    fi
    
    # Compare exit codes
    if [ $pipex_exit -eq $shell_exit ]; then
        echo -e "${GREEN}✓ Exit code matches ($pipex_exit)${NC}"
    else
        echo -e "${RED}✗ Exit code differs (pipex: $pipex_exit, shell: $shell_exit)${NC}"
    fi
    
    # Cleanup
    rm -f pipex_out.txt shell_out.txt pipex_err.txt shell_err.txt
}

echo -e "${BLUE}╔════════════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║           PIPEX COMPREHENSIVE TEST SUITE           ║${NC}"
echo -e "${BLUE}╚════════════════════════════════════════════════════╝${NC}"

# Test 1: Basic two-command pipeline
run_test "Basic Pipeline" \
    "$PIPEX infile.txt 'cat' 'wc -l' pipex_out.txt" \
    "< infile.txt cat | wc -l > shell_out.txt"

# Test 2: Multiple pipes
run_test "Multiple Pipes (3 commands)" \
    "$PIPEX infile.txt 'cat' 'grep test' 'wc -l' pipex_out.txt" \
    "< infile.txt cat | grep test | wc -l > shell_out.txt"

# Test 3: Commands with options
run_test "Commands with Options" \
    "$PIPEX fruits.txt 'grep a' 'sort' pipex_out.txt" \
    "< fruits.txt grep a | sort > shell_out.txt"

# Test 4: Case-insensitive grep
run_test "Case Insensitive Grep" \
    "$PIPEX infile.txt 'grep -i HELLO' 'wc -w' pipex_out.txt" \
    "< infile.txt grep -i HELLO | wc -w > shell_out.txt"

# Test 5: Non-existent input file
echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${YELLOW}Test: Non-existent Input File${NC}"
$PIPEX nofile.txt 'cat' 'wc -l' pipex_out.txt 2>pipex_err.txt
pipex_exit=$?
< nofile.txt cat | wc -l > shell_out.txt 2>shell_err.txt
shell_exit=$?

if diff -q pipex_out.txt shell_out.txt >/dev/null 2>&1; then
    echo -e "${GREEN}✓ Handles missing file correctly (continues with empty input)${NC}"
    ((PASS++))
else
    echo -e "${RED}✗ Does not match shell behavior for missing input${NC}"
    ((FAIL++))
fi
rm -f pipex_out.txt shell_out.txt pipex_err.txt shell_err.txt

# Test 6: here_doc basic
echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${YELLOW}Test: here_doc Basic${NC}"
rm -f heredoc_pipex.txt heredoc_shell.txt
echo -e "line1\nline2\nline3" | $PIPEX here_doc EOF 'cat' 'wc -l' heredoc_pipex.txt
echo -e "line1\nline2\nline3" | cat | wc -l >> heredoc_shell.txt

if diff -q heredoc_pipex.txt heredoc_shell.txt >/dev/null 2>&1; then
    echo -e "${GREEN}✓ here_doc works correctly${NC}"
    ((PASS++))
else
    echo -e "${RED}✗ here_doc output differs${NC}"
    ((FAIL++))
fi

# Test 7: here_doc APPEND mode
echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${YELLOW}Test: here_doc APPEND Mode${NC}"
rm -f heredoc_append.txt
echo "first" | $PIPEX here_doc EOF 'cat' heredoc_append.txt
echo "second" | $PIPEX here_doc EOF 'cat' heredoc_append.txt

if [ $(wc -l < heredoc_append.txt) -eq 2 ]; then
    echo -e "${GREEN}✓ here_doc appends correctly${NC}"
    ((PASS++))
else
    echo -e "${RED}✗ here_doc does not append (should have 2 lines, has $(wc -l < heredoc_append.txt))${NC}"
    ((FAIL++))
fi

# Test 8: Invalid command
echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${YELLOW}Test: Invalid Command${NC}"
$PIPEX infile.txt 'invalidcmd12345' 'wc' pipex_out.txt 2>/dev/null
pipex_exit=$?

if [ $pipex_exit -eq 127 ]; then
    echo -e "${GREEN}✓ Returns exit code 127 for command not found${NC}"
    ((PASS++))
else
    echo -e "${RED}✗ Wrong exit code for invalid command (got $pipex_exit, expected 127)${NC}"
    ((FAIL++))
fi

# Test 9: Complex command with quotes
run_test "Command with Single Quotes" \
    "$PIPEX infile.txt \"grep 'Hello'\" 'wc -l' pipex_out.txt" \
    "< infile.txt grep 'Hello' | wc -l > shell_out.txt"

# Test 10: Very long pipeline (5 commands)
run_test "Long Pipeline (5 commands)" \
    "$PIPEX fruits.txt 'cat' 'sort' 'grep a' 'wc -l' 'cat' pipex_out.txt" \
    "< fruits.txt cat | sort | grep a | wc -l | cat > shell_out.txt"

# Test 11: Testing with modified environment
echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${YELLOW}Test: Custom PATH Environment${NC}"
env PATH=/bin:/usr/bin $PIPEX infile.txt 'cat' 'wc -l' pipex_out.txt 2>/dev/null
env PATH=/bin:/usr/bin bash -c '< infile.txt cat | wc -l' > shell_out.txt 2>/dev/null

if diff -q pipex_out.txt shell_out.txt >/dev/null 2>&1; then
    echo -e "${GREEN}✓ Works with custom PATH${NC}"
    ((PASS++))
else
    echo -e "${RED}✗ Fails with custom PATH${NC}"
    ((FAIL++))
fi
rm -f pipex_out.txt shell_out.txt

# Test 12: Minimal environment
echo -e "\n${BLUE}━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━${NC}"
echo -e "${YELLOW}Test: Minimal Environment (env -i)${NC}"
env -i PATH=/bin:/usr/bin $PIPEX infile.txt 'cat' 'wc -l' pipex_out.txt 2>/dev/null
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓ Works with minimal environment${NC}"
    ((PASS++))
else
    echo -e "${RED}✗ Fails with minimal environment${NC}"
    ((FAIL++))
fi
rm -f pipex_out.txt

# Summary
echo -e "\n${BLUE}╔════════════════════════════════════════════════════╗${NC}"
echo -e "${BLUE}║                    TEST SUMMARY                    ║${NC}"
echo -e "${BLUE}╚════════════════════════════════════════════════════╝${NC}"
echo -e "${GREEN}Passed: $PASS${NC}"
echo -e "${RED}Failed: $FAIL${NC}"

if [ $FAIL -eq 0 ]; then
    echo -e "\n${GREEN}🎉 ALL TESTS PASSED! Your pipex is ready for evaluation!${NC}"
    exit 0
else
    echo -e "\n${RED}❌ Some tests failed. Please review the output above.${NC}"
    exit 1
fi

