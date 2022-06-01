#include <iostream>
#include <cmath>                   // Note: Needed for math functions in part (3)
#include <iomanip>
using namespace std;

// Part 1

int main(int argc, const char* argv[]) {
    double wallHeight;
    double wallWidth;
    double wallArea;
    double paintNeeded;
    unsigned int cansNeeded;

    cout << "Enter wall height (feet):" << endl;
    cin >> wallHeight;

    cout << "Enter wall width (feet):" << endl;
    cin >> wallWidth;

    // Calculate and output wall area
    wallArea = wallHeight * wallWidth;

    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << "Wall area: " << wallArea << " square feet" << endl;

    paintNeeded = wallArea / 350;
    cout << "Paint needed: " << setprecision(2) << fixed << paintNeeded << "gallons" << endl;
    cansNeeded = round(paintNeeded);
    cout << "Cans needed: " << cansNeeded << " can (s)" << endl;

    return 0;
}
