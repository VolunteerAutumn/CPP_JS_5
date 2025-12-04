#include <iostream>
#include <string>
using namespace std;

// ====================== TASK 1: Washing Machine ==========================
struct WashingMachine {
    string brand;
    string color;
    float width;
    float length;
    float height;
    int power;
    int spinSpeed;
    int heatingTemp;
};

WashingMachine ShowWashingMachine(WashingMachine w) {
    cout << "=== Washing Machine ===\n";
    cout << "Brand: " << w.brand << "\n";
    cout << "Color: " << w.color << "\n";
    cout << "Size (W/L/H): " << w.width << " / " << w.length << " / " << w.height << "\n";
    cout << "Power: " << w.power << "W\n";
    cout << "Spin Speed: " << w.spinSpeed << " rpm\n";
    cout << "Heating Temp: " << w.heatingTemp << "°C\n\n";
}

// ====================== TASK 2: Iron ==========================
struct Iron {
    string brand;
    string model;
    string color;
    int minTemp;
    int maxTemp;
    bool steam;
    int power;
};

Iron ShowIron(Iron i) {
    cout << "=== Iron ===\n";
    cout << "Brand: " << i.brand << "\n";
    cout << "Model: " << i.model << "\n";
    cout << "Color: " << i.color << "\n";
    cout << "Temperature range: " << i.minTemp << " - " << i.maxTemp << "°C\n";
    cout << "Steam: " << (i.steam ? "YES" : "NO") << "\n";
    cout << "Power: " << i.power << "W\n\n";
}

// ====================== TASK 3: Boiler ==========================
struct Boiler {
    string brand;
    string color;
    int power;
    int capacity;
    int heatingTemp;
};

Boiler ShowBoiler(Boiler b) {
    cout << "=== Boiler ===\n";
    cout << "Brand: " << b.brand << "\n";
    cout << "Color: " << b.color << "\n";
    cout << "Power: " << b.power << "W\n";
    cout << "Capacity: " << b.capacity << "L\n";
    cout << "Heating Temp: " << b.heatingTemp << "°C\n\n";
}

// ====================== TASK 4: Animal ==========================
struct Animal {
    string name;
    string typeClass;
    string nickname;
};

Animal FillAnimal(Animal a) {
    cout << "Enter animal name (species): ";
    getline(cin, a.name);

    cout << "Enter animal class (mammal, reptile, etc): ";
    getline(cin, a.typeClass);

    cout << "Enter nickname: ";
    getline(cin, a.nickname);
}

Animal PrintAnimal(Animal a) {
    cout << "=== Animal ===\n";
    cout << "Species: " << a.name << "\n";
    cout << "Class: " << a.typeClass << "\n";
    cout << "Nickname: " << a.nickname << "\n\n";
}

Animal MakeSound(Animal a) {
    cout << a.nickname << " is making a sound: ";
    if (a.typeClass == "dog") cout << "WOOF!\n";
    else if (a.typeClass == "cat") cout << "MEOW!\n";
    else cout << "Unknown mysterious sound 👀\n";
}

// ============================ MAIN ===============================
int main() {
    // --- TASK 1 ---
    WashingMachine w = { "Samsung", "White", 60.0f, 55.0f, 85.0f, 2000, 1400, 90 };
    ShowWashingMachine(w);

    // --- TASK 2 ---
    Iron i = { "Philips", "SteamMax 3000", "Blue", 120, 240, true, 1800 };
    ShowIron(i);

    // --- TASK 3 ---
    Boiler b = { "Ariston", "Silver", 1500, 80, 75 };
    ShowBoiler(b);

    // --- TASK 4 ---
    Animal a;
    cin.ignore();
    FillAnimal(a);
    PrintAnimal(a);
    MakeSound(a);

    return 0;
}
