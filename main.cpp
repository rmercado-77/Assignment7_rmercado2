#include <iostream>
#include <cmath>
#include "E_Field.h"
#include "B_Field.h"

// Electric_Field functions
Electric_Field::Electric_Field()
{
    // Start all three components at zero.
    E = new double[3]{0.0, 0.0, 0.0};
}

Electric_Field::Electric_Field(double x, double y, double z)
{
    // Store the components passed into the constructor.
    E = new double[3]{x, y, z};
}

Electric_Field::~Electric_Field()
{
    // Free the array when the object is done.
    delete[] E;
}

double Electric_Field::getX() const { return E[0]; }
double Electric_Field::getY() const { return E[1]; }
double Electric_Field::getZ() const { return E[2]; }
void Electric_Field::setX(double x) { E[0] = x; }
void Electric_Field::setY(double y) { E[1] = y; }
void Electric_Field::setZ(double z) { E[2] = z; }

double Electric_Field::calculateInnerProduct() const
{
    // Dot the electric field with itself.
    return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
}

double Electric_Field::calculateMagnitude() const
{
    return std::sqrt(calculateInnerProduct());
}

// Magnetic_Field functions
Magnetic_Field::Magnetic_Field()
{
    // Start all three components at zero.
    B = new double[3]{0.0, 0.0, 0.0};
}

Magnetic_Field::Magnetic_Field(double x, double y, double z)
{
    // Store the components passed into the constructor.
    B = new double[3]{x, y, z};
}

Magnetic_Field::~Magnetic_Field()
{
    // Free the array when the object is done.
    delete[] B;
}

double Magnetic_Field::getX() const { return B[0]; }
double Magnetic_Field::getY() const { return B[1]; }
double Magnetic_Field::getZ() const { return B[2]; }
void Magnetic_Field::setX(double x) { B[0] = x; }
void Magnetic_Field::setY(double y) { B[1] = y; }
void Magnetic_Field::setZ(double z) { B[2] = z; }

double Magnetic_Field::calculateMagnitude() const
{
    return std::sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
}

bool Magnetic_Field::calculateUnitVector(double &x, double &y, double &z) const
{
    double magnitude = calculateMagnitude();

    // A zero field has no unit vector, so skip the division.
    if (magnitude == 0.0)
    {
        return false;
    }

    // Divide each component by the magnitude.
    x = B[0] / magnitude;
    y = B[1] / magnitude;
    z = B[2] / magnitude;
    return true;
}

// Print the components and results for each field.
void displayElectricField(const Electric_Field &field)
{
    std::cout << "Components: (" << field.getX() << ", "
              << field.getY() << ", " << field.getZ() << ")\n";
    std::cout << "Magnitude: " << field.calculateMagnitude() << '\n';
    std::cout << "Inner product with itself: "
              << field.calculateInnerProduct() << "\n\n";
}

void displayMagneticField(const Magnetic_Field &field)
{
    std::cout << "Components: (" << field.getX() << ", "
              << field.getY() << ", " << field.getZ() << ")\n";
    std::cout << "Magnitude: " << field.calculateMagnitude() << '\n';

    double ux = 0.0, uy = 0.0, uz = 0.0;
    if (field.calculateUnitVector(ux, uy, uz))
    {
        std::cout << "Unit vector: (" << ux << ", " << uy
                  << ", " << uz << ")\n\n";
    }
    else
    {
        std::cout << "Unit vector: undefined for a zero field.\n\n";
    }
}

int main()
{
    // Try the default constructor, component constructor, and setters.
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);
    Electric_Field E_setters;
    E_setters.setX(3.0);
    E_setters.setY(4.0);
    E_setters.setZ(0.0);

    // Do the same thing for the magnetic fields.
    Magnetic_Field B_default;
    Magnetic_Field B_components(0.0, 3.0, 4.0);
    Magnetic_Field B_setters;
    B_setters.setX(1.0);
    B_setters.setY(2.0);
    B_setters.setZ(2.0);

    std::cout << "--- Default electric field ---\n";
    displayElectricField(E_default);
    std::cout << "--- Electric field from components ---\n";
    displayElectricField(E_components);
    std::cout << "--- Electric field from setters ---\n";
    displayElectricField(E_setters);

    std::cout << "--- Default magnetic field ---\n";
    displayMagneticField(B_default);
    std::cout << "--- Magnetic field from components ---\n";
    displayMagneticField(B_components);
    std::cout << "--- Magnetic field from setters ---\n";
    displayMagneticField(B_setters);
    return 0;
}
