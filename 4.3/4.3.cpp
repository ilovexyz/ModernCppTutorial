#include <tuple>
#include <iostream>
#include <variant> // c++17

auto get_student(int id)
{
    if (id == 0)
    {
        return std::make_tuple(3.8, 'A', "John");
    }
    if (id == 1)
    {
        return std::make_tuple(2.9, 'B', "Jack");
    }
    return std::make_tuple(0.0, 'D', "null");
}


template<size_t n, typename... T>
constexpr std::variant<T...> _tuple_index(const std::tuple<T...>& tpl, size_t i)
{
    if constexpr (n >= sizeof...(T))
        throw std::out_of_range(" .");
    if(i == n)
    {
        return std::variant<T...>{ std::in_place_index<n>, std::get<n>(tpl)};
    }
    return _tuple_index<(n < sizeof...(T)-1 ? n+1: 0)>(tpl, i);
}

template<typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...> &tpl, size_t i)
{
    return _tuple_index<0>(tpl, i);
}

template<typename T0, typename... Ts>
std::ostream & operator<< (std::ostream & s, std::variant<T0, Ts...> const & v)
{
    std::visit([&](auto && x) {
        s << x;
    }, v);
    return s;
}

template<typename T>
auto tuple_len(T & tpl)
{
    return std::tuple_size<T>::value;
}


int main()
{

    auto s = get_student(0);

    // using std::get to get tuple element
    std::cout << "ID: 0, " 
    << "GPA: " << std::get<0>(s) << ", "
    << "Grade: " << std::get<1>(s) << ", "
    << "Name: " << std::get<2>(s) << "\n";

    // using std::tie to unpack tuple element
    double gpa;
    char grade;
    std::string name;
    std::tie(gpa, grade, name) = get_student(1);
    std::cout << "ID: 1, "
    << "GPA: " << gpa << ", "
    << "Grade: " << grade << ", "
    << "Name: " << name << '\n';

    // runtime indexing
    std::cout << tuple_index(s, 2) << std::endl;

    for (size_t i = 0; i < tuple_len(s); i++)
    {
        std::cout << tuple_index(s, i) << " ";
    }
    std::cout << std::endl;
    return 0;
}