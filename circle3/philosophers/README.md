*This project has been created as a part of the 42 curriculum by fbaras.*

# Description
- philosophers is a project about the Dining Philosophers Problem which is a classic synchronization problem. It illustrates the challenges of resource sharing in concurrent programming, such as deadlock, starvation, and mutual exclusion.
## Problem Statement
- K philosophers sit around a circular table.
- Each philosopher alternates between thinking and eating.
- There is one chopstick between each philosopher (total K chopsticks).
- A philosopher must pick up two chopsticks (left and right) to eat.
- Only one philosopher can use a chopstick at a time.
- The challenge: Design a synchronization mechanism so that philosophers can eat without causing deadlock (all waiting forever) or starvation (some never get a chance to eat).

## Compilation
```bash
git clone <repository-url>
cd philosophers/philo
make
```
## How to run
    ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep
    [number_of_times_each_philosopher_must_eat]

# Resources
- man page for pthreads.
- codeVault youtube play list on threads: https://youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&si=Qc5yvKuRmbe_APD1
- geeksforgeeks: https://www.geeksforgeeks.org/operating-systems/dining-philosopher-problem-using-semaphores/
- https://www.geeksforgeeks.org/operating-systems/dining-philosophers-problem/

## AI USAGE:
        valgrind usage for detecting race conditions.
        how deadlocks happen.
        how to avoid deadlocks by using the odd-even strategy.
        understanding gettimeofday() more accurately.
        How to calculate time more accurately.
        why mutexes are important.
        how and when to use mutexes.
        precise timing with ft_usleep.

# example output:
```bash
./philo 5 800 200 200 10
```
    12 2 is thinking
    16 2 has taken a fork
    16 2 has taken a fork
    16 4 is thinking
    16 3 is thinking
    17 1 is thinking
    17 1 has taken a fork
    18 2 is eating
    18 4 has taken a fork
    18 4 has taken a fork
    18 4 is eating
    20 5 is thinking
    218 1 has taken a fork
    219 1 is eating
    219 4 is sleeping
    220 2 is sleeping
    220 5 has taken a fork
    220 3 has taken a fork
    221 3 has taken a fork
    221 3 is eating
    419 1 is sleeping
    419 5 has taken a fork
    419 5 is eating
    420 4 is thinking
    422 2 is thinking
    423 3 is sleeping
    619 1 is thinking

# odd-even strategy.
    Odd-numbered philosophers pick up left fork first.
    Even-numbered philosophers pick up right fork first.
    when creating even numbered threads i put a slight delay to avoid initial congestian when all threads try to take all forks.

# precise timing with ft_usleep.
    The standard usleep() function is imprecise - the OS scheduler adds 1-10ms delay each time.
    Over multiple eat/sleep cycles, these delays accumulate and can cause philosophers to die.
    ft_usleep() solves this by using a busy-wait loop that checks actual elapsed time:
        1. Record the start time
        2. Sleep in tiny 100µs chunks
        3. After each mini-sleep, check real elapsed time
        4. Exit immediately when target time is reached
    This ensures eating/sleeping takes exactly the specified time with no accumulation of delays.

# Syncronized start
    before starting the simulation i wait for all threads to be ready, as well as, the monitor to start the simulation.

    There is a monitoring thread that checks the state of each philosopher, checking if they have reached the number of times to eat, as well as, if they exceeded the time to die without eating. If so the simulation will end.
