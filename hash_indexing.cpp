#include "hash_indexing.h"
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <limits>

hash_indexing::hash_indexing()
{
    //ctor
}

hash_indexing::~hash_indexing()
{
    //dtor
}

int hash_indexing::hash_function(std::string input)
{
    size_t hashed_variable;
    std::hash<std::string> hashing;
    hashed_variable = hashing(input);

    return hashed_variable;
}

void hash_indexing::welcome()
{
    std::cout << "Welcome" << std::endl;

    std::ifstream open("database.dat");
    char choice;

    if(!open)
    {
        open.close();
        std::cout << "Data Base seems not to exist, create one ? (Y/N) ";
        std::cin >> choice;

        if(choice == 'Y')
        {
            std::ofstream database_file("database.dat", std::ios::binary |
                                                        std::ios::app);
            database_file.close();
            std::cout << "Database created ! " << std::endl;

            command_interpreter();
        }

        else if(choice == 'N')
        {
            std::cout << "Nothing to be done." << std::endl;
        }

    }

    else
    {
        command_interpreter();
    }
}

void hash_indexing::command_interpreter()
{
    std::string command, option;
    while(command != "quit")
    {
        std::cin >> command >> option;
        if(command == "add")
        {
            add_function(option);
        }

        else if(command == "show")
        {
            find_function(option);
        }
    }
}

void hash_indexing::add_function(std::string option)
{
    int age(0);
    std::string city;

    std::cout << option << " : " << std::endl;
    std::cout << "age : ";
    std::cin >> age;
    std::cout << "city : ";
    std::cin >> city;

    std::ofstream open("database.dat", std::ios::binary |
                                       std::ios::app);

    open << hash_function(option) << " " << age << " " << city << std::endl;
    open.close();
}

void hash_indexing::find_function(std::string option)
{
    std::string age, city;
    size_t word;
    size_t hashed_input = hash_function(option);

    std::ifstream opening_test("database.dat");
    char line;
    int counter(1);

    while(opening_test.get(line))
    {
        counter += 1;
    }

    std::ifstream open("database.dat");

    int new_counter(1);

    while(word != hashed_input && counter != new_counter)
    {
        open >> word >> age >> city;
        open.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        new_counter += 1;
    }

    std::cout << "Name : " << option << " age : " << age << " city : " << city << std::endl;
    std::cout << "At line " << new_counter << " in database." << std::endl;
    open.close();
}
