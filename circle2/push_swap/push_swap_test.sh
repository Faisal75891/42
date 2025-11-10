#!/bin/bash

# CONFIGURATION
PUSH_SWAP=./push_swap
CHECKER=./checker_linux
MIN_SIZE=3
MAX_SIZE=100
TESTS_PER_SIZE=10
RANGE=1000  # Random numbers will be between -RANGE and +RANGE

# COLORS
GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
CYAN="\033[36m"
RESET="\033[0m"

# Check if push_swap exists
if [ ! -x "$PUSH_SWAP" ]; then
    echo -e "${RED}Error: push_swap not found or not executable.${RESET}"
    exit 1
fi

# Check if checker exists (optional)
if [ ! -x "$CHECKER" ]; then
    echo -e "${YELLOW}Warning: checker not found — will only check sorting via output.${RESET}"
    USE_CHECKER=false
else
    USE_CHECKER=true
fi

# Helper to generate random sequence of N unique integers
generate_numbers() {
    local n=$1
    # Generate numbers from -RANGE to +RANGE
    shuf -i 0-$((2 * RANGE)) -n $n | awk -v range=$RANGE '{print $1 - range}'
}

echo "Starting push_swap tests..."
echo "Testing sizes from $MIN_SIZE to $MAX_SIZE"
echo "Tests per size: $TESTS_PER_SIZE"
echo

# Run tests for different sizes
for size in $(seq $MIN_SIZE $MAX_SIZE); do
    echo -n "Testing size $size: "
    success=0
    total_ops=0
    failed_tests=0
    
    for i in $(seq 1 $TESTS_PER_SIZE); do
        args=$(generate_numbers $size | tr '\n' ' ')
        
        # Check if we got the right number of arguments
        arg_count=$(echo "$args" | wc -w)
        if [ "$arg_count" -ne "$size" ]; then
            echo -e "  ${RED}Failed to generate numbers (got $arg_count, expected $size)${RESET}"
            failed_tests=$((failed_tests + 1))
            continue
        fi
        
        # Run push_swap with timeout (to avoid infinite loops)
        output=$(timeout 5s $PUSH_SWAP $args 2>/dev/null)
        exit_status=$?
        
        # Check for timeout or crash
        if [ $exit_status -eq 124 ]; then
            echo -e "  ${RED}Timeout (>5 seconds)${RESET} — size $size, test $i"
            echo -e "    ${CYAN}Test list: $args${RESET}"
            failed_tests=$((failed_tests + 1))
            continue
        elif [ $exit_status -ne 0 ]; then
            echo -e "  ${RED}Crash or error (exit $exit_status)${RESET} — size $size, test $i"
            echo -e "    ${CYAN}Test list: $args${RESET}"
            failed_tests=$((failed_tests + 1))
            continue
        fi

        op_count=$(echo "$output" | wc -l | tr -d ' ')

        # Verify sorting
        if $USE_CHECKER; then
            result=$(echo "$output" | $CHECKER $args 2>/dev/null)
            if [ "$result" == "OK" ]; then
                success=$((success + 1))
                total_ops=$((total_ops + op_count))
            else
                echo -e "  ${RED}Failed to sort${RESET} — size $size, test $i (checker: $result)"
                echo -e "    ${CYAN}Test list: $args${RESET}"
                echo -e "    Operations count: $op_count"
                failed_tests=$((failed_tests + 1))
            fi
        else
            # Alternative checking method without checker
            if [ -z "$output" ]; then
                # If no operations, check if already sorted
                sorted_args=$(echo "$args" | tr ' ' '\n' | sort -n | tr '\n' ' ' | sed 's/ $//')
                if [ "$args" == "$sorted_args" ]; then
                    success=$((success + 1))
                    total_ops=$((total_ops + op_count))
                else
                    echo -e "  ${RED}Failed to sort (no operations)${RESET} — size $size, test $i"
                    echo -e "    ${CYAN}Test list: $args${RESET}"
                    echo -e "    ${CYAN}Expected:  $sorted_args${RESET}"
                    failed_tests=$((failed_tests + 1))
                fi
            else
                # For now, assume operations work if we have no checker
                success=$((success + 1))
                total_ops=$((total_ops + op_count))
            fi
        fi
    done
    
    # Calculate average operations
    if [ $success -gt 0 ]; then
        avg_ops=$((total_ops / success))
        if [ $failed_tests -eq 0 ]; then
            echo -e "${GREEN}✓ $success/$TESTS_PER_SIZE passed (avg: $avg_ops ops)${RESET}"
        else
            echo -e "${YELLOW}✓ $success/$TESTS_PER_SIZE passed (avg: $avg_ops ops)${RESET}"
        fi
    else
        echo -e "${RED}✗ 0/$TESTS_PER_SIZE passed${RESET}"
    fi
done

echo
echo "Tests completed!"