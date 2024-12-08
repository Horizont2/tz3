#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Car {
    string name;
    int year;
    double engineVolume;
    double price;

    void print() const {
        cout << setw(15) << name << " | "
             << setw(4) << year << " | "
             << setw(6) << engineVolume << " л | "
             << setw(8) << price << " $"
             << endl;
    }
};

void displayCars(const vector<Car>& cars) {
    cout << setw(15) << "Назва" << " | "
         << setw(4) << "Рік" << " | "
         << setw(6) << "Об'єм" << " | "
         << setw(8) << "Ціна"
         << endl;
    cout << string(45, '-') << endl;

    for (const auto& car : cars) {
        car.print();
    }
}

void addCar(vector<Car>& cars) {
    Car car;
    cout << "Введіть назву автомобіля: ";
    cin >> ws; // Для очищення потоку
    getline(cin, car.name);
    cout << "Введіть рік випуску: ";
    cin >> car.year;
    cout << "Введіть об'єм двигуна (л): ";
    cin >> car.engineVolume;
    cout << "Введіть ціну ($): ";
    cin >> car.price;
    cars.push_back(car);
    cout << "Автомобіль додано!" << endl;
}

void removeCar(vector<Car>& cars) {
    string name;
    cout << "Введіть назву автомобіля для видалення: ";
    cin >> ws;
    getline(cin, name);

    auto it = remove_if(cars.begin(), cars.end(),
                        [&name](const Car& car) { return car.name == name; });

    if (it != cars.end()) {
        cars.erase(it, cars.end());
        cout << "Автомобіль видалено!" << endl;
    } else {
        cout << "Автомобіль не знайдено!" << endl;
    }
}

void sortCars(vector<Car>& cars) {
    int option;
    cout << "Оберіть параметр для сортування:\n"
         << "1 - За назвою\n"
         << "2 - За роком випуску\n"
         << "3 - За об'ємом двигуна\n"
         << "4 - За ціною\n"
         << "Ваш вибір: ";
    cin >> option;

    switch (option) {
        case 1:
            sort(cars.begin(), cars.end(),
                 [](const Car& a, const Car& b) { return a.name < b.name; });
            break;
        case 2:
            sort(cars.begin(), cars.end(),
                 [](const Car& a, const Car& b) { return a.year < b.year; });
            break;
        case 3:
            sort(cars.begin(), cars.end(),
                 [](const Car& a, const Car& b) { return a.engineVolume < b.engineVolume; });
            break;
        case 4:
            sort(cars.begin(), cars.end(),
                 [](const Car& a, const Car& b) { return a.price < b.price; });
            break;
        default:
            cout << "Неправильний вибір!" << endl;
            return;
    }
    cout << "Автомобілі відсортовано!" << endl;
}

void searchCarsByYear(const vector<Car>& cars) {
    int year;
    cout << "Введіть рік для пошуку: ";
    cin >> year;

    cout << "Результати пошуку:" << endl;
    for (const auto& car : cars) {
        if (car.year == year) {
            car.print();
        }
    }
}

int main() {
    vector<Car> cars;
    int choice;

    do {
        cout << "\nМеню:\n"
             << "1 - Додати автомобіль\n"
             << "2 - Видалити автомобіль\n"
             << "3 - Відобразити всі автомобілі\n"
             << "4 - Відсортувати автомобілі\n"
             << "5 - Пошук автомобілів за роком\n"
             << "0 - Вихід\n"
             << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addCar(cars);
                break;
            case 2:
                removeCar(cars);
                break;
            case 3:
                displayCars(cars);
                break;
            case 4:
                sortCars(cars);
                break;
            case 5:
                searchCarsByYear(cars);
                break;
            case 0:
                cout << "До побачення!" << endl;
                break;
            default:
                cout << "Неправильний вибір!" << endl;
        }
    } while (choice != 0);

    return 0;
}
