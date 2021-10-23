<?php

require_once("quadTree.php");

$qt = new QuadTree(new Point(100, 100));

$p0 = new Point(50, 50, 15);

$p1 = new Point(70, 40, 10);
$p2 = new Point(10, 20, 5);
$p3 = new Point(70, 70, 10);
$p4 = new Point(30, 80, 5);
$p5 = new Point(90, 80, 5);

// echo $p1->to_string();

// $n1 = new Node($p1, new Point(0, 0), new Point(10, 10));
// echo $n1->to_string();

echo $qt->to_string();
$qt->insert($p0, $qt->get_root());
echo $qt->to_string();
$qt->insert($p1, $qt->get_root());
echo $qt->to_string();
$qt->insert($p2, $qt->get_root());
echo $qt->to_string();
$qt->insert($p3, $qt->get_root());
echo $qt->to_string();
$qt->insert($p4, $qt->get_root());
echo $qt->to_string();
$qt->insert($p5, $qt->get_root());
echo $qt->to_string();



// $qt->insert($p1, $qt->root);
// $qt->insert($p2, $qt->root);
// $qt->insert($p3, $qt->root);
// $qt->insert($p4, $qt->root);


// qt.print();
// echo $qt->root->to_string();

?>

