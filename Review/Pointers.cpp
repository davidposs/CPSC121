/******************************************************************************
SI Session 1
Crash Course in Arrays, Pointers and References

Subjects:	Arrays
Functions
Pointers
References
******************************************************************************/


/************************** INTRODUCTION TO ARRAYS ***************************
An array is a sequence of consecutive addresses in memory. Memory is
this scary thing where everything we do is stored, but we'll focus more
on memory in just a bit. For now, let's think of an array as a street.

Like an array, a street has consecutive addresses, like 1 Melrose Lane,
2 Melrose Lane, 3 Melrose Lane, etc.

The number of houses on a street doesn't change very often, so
let's assume there is a fixed amount of houses on a particular street.

We can imagine then that the street is an array, and the houses are the
variables(or objects) stored in it.

Like streets, when populating an array, we typically do it starting
from the lowest address and end at the highest.A street address may
start at 1, 1000, 800, or any arbitrary value, but in C++, arrays
always start at 0. Always. (ALWAYS!!!)

We also know that a street will be designed to fit a certain number of
houses on it. Say we know the street is designed to fit 10 houses, and
the first house's address is 1 Melrose Lane. We then know the last
house will be 10 Melrose Lane since they are consecutively addressed.

Similarly, we know where an array ends because we know beforehand how
many variables we want to store in it(later we'll see what happens if
we don't already know).

So if we have 10 variables to store, we know we'll have an array like:
	arr[0], arr[1], arr[2], arr[3], arr[4],
	arr[5], arr[6], arr[7], arr[8], arr[9]

******************************************************************************/


/************************ INTRODUCTION TO POINTERS ************************
Now that we understand arrays, we can learn the shocking truth behind them.

Arrays are pointers! You've been duped this whole time :)
In fact, arrays are a special type of pointer, called a constant pointer,
but we'll get to that later.

So how exactly is an array a pointer?

First we have to talk about what exactly pointers are.

Pointers.. well they point. They point to an address in memory.
Memory is a vague term that probably hasnt been explained well yet, but,
going back to the analogy, let's think of 'memory' as a city that has
a bunch of streets in it.

Remember: A street is a series of houses, like how an array is a series
of values.

A pointer gives you access to a value at a specific address (i.e a house)
in memory (the city) by storing the memory address of that variable.
Dereferencing a pointer means revealing the value stored at that address,
and it is comparable to using the address of a house to see who lives there.


When we type:
===> int  f = 10;
===> int* p = f;

The value of p (what'd we get it we did "cout << p")  is the memory
location of f, which will look something like 00FFA810.

However if we did "cout << *p", we would get 10, because we are no
longer referencing the memory location, we are looking at the value
stored in it (aka dereferencing).

* *********************************************************************
* Side Note: If you're wondering why you'd get a value like 00FFA810  *
* when I output p without dereferencing it, that's because memory     *
* addresses are stored as hexadecimal (base 16) values. Notice how it *
* has 8 integers in it (A-F represent 10-15 in base 16).              *
* Two hex integers make 1 byte, so the address is 4 bytes, or 32 bits.*
* This doesn't mean I'm on a 32 bit operating system, it just means   *
* that my system is defining integers to be 32 bits wide. This won't  *
* effect your programs any time soon, it's just interesting to note.  *
***********************************************************************

Recap:
An array is a series of values, each of which have a memory address
directly following the previous value's memory address, just like how street
addresses increase consecutively from the previous one.


Suppose we have an array
===> int arr[3] = {111, -52, 202 };

In memory, these values addresses could be:
Value				Address (hex)		Address (decimal)		Address (binary)
arr[0] = 111		0x7FFFB000			2147463168				1111111111111111011000000000000
arr[1] = -52		0x7FFFB004			2147463172				1111111111111111011000000000100
arr[2] = 202		0x7FFB0008			2147463176				1111111111111111011000000001000

Notice how the offset between each value is 4. That's because on my system,
integers are 32 bit values (4 bytes).

A pointer stores the memory address of a variable. Using the example
above, if we did
===> int* p = arr;
===> cout << p << endl;
Outputs:	0x7FFFB000
===> cout << *p << endl
Outputs:	111


*******************************************************************************
* Side Note: One thing to keep in mind: a variable's memory address has no    *
* correlation with its stored value. Larger data types (like long long) need  *
* more space, so an array of them might have memory address offsets of 8,     * 
* meaning they take up 8 bytes, but that could be 63 0s and a 1, like so:     *  
* 00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000001     *
* Memory addresses are just sequential bytes. The value at them is irrelevant *
* to the computer when looking that address up.                               *
*******************************************************************************

Remember, if we know the address of a location in memory, we can access the
data in it by dereferencing it.

To get the address of an integer, we can do
===> int x = 12;
===> std::cout << &x;

With an array, the first address is given by
===> &arr
or
===> int* p = &arr;
As we saw earlier since arrays hold data of the same size (as defined by
your computer), they will all be equally offset from each other.

See where this is going?

Again: a STREET has a series of consecutively numbered houses, and is
in a city. An array has a series of values that appear consecutively
after each other within memory. And we know their starting address.

Since array values are consecutive in memory, all the first element of
an array does is point to the address of that first element!

Actually, this is what all elements in the array do. Every subsequent
value in the array is an equal offset away from each other. The size of that
offset varies from system to system and by object type, kind of like how
certain building codes require houses to be some distance apart depending on
the city. The principle is the same no matter what type or system you're on.

We specify the offset using the brackets [].
===> arr[5] 
is the 6th house on the street, or the 6th element in the array.

Confused? Think about this:
If you know your friend's address is 4442 Abernathy Drive, and his
neighbor, Jack, who lives one door down, is a jerk and you want to
mail something nasty to him, don't you know his address?

It's just one after your friend's, 4443 Abernathy Drive!

Pointers work the same way.

If you know			  0		1     2     3     4
===> int houses[5] = {4441, 4442, 4443, 4444, 4445}; //street addresses

And your friend's house is the second house on the street
===> int* friendsHouse =  &houses[1];

You can find Jack's house by saying
===> int jacksHouse = *(friendsHouse + 1);

Of course, this is the same as saying
===> int jacksHouse = houses[2];

The array index is just how many equally sized offsets you want to
move from the start of the array.

This means
===> int house1 = *houses
is a perfectly acceptable statement. house1 will be 4441.

Cool right?

Finally, as I said earlier, arrays are CONSTANT pointers, so you can't change
the address they point to like regular pointers, but you can change the values
in them.

And if you're in the mood for some real janky stuff, check this out.
You can also do:
===> int arr[4] = {1, 51, -13, 33}
===> std::cout << 3[arr];
You'll get 33. All the [] operator really does is tell the compiler to add
the inside value to the outside value's spot in memory. Since addition is
commutative, it doesn't matter what we add first. 

And that's bonkers.

******************************************************************************/


/************** DIFFERENCE BETWEEN POINTER (*) AND REFERENCE (&) **************
Often times, pointers and references can be used to achieve the same purpose,
like we saw with the swap functions.

The most important distinction is that you cannot change the address that a
reference variable refers to.
For example:
===> int x = 120;
===> int& y = x;
No matter what, the address y references will stay the same. Changing the value
at that memory location is acceptable though.
For example:
===> y = 175;
===> std::cout << x << std::endl;
Outputs: 175
This is because x references the same memory location. Changing x changes y.
The reason we use references is for functions like swap(...), where we either
cannot return something, or it is more convenient to pass references that can
change values for us, effectively returning them without explicitly calling a
return.

References also cannot be null. They must be linked to an existing location in
memory. Pointers can be assigned a null value just by doing:
===> float* pf = nullptr;
Doing
===> int& x;
Is illegal in c++. The program will not compile, and you wouldn't want it to.

Generally you want to use references whenever possible, unless you know
there is a case where a nullptr is acceptable.
******************************************************************************/


/********************************** PRACTICE *********************************/
/* Fixed Array Size */
#define NUM_SCORES 10
#include <iostream>
#include <string>
/* Prototypes */
float a_avg(int arr[], int n);
float p_avg(int* arr,  int n);
float r_avg(int& arr,  int n);


int main() {

	/* Array of test scores */
	int testScores[NUM_SCORES];

	/* Following can be made into a function as well */
	std::cout << "Enter 10 test scores:\n";
	for (int i = 0; i < NUM_SCORES; i++) {
		std::cout << i + 1 << ". ";
		std::cin >> testScores[i];
	}

	/* Compare getting the average of an array by passing the array as a
	pointer vs an array vs by refernce. It should be the same!             */
	float avg_array     = a_avg(testScores, NUM_SCORES);
	float avg_pointer   = p_avg(testScores, NUM_SCORES);
	float avg_reference = r_avg(*testScores, NUM_SCORES);

	std::cout << "Average from array:\t" << avg_array << std::endl;
	std::cout << "Average from pointer:\t" << avg_pointer << std::endl;
	std::cout << "Average from reference:\t" << avg_reference << std::endl;


	/**************************************************************************
	* Take a look at some of the various methods to pull values from arrays 
	**************************************************************************/
	std::cout << "\nNow looking at houses:\n";
	std::string houses[5] = { "Bill", "Mary", "Pablo", "Jack", "Demarius" };
	
	/* Print out the memory locations of each object in houses */
	std::cout << "Addresses: " << &houses << " " << &houses[1] << " "
		<< &houses[2] << " " << &houses[3] << " " << &houses[4] << std::endl;

	/* We use the & since calling an array with an index will automatically
	dereference it. If we want to keep the address, we need the ampersand */		
	std::string* friendsHouse = &houses[2];

	/* Let's say Jack's house is 1 after our friend's house. We can get the VALUE 
	stored at Jack's address by dereferencing the address 1 after our friend's house */
	std::string  jacksHouse = *(friendsHouse + 1);
	std::cout << "Address of first house: "	<< houses << std::endl;
	std::cout << "Address of friend's house: " << friendsHouse;
    std::cout << ", occupied by " << *friendsHouse << std::endl;
	
	std::cout << "Jack's address: " << &jacksHouse
		      << ", occupied by " << jacksHouse << std::endl;


	/* Note here how the differences between address spaces is only 1. That's
	because bools are only 1 bit in size. They are either 0 or 1, so no 
	additional bits are needed to describe them. */
	std::cout << "\nSize of bools:\n";
	bool bools[] = { false, false, true };
	std::cout << "bool addresses: " << &bools << " " << &bools[1] << std::endl;

	/* Lastly, you can also index pointers the way you can with arrays */
	int anotherOne[] = { 1, 2, 3, 4, 5 };
	int* ip = anotherOne;
	std::cout << "Indexing a pointer: " << ip[4] << std::endl;

	/* You also reverse the way you index them, like so: */
	std::cout << "Weirdly indexing a pointer: " << 4[ip] << std::endl;

	return 0;
}

/* Computes array average by passing the array with [] parameter */
float a_avg(int arr[], int n) {
	float avg = 0;
	for (int i = 0; i < n; i++) {
		avg += arr[i];
	}
	return avg / n;
}

/* Computes array average by passing array as a pointer */
float p_avg(int * arr, int n) {
	float avg = 0;
	for (int i = 0; i < n; i++) {
		avg += *(arr + i);
	}
	return avg / n;
}
/* Computes array average by passing a reference to the first pointer */
float r_avg(int& arr, int n) {
	float avg = 0;
	for (int i = 0; i < n; i++) {
		avg += *(&arr + i);
	}
	return avg / n;
}