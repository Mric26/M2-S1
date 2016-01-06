function N = bezierpatchnormal(B,u,v)

N = zeros(length(u),length(v),3);
T(:,:,:) = bezierPatchEval(B(:,:,:),u,v);

for i = 1:length(u)-1
	for j = 1:length(v)-1
        x = T(i+1,j,:) - T(i,j,:);
        x = [x(1); x(2); x(3)]; 
        y = T(i,j+1,:) - T(i,j,:);
        y = [y(1); y(2); y(3)];
        N(i,j,:) = cross(x,y) / norm(cross(x,y));
 	 end    
end