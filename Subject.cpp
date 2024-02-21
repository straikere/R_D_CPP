#include "Subject.h"

void Subject::addObserver(Observer* observer) {
	m_observers.push_back(observer);
};
void Subject::removeObserver(Observer* observer) {
	m_observers.erase(std::find(m_observers.begin(), m_observers.end(), observer));
};

void Subject::notify(const EventData& data, Event event) {
	for (auto observer : m_observers) {
		observer->onNotify(data, event);
	}
}