#include "main.ih"

int main(int argc, char * argv[]) {
    // Running PMX, MPX, UX on PopulationBase
    TestSuite<PopulationPMX<>> testSuite1;
    TestSuite<PopulationMPX<>> testSuite2;
    TestSuite<PopulationUX<>> testSuite3;
    // NOTE: Above is the same as: TestSuite<PopulationUX<PopulationBase>> testSuite;

    // Running BLS with a specific crossover;
    TestSuite<PopulationPMX<PopulationBLS>> testSuite4;
    TestSuite<PopulationMPX<PopulationBLS>> testSuite5;
    TestSuite<PopulationUX<PopulationBLS>> testSuite6;

    std::string name = "tai60a";
    std::string suite = "bls+ux";
    size_t runtime = 0;
    size_t iterations = 0;

    switch (argc)
    {
        case 5:
        {
            runtime = atoi(argv[3]);
            iterations = atoi(argv[4]);
        }
        // falling through
        case 3:
        {
            name = argv[1];
            suite = argv[2];
        }
        break;
        default:
        {
            std::cout << "Usage: ./machine-learning problem method [runtime iterations]" << std::endl
                      << "\tProblem can be any of the qap names e.g. tai60a" << std::endl
                      << "\tmethod can be: ux, pmx, mpx or bls+ux, bls+pmx, bls+mpx" << std::endl
                      << "\truntime (optional) is in seconds" << std::endl
                      << "\titerations (optional) is in seconds" << std::endl
                      << "\tOmitting runtime and iterations will result in calculation till optimal solution" << std::endl;
            return 0;
        }
        break;
    }

    // name, maxIterations, populationSize, runs         // defaults to 1 hour run
    // name, maxIterations, maxTime (in seconds), populationSize, runs
    testSuite1.add(  name,  iterations, runtime, 50, 3);
    testSuite2.add(  name,  iterations, runtime, 50, 3);
    testSuite3.add(  name,  iterations, runtime, 50, 3);
    testSuite4.add(  name,  iterations, runtime, 15, 3);
    testSuite5.add(  name,  iterations, runtime, 15, 3);
    testSuite6.add(  name,  iterations, runtime, 15, 3);

    if (suite == "pmx")
        testSuite1.execute();
    if (suite == "mpx")
        testSuite2.execute();
    if (suite == "ux")
        testSuite3.execute();
    if (suite == "bls+pmx")
        testSuite4.execute();
    if (suite == "bls+mpx")
        testSuite5.execute();
    if (suite == "bls+ux")
        testSuite6.execute();

    return 0;
}
