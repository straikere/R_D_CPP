#pragma once
#include "EventData.h"
#include "Event.h"

// IDamagable
// IHealthReceiver
class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(const EventData& data, Event event) = 0;
};

