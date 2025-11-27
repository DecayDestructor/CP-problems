#include <bits/stdc++.h>
using namespace std;

// Trapezoidal membership function
double trapezoidal(double x, double a, double b, double c, double d) {
    if (x <= a || x >= d) return 0.0;
    if (x >= b && x <= c) return 1.0;
    if (x > a && x < b) return (x - a) / (b - a);
    if (x > c && x < d) return (d - x) / (d - c);
    return 0.0;
}

// Fuzzy sets for temperature
double cold(double temp) {
    return trapezoidal(temp, 0, 0, 10, 20);
}

double warm(double temp) {
    return trapezoidal(temp, 15, 20, 25, 30);
}

double hot(double temp) {
    return trapezoidal(temp, 25, 30, 40, 40);
}

// Fuzzy sets for power adjustment
double increase(double power) {
    return trapezoidal(power, 0, 0, 50, 100);
}

double hold(double power) {
    return trapezoidal(power, -25, 0, 0, 25);
}

double decrease(double power) {
    return trapezoidal(power, -100, -50, 0, 0);
}

// Fuzzification
struct FuzzyInput {
    double cold_val;
    double warm_val;
    double hot_val;
};

FuzzyInput fuzzify(double temp) {
    FuzzyInput fi;
    fi.cold_val = cold(temp);
    fi.warm_val = warm(temp);
    fi.hot_val = hot(temp);
    return fi;
}

// Inference (Mamdani with min implication and max aggregation)
struct FuzzyOutput {
    double increase_val;
    double hold_val;
    double decrease_val;
};

FuzzyOutput infer(FuzzyInput fi) {
    // Rules:
    // If Cold then Increase
    // If Warm then Hold
    // If Hot then Decrease

    FuzzyOutput fo;
    fo.increase_val = fi.cold_val;  // min implication
    fo.hold_val = fi.warm_val;
    fo.decrease_val = fi.hot_val;

    return fo;
}

// Defuzzification using Center of Gravity (COG)
double defuzzify(FuzzyOutput fo) {
    // Discretize the output range from -100 to 100
    const int steps = 1000;
    double min_range = -100.0;
    double max_range = 100.0;
    double step_size = (max_range - min_range) / steps;

    double numerator = 0.0;
    double denominator = 0.0;

    for (int i = 0; i <= steps; ++i) {
        double x = min_range + i * step_size;
        double mu = max({fo.increase_val * increase(x), fo.hold_val * hold(x), fo.decrease_val * decrease(x)});
        numerator += x * mu;
        denominator += mu;
    }

    if (denominator == 0.0) return 0.0;
    return numerator / denominator;
}

int main() {
    double temp;
    cout << "Enter temperature: ";
    cin >> temp;

    FuzzyInput fi = fuzzify(temp);
    FuzzyOutput fo = infer(fi);
    double crisp_output = defuzzify(fo);

    cout << "Temperature: " << temp << "°C" << endl;
    cout << "Cold membership: " << fi.cold_val << endl;
    cout << "Warm membership: " << fi.warm_val << endl;
    cout << "Hot membership: " << fi.hot_val << endl;
    cout << "Power adjustment: " << crisp_output << endl;

    return 0;
}
