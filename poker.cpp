#include "poker.h"

/*
I wanted to show what it looks like when a test case passes.
So I implemented the functions in poker.cpp and wrote tests in tests.cpp.
You can see that the tests pass when you run `make test`.
You can try and delete the solution and try and solve it
yourself if you want to.

I purposely left containsPair and containsTwoPair for you to implement.
You can run `make run-tests` to see if your implementation is correct.
*/

void buildCounts(const int hand[], int counts[]) {
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        counts[i] = 0;
    }
    for (int i = 0; i < HAND_SIZE; i++) {
        counts[hand[i]]++;
    }
}

bool containsPair(const int hand[]) {
    int counts[HIGHEST_NUM + 1];
    buildCounts(hand, counts);

    int pairCount = 0;
    for (int i = LOWEST_NUM; i <= HIGHEST_NUM; i++) {
        if (counts[i] == 2) {
            pairCount++;
        } else if (counts[i] > 2) {
            return false;
        }
    }
    return (pairCount == 1);
}

bool containsTwoPair(const int hand[]) {
    // TODO: implement this function
    return false;
}

/*
If you want to do all your wishlist entries first you can
just return dummy values as shown above.
Then you can come back and implement the functions properly later.
*/