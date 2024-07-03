#include <iostream>

namespace X {
    class A {
        private:
        int baba_joe = 200;

        public:
        std::ostream& operator<<(/* A* this, */std::ostream& out) {
            out << this->baba_joe << " ===== ";
            return out;
        }
        friend std::ostream& operator<<(std::ostream& out, const A& value);
    };

    namespace Y {
        void foo(const A& value) { }
    }

    std::ostream& operator<<(std::ostream& out, const A& value) {
        out << value.baba_joe;
        A& new_value = const_cast<A&>(value);
        new_value.baba_joe = 300;
        return out;
    }
}

int main()
{
    X::A a;
    std::cout << a << std::endl;
    a << std::cout << std::endl;
    X::Y::foo(a);
}
