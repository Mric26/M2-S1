function I = isophotes(N,u,v,c,e)

I = N;
Iso = zeros(length(u),length(v));
L = [0 0 1];

% I(u; v) =< N(u;v);L >
%produit saclaire de x et y = x*y'

for i = 1:length(u)-1
	for j = 1:length(v)-1
        n = [N(i,j,1) N(i,j,2) N(i,j,3) ];
        Iso(i,j) = L*n';
 	 end    
end

% plot3 des points Xk(u;v) pour lesquels |I(u;v) -c| < E.

for i = 1:length(u)-1
	for j = 1:length(v)-1
        if abs(Iso(i,j)-c) > e
            I(i,j,:) = [0 0 0];
        end
 	 end    
end
