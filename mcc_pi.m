function [znotraj_kroznice, znotraj_kvadrata] = mcc_pi(SteviloTock)
%definiramo prazni matriki, kamor se bodo shranjevale vrednosti
znotraj_kroznice=[];
znotraj_kvadrata=[];
r=1;

%naredimo for zanko, kjer se vrednosti po izpolnitvi pogoja shranijo v
%matriki, v vrednosti x in y koordinat.
for i=1:SteviloTock
    x = 2 * rand() - 1;
    y = 2 * rand() - 1;
    if x^2 + y^2 <= r^2
         znotraj_kroznice=[znotraj_kroznice; [x,y]];
         znotraj_kvadrata=[znotraj_kvadrata;[x,y]];
    else
         znotraj_kvadrata=[znotraj_kvadrata;[x,y]];
    end
end

