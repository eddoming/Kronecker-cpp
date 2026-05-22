#include <iostream>
#include <vector>
#include <filesystem>
#include <cstdlib> // for std::exit
#include <iostream>
#include <fstream>
#include <limits> // for std::numeric_limits

// Standard C-linkage header for LAPACKE
#include <lapacke.h>
// Local code
#include "include/Functions.h"

//https://www.learncpp.com/cpp-tutorial/stdcin-and-handling-invalid-input/

struct CurrentSession
{
    int data {0};
    std::vector<double> n_xv;
    std::vector<double> n_yv;
    std::filesystem::path n_x_path{""};
    std::filesystem::path n_y_path{""};
};

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
        std::cout << "Enter a intger number: ";
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
    // std::setfill('0') pads empty spaces with zeros
    // std::setw(2) forces the numerical output to be exactly 2 characters wide
    ss << "roots_" << std::setfill('0') << std::setw(2) << n << ".dat";
    std::string filename = ss.str();
    std::filesystem::path file_path = dirN / filename;
    //std::cout << file_path << std::endl;
    //return (std::filesystem::exists(file_path) && std::filesystem::is_regular_file(file_path));
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

bool initializer(CurrentSession& currentSession)
{
    std::filesystem::path dir("../src/Roots");
    //std::cout << dir << std::endl;
    if (!std::filesystem::exists(dir) || !std::filesystem::is_directory(dir)) {
        std::cerr << "Error: Directory missing or invalid: ../src/Roots" << std::endl;
        return false;
    }
    std::cout << "Select Nx for system: " << std::endl;
    int n_x {getInteger()};

    if (!checkNFile(dir, n_x, currentSession.n_xv))
    {
        std::cerr << "Error: File missing or invalid: ./src/Roots/roots_" << n_x << ".dat" << std::endl;
        return false;
    }

    std::cout << "Select Ny for system: " << std::endl;
    int n_y {getInteger()};
    if (!checkNFile(dir, n_y, currentSession.n_yv))
    {
        std::cerr << "Error: File missing or invalid: ./src/Roots/roots_" << n_y << ".dat" << std::endl;
        return false;
    }
    
    return true;
}

int main() {

    // [A Kronecker B] x = b
    // Polinomios de Lagere variable x
    std::cout << "Kronecker-cpp Project" << std::endl;
    CurrentSession currentSession{};
    initializer(currentSession);
    for (auto a : currentSession.n_xv)
    {
        std::cout << std::setprecision(17);
        std::cout << a << std::endl;
    }

    return EXIT_SUCCESS;
    //[[maybe_unused]] auto var = Functions::a_t(1, 2, 3) * Functions::b_t(1, 2, 3);
    //std::cout << var << std::endl; 
    // Solve Ax = b
    // A = [ 1, 2 ]
    //     [ 3, 4 ]
    // b = [ 5, 11 ]
    //
    int n = 2; // Matrix size (n x n)
    int nrhs = 1; // Number of right-hand columns

    std::vector<double> A = {1.0, 2.0,
                             3.0, 4.0};
    std::vector<double> b = {5.0,
                             11.0};

    // LAPACK will output the pivot indices here
    std::vector<int> ipiv(n);

    // Call LAPACKE using Row Major layout
    int info = LAPACKE_dgesv(LAPACK_ROW_MAJOR, n, nrhs,
                             A.data(), n,
                             ipiv.data(),
                             b.data(), nrhs);

    if (info == 0) {
        std::cout << "Solution successful!" << std::endl;
        std::cout << "x = [" << b[0] << ", " << b[1] << "]" << std::endl;
        // Expected output: x = [1, 2]
    } else {
        std::cerr << "LAPACK Matrix factorization failed. Info code: " << info << std::endl;
    }

//    std::string result = "1/2"; 
//
//    std::string text_markup = 
//        "<span size='large' foreground='#555555'>Calculation Complete</span>\\n\\n"
//        "The final result is: <span font='26' weight='bold' foreground='#1A73E8'>" + result + "</span>";
//
//    // Set custom options: window title, icon style, width/height boundaries, and disable ugly line wrapping
//    std::string command = "zenity --info "
//                          "--title=\"Kronecker Engine\" "
//                          "--window-icon=\"info\" "
//                          "--width=350 "
//                          "--no-wrap "
//                          "--text=\"" + text_markup + "\"";
//
//    // Execute directly
//    std::system(command.c_str());
//
    return 0;
}
