#include "access.h"
#include <mutex>
#include "editor.h"

void accessDate(Editor &editor) {
  editor.mu.lock();
}

void accessComplete(Editor &editor) {
  editor.mu.unlock();
}
