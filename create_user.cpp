#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>
namespace fs = std::filesystem;

bool create_user(std::string user, std::string password)
{
    auto current_path = fs::current_path();
    auto path = current_path/user;
    fs::path file(path);
    if(fs::exists(file)) {
        return false;
    }
    std::ofstream user_file;
    user_file.open(user, std::ofstream::out);

    user_file << password;
    user_file.close();
    return true;
}
