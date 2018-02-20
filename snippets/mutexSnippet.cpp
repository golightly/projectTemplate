#include <thread>
#include <string>
#include <mutex>
#include <iostream>

//a mutex only protects passages of code NOT VARIABLES, so you need to write code properly to protect that code

std::mutex mu;

void accessData() {
  mu.lock();
}

void accessComplete() {
  mu.unlock();
}

void printSomething(char a) {
  accessData();
  std::cout << "print a thing: " << a;
  accessComplete();
}

void printSomethingElse() {
  accessData();
  std::cout << "print a different thing";
  accessComplete();
}

int main() {
  std::thread t1(printSomething, 'h');
  std::thread t2(printSomethingElse);
  t1.join();
  t2.join();
  return 0;
}
