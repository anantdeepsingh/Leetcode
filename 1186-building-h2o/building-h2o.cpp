class H2O {
public:
    mutex m;
    condition_variable cv;
    int turn;  // 0,1 → H; 2 → O

    H2O() {
        turn = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&] { return turn % 3 != 2; }); // only 0 or 1 is hydrogen's turn

        releaseHydrogen();
        turn = (turn + 1) % 3;   // move to next slot
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&] { return turn % 3 == 2; }); // oxygen only when turn == 2

        releaseOxygen();
        turn = (turn + 1) % 3;   // wrap back to start of next molecule
        cv.notify_all();
    }
};
