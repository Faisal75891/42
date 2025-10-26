# Pipex Testing Guide

## 🖥️ For Windows Users

Since you're on Windows, you need to run these tests in **WSL (Windows Subsystem for Linux)** or **Git Bash**. Here's how:

### Option 1: Using WSL (Recommended for 42)

```bash
# In WSL terminal:
cd /mnt/c/Users/Faisa/OneDrive/Desktop/common_core/42/test_pipex

# Make scripts executable
chmod +x test_pipex.sh leak_test.sh

# Run comprehensive tests
./test_pipex.sh

# Run memory leak tests
./leak_test.sh
```

### Option 2: Using Git Bash

```bash
# Open Git Bash
cd /c/Users/Faisa/OneDrive/Desktop/common_core/42/test_pipex

# Make scripts executable
chmod +x test_pipex.sh leak_test.sh

# Run tests
bash test_pipex.sh
bash leak_test.sh
```

---

## 📝 Quick Manual Tests

If you can't run the scripts, here are manual tests you can run:

### Test 1: Basic Pipeline
```bash
cd circle2/pipex
make

# Create test file
echo -e "Hello\nWorld\nTest" > infile.txt

# Run pipex
./pipex infile.txt "cat" "wc -l" outfile.txt

# Check output
cat outfile.txt
# Should show: 3

# Compare with shell
< infile.txt cat | wc -l
# Should also show: 3
```

### Test 2: Multiple Pipes (Bonus)
```bash
# Create test file
echo -e "apple\nbanana\napricot\navocado" > fruits.txt

# Run pipex with 3 commands
./pipex fruits.txt "cat" "grep a" "wc -l" outfile.txt

# Check output
cat outfile.txt

# Compare with shell
< fruits.txt cat | grep a | wc -l
```

### Test 3: here_doc (Bonus)
```bash
# Run pipex in here_doc mode
./pipex here_doc EOF "cat" "wc -l" heredoc_out.txt
line1
line2
line3
EOF

# Check output
cat heredoc_out.txt
# Should show: 3

# Run again to test APPEND
./pipex here_doc EOF "cat" heredoc_out.txt
line4
EOF

# Check that it appended
cat heredoc_out.txt
# Should show all 4 lines
```

### Test 4: Missing Input File
```bash
# This should NOT crash
./pipex nonexistent.txt "cat" "wc -l" outfile.txt

# Should print error but continue
# Check exit code
echo $?
```

### Test 5: Invalid Command
```bash
./pipex infile.txt "invalidcommand123" "wc" outfile.txt

# Check exit code (should be 127)
echo $?
```

---

## 🧪 Testing Environment Variables

### Test with Custom PATH
```bash
# Minimal PATH
env PATH=/bin:/usr/bin ./pipex infile.txt "cat" "wc -l" outfile.txt

# No environment at all
env -i PATH=/bin:/usr/bin ./pipex infile.txt "cat" "wc -l" outfile.txt
```

### Test with Commands (not full paths)
Since you're using `/bin/sh -c`, these should work automatically:

```bash
./pipex infile.txt "cat" "wc -l" outfile.txt        # ✓ Works
./pipex infile.txt "/bin/cat" "wc -l" outfile.txt   # ✓ Also works
./pipex infile.txt "grep test" "wc -l" outfile.txt  # ✓ Works
```

The shell (`/bin/sh`) knows where to find `cat`, `grep`, etc. because they're in standard locations.

---

## 🔍 Memory Leak Testing

### With Valgrind (Linux/WSL only)
```bash
# Install valgrind if needed
sudo apt-get install valgrind

# Test basic pipeline
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
    ./pipex infile.txt "cat" "wc -l" outfile.txt

# Look for this line in output:
# "All heap blocks were freed -- no leaks are possible"

# Check for FD leaks:
# Should NOT see: "Open file descriptor"
```

### Expected Output (Good):
```
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: X allocs, X frees, Y bytes allocated
==12345==
==12345== All heap blocks were freed -- no leaks are possible
==12345==
==12345== FILE DESCRIPTORS: 3 open at exit.
==12345== Open file descriptor 2: /dev/pts/0
==12345== Open file descriptor 1: /dev/pts/0
==12345== Open file descriptor 0: /dev/pts/0
```

Note: FD 0, 1, 2 (stdin, stdout, stderr) are always open - that's normal!

---

## ✅ Pre-Evaluation Checklist

Run these before your evaluation:

```bash
# 1. Compile cleanly
cd circle2/pipex
make re
# Should compile with no warnings

# 2. Test mandatory (basic pipeline)
./pipex infile.txt "cat" "wc -l" outfile.txt
# Compare output with shell

# 3. Test bonus (multiple pipes)
./pipex infile.txt "cat" "grep test" "wc -w" "cat" outfile.txt

# 4. Test bonus (here_doc)
./pipex here_doc EOF "cat" "wc -l" outfile.txt
test
EOF

# 5. Test here_doc append
./pipex here_doc EOF "cat" append_test.txt
first
EOF
./pipex here_doc EOF "cat" append_test.txt
second
EOF
cat append_test.txt
# Should contain both "first" and "second"

# 6. Test error handling
./pipex nonexistent.txt "cat" "wc" out.txt
# Should not crash

# 7. Check norminette
norminette *.c *.h

# 8. Test with valgrind (if available)
valgrind --leak-check=full ./pipex infile.txt "cat" "wc" outfile.txt
```

---

## 🎯 Common Evaluation Questions

### "How does your pipex handle quotes?"
**Answer:** "I use `/bin/sh -c` to execute commands, which handles quotes and special characters just like the real shell."

**Demo:**
```bash
echo "hello world" > infile.txt
./pipex infile.txt "grep 'hello'" "wc -w" outfile.txt
cat outfile.txt  # Shows: 2
```

### "What if the input file doesn't exist?"
**Answer:** "My program prints an error to stderr but continues execution with empty input from /dev/null, matching shell behavior."

**Demo:**
```bash
./pipex nonexistent.txt "cat" "wc -l" outfile.txt
# Prints error but doesn't crash
cat outfile.txt  # Shows: 0
```

### "How does here_doc append work?"
**Answer:** "I use O_APPEND flag when opening the output file in here_doc mode, so multiple runs append instead of overwriting."

**Demo:**
```bash
rm -f test.txt
./pipex here_doc END "cat" test.txt
first
END
./pipex here_doc END "cat" test.txt
second
END
cat test.txt  # Shows both "first" and "second"
```

---

## 📊 Test Results Template

Keep track of your test results:

| Test | Status | Notes |
|------|--------|-------|
| Compile with make | ⬜ | |
| No warnings | ⬜ | |
| Norminette passes | ⬜ | |
| Basic pipeline works | ⬜ | |
| Multiple pipes work | ⬜ | |
| here_doc basic | ⬜ | |
| here_doc append | ⬜ | |
| Missing input file | ⬜ | |
| Invalid command | ⬜ | |
| Complex commands with quotes | ⬜ | |
| No memory leaks | ⬜ | |
| No FD leaks | ⬜ | |

✅ = Passing  
❌ = Failing  
⚠️ = Needs attention  
⬜ = Not tested yet

---

## 🚀 Quick Test Commands

Copy and paste these for rapid testing:

```bash
# Setup
cd circle2/pipex && make re && cd ../..
echo -e "Hello\nWorld\nTest line\nAnother" > test_pipex/infile.txt

# Test 1: Basic
./circle2/pipex/pipex test_pipex/infile.txt "cat" "wc -l" test_pipex/out.txt && cat test_pipex/out.txt

# Test 2: Multiple pipes
./circle2/pipex/pipex test_pipex/infile.txt "cat" "grep e" "wc -l" test_pipex/out.txt && cat test_pipex/out.txt

# Test 3: here_doc
echo -e "line1\nline2" | ./circle2/pipex/pipex here_doc EOF "cat" test_pipex/heredoc.txt && cat test_pipex/heredoc.txt

# Test 4: Error handling
./circle2/pipex/pipex nofile.txt "cat" "wc" test_pipex/out.txt; echo "Exit code: $?"

# Test 5: Valgrind (WSL/Linux only)
valgrind --leak-check=full ./circle2/pipex/pipex test_pipex/infile.txt "cat" "wc -l" test_pipex/out.txt 2>&1 | grep "no leaks are possible"
```

Good luck with your evaluation! 🍀

