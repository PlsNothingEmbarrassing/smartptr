#include <iostream>
#include <cstring>
using namespace std;
class my_string
{
private:
	char *ptr_;
	int length;
	int *ref_count;

public:
	/* Contructor */
	my_string() : ptr_(nullptr), length(0), ref_count(nullptr){};

	my_string(const char *s) : ptr_(nullptr), length(0), ref_count(new int(1))
	{
		length = strlen(s);
		ptr_ = new char[length + 1];
		strcpy(ptr_, s);
	}
	/* Copy Constructor */
	my_string(my_string const &s) : ptr_(s.ptr_), length(s.length), ref_count(s.ref_count)
	{
		/* Creating a shallow copy with shared memory */

		if (ref_count)
		{
			(*ref_count)++;
		}
	}

	/* Assignment Operator */
	my_string &operator=(my_string const &s)
	{

		if (this != &s)
		{

			ptr_ = s.ptr_;
			length = s.length;
			ref_count = s.ref_count;
			cout << "new assignment" << endl;

			if (ref_count)
			{
				(*ref_count)++;
			}
		}
		return *this;
	}
	/* Decontructor*/
	~my_string()
	{
		if (ref_count && --(*ref_count) == 0)
		{
			cout << "Ref count has reached 0" << endl;
			delete[] ptr_;
			delete ref_count;
			
		}
	}
	int get_count(){
		return (ref_count ? *ref_count : 0);
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
			std::cout << ptr_ << " [" << (ref_count ? *ref_count : 0) << "]" << std::endl;
		}
		else
		{
			std::cout << "(Empty String)" << std::endl;
		}
	}
};
