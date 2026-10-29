#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <cmath>
using namespace std;

// Original project assumptions (not species-validated)
const double MIN_DO = 5.0;
const double MIN_TEMP = 27.0;
const double MAX_TEMP = 32.0;
const double MIN_PH = 7.0;
const double MAX_PH = 8.0;
const int MONTHS = 12;

struct WaterQuality {
    double dox;
    double temp;
    double ph;
};

struct MonthlyRecord {
    int month;
    WaterQuality water;
    int outsideCount;
    string status;
    double growthRate;
    double population;
};

// Keeps user input safe from letters, infinities, and out-of-range values.
double readNumber(const string& prompt, double minimum, double maximum) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && isfinite(value) && value >= minimum && value <= maximum) {
            return value;
        }
        cout << "Invalid input. Please enter a number between "
             << minimum << " and " << maximum << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

char readChoice() {
    char choice;
    while (true) {
        cout << "\nDo you want to simulate fish population? (y/n): ";
        if (cin >> choice && (choice == 'y' || choice == 'Y' ||
                              choice == 'n' || choice == 'N')) {
            return choice;
        }
        cout << "Invalid choice. Please enter y or n.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void inputWaterQuality(WaterQuality& water, int month) {
    cout << "\n---------- MONTH " << month << " WATER QUALITY ----------\n";
    water.dox = readNumber("Enter Dissolved Oxygen (mg/L): ", 0, 100);
    water.temp = readNumber("Enter Temperature (C): ", 0, 60);
    water.ph = readNumber("Enter pH Level: ", 0, 14);
}

int countOutsideRange(const WaterQuality& water) {
    int count = 0;
    if (water.dox < MIN_DO) count++;
    if (water.temp < MIN_TEMP || water.temp > MAX_TEMP) count++;
    if (water.ph < MIN_PH || water.ph > MAX_PH) count++;
    return count;
}

string getStatus(int outsideCount) {
    if (outsideCount == 0) return "SUITABLE";
    if (outsideCount <= 2) return "PROBABLE";
    return "UNSUITABLE";
}

double getGrowthRate(int outsideCount) {
    if (outsideCount == 0) return 0.01;
    if (outsideCount == 1) return 0.005;
    if (outsideCount == 2) return -0.005;
    return -0.01;
}

void displayWaterQuality(const WaterQuality& water, int outsideCount) {
    cout << "\nDissolved Oxygen: "
         << (water.dox >= MIN_DO ? "SUITABLE" : "OUTSIDE RANGE (Low DO)") << '\n';
    cout << "Temperature: "
         << (water.temp >= MIN_TEMP && water.temp <= MAX_TEMP ? "SUITABLE" : "OUTSIDE RANGE") << '\n';
    cout << "pH Level: "
         << (water.ph >= MIN_PH && water.ph <= MAX_PH ? "SUITABLE" : "OUTSIDE RANGE") << '\n';
    cout << "Overall Status: " << getStatus(outsideCount) << '\n';
    cout << "Variables Outside Range: " << outsideCount << "/3\n";
}

void displayContributingFactors(const WaterQuality& water) {
    if (water.dox < MIN_DO) cout << "  - Low Dissolved Oxygen\n";
    if (water.temp < MIN_TEMP || water.temp > MAX_TEMP)
        cout << "  - Temperature outside preferred range\n";
    if (water.ph < MIN_PH || water.ph > MAX_PH)
        cout << "  - pH outside preferred range\n";
}

// Every record is kept for future Qt graphing: month = X, population = Y.
vector<MonthlyRecord> simulatePopulation(double initialPopulation) {
    vector<MonthlyRecord> history;
    double population = initialPopulation;

    for (int month = 1; month <= MONTHS; month++) {
        WaterQuality water;
        inputWaterQuality(water, month);

        int outsideCount = countOutsideRange(water);
        double rate = getGrowthRate(outsideCount);
        population *= (1.0 + rate);

        MonthlyRecord record = {month, water, outsideCount,
                                getStatus(outsideCount), rate, population};
        history.push_back(record);

        displayWaterQuality(water, outsideCount);
        cout << "Monthly Growth Rate: " << showpos << fixed << setprecision(2)
             << rate * 100 << "%" << noshowpos << '\n';
        cout << "Estimated Population: " << fixed << setprecision(0)
             << population << " fish\n";
        if (rate < 0) {
            cout << "Possible contributing variables:\n";
            displayContributingFactors(water);
        }
    }
    return history;
}

void displaySummary(const vector<MonthlyRecord>& history, double initialPopulation) {
    cout << "\n---------------- 12-MONTH SUMMARY ----------------\n";
    cout << left << setw(7) << "Month" << setw(9) << "DO"
         << setw(9) << "Temp" << setw(8) << "pH"
         << setw(14) << "Status" << setw(10) << "Rate"
         << "Population\n";
    cout << string(70, '-') << '\n';
    cout << left << setw(7) << 0 << setw(9) << "-" << setw(9) << "-"
         << setw(8) << "-" << setw(14) << "INITIAL" << setw(10) << "-"
         << fixed << setprecision(0) << initialPopulation << '\n';

    for (const MonthlyRecord& r : history) {
        cout << left << setw(7) << r.month
             << setw(9) << fixed << setprecision(2) << r.water.dox
             << setw(9) << r.water.temp
             << setw(8) << r.water.ph
             << setw(14) << r.status
             << showpos << fixed << setprecision(2) << r.growthRate * 100
             << "%" << noshowpos << "       "
             << fixed << setprecision(0) << r.population << '\n';
    }

    double finalPopulation = history.back().population;
    cout << "\n---------- SIMULATION RESULT ----------\n";
    cout << "Initial Population: " << fixed << setprecision(0) << initialPopulation << '\n';
    cout << "Final Population: " << finalPopulation << '\n';
    cout << "Net Change: " << showpos << finalPopulation - initialPopulation
         << noshowpos << " fish\n";

    if (finalPopulation > initialPopulation)
        cout << "Overall Trend: Population increased!\n";
    else if (finalPopulation < initialPopulation)
        cout << "Overall Trend: Population decreased!\n";
    else
        cout << "Overall Trend: Population remained the same.\n";
    cout << "Note: This is a simplified estimate, not a validated biological forecast.\n";
}

int main() {
    cout << "--------------- FISH++ ---------------\n";
    cout << "12-Month Water Quality and Fish Population Simulation\n";
    char choice = readChoice();
    if (choice == 'n' || choice == 'N') {
        cout << "\nThank you for using Fish++!\n";
        return 0;
    }

    double initialPopulation = readNumber("\nEnter initial fish population: ", 1, 1000000000);
    cout << "Initial Population: " << fixed << setprecision(0)
         << initialPopulation << " fish\n";
    vector<MonthlyRecord> history = simulatePopulation(initialPopulation);
    displaySummary(history, initialPopulation);
    cout << "\nThank you for using Fish++!\n";
    return 0;
}