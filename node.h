struct Point
{
    int x = -1;
    int y = -1;
    int value;
    std::string to_string()
    {
        return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }
};

class Node 
{
public:
    Point point;
    Point bottomLeftBorder;
    Point topRightBorder; 

    Node *NE;
    Node *NO;
    Node *SE;
    Node *SO;

    Node() = default;
    Node(Point point, Point bottomLeftBorder, Point topRightBorder);
    int getNumberOfPoints();
    std::string toString();
};

Node::Node(Point point, Point bottomLeftBorder, Point topRightBorder)
{
    this->point = point;
    this->bottomLeftBorder = bottomLeftBorder;
    this->topRightBorder = topRightBorder;
}

int Node::getNumberOfPoints()
{
    int numberOfPoints = 0;

    if (NE->point.x != -1 && NE->point.y != -1)
    {
        numberOfPoints += NE->getNumberOfPoints();
    }
    if (SE->point.x != -1 && SE->point.y != -1)
    {
        numberOfPoints += SE->getNumberOfPoints();
    }
    if (SO->point.x != -1 && SO->point.y != -1)
    {
        numberOfPoints += SO->getNumberOfPoints();
    }
    if (NO->point.x != -1 && NO->point.y != -1)
    {
        numberOfPoints += NO->getNumberOfPoints();
    }

    return numberOfPoints;
}

std::string Node::toString()
{
    std::string result = "Point: (" + std::to_string(point.x) + "," + std::to_string(point.y) + ")\n";
    if (NE->point.x != -1 && NE->point.y != -1)
    {
        result += " NE: " + NE->toString();
    }
    if (SE->point.x != -1 && SE->point.y != -1)
    {
        result += " SE: " + SE->toString();
    }
    if (SO->point.x != -1 && SO->point.y != -1)
    {
        result += " SO: " + SO->toString();
    }
    if (NO->point.x != -1 && NO->point.y != -1)
    {
        result += " NO: " + NO->toString();
    }

    return result;
}