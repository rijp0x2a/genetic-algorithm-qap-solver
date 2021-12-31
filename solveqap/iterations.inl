template <typename PopulationType>
std::string const SolveQAP<PopulationType>::iterations() const
{
    if (m_itMax == 0)
        return "indefinite";

    std::stringstream ss;
    ss << m_itMax;
    return ss.str();
}
