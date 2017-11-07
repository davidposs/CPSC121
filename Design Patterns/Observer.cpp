/* ****************************************************************************
* Observer Design Pattern Practice
* CPSC 121
* ***************************************************************************/

#include <vector>
#include <string>
#include <iostream>

/* Review
An observer is handy when part of our program is waiting on an update from
another part of the program. Observers must be registered to subjects.

A subject will allow observers to register themselves with the subject.
Observers will register themselves and will receive notifications whenthe
subject changes.
*/

/* We want to know when the price of an item changes, so Item is our subject
Subjects are responsible for registering and unregistering observers
so we must add those methods here. */


// Need to do forward declaration of observer for Subject class
class Subject;

class Observer {
public:
	// Basic constructor, doesn't need to do anything fancy
	Observer() {};
	// REQUIRE child classes to implement this method!
	virtual void update(Subject* subject) = 0;
};

class Subject {
public:
	Subject() {};
	virtual void registerObserver(Observer* obs) {
		observers_.push_back(obs);
	}
	virtual void unregisterObserver(Observer* obs) {
		for (size_t i = 0; i < observers_.size(); i++) {
			if (observers_[i] == obs) {
				observers_.erase(observers_.begin() + i);
			}
		}
	}

	virtual void notify() {
		for (size_t i = 0; i < observers_.size(); i++) {
			observers_[i]->update(this);
		}
	}
private:
	std::vector<Observer*> observers_;
};

class Item : public Subject {
public:
	/* Constructors */
	Item() : name_("something"), price_(14.99) {}
	Item(std::string name, double price) : name_(name), price_(price) {}

	double getPrice() { return price_; }
	std::string getName() { return name_; }

	void updatePrice(double newPrice) {
		/* check to see if price is actually updating. If so, tell everyone! */
		if (price_ != newPrice) {
			price_ = newPrice;
			notify();
		}
	}

private:
	std::string name_;
	double price_;
};

/* Make our observing class. Note it  HAS to implement that pure virtual method
otherwise the program won't even compile. */
class Customer : public Observer {
public:
	/* Constructors */
	Customer(std::string name, int age)
		: name_(name), age_(age) {}

	/* Same as above, but includes an Item to observe */
	Customer(std::string name, int age, Item* item)
		: name_(name), age_(age), watchedItem_(item) {
		item->registerObserver(this);
	}

	/* update function to notify a user something changed */
	void update(Subject* sub) {
		if (watchedItem_ == sub) {
			std::cout << "Hey " << name_ << "! The price of "
				<< watchedItem_->getName() << " has changed to "
				<< watchedItem_->getPrice() << std::endl;
		}
	}

	void watchItem(Item* sub) {
		watchedItem_ = sub;
		watchedItem_->registerObserver(this);
	}

	~Customer() {};

private:
	std::string name_;
	unsigned int age_;
	/* Currently this limits a user to only being able to watch one
	item at a time, but we could make this a list or vector isntead */
	Item* watchedItem_;
};



int main() {

	Item keyboard("keyboard", 26.99);
	Customer* megan = new Customer("megan", 23, &keyboard);
	keyboard.updatePrice(12.99);
	Customer* jack = new Customer("jack", 33);
	jack->watchItem(&keyboard);
	keyboard.updatePrice(45.99);

	Item bathMat("bath math", 12.49);
	bathMat.updatePrice(12.99);
	jack->watchItem(&bathMat);
	bathMat.updatePrice(9.99);
	keyboard.updatePrice(2.99);


	return 0;
}

