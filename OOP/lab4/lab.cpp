class box
{
    float length;
    float breadth;
    float height;

public:
    box()
    {
        length = 0;
        breadth = 0;
        height = 0;
    }
    box(float l, float b, float h)
    {
        length = l;
        breadth = b;
        height = h;
    }
    friend ostream &operator<<(ostream &out, const box &b);
    friend istream &operator>>(istream &in, box &b);

    box operator+(box b2)
    {
        box b;
        b.length = length + b2.length;
        b.breadth = breadth + b2.breadth;
        b.height = height + b2.height;
        return b2;
    }
};

istream &operator>>(istream &in, box &b)
{
    in >> b.length;
    in >> b.breadth;
    in >> b.height;
    return in;
}