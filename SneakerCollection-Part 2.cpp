// SneakerCollection.cpp
// Assignment: Sneaker Collection Manager - Part 2
// Author: Christina Clemente
// Description: Manages a collection of five sneakers using an array.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Brand enumeration
enum SneakerBrand
{
    Nike,
    Adidas,
    Jordan,
    NewBalance,
    Puma
};

// Condition enumeration
enum SneakerCondition
{
    New,
    Excellent,
    Good,
    Fair,
    Poor
};

// Sneaker structure
struct Sneaker
{
    string model;
    SneakerBrand brand;
    double size;
    SneakerCondition condition;
    double purchasePrice;
    double estimatedValue;
};

// Function to display the available brands
void displayBrands()
{
    cout << "Select a brand:\n";
    cout << "1. Nike\n";
    cout << "2. Adidas\n";
    cout << "3. Jordan\n";
    cout << "4. New Balance\n";
    cout << "5. Puma\n";
}

// Function to convert a brand enum to a string
string getBrandName(SneakerBrand brand)
{
    switch (brand)
    {
        case Nike:
            return "Nike";
        case Adidas:
            return "Adidas";
        case Jordan:
            return "Jordan";
        case NewBalance:
            return "New Balance";
        case Puma:
            return "Puma";
        default:
            return "Unknown";
    }
}

// Function to display the available conditions
void displayConditions()
{
    cout << "Select a condition:\n";
    cout << "1. New\n";
    cout << "2. Excellent\n";
    cout << "3. Good\n";
    cout << "4. Fair\n";
    cout << "5. Poor\n";
}

// Function to convert a condition enum to a string
string getConditionName(SneakerCondition condition)
{
    switch (condition)
    {
        case New:
            return "New";
        case Excellent:
            return "Excellent";
        case Good:
            return "Good";
        case Fair:
            return "Fair";
        case Poor:
            return "Poor";
        default:
            return "Unknown";
    }
}

// Function to enter information for one sneaker
void enterSneakerInfo(Sneaker& sneaker, int number)
{
    cout << "\n================================\n";
    cout << "Enter information for Sneaker #" << number << "\n";
    cout << "================================\n";

    cout << "Model Name: ";
    getline(cin, sneaker.model);

    int brandChoice;
    displayBrands();
    cout << "Enter your choice: ";
    cin >> brandChoice;

    sneaker.brand = static_cast<SneakerBrand>(brandChoice - 1);

    cout << "Size: ";
    cin >> sneaker.size;

    int conditionChoice;
    displayConditions();
    cout << "Enter your choice: ";
    cin >> conditionChoice;

    sneaker.condition = static_cast<SneakerCondition>(conditionChoice - 1);

    cout << "Purchase Price: $";
    cin >> sneaker.purchasePrice;

    cout << "Estimated Current Value: $";
    cin >> sneaker.estimatedValue;

    // Clear the newline before the next getline()
    cin.ignore(1000, '\n');
}

// Function to display one sneaker
void displaySneaker(const Sneaker& sneaker, int number)
{
    cout << "\nSneaker #" << number << "\n";
    cout << "Model: " << sneaker.model << "\n";
    cout << "Brand: " << getBrandName(sneaker.brand) << "\n";
    cout << "Size: " << sneaker.size << "\n";
    cout << "Condition: " << getConditionName(sneaker.condition) << "\n";
    cout << "Purchase Price: $" << sneaker.purchasePrice << "\n";
    cout << "Estimated Value: $" << sneaker.estimatedValue << "\n";
}

int main()
{
    // Size of the sneaker collection
    const int COLLECTION_SIZE = 5;

    // Create an array that stores five Sneaker structures
    Sneaker collection[COLLECTION_SIZE];

    // Set money values to display with two decimal places
    cout << fixed << setprecision(2);

    // Enter information for all five sneakers using a loop
    for (int i = 0; i < COLLECTION_SIZE; i++)
    {
        enterSneakerInfo(collection[i], i + 1);
    }

    // Display the entire collection
    cout << "\n\n================================\n";
    cout << "       SNEAKER COLLECTION\n";
    cout << "================================\n";

    for (int i = 0; i < COLLECTION_SIZE; i++)
    {
        displaySneaker(collection[i], i + 1);
    }

    // Variables for collection calculations
    double totalPaid = 0;
    double totalValue = 0;

    // Calculate total purchase price and total estimated value
    for (int i = 0; i < COLLECTION_SIZE; i++)
    {
        totalPaid += collection[i].purchasePrice;
        totalValue += collection[i].estimatedValue;
    }

    // Calculate gain or loss
    double gainLoss = totalValue - totalPaid;

    // Calculate average sneaker value
    double averageValue = totalValue / COLLECTION_SIZE;

    // Display collection summary
    cout << "\n================================\n";
    cout << "       COLLECTION SUMMARY\n";
    cout << "================================\n";

    cout << "Total Paid:       $" << totalPaid << "\n";
    cout << "Current Value:    $" << totalValue << "\n";
    cout << "Gain/Loss:        $" << gainLoss << "\n";
    cout << "Average Value:    $" << averageValue << "\n";

    // Determine whether the collection gained, lost, or stayed the same
    if (gainLoss > 0)
    {
        cout << "\nYour collection has increased in value!\n";
    }
    else if (gainLoss < 0)
    {
        cout << "\nYour collection has decreased in value.\n";
    }
    else
    {
        cout << "\nYour collection has stayed the same in value.\n";
    }

    // Search for a sneaker by model name
    cout << "\n================================\n";
    cout << "         SNEAKER SEARCH\n";
    cout << "================================\n";

    string searchModel;

    cout << "Enter a sneaker model to search for: ";
    getline(cin, searchModel);

    bool found = false;

    for (int i = 0; i < COLLECTION_SIZE; i++)
    {
        if (collection[i].model == searchModel)
        {
            cout << "\nSneaker Found!\n";
            displaySneaker(collection[i], i + 1);
            found = true;
        }
    }

    if (found == false)
    {
        cout << "\nSneaker not found in collection.\n";
    }

    // Find the most valuable sneaker
    int mostValuableIndex = 0;

    for (int i = 1; i < COLLECTION_SIZE; i++)
    {
        if (collection[i].estimatedValue >
            collection[mostValuableIndex].estimatedValue)
        {
            mostValuableIndex = i;
        }
    }

    // Display the most valuable sneaker
    cout << "\n================================\n";
    cout << "       MOST VALUABLE SNEAKER\n";
    cout << "================================\n";

    cout << "Model: "
         << collection[mostValuableIndex].model << "\n";

    cout << "Brand: "
         << getBrandName(collection[mostValuableIndex].brand) << "\n";

    cout << "Estimated Value: $"
         << collection[mostValuableIndex].estimatedValue << "\n";

    return 0;
}