#include <iostream>
#include "File.hpp"
#include "Folder.hpp"

/* 
Muslim Hussaini
*/

int main() {

    // Create files with different names, and copying/moving various files
    File file1; 
    File file2(".env", "aaaaa");
    File file3("aaa", "Content");
    File file4 = File(file1);
    File file5 = file3;
    File file6 = std::move(file1);
    File file7 = File("hello.png");
    file7 = file1;

    // check names of each file
    std::cout << file1.getName() << std::endl;
    std::cout << file2.getName() << std::endl;
    std::cout << file3.getName() << std::endl;
    std::cout << file4.getName() <<std::endl;
    std::cout << file5.getName() <<std::endl;
    std::cout << file6.getName() <<std::endl;
    std::cout << file7.getName() << std::endl;

    return 0;
}


