#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class smart_ptr
{
private:
    /* Pointer to managed object*/ 
    T *m_Obj{nullptr};
    /* Pointer to managed object reference count*/ 
    int *refCount{nullptr};

public:
/* Default constructor */
    smart_ptr() {}
    /* Constructor using obj */
    smart_ptr(T *object) : m_Obj{object}, refCount{new int(0)}
    {
        Increment();
        //cout << "New ptr, ref count is: " << refCount->GetCount() << endl;
    }
    
    /* Copy Constructor*/ 
    smart_ptr(const smart_ptr<T> &other) : m_Obj{other.m_Obj}, refCount{other.refCount}
    {
        Increment();
        
    }

    /* Overloaded Assignment Operator */
    smart_ptr<T> &operator=(const smart_ptr<T> &other)
    {
        if (this != &other)
        {
            if (refCount && Decrement() == 0)
            {
                
                delete m_Obj;
            }
            m_Obj = other.m_Obj;
            refCount = other.refCount;
            Increment();
        }
        //cout << "Assigning ptr ref count is: " << refCount->GetCount() << endl;
        return *this;
    }
    /* managed object and count is destroyed when ref count is 0 */
    virtual ~smart_ptr()
    {
        if (refCount)
        {
            int decCount = Decrement();            
            if (decCount <= 0)
            {/* Deallocate memory and set ptrs to nullptr to avoid dangling*/
               // cout << "Ptr deleted" << endl;                
                delete m_Obj;
                delete refCount;                
                m_Obj = nullptr;
                refCount = nullptr;
            }
        }
    }
    void Increment()
    {
        ++(*refCount);
    }
    int Decrement()
    {
        return --(*refCount);
    }    
    /* Dereference operator */
    T &operator*()
    {
        return *m_Obj;
    }
    /* Member access operator*/
    T *operator->() const
    {
        return m_Obj;
    }
    /* Member access to pointer */
    T *get() const
    {
        return m_Obj;
    }
    int get_count() const
    {
        return *refCount;
    }
    
};
/* String class uses smart pointer object which keeps track of ref count*/
class my_string
{
private:
    int length;
    smart_ptr<char> ptr_;

public:
    /* Defualt constructor */
    my_string() : ptr_(nullptr), length(0) {}
    /* Creating object with smart pointer class */
    my_string(const char *s) : ptr_(new char[std::strlen(s)]), length(0)
    {
        length = strlen(s);
        strcpy(ptr_.get(), s);
    }
    /* Copy constructor */
    my_string(const my_string &other) : ptr_(other.ptr_), length(other.length)
    {
    }
    /* Overloaded assignment operator */
    my_string &operator=(const my_string &other)
    {
        if (this != &other)
        {
            ptr_ = other.ptr_;
            length = other.length;
        }
        return *this;
    }
    /* Member fuctions */
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

    int get_count(){
        if(ptr_.get())
        {
            return ptr_.get_count();

        }
        else{
            return 0;
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



