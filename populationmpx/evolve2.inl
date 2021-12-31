#include "populationmpx.ih"

template <typename PopulationType>
void PopulationMPX<PopulationType>::evolve(size_t n, size_t runtime) {
    PopulationType::evolve(n, runtime);
}
