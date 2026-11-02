#include <cctype>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string normalizeFuelType(const string& fuel)
{
    string normalized = fuel;

    for (char& ch : normalized)
    {
        ch = static_cast<char>(tolower(static_cast<unsigned char>(ch)));
    }

    return normalized;
}

double getDistance()
{
    double distance;

    do
    {
        cout << "Enter distance travelled (miles): ";
        cin >> distance;

        if (distance < 0)
        {
            cout << "Distance cannot be negative. Please try again.\n";
        }
    } while (distance < 0);

    return distance;
}

string getFuelType()
{
    string fuel;

    do
    {
        cout << "Enter fuel type (diesel or petrol): ";
        cin >> fuel;

        fuel = normalizeFuelType(fuel);

        if (fuel != "diesel" && fuel != "petrol")
        {
            cout << "Invalid fuel type. Please enter diesel or petrol.\n";
        }
    } while (fuel != "diesel" && fuel != "petrol");

    return fuel;
}

double calculateCO2(double distance, const string& fuel)
{
    const double FUEL_CONSUMPTION = 9.66;
    const double DIESEL_EMISSIONS = 2.68;
    const double PETROL_EMISSIONS = 2.31;

    double litresUsed = (distance * FUEL_CONSUMPTION) / 100.0;
    string normalizedFuel = normalizeFuelType(fuel);

    if (normalizedFuel == "diesel")
    {
        return litresUsed * DIESEL_EMISSIONS;
    }

    return litresUsed * PETROL_EMISSIONS;
}

int main()
{
    double distance = getDistance();
    string fuel = getFuelType();

    double emissions = calculateCO2(distance, fuel);

    cout << fixed << setprecision(2);

    cout << "\nEstimated CO2 emissions: "
         << emissions << " kg" << endl;

    return 0;
}