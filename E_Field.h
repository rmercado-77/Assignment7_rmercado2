#ifndef E_FIELD_H
#define E_FIELD_H

class Electric_Field
{
private:
    // Holds the x, y, and z components.
    double *E;

public:
    Electric_Field();
    Electric_Field(double x, double y, double z);
    ~Electric_Field();

    // Keep objects from sharing the same allocated array.
    Electric_Field(const Electric_Field&) = delete;
    Electric_Field& operator=(const Electric_Field&) = delete;

    // Read or change each component.
    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    double calculateMagnitude() const;
    double calculateInnerProduct() const;
};

#endif
