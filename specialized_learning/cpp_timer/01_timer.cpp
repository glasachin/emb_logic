
#include <iostream>
#include <csignal>
#include <ctime>
#include <unistd.h>

#define TIMER_SIGNAL SIGRTMIN

// 1. THIS IS THE TIMER HANDLER (Callback)
void timer_handler(int sig, siginfo_t *si, void *uc) {
    // Note: Inside signal handlers, you should strictly use async-signal-safe functions!
    // Write directly to standard output instead of printf/std::cout in high-reliability code.
    const char msg[] = "Timer expired!\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
}

int main() {
    // 2. Register the signal handler
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = timer_handler; // Assigning our timer_handler callback
    sigemptyset(&sa.sa_mask);
    sigaction(TIMER_SIGNAL, &sa, NULL);

    // 3. Configure the POSIX timer
    timer_t timerid;
    struct sigevent sev;
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = TIMER_SIGNAL;
    sev.sigev_value.sival_ptr = &timerid;

    timer_create(CLOCK_MONOTONIC, &sev, &timerid);

    // 4. Arm the timer (fires in 1 sec, then repeats every 1 sec)
    struct itimerspec its;
    its.it_value.tv_sec = 1;
    its.it_value.tv_nsec = 0;
    its.it_interval.tv_sec = 1;
    its.it_interval.tv_nsec = 0;

    timer_settime(timerid, 0, &its, NULL);

    // Keep process alive to catch timer events
    for (int i = 0; i < 3; ++i) {
        sleep(2);
    }

    timer_delete(timerid);
    return 0;
}
