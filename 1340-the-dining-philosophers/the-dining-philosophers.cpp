

class DiningPhilosophers {
public:
    mutex forks[5];  // 5 forks

    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int left = philosopher;              // left fork
        int right = (philosopher + 1) % 5;   // right fork

        if (philosopher % 2 == 0) {
            // Even philosopher: pick right first, then left
            forks[right].lock();
            forks[left].lock();
        } else {
            // Odd philosopher: pick left first, then right
            forks[left].lock();
            forks[right].lock();
        }

        // Actions
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        // Release forks
        forks[left].unlock();
        forks[right].unlock();
    }
};
