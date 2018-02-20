#include <thread>
#include <string>
#include <mutex>
#include <iostream>

//a mutex only protects passages of code NOT VARIABLES, so you need to write code properly to protect that code

std::mutex mu;

bool accessData() {
  mu.lock();
  return true;
}

void printSomething(char a) {
  if(accessData)
    std::cout << "print a thing: " << a;
}

void printSomethingElse() {
  if(accessData)
    std::cout << "print a different thing";
}

int main() {
  std::thread t1(printSomething, 'h');
  std::thread t2(printSomethingElse);
  t1.join();
  t2.join();
  return 0;
}
