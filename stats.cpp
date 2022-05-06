#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<double>& input)
{
    double aMin;
    double aMax;
    double aAverage;
    double aSum;

    if(input.empty())
    {
        aAverage = nan("1");
        aMin = nan("1");
        aMax = nan("1");
        Stats aStat(aMin, aMax, aAverage);
        return aStat;
    }

    //input vector is non empty, Implement statistics here
    aMin = *min_element(input.begin(), input.end());
    aMax = *max_element(input.begin(), input.end());

    for(double elem : input)
    {
        aSum += elem;
    }

    aAverage = aSum/input.size();

    Stats aStat(aMin, aMax, aAverage);
    return aStat;
}

void StatsAlerter::checkAndAlert(std::vector<float> iInput)
{
    const float aMaxInputThreshold = *max_element(iInput.begin(), iInput.end());
    if (aMaxInputThreshold > aMaxThreshold)
    {
        //Input threshold is greater than Max Threshold. Set the Alerts
        aAlerters[0]->emailSent = true;
        aAlerters[1]->ledGlows = true;
    }
}
