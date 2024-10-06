#include <iostream>
#include "File.hpp"
#include "Folder.hpp"

/* 
Muslim Hussaini
*/

int main() {

    // Create files with different names, and copying/moving various files
    File file1; 
    File file6 = std::move(file1);


    
    // Check sizes for each file
    std::cout <<file1.getSize() <<std::endl;
    std::cout << file6.getSize() <<std::endl;


    // check names of each file
    std::cout << file1.getName() << std::endl;
    std::cout << file6.getName() <<std::endl;

   /*
    //Add files to source folder
    sourceFolder.addFile(file1);
    sourceFolder.addFile(file2);
    sourceFolder.addFile(file3);
    sourceFolder.addFile(file4);

    //Display folder to see if files were added
    sourceFolder.display();
    
    //Get size
    std::cout << "Source Folder Size: " << sourceFolder.getSize() << std::endl;


    //Check if copying file function in folder
    bool res1 = sourceFolder.copyFileTo(".env", destinationFolder);
    std::cout << "Copy hello.txt: " << (res1 ? "true" : "false") << std::endl;
    std::cout << "Destination Folder Size after copying hello.txt: " << destinationFolder.getSize() << std::endl;

    bool res2 = sourceFolder.copyFileTo("NewFile.txt", destinationFolder);
    std::cout << "Copy NewFile.txt: " << (res2 ? "true" : "false") << std::endl;

    bool res3 = sourceFolder.copyFileTo("file.txt", destinationFolder);
    std::cout << "Copy file.txt: " << (res3 ? "true" : "false") << std::endl;

    bool res4 = sourceFolder.copyFileTo("NewFile.txt", destinationFolder);
    std::cout << "Copy NewFile.txt again: " << (res4 ? "true" : "false") << std::endl;

    std::cout << "Final Destination Folder Size: " << destinationFolder.getSize() << std::endl;
    std::cout << "Files in Destination Folder: " << std::endl;


    // Test moving file function
    bool res5 = sourceFolder.moveFileTo("file.txt", destinationFolder);
    std::cout << "Move file.txt: " << (res5 ? "true" : "false") << std::endl;

    bool res6 = sourceFolder.moveFileTo("NewFile.txt", destinationFolder);
    std::cout << "Move NewFile.txt again: " << (res6 ? "true" : "false") << std::endl;

    // Test removing file
    bool res5 = sourceFolder.removeFile("aaa.txt");
    std::cout << "Move file.txt: " << (res5 ? "true" : "false") << std::endl;


    // Final status of the folder
    std::cout << "Final Destination Folder Size: " << destinationFolder.getSize() << std::endl;
    std::cout << "Files in Destination Folder: " << std::endl;
    destinationFolder.display();*/

    return 0;
}


