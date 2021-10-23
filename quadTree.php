<?php
require_once('node.php');

class QuadTree 
{
    public Node $root;
    
    public function __construct(Point $topRightBorder)
    {
        // echo "<h1> ---------------------------------- QuadTree ----------------------------------</h1>";
        echo "<h4>(Creating QuadTree)</h4>";
        $this->root = new Node(new Point(), new Point(0, 0), $topRightBorder);
    }

    public function get_root()
    {
        return $this->root;
    }

    private function to_string_aux(Node $node)
    {
        echo "<p> Node: " . $node->to_string() . "</p>";
        if ($node->point->x != -1 && $node->point->y != -1) 
        {
            if ($node->NE->point->x != -1  &&  $node->NE->point->y != -1)
            // {
                // echo " NE: ";
                echo $this->to_string_aux($node->NE);
            // }
            if ($node->SE->point->x != -1  &&  $node->SE->point->y != -1)
            // {
                // echo " SE: ";
                echo $this->to_string_aux($node->SE);
            // }
            if ($node->SO->point->x != -1  &&  $node->SO->point->y != -1)
            // {
                // echo " SO: ";
                echo $this->to_string_aux($node->SO);
            // }
            if ($node->NO->point->x != -1  &&  $node->NO->point->y != -1)
            // {
                // echo " NO: ";
                echo $this->to_string_aux($node->NO);
            // }
        }        
    }

    public function to_string()
    {
        echo "<h1> ---------------------------------- QuadTree ----------------------------------</h1>";
        echo "<h4>Root: </h4>";
        $this->to_string_aux($this->root);
        echo "<h1> -----------------------------------------------------------------------------------</h1>";   
    }
    
    public function insert(Point $p, Node $node)
    {
        // if it's out of the node's borders, return
        if ( ($p->x < $node->bottomLeftBorder->x || $p->x > $node->topRightBorder->x) ||($p->y < $node->bottomLeftBorder->y || $p->y > $node->topRightBorder->y ) )
        {
            return;
        }
        

        if ( $node->point->x == -1 && $node->point->y == -1 )
        {
            $node->point = $p;
            
            $node->NE = new Node();
            $node->NE->bottomLeftBorder->x = $node->point->x;
            $node->NE->bottomLeftBorder->y = $node->point->y;
            $node->NE->topRightBorder->x = $node->topRightBorder->x;
            $node->NE->topRightBorder->y = $node->topRightBorder->y;

            $node->NO = new Node();
            $node->NO->bottomLeftBorder->x = $node->bottomLeftBorder->x;
            $node->NO->bottomLeftBorder->y = $node->point->y;
            $node->NO->topRightBorder->x = $node->point->x;
            $node->NO->topRightBorder->y = $node->topRightBorder->y;
            
            $node->SE = new Node();
            $node->SE->bottomLeftBorder->x = $node->point->x;
            $node->SE->bottomLeftBorder->y = $node->bottomLeftBorder->y;
            $node->SE->topRightBorder->x = $node->topRightBorder->x;
            $node->SE->topRightBorder->y = $node->point->y;
        
            $node->SO = new Node();
            $node->SO->bottomLeftBorder->x = $node->bottomLeftBorder->x;
            $node->SO->bottomLeftBorder->y = $node->bottomLeftBorder->y;
            $node->SO->topRightBorder->x = $node->point->x;
            $node->SO->topRightBorder->y = $node->point->y;

            echo "Insertado: " . $p->to_string() . "<br>";
        }
        else
        {
            if ( $p->x >= $node->point->x && $p->y >= $node->point->y )
            {
                $this->insert($p, $node->NE);
            }
            else if ($p->x >= $node->point->x && $p->y < $node->point->y)
            {
                $this->insert($p, $node->SE);
            }
            else if ($p->x < $node->point->x && $p->y < $node->point->y)
            {
                $this->insert($p, $node->SO);
            }
            else if ($p->x < $node->point->x && $p->y >= $node->point->y)
            {
                $this->insert($p, $node->NO);
            }
        }
    }

};



