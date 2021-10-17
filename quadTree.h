class QuadTree 
{
private:
    Node *root;

public:

    QuadTree();
    Node * getRoot();
    void insert(Point point_to_insert);
    void insert(Point point_to_insert, Node *node);
    int query(Point bottom_left, Point top_right);
    int query(Point bottom_left, Point top_right, Node *node);
    void deleteNode(Node *node);
    ~QuadTree();
};


QuadTree::QuadTree()
{
    std::cout << "-------------------- QuadTree --------------------" << std::endl;
    std::cout << "Ingrese las dimensiones del  QuadTree (mxn): ";
    this->root = new Node();
    std::cin >> this->root->topRightBorder.x >> this->root->topRightBorder.y;
}

Node * QuadTree::getRoot()
{
    return this->root;
}

void QuadTree::insert(Point point_to_insert)
{
    this->insert(point_to_insert, this->root);
}

void QuadTree::insert(Point p, Node *node)
{
    // if it's out of the node's borders, return
    if ( (p.x < node->bottomLeftBorder.x || p.x > node->topRightBorder.x) ||(p.y < node->bottomLeftBorder.y || p.y > node->topRightBorder.y ) )
    {
        return;
    }

    if ( node->point.x == -1 && node->point.y == -1 )
    {
        node->point.x = p.x;
        node->point.y = p.y;
        node->point.value = p.value;

        node->NE = new Node();
        node->NE->bottomLeftBorder.x = node->point.x;
        node->NE->bottomLeftBorder.y = node->point.y;
        node->NE->topRightBorder.x = node->topRightBorder.x;
        node->NE->topRightBorder.y = node->topRightBorder.y;

        node->NO = new Node();
        node->NO->bottomLeftBorder.x = node->bottomLeftBorder.x;
        node->NO->bottomLeftBorder.y = node->point.y;
        node->NO->topRightBorder.x = node->point.x;
        node->NO->topRightBorder.y = node->topRightBorder.y;
        
        node->SE = new Node();
        node->SE->bottomLeftBorder.x = node->point.x;
        node->SE->bottomLeftBorder.y = node->bottomLeftBorder.y;
        node->SE->topRightBorder.x = node->topRightBorder.x;
        node->SE->topRightBorder.y = node->point.y;
        
        node->SO = new Node();
        node->SO->bottomLeftBorder.x = node->bottomLeftBorder.x;
        node->SO->bottomLeftBorder.y = node->bottomLeftBorder.y;
        node->SO->topRightBorder.x = node->point.x;
        node->SO->topRightBorder.y = node->point.y;

        std::cout<< "Insertado: " << node->toString() << std::endl;
    }
    else
    {
        if ( p.x >= node->point.x && p.y >= node->point.y )
        {
            this->insert(p, node->NE);
        }
        else if (p.x >= node->point.x && p.y < node->point.y)
        {
            this->insert(p, node->SE);
        }
        else if (p.x < node->point.x && p.y < node->point.y)
        {
            this->insert(p, node->SO);
        }
        else if (p.x < node->point.x && p.y >= node->point.y)
        {
            this->insert(p, node->NO);
        }
    }
}

int QuadTree::query(Point bottom_left, Point top_right)
{
    return this->query(bottom_left, top_right, this->root);
}

int QuadTree::query(Point bottom_left, Point top_right, Node *node)
{
    // si la entrada esta no es valida, retornar 0
    if ( (bottom_left.x < node->bottomLeftBorder.x || bottom_left.x > node->topRightBorder.x) ||(bottom_left.y < node->bottomLeftBorder.y || bottom_left.y > node->topRightBorder.y ) )
    {
        std::cout << "La entrada no es valida" << std::endl;
        return 0;
    }
    // Si la entrada no esta dentro del nodo, retornar 0
    if ( (top_right.x < node->bottomLeftBorder.x || top_right.x > node->topRightBorder.x) ||(top_right.y < node->bottomLeftBorder.y || top_right.y > node->topRightBorder.y ) )
    {
        std::cout << "La entrada no esta dentro del nodo" << std::endl;
        std::cout << "bottomLeft: " << node->bottomLeftBorder.x << " " << node->bottomLeftBorder.y << std::endl;
        return 0;
    }
    // Si el nodo no ha sido inicializado, retornar 0
    if ( node->point.x == -1 && node->point.y == -1 )
    {
        std::cout << "El nodo no ha sido inicializado" << std::endl;
        return 0;
    }
    if ( node->bottomLeftBorder.x >= bottom_left.x && node->bottomLeftBorder.y >= bottom_left.y && node->topRightBorder.x <= top_right.x && node->topRightBorder.y <= top_right.y )
    {
        return node->getNumberOfPoints();
    }
    else // buscar recursivamente // fix: "recursivamente avanza mucho y no revisa los datos"
    {
        if ( bottom_left.x >= node->point.x && bottom_left.y >= node->point.y )
        {
            return this->query(bottom_left, top_right, node->NE);
        }
        else if (bottom_left.x >= node->point.x && bottom_left.y < node->point.y)
        {
            return this->query(bottom_left, top_right, node->SE);
        }
        else if (bottom_left.x < node->point.x && bottom_left.y < node->point.y)
        {
            return this->query(bottom_left, top_right, node->SO);
        }
        else if (bottom_left.x < node->point.x && bottom_left.y >= node->point.y)
        {
            return this->query(bottom_left, top_right, node->NO);
        }
        else
        {
            return 0;
        }
    }
}

void QuadTree::deleteNode(Node *node)
{
    if (node->point.x != -1 && node->point.y != -1)
    {
        deleteNode(node->NE);
        deleteNode(node->SE);
        deleteNode(node->SO);
        deleteNode(node->NO);
        
    }
    delete node;
}


QuadTree::~QuadTree()
{
    deleteNode(this->root);
}
