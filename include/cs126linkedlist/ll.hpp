// Copyright (c) 2020 CS126SP20. All rights reserved.

#include <cassert>
#include <utility>
#include <vector>

#include "ll.h"

namespace cs126linkedlist {

template <typename ElementType>
LinkedList<ElementType>::LinkedList() {
  head_ = nullptr;
}

template <typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType>& values) {
  head_ = nullptr;

  for (size_t idx = 0; idx < values.size(); ++idx) {
    push_back(values[idx]);
  }
}

// Copy constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
  if (source.head_ == nullptr) {
    head_ = nullptr;
    return;
  }

  head_ = new Node;
  head_->element_ = source.head_->element_;
  Node* curr_ = head_;
  Node* source_curr_ = source.head_->next_;

  while (source_curr_ != nullptr) {
    curr_->next_ = new Node;
    curr_ = curr_->next_;
    curr_->element_ = source_curr_->element_;
    source_curr_ = source_curr_->next_;
  }

  curr_->next_ = nullptr;
}

// Move constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {

  if (source.head_ == nullptr) {
    head_ = nullptr;
    return;
  }

  head_ = new Node;
  head_->element_ = source.head_->element_;
  Node* curr_ = head_;
  Node* source_curr_ = source.head_->next_;

  while (source_curr_ != nullptr) {
    curr_->next_ = new Node;
    curr_ = curr_->next_;
    curr_->element_ = source_curr_->element_;
    source_curr_ = source_curr_->next_;
  }

  curr_->next_ = nullptr;

  source.clear();
}

// Destructor
template <typename ElementType>
LinkedList<ElementType>::~LinkedList() {
  clear();
  delete head_;
}

// Copy assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    const LinkedList<ElementType>& source) {
  clear();
  head_ = new LinkedList<ElementType>(source);
}

// Move assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    LinkedList<ElementType>&& source) noexcept {
  if (this != &source) {
    clear();
    head_ = source.head_;
    source.head_ = nullptr;
  }

  return *this;
}

template <typename ElementType>
void LinkedList<ElementType>::push_front(const ElementType& value) {
  Node* new_node_ = new Node;
  new_node_->element_ = value;
  new_node_->next_ = head_;
  head_ = new_node_;
}

template <typename ElementType>
void LinkedList<ElementType>::push_back(const ElementType& value) {
  Node* new_node_ = new Node;
  new_node_->next_ = nullptr;
  new_node_->element_ = value;

  if (head_ == nullptr) {
    head_ = new_node_;
  } else {
    Node* curr_ = head_;

    while (curr_->next_ != nullptr) {
      curr_ = curr_->next_;
    }
    curr_->next_ = new_node_;
  }
}

template <typename ElementType>
ElementType LinkedList<ElementType>::front() const {
  if (head_ == nullptr) {
    throw std::invalid_argument("Empty list");
  }

  return head_->element_;
}

template <typename ElementType>
ElementType LinkedList<ElementType>::back() const {
  if (head_ == nullptr) {
    throw std::invalid_argument("Empty list");
  }

  Node* curr_ = head_;
  while (curr_->next_ != nullptr) {
    curr_ = curr_->next_;
  }

  return curr_->element_;
}

template <typename ElementType>
void LinkedList<ElementType>::pop_front() {
  Node* curr_ = head_;
  head_ = head_->next_;
  delete curr_;
}

template <typename ElementType>
void LinkedList<ElementType>::pop_back() {
  if (head_->next_ == nullptr) {
    delete head_;
    head_ = nullptr;
    return;
  }

  Node* curr_ = head_;
  Node* second_to_last_ = head_->next_;

  while (second_to_last_->next_ != nullptr) {
    curr_ = curr_->next_;
  }

  delete second_to_last_;
  curr_->next_ = nullptr;
}

template <typename ElementType>
size_t LinkedList<ElementType>::size() const {
  size_t count = 0;
  Node* curr_ = head_;

  while (curr_ != nullptr) {
    ++count;
    curr_ = curr_->next_;
  }

  return count;
}

template <typename ElementType>
bool LinkedList<ElementType>::empty() const {
  return head_ == nullptr;
}

template <typename ElementType>
void LinkedList<ElementType>::clear() {
  Node* curr_ = head_;

  while (curr_ != nullptr) {
    Node* next = curr_->next_;
    delete curr_;
    curr_ = next;
  }
  head_ = nullptr;
}

template <typename ElementType>
std::ostream& operator<<(std::ostream& os,
                         const LinkedList<ElementType>& list) {
  size_t count = 0;
  for (const ElementType& element : list) {
    ++count;

    if (count == list.size()) {
      os << element;
    } else {
      os << element << ", ";
    }
  }

  return os;
}

template <typename ElementType>
void LinkedList<ElementType>::RemoveNth(size_t n) {
  Node* curr_ = head_;

  if (n == 0) {
    pop_front();
    return;
  }

  if (n >= size() || n < 0) {
    return;
  }

  for (size_t i = 0; i < n - 1; ++i) {
    curr_ = curr_->next_;
  }

  Node* after_ = curr_->next_->next_;
  delete curr_->next_;
  curr_->next_ = after_;
}

template <typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {
  Node* even_ = head_;
  Node* odd_ = head_->next_;

  while (even_ != nullptr && odd_ != nullptr) {
    even_->next_ = odd_->next_;
    delete odd_;

    even_ = even_->next_;

    if (even_ != nullptr) {
      odd_ = even_->next_;
    }
  }
}

template <typename ElementType>
bool LinkedList<ElementType>::operator==(
    const LinkedList<ElementType>& rhs) const {
  if (head_ == nullptr && rhs.head_ == nullptr) {
    return true;
  } else if (head_ == nullptr || rhs.head_ == nullptr) {
    return false;
  }

  if (size() != rhs.size()) {
    return false;
  }

  Node* new_head_ = head_;
  Node* new_rhs_ = rhs.head_;

  while (new_head_ != nullptr && new_rhs_ != nullptr) {
    if (new_head_->element_ != new_rhs_->element_) {
      return false;
    }
    new_head_ = new_head_->next_;
    new_rhs_ = new_rhs_->next_;
  }

  return true;
}

template <typename ElementType>
bool LinkedList<ElementType>::operator!=(
    const LinkedList<ElementType>& rhs) const {
  if (head_ == nullptr && rhs.head_ == nullptr) {
    return false;
  } else if (head_ == nullptr || rhs.head_ == nullptr) {
    return true;
  }

  if (size() != rhs.size()) {
    return true;
  }

  Node* new_head_ = head_;
  Node* new_rhs_ = rhs.head_;

  while (new_head_ != nullptr && new_rhs_ != nullptr) {
    if (new_head_->element_ != new_rhs_->element_) {
      return true;
    }
    new_head_ = new_head_->next_;
    new_rhs_ = new_rhs_->next_;
  }

  return false;
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator&
LinkedList<ElementType>::iterator::operator++() {
  current_ = current_->next_;

  return *this;
}

template <typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {
  return current_->element_;
}

template <typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(
    const typename LinkedList<ElementType>::iterator& other) const {
  if (other.current_ == current_) {
    return false;
  }

  return true;
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
  return head_;
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
  return nullptr;
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator&
LinkedList<ElementType>::const_iterator::operator++() {
  current_ = current_->next_;

  return *this;
}

template <typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {
  return current_->element_;
}

template <typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(
    const typename LinkedList<ElementType>::const_iterator& other) const {
  if (other.current_ == current_) {
    return false;
  }

  return true;
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator
LinkedList<ElementType>::begin() const {
  return head_;
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end()
    const {
  return nullptr;
}

}  // namespace cs126linkedlist