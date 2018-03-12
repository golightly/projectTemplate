#include "access.h"
#include <mutex>
#include "editor.h"

void accessData(Editor &editor) {
  editor.mu.lock();
}

void accessComplete(Editor &editor) {
  editor.mu.unlock();
}
