lc = 1;

Point(1) = {0,0,0,lc};
Point(2) = {3,0,0,lc};
Point(3) = {3,6,0,lc};
Point(4) = {0,6,0,lc};
Point(5) = {1,0,0,lc};
Point(6) = {1,6,0,lc};
Point(7) = {1,1,0,lc};
Point(8) = {2,1,0,lc};
Point(9) = {2,2,0,lc};
Point(10) = {1,2,0,lc};
Point(11) = {1,3,0,lc};
Point(12) = {2,3,0,lc};
Point(13) = {2,4,0,lc};
Point(14) = {1,4,0,lc};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};
Line(5) = {5,6};
Line(6) = {5,1};
Line(7) = {4,6};
Line(8) = {7,8};
Line(9) = {8,9};
Line(10) = {9,10};
Line(11) = {10,7};
Line(12) = {11,12};
Line(13) = {12,13};
Line(14) = {13,14};
Line(15) = {14,11};

Line Loop(1) = {};
Line Loop(5) = {1,2,3,4};
Line Loop(6) = {6,5,7,4};
Plane Surface(5) = {5};
Plane Surface(6) = {6};

Physical Line("Gamma") = {1,2,3,4};
Physical Surface("Omega") = {5};
