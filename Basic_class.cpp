#include <iostream>
template<typename T>
constexpr bool is_double_or_float_or_convertible_v = 
    std::is_same<T, double>::value || std::is_same<T, float>::value;

template <typename T>
class Point{
  private:
    static_assert(is_double_or_float_or_convertible_v<T>, "Wrong type for a point!");
    T x;
    T y;
    T z;
  public:
    Point() {};
    Point (T x, T y, T z): x(x), y(y), z(z) {};
    Point (Point& other): x(other.x), y(other.y), z(other.z) {};

    T getX() const{return x;};
    T getY() const{return y;};
    T getZ() const{return z;};

    void setX(T val) {x = val;};
    void setY(T val) {y = val;};
    void setZ(T val) {z = val;};

    Point<T>& operator += (const Point& other){
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    Point<T>& operator -= (const Point& other){
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    Point<T>& operator = (const Point& other){
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }
    bool operator == (const Point& other) const{
        return x == other.x && y == other.y && z = other.z;
    }
    bool operator != (const Point& other) const{
        return !(*this == other);
    }
    Point<T> operator +(const Point<T>& s2){
        return *this += s2;
    };
    Point<T> operator -(const Point<T>& s2){
        return *this -= s2;
    };
    ~Point() = default;
};

template <typename T>
std::ostream& operator << (std::ostream& out, const Point<T>& p) {
    static_assert(is_double_or_float_or_convertible_v<T>, "Wrong type for a point!");
    out << p.getX() << " " << p.getY() << " " << p.getZ();
    return out;
};

template <typename T>
std::istream& operator >> (std::istream& in, Point<T>& p) {
    static_assert(is_double_or_float_or_convertible_v<T>, "Wrong type for a point!");
    T x, y, z;
    in >> x >> y >> z;
    p.setX(x);
    p.setY(y);
    p.setZ(z);
    return in;
};

int main(){
    return 0;
};
