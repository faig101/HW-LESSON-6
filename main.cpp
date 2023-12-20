#include <iostream>
#include <string>
using namespace std;
struct PrintJob {
    string user;
    int priority;
};
struct PrintStat {
    string user;
};

void printStatistics(const PrintStat printQueue[], int front, int rear) {
    cout << "Printing Statistics:\n";

    while (front != rear) {
        PrintStat stat = printQueue[front++];
        cout << "User: " << stat.user << "\n";
    }
}

int main() {
    const int max_size = 100;

    PrintJob* printQueue = new PrintJob[max_size];
    PrintStat* printStats = new PrintStat[max_size];
    int front = 0;
    int rear = 0;

    PrintJob job1 = {"user1", 2};
    PrintJob job2 = {"ser2", 1};
    PrintJob job3 = {"user3", 3};
    printQueue[rear++] = job1;
    rear %= max_size;
    printQueue[rear++] = job2;
    rear %= max_size;
    printQueue[rear++] = job3;
    rear %= max_size;
    while (front != rear) {
        PrintJob currentJob = printQueue[front++];
        front %= max_size;
        cout << "Printing: User " << currentJob.user << " (Priority: " << currentJob.priority << ")\n";
        PrintStat stat = {currentJob.user};
        printStats[rear++] = stat;
        rear %= max_size;
    }
    printStatistics(printStats, front, rear);
    delete[] printQueue;
    delete[] printStats;

    return 0;
}
