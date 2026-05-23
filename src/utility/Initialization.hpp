namespace Initialization {

//https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/
void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            std::exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }

    return false;
}

int getInteger()
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a integer number: ";
        int x{};
        std::cin >> x;

        if (clearFailedExtraction())
        {
            std::cout << "Oops, that input is invalid.  Please try again.\n";
            continue;
        }

        ignoreLine(); // Remove any extraneous input
        return x;     // Return the value we extracted
    }
}

void loadStructuredInputs(const std::string& filepath, std::vector<double>& array) {
    std::ifstream file(filepath);

    if (!file.is_open()) {
        std::cerr << "Error opening data file: " << filepath << std::endl;
        exit(1);
    }

    std::string line;
    // Read the file line by line
    while (std::getline(file, line)) {
        // Skip completely empty lines
        if (line.empty()) continue; 

        std::stringstream ss(line);
        double value;
        
        // Extract all numbers found on this specific line
        while (ss >> value) {
            array.push_back(value);
        }
    }

    std::cout << "Successfully loaded " << array.size() << " values from " << filepath << std::endl;
}

bool checkNFile(std::filesystem::path& dirN, int n, std::vector<double>& array)
{
    std::stringstream ss;
    //TODO

    // std::setfill('0') pads empty spaces with zeros
    // std::setw(2) forces the numerical output to be exactly 2 characters wide
    // ss << "roots_" << std::setfill('0') << std::setw(2) << n << ".dat";
    ss << "roots_" << n << ".dat";
    std::string filename = ss.str();
    std::filesystem::path file_path = dirN / filename;
    if (std::filesystem::exists(file_path) && std::filesystem::is_regular_file(file_path))
    {
        loadStructuredInputs(file_path.string(), array);
        return true;
    }
    else
    {
        return false;
    }
}

bool initializer(core::CurrentSession& currentSession)
{
    std::filesystem::path dir("../src/Roots");
    //std::cout << dir << std::endl;
    if (!std::filesystem::exists(dir) || !std::filesystem::is_directory(dir)) {
        std::cerr << "Error: Directory missing or invalid: ../src/Roots" << std::endl;
        return false;
    }
    std::cout << "Select Nx for system: " << std::endl;
    currentSession.nx = getInteger();

    if (!checkNFile(dir, currentSession.nx, currentSession.xi))
    {
        std::cerr << "Error: File missing or invalid: ./src/Roots/roots_" << currentSession.nx << ".dat" << std::endl;
        return false;
    }

    std::cout << "Select Ny for system: " << std::endl;
    currentSession.ny = getInteger();
    if (!checkNFile(dir, currentSession.ny, currentSession.yi))
    {
        std::cerr << "Error: File missing or invalid: ./src/Roots/roots_" << currentSession.ny << ".dat" << std::endl;
        return false;
    }
    
    return true;
}
}