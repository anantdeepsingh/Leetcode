class FizzBuzz {
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn;

public:
    FizzBuzz(int n) {
        this->n = n;
        turn = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (turn <= n && !(turn % 3 == 0 && turn % 5 != 0)) {
                cv.wait(lock);
            }
            if (turn > n) break;
            printFizz();
            turn++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (turn <= n && !(turn % 5 == 0 && turn % 3 != 0)) {
                cv.wait(lock);
            }
            if (turn > n) break;
            printBuzz();
            turn++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (turn <= n && !(turn % 3 == 0 && turn % 5 == 0)) {
                cv.wait(lock);
            }
            if (turn > n) break;
            printFizzBuzz();
            turn++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (turn <= n && (turn % 3 == 0 || turn % 5 == 0)) {
                cv.wait(lock);
            }
            if (turn > n) break;
            printNumber(turn);
            turn++;
            cv.notify_all();
        }
    }
};
