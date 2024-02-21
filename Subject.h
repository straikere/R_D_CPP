#pragma once
#include "Observer.h"
#include <vector>

using std::vector;

class Subject
{
public:

	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);

protected:

	void notify(const EventData& data, Event event);

private:

	vector<Observer*> m_observers;

};

