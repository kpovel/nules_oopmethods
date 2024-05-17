#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <csignal>
#include <atomic>

class jileWriter {
public:
    FileWriter(const std::string &filename) : file(filename, std::ios::app) {
        if (!file.is_open()) {
            throw std::runtime_error("Unable to open file");
        }
    }

    ~FileWriter() {
        if (file.is_open()) {
            file.close();
        }
    }

    void writeLine(const std::string &line) {
        std::lock_guard<std::mutex> lock(file_mutex);
        file << line << std::endl;
    }

private:
    std::ofstream file;
    static std::mutex file_mutex;
};

std::mutex FileWriter::file_mutex;
std::atomic<bool> keep_running(true);

void signalHandler(int signum) {
    keep_running = false;
}

void writeToFile(FileWriter &writer) {
    std::string line;
    while (keep_running && std::getline(std::cin, line)) {
        writer.writeLine(line);
    }
}

int main() {
  std::signal(SIGINT, signalHandler);
  FileWriter writer("output.txt");
  std::thread input_thread(writeToFile, std::ref(writer));
  input_thread.join();
  return 0;
}

