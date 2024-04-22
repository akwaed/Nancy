#include <iostream>
#include <string>

using namespace std;


class Furniture
{
public:
    Furniture(string name, string color);
    void setName(string name);
    void setColor(string color);
    string getName();
    string getColor();
    // virtual print to display the name and color of the furniture
    virtual void print() {
        cout << "Name=" << name << ",Color=" << color << endl;};



protected:
    string name;
    string color;
};


class Recliner : public Furniture
{
public:
    Recliner(string name, string color, float maxRecliningPosition);
    void setMaxRecliningPosition(float maxRecliningPosition);
    float getMaxRecliningPosition();
    void print() override;

private:
    float maxRecliningPosition;
};

class Bed : public Furniture
{
public:
    Bed(string name, string color, float width, float length);
    void setWidth(float width);
    void setLength(int length);
    float getWidth();
    float getLength();
    void print() override;

private:
    float width;
    float length;
};

Furniture::Furniture(string name, string color) : name(name), color(color) {}

Recliner::Recliner(string name, string color, float maxRecliningPosition) : Furniture(name, color), maxRecliningPosition(maxRecliningPosition) {}

Bed::Bed(string name, string color, float width, float length) : Furniture(name, color), width(width), length(length) {}

void Recliner::print() {
    cout << "Name=" << name << ",Color=" << color << ",Position=" << maxRecliningPosition << endl;
}

// to print recliner without the color
// void Recliner::print() {
//     cout << "Name=" << name << ",Position=" << maxRecliningPosition << endl;
// }

void Bed::print() {
    cout << "Name=" << name << ",Color=" << color << ", Length=" << length << ",Width=" << length << endl;
}




int main() {
    Furniture* furniture[3];
    
    furniture[0] = new Furniture("Generic Piece", "Brown");
    furniture[1] = new Recliner("Recliner", "Black", 45.5);
    furniture[2] = new Bed("Bed", "White", 75.9, 36.5);

    for (int i = 0; i < 3; i++) {
        furniture[i]->print();
    }

    for (int i = 0; i < 3; i++) {
        delete furniture[i];
    }

    return 0;
}