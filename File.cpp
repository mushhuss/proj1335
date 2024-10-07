#include "File.hpp"
      
std::string File::getName() const {
   return filename_;
}

std::string File::getContents() const {
   return contents_;
}

void File::setContents(const std::string& new_contents) {
   contents_ = new_contents;
}

int* File::getIcon() const {
   return icon_;
}

void File::setIcon(int* new_icon) {
   if (icon_) { delete[] icon_; }
   icon_ = new_icon;
} 

std::ostream& operator<< (std::ostream& os, const File& target) {
   os << "Name: " << target.getName() << std::endl;
   os << "Size: " << target.getSize() << " bytes" << std::endl;
   os << "Contents: " << target.getContents(); 
   return os;
}

bool File::operator<(const File& rhs) const {
   return getName() < rhs.getName();
}

//                       DO NOT EDIT ABOVE THIS LINE. 
//             (unless you want your work to be tested incorrectly)
//    That also means includes. Remember, all other includes go in .hpp

// However, you may notice an operator overload you don't recognize (<<)
// Try calling the following once you've implemented a constructor & getSize():
//    File a; 
//    std::cout << a << std::endl;

// =========================== YOUR CODE HERE ===========================

      /**
      * @brief Constructs a new File object.
      * 
      * @param filename A const reference to a string containing alphanumeric characters and exactly one period in the format "filename" or "filename.extension"
      *    - If the string contains any non-alphanumeric characters besides *exactly_one* period an InvalidFormatException is thrown
      *    - If no extension is provided (e.g. there is no period within the provided filename) or nothing follows the period, then ".txt" is used as the extension
      *    - Default value of "NewFile.txt" if none provided or if filename is empty 
      * @param contents A string representing the contents of the file. Default to empty string if none provided.
      * @param icon A pointer to an integer array with length ICON_DIM. Default to nullptr if none provided.
      * @throws InvalidFormatException - An error that occurs if the filename is not valid by the above constraints.
      * @note You'll notice we provide a default value for the first possible argument (filename)
      *       Yes, this means we can define override the default constructor and define a parameterized one simultaneously.
      */
      File::File(const std::string &filename, const std::string &contents, int *icon) : contents_(contents), icon_(icon) {

         int pcount = 0;
         int pindex;

         for (int i = 0; i < filename.length(); i++){

            //checks if characther isnt alphanumerical
            if ( !isalnum(filename[i])){
            
               //checks if its a period or not
               if (filename[i] == '.'){
                  pcount++;
                  pindex = i;
               }
               //if its a period throw exception
               else {
                  throw InvalidFormatException("Non alphanum value spotted, invalid");
               }
            }

            //if the period count ever goes above 1 automatically throw an exception
            if (pcount > 1){
               throw InvalidFormatException("too many periods, invalid");
            }
            
         }

         if (pcount == 0){
            filename_ = filename + ".txt";
         }
         else if(pcount == 1){
            if (pindex  == filename.length() - 1){
               filename_ = filename + "txt";
            }
            else{
               filename_ = filename;
            }
         }

         if (filename == ""){
               filename_ = "NewFile.txt";
         }

      }

      /**
      * @brief Calculates and returns the size of the File Object (IN BYTES), using .size()
      * @return size_t The number of bytes the File's contents consumes
      * @note Consider this: how does this relate to the string's length? Why is that the case?
      */
      size_t File::getSize() const{
         
         return contents_.size();   

      }

      /**
       * @brief (COPY CONSTRUCTOR) Constructs a new File object as a deep copy of the target File
       * @param rhs A const reference to the file to be copied from
       */
      File::File(const File &rhs) : filename_(rhs.filename_), contents_(rhs.contents_) {

        if (rhs.icon_) { //if its not nullptr 
            icon_ = new int[ICON_DIM];
            for (auto i=0; i< ICON_DIM; i++){
               icon_[i] = rhs.icon_[i];
            }
        }
         else {
            icon_ = nullptr; // If rhs.icon is nullptr, make new icon nullptr as well
        }

      }

      /**
       * @brief (COPY ASSIGNMENT) Replaces the calling File's data members using a deep copy of the rhs File.
       * 
       * @param rhs A const reference to the File object to be copied
       * @return A reference to the new File copy
       * @note If copy assignment operator is invoked upon itself, do nothing.
       */
      
      File& File::operator=(const File &rhs){

         if (this == &rhs){ // if its invoked upon itself 
            return *this;
         }

         if (rhs.icon_) {

            icon_ = new int[ICON_DIM]; 

            std::copy(rhs.icon_, rhs.icon_ + ICON_DIM, icon_); 

         } 

         else {
            icon_ = nullptr;
         }

        contents_ = rhs.contents_;
        filename_ = rhs.filename_;

         return *this; //returns reference to the new file copy


      }

      /**
       * @brief (MOVE CONSTRUCTOR) Construct a new File object by moving the data from the righthand side File Object
       * @param rhs The File whose data is moved
       * @post The rhs File object is left in a valid, but ready to be deleted state:
       *    - All string members are themselves moved.
       *    - ALl pointers are set to nullptr
       */
      File::File(File &&rhs) : filename_(std::move(rhs.filename_)), contents_(std::move(rhs.contents_)), icon_(rhs.icon_){
      
         rhs.icon_ = nullptr;//make ready to delete

      }

      /**
       * @brief (MOVE ASSIGNMENT) Move the rhs data to the calling file object
       * 
       * @param rhs The File whose data is moved
       * @return A reference to the object which the data was moved into
       * @post The rhs File object is left in a valid, but ready to be deleted state:
       *    - All string members are moved.
       *    - ALl pointers are set to nullptr
       * @note If move assignment operator is invoked upon itself, do nothing.
       */
      File& File::operator=(File&& rhs){

         if (this == &rhs){
            return *this;
         }

         //transfer ownership of icon_
         delete[] icon_;
         icon_ = rhs.icon_;
         rhs.icon_ = nullptr;

        // move strings
        filename_ = std::move(rhs.filename_);
        contents_ = std::move(rhs.contents_);

        return *this;
         

      }

      /**
       * @brief (DESTRUCTOR) Routine for object deletion
       * @post All dynamically allocated memory is released
       */
      File::~File(){

         delete[] icon_;
         icon_ = nullptr;

      }