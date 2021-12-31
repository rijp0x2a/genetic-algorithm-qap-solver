#include "populationbase.ih"

void PopulationBase::evolve(size_t n, size_t runtime) {
    // Get date-time for filename
    time_t rawTime;
    struct tm *timeInfo;
    time ( &rawTime );
    timeInfo = localtime ( &rawTime );

    // Build filename
    std::stringstream filename;
    std::string time = asctime(timeInfo);
    time.pop_back();
    filename << m_name << "_" << time << ".csv";

    // Create and open file
    std::ofstream csvFile;
    csvFile.open (filename.str());

    // Track the amount of time running the calculations
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    high_resolution_clock::time_point t2;
    size_t idx(0);

    // Add first entries to file
    csvFile << "name" << "," << "optimal-fitness" << "\r\n";;
    csvFile << m_name << "," << m_qap.solution.optimal << "\r\n" << "\r\n";

    csvFile << "microseconds" << "," << "iteration" << "," << "fitness" << "\r\n";
    csvFile << "0" << "," << "0" << "," << fitness() << "\r\n";

    // Track previous fitness to detect changes in fitness
    int previousFitness = fitness();

    // Convert runtime to microseconds
    runtime *= 1000; // milliseconds
    runtime *= 1000; // microseconds

    while (!m_solution_found) {
        // Stop when optimal (or better) solution is found
        if (previousFitness <= optimal())
            break;

        ++idx;      // increase iteration

        // calculate execution time
        t2 = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(t2 - t1).count();

        // Stop when execution time is reached
        if (runtime > 0 && static_cast<size_t>(duration) >= runtime)
            break;

        // Stop when max iterations is reached
        if (n > 0 && idx > n)
            break;

        // Print iterations per second, ETA and current fitness
        std::cout << "\r" << "Iteration " << idx << " / " << n;
        if (duration > 0 && idx > 1) {
            auto itPerSec = (idx * 1000 * 1000) / static_cast<double>(duration);
            std::cout << " @ " << itPerSec << " it / sec";
            if (idx > 1 && itPerSec > 0 && n > 0)
                std::cout << " - ETA: " << formatSeconds((n - idx) / itPerSec);
            std::cout << " (current: " << fitness() << ", mutation: " << m_mutation << ", s: " << m_stuck << ", ns: " << m_notstuck << ")";

        }
        std::cout << std::flush;

        // Perform a step of the genetic algorithm
        evolve();

        // If fitness changed, log it to file
        if(previousFitness != fitness())
            csvFile << duration << "," << (n - idx + 1) << "," << fitness() << "\r\n";
        previousFitness = fitness();
    }

    std::cout << " - Completed in " << formatSeconds(duration_cast<seconds>(t2 - t1).count()) << std::endl;

    // Add last entry
    csvFile << duration_cast<microseconds>(t2 - t1).count() << "," << n << "," << fitness() << "\r\n";
    csvFile.close();
}
