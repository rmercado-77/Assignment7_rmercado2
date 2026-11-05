#ifndef B_FIELD_H
#define B_FIELD_H


//pretty much same as E-Field 

class Magnetic_Field
{
private:
    // Holds the x, y, and z components.
    double *B;

public:
    Magnetic_Field();
    Magnetic_Field(double x, double y, double z);
    ~Magnetic_Field();

    // Keep objects from sharing the same allocated array.
    Magnetic_Field(const Magnetic_Field&) = delete;
    Magnetic_Field& operator=(const Magnetic_Field&) = delete;

    // Read or change each component.
    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    double calculateMagnitude() const;
    bool calculateUnitVector(double &x, double &y, double &z) const;
};

#endif
