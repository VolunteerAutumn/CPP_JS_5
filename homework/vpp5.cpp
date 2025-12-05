#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Enum for species type
enum class Species { Human, Bird, Cattle };

// Union for characteristic
union Characteristic {
    int IQ;           // For human
    double flightSpeed; // For bird
    bool isArtiodactyl; // For cattle
};

// Struct for living entity
struct LivingEntity {
    int speed;
    Species specie;
    string color;
    Characteristic characteristic;
};

// Function to input a single living entity
void InputEntity(LivingEntity& entity) {
    cout << "Enter speed: ";
    cin >> entity.speed;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char type;
    cout << "Enter specie (h = human, b = bird, c = cattle): ";
    cin >> type;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (type == 'h') entity.specie = Species::Human;
    else if (type == 'b') entity.specie = Species::Bird;
    else if (type == 'c') entity.specie = Species::Cattle;

    cout << "Enter color: ";
    getline(cin, entity.color);

    switch (entity.specie) {
    case Species::Human:
        cout << "Enter IQ: ";
        cin >> entity.characteristic.IQ;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    case Species::Bird:
        cout << "Enter flight speed: ";
        cin >> entity.characteristic.flightSpeed;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    case Species::Cattle:
        cout << "Is it aritodactyl? (0 = No, 1 = Yes): ";
        cin >> entity.characteristic.isArtiodactyl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
    }
}

// Function to print a single entity
void PrintEntity(const LivingEntity& entity) {
    cout << "Speed: " << entity.speed << ", Color: " << entity.color << ", Specie: ";
    switch (entity.specie) {
    case Species::Human:
        cout << "Human, IQ: " << entity.characteristic.IQ;
        break;
    case Species::Bird:
        cout << "Bird, Flight speed: " << entity.characteristic.flightSpeed;
        break;
    case Species::Cattle:
        cout << "Cattle, Is aritodactyl: " << (entity.characteristic.isArtiodactyl ? "Yes" : "No");
        break;
    }
    cout << endl;
}

// Edit an entity
void EditEntity(LivingEntity& entity) {
    cout << "Editing entity:\n";
    InputEntity(entity);
}

// Print an array of entities
void PrintAllEntities(LivingEntity entities[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". ";
        PrintEntity(entities[i]);
    }
}

// Search by characteristic
void SearchByCharacteristic(LivingEntity entities[], int size) {
    char choice;
    cout << "Search by specie? (h/b/c): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
    case 'h': {
        int iq;
        cout << "Enter IQ to search: ";
        cin >> iq;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < size; i++) {
            if (entities[i].specie == Species::Human && entities[i].characteristic.IQ == iq) {
                PrintEntity(entities[i]);
            }
        }
        break;
    }
    case 'b': {
        double fs;
        cout << "Enter flight speed to search: ";
        cin >> fs;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < size; i++) {
            if (entities[i].specie == Species::Bird && entities[i].characteristic.flightSpeed == fs) {
                PrintEntity(entities[i]);
            }
        }
        break;
    }
    case 'c': {
        bool arti;
        cout << "Enter 0 for No, 1 for Yes: ";
        cin >> arti;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < size; i++) {
            if (entities[i].specie == Species::Cattle && entities[i].characteristic.isArtiodactyl == arti) {
                PrintEntity(entities[i]);
            }
        }
        break;
    }
    }
}

int main() {
    // Single entity
    LivingEntity entity;
    cout << "Input a single living entity:\n";
    InputEntity(entity);
    cout << "You entered:\n";
    PrintEntity(entity);

    // Array of 10 entities
    const int SIZE = 10;
    LivingEntity entities[SIZE];

    cout << "\nInput 10 living entities:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << ":\n";
        InputEntity(entities[i]);
    }

    cout << "\nAll entities:\n";
    PrintAllEntities(entities, SIZE);

    // Edit first entity
    cout << "\nEditing first entity:\n";
    EditEntity(entities[0]);

    cout << "\nAll entities after editing:\n";
    PrintAllEntities(entities, SIZE);

    // Search
    cout << "\nSearch entities by characteristic:\n";
    SearchByCharacteristic(entities, SIZE);
}
