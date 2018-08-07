#include <iostream>
#include <vector>
#include <algorithm>


// holds a pair of ints, ex. (3,4),(-1,0)
class NumberPair {
private:
    int first_;
    int second_;
public:
    NumberPair(int first, int second) : first_(first), second_(second) {
        // ayy lmao
    }

    // accessors
    int getFirst() const {
        return first_;
    }
    int getSecond() const {
        return second_;
    }

    // increment first and second ints
    void incBoth() {
        first_++;
        second_++;
    }

    // compars size of two NPs
    bool operator<(const NumberPair& compared) {
        if (this->getFirst() != compared.getFirst()) {
            return this->getFirst() < compared.getFirst();
        }
        return this->getSecond() < compared.getSecond();
    }

    // adds two NPs
    NumberPair operator+(const NumberPair& x) {
        return NumberPair(this->getFirst() + x.getFirst(), this->getSecond() + x.getSecond());
    }

    // functor to add two 
    NumberPair operator()(NumberPair element) {
        return element + *this;
    }
};

std::ostream& operator<<(std::ostream& out, const NumberPair& num) {
    out << num.getFirst() << " " << num.getSecond();
    return out;
}

void print(std::vector<NumberPair> a) {
    for (auto i = a.begin(); i != a.end(); i++) {
        std::cout << *i << std::endl;
    }
}

bool compare(NumberPair first, NumberPair second) {
    return first < second;
}

int main(int argc, const char * argv[]) {

    // create vector of number pairs
    std::vector<NumberPair> numbers;
    numbers.push_back(NumberPair(1,3));
    numbers.push_back(NumberPair(2,1));
    numbers.push_back(NumberPair(3,2));
    numbers.push_back(NumberPair(2,10));
    numbers.push_back(NumberPair(1,2));
    numbers.push_back(NumberPair(4,2));
    numbers.push_back(NumberPair(3,1));

    std::cout << "list" << std::endl;
    print(numbers);
    std::cout << "---" << std::endl;

    // sort number pairs
    // sort(numbers.begin(), numbers.end(), compare);
    sort(numbers.begin(), numbers.end(), [] (NumberPair first, NumberPair second) {return first < second;});

    // print number paris
    std::cout << "sorted" << std::endl;
    print(numbers);
    std::cout << "---" << std::endl;

    // add an NP to the NP vecotr with a functor
    NumberPair np = NumberPair(3,14);
    transform(numbers.begin(), numbers.end(), numbers.begin(), np);

    // print number paris
    std::cout << "transformed" << std::endl;
    print(numbers);

    return 0;
}
