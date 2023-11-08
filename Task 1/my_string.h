#include <iostream>
#include <cstring>
using namespace std;
class my_string
{
private:
    /* ptr to object data*/
    char *ptr_;
    int length;

public:
    /* Contructors */
    my_string() : ptr_(nullptr), length(0){};
    
    my_string(const char *s) : ptr_(nullptr), length(0)
    {/* Assigning ptr and length to s */
        length = strlen(s);
        ptr_ = new char[length + 1];
        strcpy(ptr_, s);
    }
    /* Copy Constructor */
    my_string(my_string const &s) : ptr_(s.ptr_), length(s.length)
    {
        }

    /* Assignment Operator */
    my_string &operator=(my_string const &s)
    {

        if (this != &s)
        {
            /* make object pointer point to s */
            ptr_ = s.ptr_;
            length = s.length;
            cout << "new assignment" << endl;
        }
        return *this;
    }
    /* Decontructor*/
    ~my_string()
    {
    }

    /* getChar member function*/
    char getChar(const int &i) const
    {
        if (i >= 0 && i < length)
        {
            return ptr_[i];
        }
        return '\0';
    }

    /* setChar member function*/
    void setChar(const int &i, const char &c)
    {
        if (i >= 0 && i < length)
        {
            ptr_[i] = c;
        }
    }
    /* Print func */
    void print() const
    {
        if (ptr_)
        {
            std::cout << ptr_ << std::endl;
        }
        else
        {
            std::cout << "(Empty String)" << std::endl;
        }
    }
};
