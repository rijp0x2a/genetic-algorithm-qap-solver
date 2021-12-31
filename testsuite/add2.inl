template <typename PopulationType>
void TestSuite<PopulationType>::add(const std::string name, const size_t iterations, const size_t runtime, const size_t population, const size_t runs) {
    Test<PopulationType> test {
        name,
        iterations,
        runtime,
        population,
        runs
    };

    m_tests.push_back(test);
}
