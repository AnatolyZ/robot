#include <iostream>
#include <filesystem>

int main()
{
    std::error_code ec;
    const auto created = std::filesystem::create_directory("hellocpp17", ec);
    std::cout << "Dir created: " << (created ? "YES" : "NO") << " Error: " << ec.message() << std::endl;
    std::cout << "Current directiry" << std::filesystem::current_path() << std::endl;
    return 0;
}
