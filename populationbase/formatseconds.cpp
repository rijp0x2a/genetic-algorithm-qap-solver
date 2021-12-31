#include "populationbase.ih"

std::string PopulationBase::formatSeconds(size_t s)
{
    std::stringstream ss;

    size_t days = s / 60 / 60 / 24;
    if (days != 0)
        ss << days << "d ";

    size_t hours = (s / 60 / 60) % 24;
    if (hours != 0)
        ss << hours << "h ";

    size_t minutes = (s / 60) % 60;
    if (minutes != 0)
        ss << minutes << "m ";

    size_t seconds = s % 60;
    ss << seconds << "s";

    return ss.str();
}
