#include "Storable.h"

#include <iostream>
#include <fstream>

namespace Core {
    bool Storable::Save(std::string filepath)
    {
        // Automatically creates the file if it does not exist
        std::ofstream file(filepath);

        // Check if file failed to load
        if (!file.good()) {
            std::cout << "File failed to save correctly: `" << filepath << "`" << std::endl;
            return false;
        }

        // Write to file
        file << ToStorable();

        file.close();
        return true;
    }

    bool Storable::Load(std::string filepath)
    {

        std::ifstream file(filepath);

        // Check if file failed to load
        if (file.fail()) {
            std::cout << "File failed to load correctly: `" << filepath << "`" << std::endl;
            return false;
        }

        // Dump the data from file into data
        std::string data;
        file >> data;

        // We no longer need the file
        file.close();

        // Tell the object to load
        return FromStorable(data);
    }
}