#include "parser.ih"

QAP Parser::parse(string file)
{
    string pathToDatFile = m_dataDir + "/qapdata/" + file + ".dat";
    string pathToSlnFile = m_dataDir + "/qapsoln/" + file + ".sln";

    // Read from file
    string &&bigDatString = readBigString(pathToDatFile);
    string &&bigSlnString = readBigString(pathToSlnFile);

    // Tokenize string
    vector<int> &&tokenizedDat = tokenizeStringAsInt(bigDatString);
    vector<int> &&tokenizedSln = tokenizeStringAsInt(bigSlnString);

    size_t datSize = tokenizedDat[0];

    // Verify
    size_t expectedDatSize = (datSize * datSize) * 2 + 1;
    if(tokenizedDat.size() != expectedDatSize) {
        cerr << "Tokenized dat string is not the correct length (is: " << tokenizedDat.size() << ", should be: " << expectedDatSize << ") for: " << file << endl;
    }

    size_t expectedSlnSize = datSize + 2;
    if(tokenizedSln.size() != expectedSlnSize) {
        cerr << "Tokenized sln string is not the correct length (is: " << tokenizedSln.size() << ", should be: " << expectedSlnSize << ") for: " << file << endl;
    }

    // Build flow and distance matrix
    Matrix &&distanceMatrix = generateEmptyMatrix(datSize, datSize);
    Matrix &&flowMatrix = generateEmptyMatrix(datSize, datSize);
    for(size_t i = 0; i < datSize * datSize; i++) {
        distanceMatrix[i / datSize][i % datSize] = tokenizedDat[i+1];
        flowMatrix[i / datSize][i % datSize] = tokenizedDat[i+1+(datSize * datSize)];
    }

    // Build permutation list
    size_t slnSize = tokenizedSln[0];
    int optimalFitness = tokenizedSln[1];
    vector<int> permutation(tokenizedSln.begin() + 2, tokenizedSln.end());

    // Verify
    if(slnSize != datSize) {
        cerr << "Solution size is not equal to data size for: " << file << endl;
    }

    if(permutation.size() != datSize) {
        cerr << "Permutation size is not equal to data size for: " << file  << endl;
    }

    for(size_t i = 0; i < datSize * datSize; i++) {
        if(distanceMatrix[i / datSize][i % datSize] != distanceMatrix[i % datSize][i / datSize]) {
            cerr << "Distance matrix is not symmetrical for: " << file  << endl;
            break;
        }
    }

    int calculatedFitness = 0;
    for(size_t i = 0; i < permutation.size(); i++) {
        for(size_t j = 0; j < permutation.size(); j++) {
            calculatedFitness += flowMatrix[permutation[i]-1][permutation[j]-1] * distanceMatrix[i][j];
        }
    }

    if(calculatedFitness != optimalFitness) {
        cerr << "Calculated fitness (" << calculatedFitness << ") is not equal to optimal fitness (" << optimalFitness << ") for: " << file  << endl;
    }

    QAP problem;
    problem.size = datSize;
    problem.distance = std::move(distanceMatrix);
    problem.flow = std::move(flowMatrix);
    problem.solution.optimal = optimalFitness;
    problem.solution.permutation = std::move(permutation);

    return problem;
}
