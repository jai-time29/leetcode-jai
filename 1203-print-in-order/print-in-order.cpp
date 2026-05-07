#include <mutex>
#include <condition_variable>

class Foo {
private:
    mutex mtx;
    condition_variable cv;

    bool firstDone = false;
    bool secondDone = false;

public:
    Foo() {}

    void first(function<void()> printFirst) {

        // printFirst() outputs "first".
        printFirst();

        unique_lock<mutex> lock(mtx);
        firstDone = true;

        cv.notify_all();
    }

    void second(function<void()> printSecond) {

        unique_lock<mutex> lock(mtx);

        // Wait until first() finishes
        cv.wait(lock, [&]() {
            return firstDone;
        });

        printSecond();

        secondDone = true;

        cv.notify_all();
    }

    void third(function<void()> printThird) {

        unique_lock<mutex> lock(mtx);

        // Wait until second() finishes
        cv.wait(lock, [&]() {
            return secondDone;
        });

        printThird();
    }
};