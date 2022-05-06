#include <vector>
#include <bits/stdc++.h>

class Stats
{
    public:
        double min;
        double max;
        double average;

    Stats(double imin, double imax, double iaverage): min(imin), max(imax), average(iaverage) {}
};

namespace Statistics
{
    Stats ComputeStatistics(const std::vector<double>& input);
}


class IAlerter
{
    public:
        bool emailSent = false;
        bool ledGlows = false;
        virtual void setEmailAlert();
        virtual void setLedAlert();

};

class EmailAlert : public IAlerter
{
    virtual void setEmailAlert();
};

class LEDAlert : public IAlerter
{
    virtual void setLedAlert();
};

class StatsAlerter
{
    private:
    const float aMaxThreshold;
    std::vector<IAlerter*> aAlerters;

    public:
        StatsAlerter(const float iMaxThreshold, std::vector<IAlerter*> iAlerters):
                aMaxThreshold(iMaxThreshold), aAlerters(iAlerters) { }

    void checkAndAlert(std::vector<float> iInput);
};
