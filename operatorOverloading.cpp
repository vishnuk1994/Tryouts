#include <iostream>
const int MAX_ELEMENT = 5;

namespace my
{
    void cout (std::ostream& os, char* arg)
    {
        os << arg <<std::endl;
    }
}

void* operator new(size_t size)
{
    void* ob = malloc(size);
    return ob;
}

class Complex
{
    private:
        int x;
        int y;
        static unsigned short counter;
    public:
        Complex();
        Complex(const Complex& ob);
        Complex& operator = (const Complex& ob);
        friend std::ostream& operator << (std::ostream& os, const Complex& ob);
        friend void operator >> (std::istream& is, Complex& ob);
        static void IncrementCounter ();
};

unsigned short Complex::counter = 0;

Complex::Complex():x(8),y(0) {}

Complex::Complex (const Complex& ob)
{
    my::cout(std::cout, "// Copy constructor called.");
    x = ob.x;
    y = ob.y;
}

Complex& Complex::operator = (const Complex& ob)
{
    std::cout << "// Assignment operator called." <<std::endl;
    if (this == &ob)
    {
        return *this;
    }
        
    this->x = ob.x;
    this->y = ob.y;
    return *this;
}

std::ostream& operator << (std::ostream& os, const Complex& ob)
{
    os << "// Value : " << ob.x << " +i" << ob.y << std::endl;
    return os;
}

void operator >> (std::istream& is, Complex& ob)
{
    is >> ob.x >> ob.y;
}

int main() {
	Complex ob;
	Complex ob1(ob);
	Complex ob2 = ob1;
	Complex ob3;
	ob3 = ob2;
	std::cin >> ob2;
	std::cout << ob2;
	return 0;
}
