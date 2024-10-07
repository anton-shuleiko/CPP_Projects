#pragma once

#include <cstddef>
#include <vector>

class RingBuffer {
  std::vector<int> arr_;
  size_t cap_;

 public:
  explicit RingBuffer(size_t capacity) { this->cap_ = capacity; }

  size_t Size() const { return this->arr_.size(); }

  bool Empty() const { return (this->arr_.empty()); }

  bool TryPush(int element) {
    if (this->arr_.size() == this->cap_) {
      return false;
    }
    this->arr_.push_back(element);
    return true;
  }

  bool TryPop(int* element) {
    if (this->Empty()) {
      return false;
    }
    *element = this->arr_[0];
    for (size_t i = 0; i < this->arr_.size() - 1; i++) {
      this->arr_[i] = this->arr_[i + 1];
    }
    this->arr_.pop_back();
    return true;
  }
};
