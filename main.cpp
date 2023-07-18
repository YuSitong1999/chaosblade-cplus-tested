//
// Created by root on 23-7-17.
//

#include<iostream>
#include <thread>
#include <chrono>

using namespace std;

// for getpid()
#include <unistd.h>

// print system time and PID
int printTimeAndHelloWorld(const string &filePath, const int count) {
    time_t now = time(nullptr);
    char *dt = ctime(&now);
    // output to console
    cout << count << endl;
    cout << "The local date and time is: " << dt;
    // output same to file
    FILE *fp = fopen(filePath.c_str(), "a");
    fprintf(fp, "%d\n", count);
    fprintf(fp, "The local date and time is: %s", dt);
    fclose(fp);
    return count * count;
}

int main() {
    // get the path where program running
    string path = get_current_dir_name();
    cout << "The path is: " << path << endl;
    cout << "PID: " << getpid() << endl;
    // create new file
    string filePath = path + "/hello.txt";
    FILE *fp = fopen(filePath.c_str(), "w");
    fprintf(fp, "PID: %d\n", getpid());
    fclose(fp);

    int count = 0;
    while (true) {
        ++count;
        const auto result = printTimeAndHelloWorld(filePath, count);
        cout << "result: " << result << endl;
        fp = fopen(filePath.c_str(), "a");
        fprintf(fp, "result: %d\n", result);
        fclose(fp);
        // C++: sleep 10s
        this_thread::sleep_for(chrono::seconds(5));
    }
}
