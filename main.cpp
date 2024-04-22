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
    virtual void print() = 0;


protected:
    string name;
    string color;
};


class Recliner : public Furniture
{
public:
    Recliner(string name, string color, int maxRecliningPosition);
    void setMaxRecliningPosition(int maxRecliningPosition);
    int getMaxRecliningPosition();
    void print() override;

private:
    int maxRecliningPosition;
};

class Bed : public Furniture
{
public:
    Bed(string name, string color, int width, int length);
    void setWidth(int width);
    void setLength(int length);
    int getWidth();
    int getLength();
    void print() override;

private:
    int width;
    int length;
};

Furniture::Furniture(string name, string color) : name(name), color(color) {}

Recliner::Recliner(string name, string color, int maxRecliningPosition) : Furniture(name, color), maxRecliningPosition(maxRecliningPosition) {}

Bed::Bed(string name, string color, int width, int length) : Furniture(name, color), width(width), length(length) {}

void Recliner::print() {
    cout << "Recliner: Name - " << name << ", Color - " << color << ", Max Reclining Position - " << maxRecliningPosition << endl;
}

void Bed::print() {
    cout << "Bed: Name - " << name << ", Color - " << color << ", Width - " << width << ", Length - " << length << endl;
}

int main() {
    Furniture* furniture[3];
    
    furniture[0] = new Recliner("Recliner", "Black", 5);
    furniture[1] = new Bed("Bed", "White", 100, 200);

    for (int i = 0; i < 2; i++) {
        furniture[i]->print();
    }

    for (int i = 0; i < 2; i++) {
        delete furniture[i];
    }

    return 0;
}