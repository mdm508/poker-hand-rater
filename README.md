# Poker Hand Analyzer (C++ Project)
Purpose of this project is to provide you with some structure so it will be easier to focus on the development proccess itself. 

You can use this project as a sort of template for future
projects. It shows you how to organize your code and is suitable for small projects.

## Project Structure

- **poker.h**  
  Header file containing global constants (`HAND_SIZE`, `LOWEST_NUM`, `HIGHEST_NUM`) and all function prototypes.  
  This is the “wishlist” of everything the program will implement.  

- **main.cpp**  
  Entry point of the program.  
  Responsible for reading in a hand from the user and calling the analysis functions to determine the hand type.  

- **my.cpp** *(not in screenshot, but required)*  
  Contains the actual implementation of the functions declared in `poker.h`.  
  Example: `containsPair`, `containsTwoPair`, etc.  

- **tests.cpp**  
  Contains test cases written with Catch2.  
  These verify that each function works correctly before integrating everything in `main.cpp`.  

- **catch.hpp**  
  Single-header testing framework (Catch2 v2).  
  Provides macros like `TEST_CASE` and `REQUIRE` to define and run tests.  

- **makefile**  
  Automates compilation.  
  Provides shortcuts to build the main program, build the tests, run tests, and clean up.  

- **README.md**  
  This file. Explains the purpose of each file and the recommended workflow.  

---

## Recommended Workflow

1. **Start with the wishlist (`poker.h`)**  
   - Write the function header and add clear comments describing what it should do.  

2. **Pick one function at a time**  
   - Example: `containsPair`.  

3. **Write test cases in `tests.cpp`**  
   - Add a `TEST_CASE` with several inputs (one that should pass, and a few that should fail).  

4. **Implement the function in `my.cpp`**  
   - Use simple, readable code that matches the requirements.  

5. **Run the tests**  
   - Use `make run-tests` to compile and execute the test suite.  
   - Confirm that the function works as expected.  

6. **Repeat for each function**  
   - Move on to the next function (e.g., `containsTwoPair`, `containsThreeOfaKind`, etc.).  
   - Always follow the same cycle: write header → write tests → implement → run tests.  

7. **Integrate into `main.cpp`**  
   - Once all functions pass their tests, implement `main.cpp`.  
   - Here you can read user input and call `analyzeHand` to print results.  

---

## Test-Driven Development Workflow (HtDP Style)

This project is best approached one function at a time, following a test-driven development (TDD) cycle.  
The process is very similar to the **How to Design Programs (HtDP)** design recipe: start with the contract, examples, and tests, then move on to the implementation.  

### Step 1: Write the function header and contract
- In `poker.h`, write the function prototype and a short comment (contract).  
- The contract explains:
  - **Name** of the function
  - **Inputs** (parameters)
  - **Outputs** (return type)
  - **Purpose** (what the function should do)

#### What is a contract?
I'm calling the header of a function a contract. We call it a contract because it as an agreement between the implementor of the function (you) and the caller of the function (also probably you, though if you were working on a project with others
it probably wouldn't be). 

`int add(int a, int b)`

The person who wrote `add` is demanding you provide two integers.
The person using `add` is demanding that `add` returns an int.

So it's kind of like, "if you promise to give me two ints then I promise to add them for you and give you back an int".

Here are some examplese from this project.

*Example:*  
```cpp
/**
 * @brief Returns true if the hand contains exactly one pair.
 * @param hand The array of cards
 * @return true if there is a pair, false otherwise
 */
bool containsPair(const int hand[]);
```


### Step 2: Write tests before implementation
	•	Go to tests.cpp.
	•	Create one or more TEST_CASEs for the new function.
	•	Use examples that clarify the contract:
	•	A case where the function should return true.
	•	Cases where the function should return false.
	•	Edge cases from the assignment table.

Example:

```cpp
TEST_CASE("add function works for basic cases") {
    REQUIRE(add(2, 3) == 5);
    REQUIRE(add(-1, 1) == 0);
    REQUIRE(add(0, 0) == 0);
}
```
Above is 3 test cases. You can put all tests cases related to the `add` function inside of this
`TEST_CASE` block.

Here are some other examples
```cpp
TEST_CASE("containsPair") {
    SECTION("Detects a simple pair") {
        int hand[5] = {2, 2, 3, 4, 5};
        REQUIRE( containsPair(hand) );
    }
    SECTION("Does not count three-of-a-kind as a pair") {
        int hand[5] = {2, 2, 2, 4, 5};
        REQUIRE_FALSE( containsPair(hand) );
    }
}
```

### Step 3: Implement the function
	•	Only now do you write the body of the function in my.cpp.
	•	Focus on correctness and clarity, not efficiency.
	•	Use helper functions (buildCounts) when you notice repetition.

### Step 4: Run tests
	•	Build and run the test suite:

`make run-tests`


	•	Confirm that all tests for this function pass.

### Step 5: Refine if needed
	•	If tests fail, go back to your implementation and fix the logic.
	•	If your implementation passes but you see untested behavior, add new test cases.
	•	Keep looping until you are confident.

### Step 6: Repeat
	•	Pick the next function in the wishlist and repeat steps 1–5.
	•	By the end, every function will be tested and reliable.
	•	When all helper functions pass their tests, implementing main.cpp is straightforward.

⸻

### Why this works
	•	Confidence: Every function is verified in isolation.
	•	Small steps: Bugs are easier to find because you only focus on one function at a time.
	•	Clarity: Contracts and examples document exactly what each function is supposed to do.
	•	Reuse: Helper functions (like counting card occurrences) emerge naturally when you see repeated patterns.

This is exactly the HtDP spirit: from problem statement → to function contract → to examples/tests → to implementation.
