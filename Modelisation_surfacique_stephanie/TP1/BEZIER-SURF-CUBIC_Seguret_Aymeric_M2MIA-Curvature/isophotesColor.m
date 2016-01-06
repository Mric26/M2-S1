function I = isophotesColor(N,u,v,L,taille)

I = zeros(length(u),length(v));
Iso = zeros(length(u),length(v));

for i = 1:length(u)-1
	for j = 1:length(v)-1
        n = [N(i,j,1) N(i,j,2) N(i,j,3) ];
        Iso(i,j) = abs(L*n');
 	 end    
end

minm = min(min(Iso));
maxm = max(max(Iso));
inter = (maxm-minm)/taille;

for i = 1:length(u)
	for j = 1:length(v)
        val = floor(Iso(i,j)/inter);
        if val < taille
            I(i,j) = val+1;
        else 
            I(i,j) = val;
        end
 	 end    
end