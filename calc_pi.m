SteviloTock = 10000; %definiramo stevilo tock
[napaka,pii] = area_pi1(SteviloTock);

% anonimna funkcija
kroznica = @(theta) deal(sin(theta), cos(theta));
[g,w] = kroznica(0:pi/50:2*pi);

%definiramo graf
x = 2 * rand(tocke, 1) - 1;
y = 2 * rand(tocke, 1) - 1;
razdalja = sqrt(x.^2 + y.^2);
tocke_znotraj_kroznice = razdalja <= r;
tocke_zunaj_kroznice = razdalja > r;
scatter(x(tocke_znotraj_kroznice), y(tocke_znotraj_kroznice), 50, 'red', 'x');
hold on;
scatter(x(tocke_zunaj_kroznice), y(tocke_zunaj_kroznice), 50, 'blue', 'filled');
krog(r);
axis equal;
title('Naključno generirane točke');
xlabel('x');
ylabel('y');
legend('Znotraj kroga','Izven kroga','Kroznica');

function krog(r)
    alfa = linspace(0, 2 * pi, 1000);
    x = r * cos(alfa);
    y = r * sin(alfa);
    plot(x, y, 'black', 'LineWidth', 3);
end

%funkcija za oceno napake števila pi
function [napaka, pii] = area_pi1(SteviloTock)
         [znotraj_kroznice,znotraj_kvadrata] = mcc_pi(SteviloTock);
         pii = 4*length(znotraj_kroznice)/length(znotraj_kvadrata);
         napaka = abs(pii-pi);
         disp(['Ocenjena vrednost π: ', num2str(pii)]);
         disp(['Napaka ocene: ', num2str(napaka)]);
end
