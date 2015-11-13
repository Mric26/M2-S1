lc = 1;

Point(1) = {0,0,0,lc};
Point(2) = {3,0,0,lc};
Point(3) = {3,8,0,lc};
Point(4) = {0,8,0,lc};

Point(5) = {1,0,0,lc};
Point(6) = {1,8,0,lc};

Point(7) = {1,1,0,lc};
Point(8) = {2,1,0,lc};
Point(9) = {2,3,0,lc};
Point(10) = {1,3,0,lc};

Point(11) = {1,4,0,lc};
Point(12) = {2,4,0,lc};
Point(13) = {2,6,0,lc};
Point(14) = {1,6,0,lc};

Point(15) = {2,0,0,lc};
Point(16) = {2,6,0,lc};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};
Line(5) = {5,6};
Line(6) = {1,5};
Line(7) = {6,4};
Line(8) = {7,8};
Line(9) = {8,9};
Line(10) = {9,10};
Line(11) = {10,7};
Line(12) = {11,12};
Line(13) = {12,13};
Line(14) = {13,14};
Line(15) = {14,11};
Line(16) = {2,5};
Line(17) = {6,3};
Line(18) = {3,2};
Line(19) = {5,7};
Line(20) = {10,11};
Line(21) = {14,6};

Line Loop(17) = {1,2,3,4};
Line Loop(18) = {6,5,7,4};
Line Loop(19) = {8,9,10,11};
Line Loop(20) = {12,13,14,15};
Line Loop(21) = {16,19,8,9,10,20,12,13,14,21,17,18};

Plane Surface(23) = {17};
Plane Surface(24) = {18};
Plane Surface(25) = {19};
Plane Surface(26) = {20};
Plane Surface(27) = {21};

Physical Line("Gamma") = {1,2,3,4};
Physical Line("Gamma1") = {6,5,7,4};
Physical Line("Gamma2") = {8,9,10,11};
Physical Line("Gamma3") = {12,13,14,15};
Physical Line("Gamma4") = {16,19,8,9,10,20,12,13,14,21,17,18};

Physical Surface("Omega") = {23};
Physical Surface("Omega1") = {25};
Physical Surface("Omega2") = {26};
Physical Surface("Omega3") = {24};
Physical Surface("Omega4") = {27};
