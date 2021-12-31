template <typename PopulationType>
SolveQAP<PopulationType>::SolveQAP(std::string name, size_t itMax, size_t runtime, size_t popSize)
:
    m_itMax(itMax),
    m_runtime(runtime),
    m_name(name),
    m_pop(name, popSize)
{
    // empty
}
