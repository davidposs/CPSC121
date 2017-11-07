/* Question 9 : Simple Stack */
#include "int_stack.h"
#include <iostream>

// Default size is 0, has no data
int_stack::int_stack() : size_(0) {}

// Constructor to initialize stack with a list
int_stack::int_stack(const std::initializer_list<int>& li) :
	int_stack() {
	for (int i : li) {
		push(i);
	}
}

// Get number of elements in stack
size_t int_stack::size() const { 
	return size_; 
}

// See if stack is empty
bool int_stack::empty()  const { 
	return size() == 0; 
}

// Peek returns the value at the top of the stack
int int_stack::peek() const {
	check_empty();
	return data_[size_ - 1];
}

// Remove value from the top of the stack
void int_stack::pop() {
	check_empty();
	data_[size_ - 1] = -999;
	size_--;
}

// Add value to top of the stack
void int_stack::push(int value) {
	size_++;
	check_overflow();
	data_[size_ - 1] = value;

}

// Output contents of stack in order they would be popped in
std::ostream& operator<<(std::ostream& os, const int_stack& st) {
	os << "stack [";
	if (st.empty()) { os << "empty]"; }
	else {
		for (int i = st.size() - 1; i >= 0; i--) {
			os << st.data_[i] << ", ";
		}
		// Back os up 2 places to det rid of last coma
		os << "\b\b]";
	}
	return os;
}

// Throws exception if stack is empty when it shouldn't be
void int_stack::check_empty() const {
	if (size_ == 0) {
		throw new std::exception("Stack is empty\n");
	}
}

// Throws exception if we try to add when the stack is full
void int_stack::check_overflow() const {
	if (size_ > maxStack_) {
		throw new std::exception("Stack is too full\n");
	}
}