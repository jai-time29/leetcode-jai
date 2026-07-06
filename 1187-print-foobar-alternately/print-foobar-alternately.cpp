#include <semaphore>

class FooBar {
private:
    int n;
    binary_semaphore fooSem{1};
    binary_semaphore barSem{0};

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            fooSem.acquire();

            printFoo();

            barSem.release();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            barSem.acquire();

            printBar();

            fooSem.release();
        }
    }
};
/*
class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool fooTurn = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for(int i=0;i<n;i++) {

            unique_lock<mutex> lock(mtx);

            cv.wait(lock,[&]{
                return fooTurn;
            });

            printFoo();

            fooTurn = false;

            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {

        for(int i=0;i<n;i++) {

            unique_lock<mutex> lock(mtx);

            cv.wait(lock,[&]{
                return !fooTurn;
            });

            printBar();

            fooTurn = true;

            cv.notify_one();
        }
    }
}; */