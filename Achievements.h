#pragma once
#include "Observer.h"

enum class Achievement
{
    BossIsDead,
    SecondLife,
    FirstWeapon
};

// HealthBar : public IhealthReceiver
class Achievements :
    public Observer
{
public:

    virtual void onNotify(const EventData& data, Event event) override;

private:

    void unlock(Achievement achievement);

    bool m_BossIsDead{ false };
    bool m_secondLife{ false };
    bool m_FirstWeapon{ false };
};

