#include<fstream>
#include<iostream>
#include <limits>
#include <string>
class Drive
{
private:
    /* data */
    std::string PATH="/dev/test_device_file";
    std::fstream m_fd;

public:

    void Write_To_File(std::string message);
    std::string Read_From_File(void);


};


void Drive::Write_To_File(std::string message)
{
    m_fd.open(PATH,std::ios::out);
    m_fd.write(message.c_str(),message.size());
    m_fd.close();

}
std::string  Drive::Read_From_File(void)
{
    std::string str;

    m_fd.open(PATH,std::ios::in);
    std::getline(m_fd,str);
    m_fd.close();


    return str;

}


int main(void)
{
    int answer;
    Drive d;
    std::cout<<"Do you want to read or write ? 1 to read , 2 to write"<<std::endl;
    std::cin>> answer ;

    if (answer == 1)
    {
        std::string str;
        str = d.Read_From_File();
        std::cout << "the reading message is "<<str<<std::endl; 

    }
    else if (answer == 2)
    {
        std::string str;
        std::cout << "please enter the data " <<std::endl;
         // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // Read a line of text from the user
        std::getline(std::cin, str);

        d.Write_To_File(str);
    }
    else 
    {
        std::cout<<"wrong option \n" <<std::endl;
    }

    return 0;
}