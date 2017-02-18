#ifndef HASH_INDEXING_H
#define HASH_INDEXING_H

#include <iostream>
#include <string>

class hash_indexing
{
    public:
        hash_indexing();
        virtual ~hash_indexing();

        void welcome();
        void command_interpreter();
        void add_function(std::string option);
        void find_function(std::string option);

        int hash_function(std::string input);

        std::string name, city;
        int age;

    protected:

    private:
};

#endif // HASH_INDEXING_H
