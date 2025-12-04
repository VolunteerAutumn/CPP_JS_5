#include <iostream>
#include <cmath>
using namespace std;

// =============================================================
//                   TASK 1 — RECTANGLE
// =============================================================
struct Rectangle {
    double x;      // position (top-left corner)
    double y;
    double width;
    double height;
};

void Move(Rectangle& r, double dx, double dy) {
    r.x += dx;
    r.y += dy;
}

void Resize(Rectangle& r, double newW, double newH) {
    if (newW > 0) r.width = newW;
    if (newH > 0) r.height = newH;
}

void PrintRectangle(const Rectangle& r) {
    cout << "Rectangle:\n";
    cout << " Position: (" << r.x << ", " << r.y << ")\n";
    cout << " Size: " << r.width << " x " << r.height << "\n\n";
}

// =============================================================
//                   TASK 2 — POINT & DISTANCE
// =============================================================
struct Point {
    double x;
    double y;
};

double Distance(const Point& a, const Point& b) {
    return sqrt((b.x - a.x)*(b.x - a.x) +
                (b.y - a.y)*(b.y - a.y));
}

// =============================================================
//                   TASK 3 — FRACTION
// =============================================================

int GCD(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return abs(a);
}

struct Fraction {
    int num;  // numerator
    int den;  // denominator
};

void Reduce(Fraction& f) {
    int g = GCD(f.num, f.den);
    f.num /= g;
    f.den /= g;
    if (f.den < 0) {       // normalize sign
        f.den *= -1;
        f.num *= -1;
    }
}

Fraction Add(Fraction a, Fraction b) {
    Fraction r;
    r.num = a.num * b.den + b.num * a.den;
    r.den = a.den * b.den;
    Reduce(r);
    return r;
}

Fraction Sub(Fraction a, Fraction b) {
    Fraction r;
    r.num = a.num * b.den - b.num * a.den;
    r.den = a.den * b.den;
    Reduce(r);
    return r;
}

Fraction Mul(Fraction a, Fraction b) {
    Fraction r;
    r.num = a.num * b.num;
    r.den = a.den * b.den;
    Reduce(r);
    return r;
}

Fraction Div(Fraction a, Fraction b) {
    Fraction r;
    r.num = a.num * b.den;
    r.den = a.den * b.num;
    Reduce(r);
    return r;
}

void PrintFraction(Fraction f) {
    Reduce(f);
    if (abs(f.num) > abs(f.den)) {
        int whole = f.num / f.den;
        int rem = abs(f.num % f.den);
        cout << whole;
        if (rem != 0) cout << " " << rem << "/" << f.den;
    }
    else {
        cout << f.num << "/" << f.den;
    }
}

// =============================================================
//                              MAIN
// =============================================================
int main() {

    // ---------------- TASK 1 ----------------
    Rectangle R = {0, 0, 10, 20};
    PrintRectangle(R);
    Move(R, 5, -3);
    Resize(R, 15, 25);
    PrintRectangle(R);

    // ---------------- TASK 2 ----------------
    Point A = {0, 0};
    Point B = {3, 4};
    cout << "Distance between A and B = " << Distance(A, B) << "\n\n";

    // ---------------- TASK 3 ----------------
    Fraction f1 = {5, 6};
    Fraction f2 = {3, 4};

    cout << "f1 + f2 = ";
    PrintFraction(Add(f1, f2));
    cout << "\n";

    cout << "f1 - f2 = ";
    PrintFraction(Sub(f1, f2));
    cout << "\n";

    cout << "f1 * f2 = ";
    PrintFraction(Mul(f1, f2));
    cout << "\n";

    cout << "f1 / f2 = ";
    PrintFraction(Div(f1, f2));
    cout << "\n";

    return 0;
}
