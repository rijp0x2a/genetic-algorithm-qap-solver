template <typename PopulationType>
void TestSuite<PopulationType>::execute() {
    for(auto it = m_tests.begin(); it != m_tests.end(); it++) {
        // Get date-time
        time_t rawTime;
        struct tm *timeInfo;
        time(&rawTime);
        timeInfo = localtime(&rawTime);
        std::string time = asctime(timeInfo);
        time.pop_back();

        std::cout << "> Running test suite for " << (*it).name << " on " << time << std::endl;

        std::vector<double> relErrors;
        for(size_t i = 0; i < (*it).runs; i++) {
            std::cout << "> Run " << i+1 << " / " << (*it).runs << std::endl;

            SolveQAP<PopulationType> qap((*it).name, (*it).iterations, (*it).runtime, (*it).population);
            PopulationType finalPopulation = qap.run();
            (*it).results.push_back(finalPopulation);

            double relError = round((finalPopulation.fitness() - finalPopulation.optimal()) / double(finalPopulation.fitness()) * 100.0 * 1000.0) / 1000.0;
            relErrors.push_back(relError);
        }

        double max = *std::max_element(relErrors.begin(), relErrors.end());
        double min = *std::min_element(relErrors.begin(), relErrors.end());

        double sum = std::accumulate(relErrors.begin(), relErrors.end(), 0.0);
        double mean = sum / relErrors.size();

        double sq_sum = std::inner_product(relErrors.begin(), relErrors.end(), relErrors.begin(), 0.0);
        double stdev = sqrt(sq_sum / relErrors.size() - mean * mean);

        std::cout << "> Test suite report for " << (*it).name << " after " << (*it).runs << " runs" << std::endl;
        std::cout << "> Max     relative error = " << max << std::endl;
        std::cout << "> Min     relative error = " << min << std::endl;
        std::cout << "> Average relative error = " << mean << std::endl;
        std::cout << "> SD of   relative error = " << stdev << std::endl;

        std::cout << std::endl;
    }
}
