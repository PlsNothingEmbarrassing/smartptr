#include <iostream>
#include <cstring>
using namespace std;
class my_string
{
private:
    int length;
    smart_ptr<char> ptr_;

public:
    // Defualt constructor
    my_string() : ptr_(nullptr), length(0) {}
    // Creating object with smart pointer class
    my_string(const char *s) : ptr_(new char[std::strlen(s)]), length(0)
    {
        length = strlen(s);
        strcpy(ptr_.get(), s);
    }
    // Copy constructor
    my_string(const my_string &other) : ptr_(other.ptr_), length(other.length)
    {
    }
    // Overloaded assignment operator
    my_string &operator=(const my_string &other)
    {
        if (this != &other)
        {
            ptr_ = other.ptr_;
            length = other.length;
        }
        return *this;
    }
    // Member fuctions
    char getChar(const int &i) const
    {
        if (i >= 0 && i < length)
        {
            return ptr_.get()[i];
        }
        return '\0';
    }

    void setChar(const int &i, const char &c)
    {
        if (i >= 0 && i < length)
        {
            ptr_.get()[i] = c;
        }
    }

    void print() const
    {
        if (ptr_.get())
        {
            std::cout << ptr_.get() << " "
                      << "[" << ptr_.get_count() << "]" << std::endl;
        }
        else
        {
            std::cout << "(Empty String)" << std::endl;
        }
    }
};

class ReferenceCount
{
private:
    // Where the actual count of the managed object is being stored
    int RefCount{0};

public:
    void Increment()
    {
        ++RefCount;
    }
    int Decrement()
    {
        return --RefCount;
    }
    int GetCount() const
    {
        return RefCount;
    }
};

template <typename T>
class smart_ptr
{
private:
    // Pointer to managed object
    T *m_Obj{nullptr};
    // Pointer to managed object reference count
    ReferenceCount *m_ReferenceCount{nullptr};

public:
    smart_ptr() {}
    // Constructor
    smart_ptr(T *object) : m_Obj{object}, m_ReferenceCount{new ReferenceCount()}
    {
        m_ReferenceCount->Increment();
        cout << "Created ptr ref count is " << m_ReferenceCount->GetCount() << endl;
    }
    // Virtual deconstructor - managed object and count is destroyed when ref count is 0
    virtual ~smart_ptr()
    {
        if (m_ReferenceCount)
        {
            int decrementedCount = m_ReferenceCount->Decrement();
            cout << "Destroyed ptr! Ref count is " << decrementedCount << endl;
            if (decrementedCount <= 0)
            {
                delete m_ReferenceCount;
                delete m_Obj;
                m_ReferenceCount = nullptr;
                m_Obj = nullptr;
            }
        }
    }
    // Copy Constructor
    smart_ptr(const smart_ptr<T> &other) : m_Obj{other.m_Obj}, m_ReferenceCount{other.m_ReferenceCount}
    {
        m_ReferenceCount->Increment();
        cout << "Copied ptr ref count is " << m_ReferenceCount->GetCount() << endl;
    }

    // Overloaded Assignment Operator
    smart_ptr<T> &operator=(const smart_ptr<T> &other)
    {
        if (this != &other)
        {
            if (m_ReferenceCount && m_ReferenceCount->Decrement() == 0)
            {
                delete m_ReferenceCount;
                delete m_Obj;
            }
            m_Obj = other.m_Obj;
            m_ReferenceCount = other.m_ReferenceCount;
            m_ReferenceCount->Increment();
        }
        cout << "Assigning ptr ref count is " << m_ReferenceCount->GetCount() << endl;
        return *this;
    }
    // Dereference operator
    T &operator*()
    {
        return *m_Obj;
    }

    T *operator->()
    {
        return m_Obj;
    }
    // Member access to pointer
    T *get() const
    {
        return m_Obj;
    }
    int get_count() const
    {
        return m_ReferenceCount->GetCount();
    }
};
