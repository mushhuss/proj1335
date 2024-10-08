#include <iostream>
#include "File.hpp"
#include "Folder.hpp"

/* 
Muslim Hussaini
*/

int main() {

    // Create files with different names, and copying/moving various files
    File one; 
    File two(".jpeg", "hi");
    File three("bb", "random");
    File four = File(one);
    File five = three;
    File six = std::move(one);
    File seven = File("bruh.jpeg");
    seven = one;
    File eight("abc.");
    File nine;

    // check names of each file
std::cout << one.getSize() << std::endl;
std::cout << two.getSize() << std::endl;
std::cout << three.getSize() << std::endl;
std::cout << four.getSize() << std::endl;
std::cout << five.getSize() << std::endl;
std::cout << six.getSize() << std::endl;
std::cout << seven.getSize() << std::endl;
std::cout << eight.getSize() << std::endl;
std::cout << nine.getSize() << std::endl;

std::cout << one.getName() << std::endl;
std::cout << two.getName() << std::endl;
std::cout << three.getName() << std::endl;
std::cout << four.getName() << std::endl;
std::cout << five.getName() << std::endl;
std::cout << six.getName() << std::endl;
std::cout << seven.getName() << std::endl;
std::cout << eight.getName() << std::endl;
std::cout << nine.getName() << std::endl;

    Folder source;
    source.display();
    Folder destination;

    source.addFile(one);
    source.moveFileTo(one.getName(), destination);
    destination.removeFile(one.getName());

    Folder f1;
    Folder f2("Folder");



    
    return 0;
}


