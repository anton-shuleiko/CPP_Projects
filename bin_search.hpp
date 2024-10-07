#pragma once

int* LowerBound(int* first, int* last, int value) {
  while (first != last - 1) {
    int* mid = first + (last - first) / 2;
    if (*(mid) >= value) {
      last = mid;
    } else {
      first = mid;
    }
  }
  if (*first >= value) {
    return first;
  }
  return last;
}
