#pragma once
/* Question 9 : Simple Stack */
#include <iostream>
class int_stack {
public:
	/* Default size is 0, has no data */
	int_stack();

	/* Initialize stack with list of values */
	int_stack(const std::initializer_list<int>& li);

	/* Get the current size of the stack */
	size_t size() const;

	/* Check if stack is empty */
	bool empty()  const;

	/* Peek returns the value at the top of the stack */
	int peek() const;

	/* Remove value from the top of the stack */
	void pop();

	/* Add value to top of the stack */
	void push(int value);

	/* Print the stack */
	friend std::ostream& operator<<(std::ostream& os, const int_stack& st);

private:
	/* Throws exception if stack is empty when it shouldn't be */
	void check_empty() const;
	/* Throws exception if we try to add when the stack is full */
	void check_overflow() const;
	
	static const size_t maxStack_ = 4; // stack is absurdly small, to help test it
	size_t size_;
	int data_[maxStack_];
};

