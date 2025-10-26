# PIPEX EVALUATION PREPARATION GUIDE

## ✅ Pre-Evaluation Checklist

### 1. **Compilation**
- [ ] `make` compiles without warnings
- [ ] `make` doesn't relink unnecessarily
- [ ] `make clean` removes object files
- [ ] `make fclean` removes everything (including binary and libraries)
- [ ] `make re` works correctly

```bash
cd circle2/pipex
make
make        # Should say "nothing to be done"
make clean
make fclean
make re
```

### 2. **Norminette**
- [ ] All `.c` files pass norminette
- [ ] All `.h` files pass norminette

```bash
norminette *.c *.h
```

### 3. **Memory Leaks (CRITICAL!)**
- [ ] No leaks in basic pipeline
- [ ] No leaks with multiple pipes
- [ ] No leaks in here_doc mode
- [ ] All file descriptors closed properly

```bash
# Test basic pipeline
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
    ./pipex infile "cat" "wc" outfile

# Test here_doc
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
    ./pipex here_doc EOF "cat" "wc" outfile
```

**Expected output:** `All heap blocks were freed -- no leaks are possible`

### 4. **Error Handling**
- [ ] No segfaults with any input
- [ ] No double free
- [ ] No bus errors
- [ ] Handles all edge cases gracefully

### 5. **Mandatory Part**
- [ ] Takes exactly 4 arguments (+ program name)
- [ ] Behaves like `< file1 cmd1 | cmd2 > file2`
- [ ] Error messages match shell behavior
- [ ] Exit codes match shell behavior

### 6. **Bonus Part**
- [ ] Handles unlimited number of pipes
- [ ] `here_doc` mode works correctly
- [ ] `here_doc` uses **append** mode (>>)
- [ ] Multiple here_doc runs append to file

---

## 🎯 Questions Evaluator Might Ask

### **About the Implementation:**

1. **"Why did you use `/bin/sh -c` instead of parsing commands yourself?"**
   - Answer: "To handle complex commands with quotes, special characters, and shell operators correctly, just like the real shell does."

2. **"How do you handle multiple pipes?"**
   - Answer: "I create a loop that forks a child process for each command. Each child sets up its input (from previous pipe or file) and output (to next pipe or file), then executes the command."

3. **"What happens if the input file doesn't exist?"**
   - Answer: "My program prints an error to stderr but continues execution with empty input (using /dev/null), matching shell behavior."

4. **"How does here_doc work?"**
   - Answer: "I fork a process that reads stdin until it finds the limiter, writes to a pipe, then the first command reads from that pipe. The output file uses O_APPEND mode."

5. **"How do you prevent memory leaks?"**
   - Answer: "I carefully free all allocated memory and close all file descriptors. I use valgrind to verify."

6. **"What if there's no PATH in the environment?"**
   - Answer: "My program uses `/bin/sh -c` which has built-in command paths, so it still works."

---

## 🧪 Edge Cases to Demonstrate

### Test 1: Basic Functionality
```bash
./pipex infile "cat" "wc -l" outfile
# Compare with:
< infile cat | wc -l > outfile
```

### Test 2: Multiple Pipes (Bonus)
```bash
./pipex infile "cat" "grep test" "wc -w" "cat" outfile
# Compare with:
< infile cat | grep test | wc -w | cat > outfile
```

### Test 3: here_doc (Bonus)
```bash
./pipex here_doc EOF "cat" "grep hello" outfile
hello world
hello everyone
goodbye
EOF
```

### Test 4: here_doc Append Behavior
```bash
# First run
echo "first" | ./pipex here_doc EOF "cat" outfile
# Second run
echo "second" | ./pipex here_doc EOF "cat" outfile
# outfile should contain both "first" and "second"
cat outfile
```

### Test 5: Missing Input File
```bash
./pipex nonexistent.txt "cat" "wc" outfile
# Should print error but continue
```

### Test 6: Invalid Command
```bash
./pipex infile "invalidcmd" "wc" outfile
# Should fail gracefully, exit code 127
echo $?
```

### Test 7: Complex Commands
```bash
./pipex infile "grep 'hello world'" "wc -l" outfile
./pipex infile "awk '{print \$1}'" "sort" outfile
```

### Test 8: Custom Environment
```bash
env -i PATH=/bin:/usr/bin ./pipex infile "cat" "wc" outfile
```

---

## 🚨 Common Mistakes to Avoid

1. **❌ Using O_TRUNC for here_doc output**
   - ✅ Should use O_APPEND

2. **❌ Exiting when input file doesn't exist**
   - ✅ Should print error and continue with empty input

3. **❌ Not closing file descriptors**
   - ✅ Close all FDs in parent and child processes

4. **❌ Memory leaks with ft_split**
   - ✅ Always free the array and all strings

5. **❌ Wrong argument count check**
   - ✅ Mandatory: argc == 5
   - ✅ Bonus here_doc: argc >= 6
   - ✅ Bonus multiple pipes: argc >= 5

6. **❌ Not handling quotes in commands**
   - ✅ Using `/bin/sh -c` handles this automatically

7. **❌ Wrong exit codes**
   - ✅ 0 for success
   - ✅ 127 for command not found
   - ✅ 1 for other errors

---

## 📋 Evaluation Session Flow

### **Part 1: Compilation & Norm (5 min)**
- Evaluator runs `make`
- Checks for warnings
- Runs `norminette`

### **Part 2: Mandatory Tests (10 min)**
- Basic 2-command pipeline
- Different commands (cat, grep, wc, ls, etc.)
- Error handling

### **Part 3: Bonus Tests (10 min)**
- Multiple pipes (3+ commands)
- here_doc basic usage
- here_doc append behavior

### **Part 4: Memory & Leaks (5 min)**
- Run valgrind on several tests
- Check for crashes

### **Part 5: Questions (5 min)**
- Code explanation
- Design decisions
- Edge cases

---

## 🎓 Quick Self-Evaluation

Run these commands before your evaluation:

```bash
# 1. Compile
cd circle2/pipex && make re

# 2. Run comprehensive tests
cd ../../test_pipex
chmod +x test_pipex.sh
./test_pipex.sh

# 3. Check for memory leaks
chmod +x leak_test.sh
./leak_test.sh

# 4. Run norminette
cd ../circle2/pipex
norminette *.c *.h
```

If all pass, you're ready! 🎉

---

## 💡 Pro Tips

1. **Explain your code confidently** - Know every line
2. **Have your own tests ready** - Show you tested thoroughly
3. **Admit if you don't know something** - Better than making up answers
4. **Compare with actual shell** - Use bash as reference
5. **Know your FD management** - This is where most bugs happen

---

## 📚 Key Concepts to Review

- **Fork and exec** - Process creation and execution
- **Pipes** - Inter-process communication
- **File descriptors** - stdin (0), stdout (1), stderr (2)
- **dup2** - Duplicating file descriptors
- **wait/waitpid** - Waiting for child processes
- **Exit codes** - Proper error reporting
- **O_TRUNC vs O_APPEND** - File opening modes

Good luck with your evaluation! 🍀

