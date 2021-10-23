<?php

class Point
{
    public $x;
    public $y;
    public $value;

    public function __construct($x=-1, $y=-1, $value=null)
    {
        $this->x = $x;
        $this->y = $y;
        $this->value = $value;
    }
    
    public function to_string()
    {
        if ($this->x == -1 && $this->y == -1)
            return "(Vacio) &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp";
        if ($this->value == null)
            return "(".$this->x.",".$this->y.")";
        return "(" . $this->x .  "," . $this->y . ") -> " . $this->value;
    }
};

class Node 
{
    public Point $point;
    public Point $bottomLeftBorder;
    public Point $topRightBorder; 

    public Node $NE;
    public Node $NO;
    public Node $SE;
    public Node $SO;

    public function __construct(Point $point = null, Point $bottomLeftBorder = null, Point $topRightBorder= null)
    {
        if ( $point != null && $bottomLeftBorder != null && $topRightBorder != null)
        {
            $this->point = $point;
            $this->bottomLeftBorder = $bottomLeftBorder;
            $this->topRightBorder = $topRightBorder;

            $this->NE = new Node();
            $this->NO = new Node();
            $this->SE = new Node();
            $this->SO = new Node();
        }
        else 
        {
            $this->point = new Point(); 
            $this->bottomLeftBorder = new Point();
            $this->topRightBorder = new Point();
        }
    }
    
    public function getNumberOfPoints()
    {
        $numberOfPoints = 0;
    
        if ($this->NE->point->x != -1 && $this->NE->point->y != -1)
        {
            $numberOfPoints += $this->NE->getNumberOfPoints();
        }
        if ($this->SE->point->x != -1 && $this->SE->point->y != -1)
        {
            $numberOfPoints += $this->SE->getNumberOfPoints();
        }
        if ($this->SO->point->x != -1 && $this->SO->point->y != -1)
        {
            $numberOfPoints += $this->SO->getNumberOfPoints();
        }
        if ($this->NO->point->x != -1 && $this->NO->point->y != -1)
        {
            $numberOfPoints += $this->NO->getNumberOfPoints();
        }
    
        return $numberOfPoints;
    }
    
    public function to_string()
    {
        $result = $this->point->to_string() . "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp";
        $result .= "&nbsp&nbsp&nbsp (x1, y1):" . $this->bottomLeftBorder->to_string();
        $result .= "&nbsp&nbsp&nbsp (x2, y2):" . $this->topRightBorder->to_string();

        return $result;
    }
};


