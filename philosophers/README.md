# philosophers

## Description

School 42's "philosophers" project is an implementation of the philosophers problem. It is a classic concurrency problem with several philosophers sitting around a table, each with a plate of spaghetti and a fork between each pair of plates. The philosophers can be in one of two states: thinking or eating. To avoid eternal hunger or mutual blockage, certain rules must be followed when taking and releasing the forks.

## Objectives.

1. **Simulation of the problem:**
   - Implement a multi-threaded simulation of the philosophers' problem.

2. **Concurrency management:**
   - Use mutexes or semaphores to manage concurrency and avoid race conditions.

3. **Mutual Deadlock Prevention:**
   - Implement logic to prevent mutual deadlock and eternal philosopher's hunger.

4. **Time Measurement:**
   - Measure and display the time each philosopher spends thinking and eating.

5. **Argument management:**
   - Allow flexible settings for the number of philosophers, time spent thinking or eating, etc.
