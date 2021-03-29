// Copyright (c) 2020 CS126SP20. All rights reserved.

#include "ll.h"

#include <cassert>
#include <utility>
#include <vector>

// TODO(you): Implement these methods.

namespace cs126linkedlist {

template <typename ElementType>
LinkedList<ElementType>::LinkedList() {
  head_ = nullptr;
}

template <typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType>& values) {}

// Copy constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {}

// Move constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {

}

// Destructor
template <typename ElementType>
LinkedList<ElementType>::~LinkedList() {
}

// Copy assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    const LinkedList<ElementType>& source) {}

// Move assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    LinkedList<ElementType>&& source) noexcept {}

template <typename ElementType>
void LinkedList<ElementType>::push_front(const ElementType& value) {
  Node *new_node_ = new Node;
  new_node_->element_ = value;
  new_node_->next_ = head_;
  head_ = new_node_;
}

template <typename ElementType>
void LinkedList<ElementType>::push_back(const ElementType& value) {
  Node *new_node_ = new Node;
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
  Node *curr_ = head_;
  while (curr_->next_ != nullptr) {
    curr_ = curr_->next_;
  }
  return curr_->element_;
}

template <typename ElementType>
void LinkedList<ElementType>::pop_front() {
  if (head_ == nullptr) {
    throw std::invalid_argument("Empty list");
  }
  Node *curr_ = head_;
  head_ = head_->next_;
  delete curr_;
}

template <typename ElementType>
void LinkedList<ElementType>::pop_back() {
  if (head_ == nullptr) {
    throw std::invalid_argument("Empty list");
  }
  if (head_->next_ == nullptr) {
    delete head_;
    head_ = nullptr;
    return;
  }
  Node *curr_ = head_;
  Node *second_to_last_ = head_->next_;
  while (second_to_last_->next_ != nullptr) {
    curr_ = curr_->next_;
  }
  delete second_to_last_;
  curr_->next_ = nullptr;
}

template <typename ElementType>
size_t LinkedList<ElementType>::size() const {
  size_t count = 0;
  Node *curr_ = head_;
  while (curr_ != nullptr) {
    count++;
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
  Node *curr_ = head_;
  while (curr_ != nullptr) {
    Node *next = curr_->next_;
    delete curr_;
    curr_ = next;
  }
  head_ == nullptr;
}

template <typename ElementType>
std::ostream& operator<<(std::ostream& os,
                         const LinkedList<ElementType>& list) {}

template <typename ElementType>
void LinkedList<ElementType>::RemoveNth(size_t n) {
  if (head_ == nullptr) {
    throw std::invalid_argument("Empty list");
  }
  Node *curr_ = head_;
  if (n == 0) {
    head_ = curr_->next_;
    delete curr_;
    return;
  }

  for (size_t i = 0; i < n - 1; i++) {
    if (!(curr_ == nullptr && curr_->next_ == nullptr)) { // check if n is out of bounds
      curr_ = curr_->next_; // node prior to one to be deleted
    } else {
      // return;
      throw std::invalid_argument("Node to be removed is out of bounds");
    }
  }

  Node *after_ = curr_->next_->next_; // node after the one to be removed
  delete curr_->next_;
  curr_->next_ = after_;
}

template <typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {}

template <typename ElementType>
bool LinkedList<ElementType>::operator==(
    const LinkedList<ElementType>& rhs) const {}

template <typename ElementType>
bool LinkedList<ElementType>::operator!=(
    const LinkedList<ElementType>& rhs) const {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator& LinkedList<ElementType>::iterator::
operator++() {}

template <typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {}

template <typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(
    const typename LinkedList<ElementType>::iterator& other) const {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator&
LinkedList<ElementType>::const_iterator::operator++() {}

template <typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {}

template <typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(
    const typename LinkedList<ElementType>::const_iterator& other) const {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator
LinkedList<ElementType>::begin() const {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end()
    const {}

}  // namespace cs126linkedlist
