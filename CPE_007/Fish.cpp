#include <iostream>
using namespace std;

int main() {

    // Dissolved Oxygen (mg/L)
    const double MIN_DO = 5.0;

    // Water Temperature (Celsius)
    const double MIN_TEMP = 27.0;
    const double MAX_TEMP = 32.0;

    // pH Level
    const double MIN_PH = 7.0;
    const double MAX_PH = 8.0;

    // Monthly Population Growth Rates
    const double SUITABLE_RATE = 0.01;
    const double PROBABLE_RATE_1 = 0.005;
    const double PROBABLE_RATE_2 = -0.005;
    const double UNSUITABLE_RATE = -0.01;

    // Simulation Duration
    const int MONTHS = 12;

    double dox, temp, ph;
    int outsideCount = 0;

    cout << "--------------- FISH++ ---------------" << endl;

    cout << "Enter Dissolved Oxygen (mg/L): ";
    cin >> dox;

    cout << "Enter Temperature in C: ";
    cin >> temp;

    cout << "Enter pH Level: ";
    cin >> ph;
    cout << endl;

    // Input validation
    if (!cin || dox < 0 || temp < 0 || ph < 0 || ph > 14) {
        cout << "Invalid water quality measurements!" << endl;
        return 0;
    }

    cout << "---------- WATER QUALITY ----------" << endl;

    // Dissolved Oxygen Comparison
    if (dox >= MIN_DO) {
        cout << "Dissolved Oxygen: SUITABLE" << endl;
    }
    else {
        cout << "Dissolved Oxygen: OUTSIDE RANGE (Low DO)" << endl;
        outsideCount++;
    }

    // Temperature Comparison
    if (temp >= MIN_TEMP && temp <= MAX_TEMP) {
        cout << "Temperature: SUITABLE" << endl;
    }
    else {
        cout << "Temperature: OUTSIDE RANGE" << endl;
        outsideCount++;
    }

    // pH Comparison
    if (ph >= MIN_PH && ph <= MAX_PH) {
        cout << "pH Level: SUITABLE" << endl;
    }
    else {
        cout << "pH Level: OUTSIDE RANGE" << endl;
        outsideCount++;
    }

    // Overall Water Quality
    cout << "\n---------- OVERALL RESULT ----------" << endl;

    if (outsideCount == 0) {
        cout << "Overall Status: SUITABLE" << endl;
    }
    else if (outsideCount == 1 || outsideCount == 2) {
        cout << "Overall Status: PROBABLE" << endl;
    }
    else {
        cout << "Overall Status: UNSUITABLE" << endl;
    }

    cout << "Variables Outside Range: "
         << outsideCount << "/3" << endl;

    // Ask user if they want to simulate
    char choice;

    cout << "\nDo you want to simulate fish population? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {

        double population, initialPopulation;
        double growthRate = 0;

        cout << "\nEnter initial fish population: ";
        cin >> population;

        if (!cin || population <= 0) {
            cout << "Invalid fish population!" << endl;
            return 0;
        }

        initialPopulation = population;

        // Select growth rate
        if (outsideCount == 0) {
            growthRate = SUITABLE_RATE;
        }
        else if (outsideCount == 1) {
            growthRate = PROBABLE_RATE_1;
        }
        else if (outsideCount == 2) {
            growthRate = PROBABLE_RATE_2;
        }
        else {
            growthRate = UNSUITABLE_RATE;
        }

        cout << "\n---------- 12-MONTH SIMULATION ----------" << endl;

        cout << "Initial Population: "
             << (long long)population << " fish" << endl;

        cout << "Monthly Growth Rate: "
             << growthRate * 100 << "%" << endl;

        cout << "\nMonth 0: "
             << (long long)(population + 0.5) << " fish" << endl;

        // Calculate population for 12 months
        for (int month = 1; month <= MONTHS; month++) {

            population = population * (1 + growthRate);

            cout << "Month " << month << ": "
                 << (long long)(population + 0.5)
                 << " fish" << endl;
        }

        cout << "\n---------- SIMULATION RESULT ----------" << endl;

        cout << "Initial Population: "
             << (long long)initialPopulation << endl;

        cout << "Final Population: "
             << (long long)(population + 0.5) << endl;

        // Identify possible contributing factors
        if (population < initialPopulation) {

            cout << "\nPopulation decreased!" << endl;
            cout << "Possible contributing variables:" << endl;

            if (dox < MIN_DO) {
                cout << "- Low Dissolved Oxygen" << endl;
            }

            if (temp < MIN_TEMP || temp > MAX_TEMP) {
                cout << "- Temperature outside preferred range" << endl;
            }

            if (ph < MIN_PH || ph > MAX_PH) {
                cout << "- pH outside preferred range" << endl;
            }
        }
        else if (population > initialPopulation) {
            cout << "\nPopulation increased!" << endl;
        }
        else {
            cout << "\nPopulation remained the same." << endl;
        }

        cout << "\nThank you for using Fish++!" << endl;
    }
    else if (choice == 'n' || choice == 'N') {
        cout << "\nThank you for using Fish++!" << endl;
    }
    else {
        cout << "\nInvalid choice! Please enter y or n." << endl;
    }

    return 0;
}