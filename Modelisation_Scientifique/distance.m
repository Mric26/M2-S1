function [ d ] = distance( x, xi )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
    d = -1;
    if (all(size(x) == size(xi)))
        d = x * xi';
    end
end

