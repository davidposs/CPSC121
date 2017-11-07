/******************************************************************************
*
*
* CS 121 Midterm Study Guide
*
*
******************************************************************************/

#include <iostream>
#include <string>
#include "Shapes.h"
#include "int_stack.h"

/* Handy helper functions to print stuff, cuz I got tired of having to keep
   writing std::cout << ... << ... */
template <typename T>
void print(T s) {
	std::cout << s << std::endl;
}

/* Print a pair of any two standard data types*/
template <typename T>
void print(T a, T b) {
	std::cout << a << '\t' << b << std::endl;
}

/* Question 1: Write a function that prints out all of the multiples of three
   and five but not ten, up to and including number.	*/
void printMultiplesOfThreeFiveNotTen(int max) {
	// Stop at i * 5 because it will reach the max faster than i*3
	for (int i = 0; i * 5 <= max; i++) {
		// Check to see if either i*3 or i*5 is divisible by 10
		// if not, output them.
		if (i * 3 % 10 != 0) {
			std::cout << i * 3 << "\t";
		}
		if (i * 5 % 10 != 0) {
			std::cout << i * 5;
		}
		std::cout << std::endl;
	}
}


/* Question 2: Write a function that returns the length of a string   */
int strlen_(char* p) {
	int length = 0;
	if (p == nullptr) {
		// p has no data assigned to it
		return length;
	}
	while (*p != '\0') {
		length++;
		p++;
	}
	return length;
}

/* Question 3: Write a function that can reverse a string in place, and
   converts all consonants to capital letters (hint: use strchr).*/

   /* 2 helper functions
	  isConsonant(char p) returns true if the character passed is a consonant
	  isLower(char p)     returns true if the character passed is lower case */
bool isConsonant(const char p) {
	char temp = tolower(p);
	switch (temp) {
	case('a'): return false;
	case('e'): return false;
	case('i'): return false;
	case('o'): return false;
	case('u'): return false;
	default: return true;
	}
}

bool isLower(const char p) {
	// See if p is between ASCII values 97-122, which correspond to 'a-z'
	return (int(p) >= 97 && int(p) <= 122);
}

char* reverseCapitalizeVowels(char* p) {
	char* start = p;
	// Set end to point to final value before \0 in p
	char *end = p + strlen_(p) - 1;

	while (start < end) {
		/* We can subtract 32 from a capital letter to get it to lower case
		  because c++ stores chars as integers, and the ascii value for
		  an uppercase letter is 32 away from its lowercase version
		  ex: 'a' has ascii value 97 and  'A' has ascii value 65 */
		if (isLower(*start) && isConsonant(*start)) { *start -= 32; }
		if (isLower(*end) && isConsonant(*end)) { *end -= 32; }
		char temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
	return start;
}

/* Question 4: Write a function that can reverse a string, but returns a
   new string that will have to be array deleted by the client.*/
char* reverse_new(char* str) {
	char* s = str;
	int length = strlen_(s);

	// Add 1 to account for null terminator \0
	char* newStr = new char[length + 1];

	// copy str into newStr. Note I'm using strncpy
	strncpy(newStr, str, length);
	// Now reverse newStr
	for (int i = 0; i < length / 2; i++) {
		char temp = newStr[length - i - 1];
		newStr[length - i - 1] = newStr[i];
		newStr[i] = temp;
	}
	// Add null terminator to the end so we don't get weird output
	newStr[length] = '\0';
	return newStr;
}

/* Question 5: Write a function that can print out a right-justified string */
void rightJustify(const char* str, size_t length) {
	//cout.width sets the width of the output buffer
	std::cout.width(length);
	//std::right will right-justify the output
	std::cout << std::right << str << std::endl;
}

/* Question 6:  Write a variation on this function that takes an array of
   character pointers (to the lines in the song), and calculates the minimum
   amount of padding necessary so that all of the lines are right justified. */
void rightJustifyStrings(const char* strings[]) {
	// i serves as a count of how many values are in strings
	int i = 0;
	// Initialize maxLength to just be the first value in strings
	int maxLength = strlen(strings[0]);
	while (strings[i] != "") {
		i++;
		// Note: I'm using the built-in strlen because it takes const values
		if (strlen(strings[i]) > maxLength) {
			maxLength = strlen(strings[i]);
		}
	}
	// Print out everything in strings
	for (int j = 0; j < i; j++) {
		rightJustify(strings[j], maxLength);
	}
}

/* Question 7: Write two different swap functions for swapping size_t’s
(aka unsigned longs): one should use pointers, and the other should use
references. */
void swapPointers(size_t* p1, size_t* p2) {
	size_t temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void swapReferences(size_t& p1, size_t& p2) {
	size_t temp = p1;
	p1 = p2;
	p2 = temp;
}


/* Question 8 : Write a Point class containing x and y variables. It should have
   constructors, accessors (getters), mutators (setters), and operator<<. Write
   an abstract Shape class that has a center variable (of type Point). It should
   have constructors, accessors, mutators, operator<<, and area() and perimeter()
   functions. Because it is an abstract class, at least one of the functions should
   be pure virtual. Write a concrete Rectangle class that inherits from Shape.
   You will also need to write some test code in main to test your Rectangle,
   Shape, and Point classes.

   See Shapes.h for implementations
*/

/* Question 9: Simple stack
   See int_stack.h and int_stack.cpp for implementations!
*/

int main() {
	/* QUESTION 1*/
	print("~~~QUESTION 1~~~");
	printMultiplesOfThreeFiveNotTen(120);

	/* QUESTION 2*/
	print("~~~QUESTION 2~~~");
	char p[] = "this is a char pointer";
	print(strlen_(p));

	/* QUESTION 3*/
	print("~~~QUESTION 3~~~");
	reverseCapitalizeVowels(p);
	print(p);

	/* QUESTION 4*/
	print("~~~QUESTION 4~~~");
	char* newStr = reverse_new(p);
	print(newStr);
	/* Free the memory we allocated to newStr*/
	delete[] newStr;
	newStr = nullptr;

	/* QUESTION 5*/
	print("~~~QUESTION 5~~~");
	size_t size = 55;
	rightJustify("i've", size);
	rightJustify(" been here", size);
	rightJustify("before, but always", size);
	rightJustify("hit the floor. i've spent", size);
	rightJustify("a lifetime running, and i always", size);
	rightJustify("get away, but with you i'm feeling something", size);
	rightJustify("that makes me want to stay", size);
	rightJustify("i'm prepared for this", size);
	rightJustify("i never shoot", size);
	rightJustify("to miss", size);
	rightJustify("sam smith", size);

	/* QUESTION 6*/
	print("~~~QUESTION 6~~~");
	const char* strings[] = { "but i feel like a storm is coming, if i'm gonna make it through the day",
		"then there's no more use in runnin', this is something i gott face",
		"if i risk it all, could you break my fall?",
		"how do i live, how do i breathe",
		"when you're not here i'm",
		"suffocating, i wannna",
		"feel love run",
		"through my",
		"blood",
		"tell me is",
		"this where i give it all up?",
		"for you i have to risk it all, cause the writing's on the wall",
		"sam smith",		"" };

	rightJustifyStrings(strings);

	/* QUESTION 7*/
	print("~~~QUESTION 7~~~");
	size_t a = 45, b = 101;
	print("Before pointer swapping: ");
	print(a, b);
	swapPointers(&a, &b);
	print("After pointer swapping: ");
	print(a, b);

	print("\nBefore reference swapping: ");
	print(a, b);
	print("After reference swapping: ");
	swapReferences(a, b);
	print(a, b);

	/* QUESTION 8 */
	print("~~~QUESTION 8~~~");
	Point point(2.3, 14.42);
	Rectangle rect(94.5, 12.3, point);
	Rectangle r1(93.2, 44.1, Point(3.2, 3.3));
	print("rect is: salfakjdf;lasdkj");
	std::cout << rect << std::endl;

	print(rect);
	print("Changing width to 100");
	rect.setWidth(100);
	print(rect);
	print("");

	/* QUESTION 9 */
	print("~~~QUESTION 9~~~");
	int_stack st;
	int_stack st2({ 3, 1, 4, 1 });

	std::cout << "st is: " << st << "\n";
	std::cout << "st2 is: " << st2 << "\n";

	st.push(10);
	st.push(100);
	st.push(1000);
	st.push(10000);	std::cout << "after all of those pushes, st is now: \n" << st << std::endl;

	std::cout << "\nnow emptying the stack item by item...\n";
	while (!st.empty()) {
		st.pop();
		std::cout << st << std::endl;
	}
	std::cout << "\ntest is st empty? \nst is now: " << st << std::endl;
	std::cout << "\t\t...done.\n";

	return 0;
}