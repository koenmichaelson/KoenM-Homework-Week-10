#include <iostream>
#include <sstream>
#include "LinkedList.cpp"

// Helper functions for testing
template <typename T>
bool checkTest(int testNum, int& correct, T whatItShouldBe, T whatItIs) {
    if (whatItShouldBe == whatItIs) {
        correct++;
        std::cout << "***TEST " << testNum << " PASSED***" << std::endl;
        return true;
    } else {
        std::cout << "***TEST " << testNum << " FAILED*** " << std::endl;
        std::cout << "   Output was " << whatItIs << std::endl;
        std::cout << "   Output should have been " << whatItShouldBe << std::endl;
        return false;
    }
}

// Individual test functions
void testInitialSize(int& correctTests) {
    Queue queue;
    checkTest(1, correctTests, 0, queue.size());
}

void testInitialEmpty(int& correctTests) {
    Queue queue;
    checkTest(2, correctTests, true, queue.isEmpty());
}

void testEnqueueOneItemSize(int& correctTests) {
    Queue queue;
    queue.enqueue("Apple");
    checkTest(3, correctTests, 1, queue.size());
}

void testEnqueueOneItemEmpty(int& correctTests) {
    Queue queue;
    queue.enqueue("Apple");
    checkTest(4, correctTests, false, queue.isEmpty());
}

void testEnqueueOneItemPeek(int& correctTests) {
    Queue queue;
    queue.enqueue("Apple");
    checkTest(5, correctTests, std::string("Apple"), queue.peek());
}

void testDequeueOneItemSize(int& correctTests) {
    Queue queue;
    queue.enqueue("Apple");
    queue.dequeue();
    checkTest(6, correctTests, 0, queue.size());
}

void testDequeueOneItemEmpty(int& correctTests) {
    Queue queue;
    queue.enqueue("Apple");
    queue.dequeue();
    checkTest(7, correctTests, true, queue.isEmpty());
}

void testDequeueFromEmpty(int& correctTests) {
    Queue queue;
    queue.dequeue(); // should not crash
    checkTest(8, correctTests, true, queue.isEmpty());
}

void testPeekEmptyQueue(int& correctTests) {
    Queue queue;
    checkTest(9, correctTests, std::string(""), queue.peek());
}

void testEnqueueMultipleItemsSize(int& correctTests) {
    Queue queue;
    queue.enqueue("Banana");
    queue.enqueue("Cherry");
    queue.enqueue("Date");
    checkTest(10, correctTests, 3, queue.size());
}

void testEnqueueMultipleItemsPeek(int& correctTests) {
    Queue queue;
    queue.enqueue("Banana");
    queue.enqueue("Cherry");
    queue.enqueue("Date");
    checkTest(11, correctTests, std::string("Banana"), queue.peek());
}

void testDequeueOneFromMultipleSize(int& correctTests) {
    Queue queue;
    queue.enqueue("Banana");
    queue.enqueue("Cherry");
    queue.enqueue("Date");
    queue.dequeue();
    checkTest(12, correctTests, 2, queue.size());
}

void testDequeueOneFromMultiplePeek(int& correctTests) {
    Queue queue;
    queue.enqueue("Banana");
    queue.enqueue("Cherry");
    queue.enqueue("Date");
    queue.dequeue();
    checkTest(13, correctTests, std::string("Cherry"), queue.peek());
}

void testEnqueueAdditionalItemSize(int& correctTests) {
    Queue queue;
    queue.enqueue("Banana");
    queue.enqueue("Cherry");
    queue.enqueue("Date");
    queue.dequeue();
    queue.enqueue("Elderberry");
    checkTest(14, correctTests, 3, queue.size());
}

void testEnqueueAdditionalItemPeek(int& correctTests) {
    Queue queue;
    queue.enqueue("Banana");
    queue.enqueue("Cherry");
    queue.enqueue("Date");
    queue.dequeue();
    queue.enqueue("Elderberry");
    checkTest(15, correctTests, std::string("Cherry"), queue.peek());
}

// Function to run all tests
void runAllTests() {
    int correctTests = 0;
    testInitialSize(correctTests);
    testInitialEmpty(correctTests);
    testEnqueueOneItemSize(correctTests);
    testEnqueueOneItemEmpty(correctTests);
    testEnqueueOneItemPeek(correctTests);
    testDequeueOneItemSize(correctTests);
    testDequeueOneItemEmpty(correctTests);
    testDequeueFromEmpty(correctTests);
    testPeekEmptyQueue(correctTests);
    testEnqueueMultipleItemsSize(correctTests);
    testEnqueueMultipleItemsPeek(correctTests);
    testDequeueOneFromMultipleSize(correctTests);
    testDequeueOneFromMultiplePeek(correctTests);
    testEnqueueAdditionalItemSize(correctTests);
    testEnqueueAdditionalItemPeek(correctTests);
    std::cout << "Total tests passed: " << correctTests << " out of 15" << std::endl;
}

// Main function to run specific tests
int main(int argc, char* argv[]) {
    if (argc == 1) {
        runAllTests();
    } else if (argc == 2) {
        int correctTests = 0;
        int testNumber = std::atoi(argv[1]);

        switch (testNumber) {
            case 1:
                testInitialSize(correctTests);
                break;
            case 2:
                testInitialEmpty(correctTests);
                break;
            case 3:
                testEnqueueOneItemSize(correctTests);
                break;
            case 4:
                testEnqueueOneItemEmpty(correctTests);
                break;
            case 5:
                testEnqueueOneItemPeek(correctTests);
                break;
            case 6:
                testDequeueOneItemSize(correctTests);
                break;
            case 7:
                testDequeueOneItemEmpty(correctTests);
                break;
            case 8:
                testDequeueFromEmpty(correctTests);
                break;
            case 9:
                testPeekEmptyQueue(correctTests);
                break;
            case 10:
                testEnqueueMultipleItemsSize(correctTests);
                break;
            case 11:
                testEnqueueMultipleItemsPeek(correctTests);
                break;
            case 12:
                testDequeueOneFromMultipleSize(correctTests);
                break;
            case 13:
                testDequeueOneFromMultiplePeek(correctTests);
                break;
            case 14:
                testEnqueueAdditionalItemSize(correctTests);
                break;
            case 15:
                testEnqueueAdditionalItemPeek(correctTests);
                break;
            default:
                std::cerr << "Invalid test number. Please enter a number between 1 and 15" << std::endl;
                return 1;
        }

        std::cout << "Total tests passed: " << correctTests << " out of 15" << std::endl;
    } else {
        std::cerr << "Usage: " << argv[0] << " [testNumber]" << std::endl;
        return 1;
    }

    return 0;
}
